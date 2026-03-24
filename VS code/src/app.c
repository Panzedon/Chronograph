#include "app.h"

#define VEL_CONST 800000UL /* База 50 мм при 16 МГц */

app_state_t app; 
static uint8_t bb_weights[5] = {20, 23, 25, 28, 30}; 

uint32_t global_ms = 0;
static uint32_t last_shot_ms = 0;

/**
 * @brief Блокуюча затримка у мілісекундах.
 * @note Використовує інструкцію nop. Калібрування під 16 МГц.
 * @param ms Кількість мілісекунд для затримки.
 */
void Delay_ms_Safe(uint16_t ms) {
    uint16_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1600; j++) { ASM_("nop"); }
    }
}

/**
 * @brief Глобальна ініціалізація апаратних та програмних підсистем.
 * @note Ініціалізує Chrono, TM1637 та кнопки. Встановлює початковий стан.
 */
void Sys_Init(void) { 
    CPU_Speed_Init(); 
    Chrono_Init(); 
    TM1637_Init();
    TM1637_SetBrightness(2);
    Buttons_Init();
    
    app.is_system_on = 1;
    app.update_screen = 1;
    app.show_mode_name = 1;
    app.mode_name_end_ms = 1000;
}

void Memory_Poll(void){
    app.current_mode = (chrono_mode_t)EEPROM_Read(EEPROM_ADDR_MODE);
    app.weight_idx = EEPROM_Read(EEPROM_ADDR_WEIGHT);
    
    if (app.current_mode > 3) { 
        app.current_mode = MODE_SPEED; 
        EEPROM_Write(EEPROM_ADDR_MODE, 0); 
    }
    if (app.weight_idx > 4) { 
        app.weight_idx = 0; 
        EEPROM_Write(EEPROM_ADDR_WEIGHT, 0); 
    }
}

/**
 * @brief Розрахунок фізичних параметрів пострілу.
 * @note Обчислює швидкість, енергію та скорострільність.
 * Фільтрує хибні спрацювання (delta_ticks < 3200).
 * @see Chrono_GetTotalTicks
 */
static void App_ProcessShot(void) {
    uint32_t delta_ticks;
    if (!Chrono_IsReady()) return;

    delta_ticks = Chrono_GetTotalTicks();
            
    if (delta_ticks > 3200) { 
        uint32_t v32, w32;
        v32 = VEL_CONST / delta_ticks;
        if (v32 > 999) v32 = 999;
        app.v_speed = (uint16_t)v32;
        
        w32 = bb_weights[app.weight_idx];
        app.v_energy = (uint16_t)((w32 * v32 * v32) / 2000); 
        
        if (last_shot_ms > 0 && global_ms > last_shot_ms) {
            uint32_t delta_ms = global_ms - last_shot_ms;
            if (delta_ms > 20 && delta_ms < 2000) { 
                app.v_rof = (uint16_t)(60000UL / delta_ms); 
            } else {
                app.v_rof = 0; 
            }
        }
        last_shot_ms = global_ms;
        app.show_mode_name = 0;
        app.update_screen = 1; 
    }
    Chrono_Reset(); 
}

/**
 * @brief Обробка натискань кнопок та навігація по меню.
 * @note Керує перемиканням режимів та зміною ваги кульки.
 * @see Buttons_GetEvent
 */
static void App_ProcessMenu(void) {
    btn_event_t btn1_event = Buttons_GetEvent(BTN_1_LASER);
    btn_event_t btn2_event = Buttons_GetEvent(BTN_2_MENU);

    if (btn1_event == EVENT_SHORT_PRESS) {
        app.is_system_on = !app.is_system_on;
        app.update_screen = 1; 
        if (!app.is_system_on) TM1637_Clear();
        return;
    }

    if (!app.is_system_on) return;

    if (btn2_event != EVENT_NONE) {
        app.update_screen = 1; 
        if (app.current_mode != MODE_WEIGHT) {
            if (btn2_event == EVENT_SHORT_PRESS) {
                app.current_mode++;
                if (app.current_mode == MODE_WEIGHT) app.current_mode = MODE_SPEED;
                EEPROM_Write(EEPROM_ADDR_MODE, (uint8_t)app.current_mode);
                app.show_mode_name = 1;
                app.mode_name_end_ms = global_ms + 1000; 
            } 
            else if (btn2_event == EVENT_LONG_PRESS) {
                app.prev_mode = app.current_mode; 
                app.current_mode = MODE_WEIGHT;
                app.show_mode_name = 1;
                app.mode_name_end_ms = global_ms + 1000;
            }
        } else {
            if (btn2_event == EVENT_SHORT_PRESS) {
                app.weight_idx++;
                if (app.weight_idx > 4) app.weight_idx = 0;
            } 
            else if (btn2_event == EVENT_LONG_PRESS) {
                EEPROM_Write(EEPROM_ADDR_WEIGHT, app.weight_idx);
                app.current_mode = app.prev_mode; 
                app.show_mode_name = 1;
                app.mode_name_end_ms = global_ms + 1000;
            }
        }
    }
}

/**
 * @brief Оновлення даних на семисегментному дисплеї.
 * @note Виводить результати вимірів або повідомлення (назви режимів).
 */
static void App_UpdateDisplay(void) {
    if (!app.update_screen || !app.is_system_on) return;

    if (app.show_mode_name) {
        switch (app.current_mode) {
            case MODE_SPEED:   ShowMode_Speed(); break;
            case MODE_ENERGY:  ShowMode_Energy(); break;
            case MODE_ROF:     ShowMode_ROF(); break;
            case MODE_WEIGHT:  ShowMode_Weight(); break;
        }
    } else {
        switch (app.current_mode) {
            case MODE_SPEED:   
                if (app.v_speed == 0) TM1637_Display000(); 
                else TM1637_DisplayInt(app.v_speed); 
                break;
            case MODE_ENERGY:  
                if (app.v_energy == 0) TM1637_Display0_00(); 
                else TM1637_DisplayIntWithDots(app.v_energy, 0x04); 
                break;
            case MODE_ROF:     
                if (app.v_rof == 0) TM1637_Display000(); 
                else TM1637_DisplayInt(app.v_rof); 
                break;
            case MODE_WEIGHT:  
                TM1637_DisplayXXX(0, bb_weights[app.weight_idx] / 10, bb_weights[app.weight_idx] % 10); 
                break;
        }
    }
    app.update_screen = 0; 
}

void App_Run(void) {
    while(1){
        if (Timer_IsTickElapsed()) { 
            Buttons_Tick();          
            global_ms++;       
            if (app.show_mode_name && global_ms >= app.mode_name_end_ms) {
                app.show_mode_name = 0;
                app.update_screen = 1; 
            }
        }
        App_ProcessMenu();           
        if (app.is_system_on) App_ProcessShot();       
        App_UpdateDisplay(); 
    }  
}