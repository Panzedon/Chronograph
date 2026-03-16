#include "iostm8s103.h"
#include "tm1637.h"
#include "buttons.h"
#include "eeprom.h" 
#include "chrono.h" 

#define VEL_CONST 800000UL /* Коэффициент для базы 50 мм при 16 МГц */

/* --- Шрифты --- */
#define L_H 0x76 
#define L_I 0x06 
#define L_S 0x6D
#define L_P 0x73
#define L_d 0x5E
#define L_E 0x79
#define L_n 0x54
#define L_r 0x50
#define L_o 0x5C
#define L_F 0x71
#define L_b 0x7C
#define L_blank 0x00

typedef enum { MODE_SPEED = 0, MODE_ENERGY, MODE_ROF, MODE_WEIGHT } chrono_mode_t;

/* Глобальные переменные UI */
chrono_mode_t current_mode = MODE_SPEED; 
uint8_t is_system_on = 1;                
uint8_t weight_idx = 0; 
uint8_t bb_weights[5] = {20, 23, 25, 28, 30}; 

/* Данные выстрела */
uint16_t v_speed = 0;   
uint16_t v_energy = 0;  
uint16_t v_rof = 0;     
chrono_mode_t prev_mode = MODE_SPEED;

/* Таймеры */
uint32_t global_ms = 0;
uint32_t last_shot_ms = 0;

void TM1637_ShowWord(uint8_t l1, uint8_t l2, uint8_t l3) {
    uint8_t s[4];
    s[0] = l1; s[1] = l2; s[2] = l3; s[3] = 0x00;
    TM1637_SetSegments(s, 4, 0);
}

void Sys_Init(void) { 
    CLK_CKDIVR = 0x00; 
    Chrono_Init(); 
}

void Delay_ms_Safe(uint16_t ms) {
    uint16_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1600; j++) { _asm("nop"); }
    }
}

void main(void) {

    uint8_t update_screen = 1;
    btn_event_t btn2_event;
    
    uint32_t delta_ticks; // БЫЛ uint16_t, СТАЛ uint32_t;
    uint32_t v32, w32, delta_ms;
    
    /* Переменные для неблокирующего показа названий режимов */
    uint8_t show_mode_name = 1; 
    uint32_t mode_name_end_ms = 1500; // Показываем 1.5 секунды

    Sys_Init();
    TM1637_Init();
    TM1637_SetBrightness(2);
    Buttons_Init();

    _asm("rim");

    TM1637_ShowWord(L_blank, L_H, L_I); 
    //TM1637_ShowWord(L_E, L_r, L_r);
    Delay_ms_Safe(1000); // Приветствие можно сделать через delay

    /* Загрузка из EEPROM */
    current_mode = (chrono_mode_t)EEPROM_Read(EEPROM_ADDR_MODE);
    weight_idx = EEPROM_Read(EEPROM_ADDR_WEIGHT);
    if (current_mode > 3) { current_mode = MODE_SPEED; EEPROM_Write(EEPROM_ADDR_MODE, 0); }
    if (weight_idx > 4) { weight_idx = 0; EEPROM_Write(EEPROM_ADDR_WEIGHT, 0); }

    /* Настраиваем таймер показа первого режима после включения */
    show_mode_name = 1;
    mode_name_end_ms = global_ms + 1000;

    TM1637_Clear();

    while (1) {
        /* Системный таймер 1мс (Не блокировать Delay_ms!) */
        if (TIM4_SR & 0x01) { 
            TIM4_SR = 0x00; 
            Buttons_Tick(); 
            global_ms++; 
            
            /* Таймер скрытия названия режима */
            if (show_mode_name && global_ms >= mode_name_end_ms) {
                show_mode_name = 0;
                update_screen = 1; // Возвращаем цифры (нули или данные)
            }
        }
        
        if (Buttons_GetEvent(BTN_1_LASER) == EVENT_SHORT_PRESS) {
            is_system_on = !is_system_on;
            update_screen = 1; 
            if (!is_system_on) TM1637_Clear();
        }

        if (!is_system_on) continue;
/* =======================================================
         * ОБРАБОТКА ВЫСТРЕЛА
         * ======================================================= */
        if (Chrono_IsReady()) {
            delta_ticks = Chrono_GetTotalTicks();
            
            if (delta_ticks > 3200) { // Защита от мусора
                /* Скорость */
                v32 = VEL_CONST / delta_ticks;
                if (v32 > 999) v32 = 999;
                v_speed = (uint16_t)v32;
                
                /* Энергия */
                w32 = bb_weights[weight_idx];
                v_energy = (uint16_t)((w32 * v32 * v32) / 2000); 
                
                /* Скорострельность */
                if (last_shot_ms > 0 && global_ms > last_shot_ms) {
                    delta_ms = global_ms - last_shot_ms;
                    if (delta_ms > 20 && delta_ms < 2000) { // Игнорируем выстрелы реже 1 раза в 2 секунды
                        v_rof = (uint16_t)(60000UL / delta_ms); 
                    } else {
                        v_rof = 0; 
                    }
                }
                last_shot_ms = global_ms;
                
                show_mode_name = 0; // Сбиваем показ букв, если выстрелили прямо во время переключения меню
                update_screen = 1; 
            }
            Chrono_Reset(); 
        }

        /* =======================================================
         * ЛОГИКА МЕНЮ
         * ======================================================= */
        btn2_event = Buttons_GetEvent(BTN_2_MENU);
        if (btn2_event != EVENT_NONE) {
            update_screen = 1; 
            
            if (current_mode != MODE_WEIGHT) {
                if (btn2_event == EVENT_SHORT_PRESS) {
                    current_mode++;
                    if (current_mode == MODE_WEIGHT) current_mode = MODE_SPEED;
                    EEPROM_Write(EEPROM_ADDR_MODE, (uint8_t)current_mode);
                    
                    show_mode_name = 1;
                    mode_name_end_ms = global_ms + 1000; // Показываем буквы 1 сек
                } 
                else if (btn2_event == EVENT_LONG_PRESS) {
                    prev_mode = current_mode; 
                    current_mode = MODE_WEIGHT;
                    show_mode_name = 1;
                    mode_name_end_ms = global_ms + 1000;
                }
            } else {
                if (btn2_event == EVENT_SHORT_PRESS) {
                    weight_idx++;
                    if (weight_idx > 4) weight_idx = 0;
                    /* В режиме веса всегда показываем цифры */
                    show_mode_name = 0; 
                } 
                else if (btn2_event == EVENT_LONG_PRESS) {
                    EEPROM_Write(EEPROM_ADDR_WEIGHT, weight_idx);
                    current_mode = prev_mode; 
                    
                    show_mode_name = 1;
                    mode_name_end_ms = global_ms + 1000;
                }
            }
        }
/* =======================================================
         * ВЫВОД НА ЭКРАН
         * ======================================================= */
        if (update_screen) {
            if (show_mode_name) {
                switch (current_mode) {
                    case MODE_SPEED:   TM1637_ShowWord(L_S, L_P, L_d); break;
                    case MODE_ENERGY:  TM1637_ShowWord(L_E, L_n, L_E); break;
                    case MODE_ROF:     TM1637_ShowWord(L_r, L_o, L_F); break;
                    case MODE_WEIGHT:  TM1637_ShowWord(L_b, L_b, L_blank); break;
                }
            } else {
                switch (current_mode) {
                    case MODE_SPEED:   
                        if (v_speed == 0) TM1637_Display000(); 
                        else TM1637_DisplayInt(v_speed); 
                        break;
                    case MODE_ENERGY:  
                        if (v_energy == 0) TM1637_Display0_00(); 
                        else TM1637_DisplayIntWithDots(v_energy, 0x04); 
                        break;
                    case MODE_ROF:     
                        if (v_rof == 0) TM1637_Display000(); 
                        else TM1637_DisplayInt(v_rof); 
                        break;
                    case MODE_WEIGHT:  
                        TM1637_DisplayXXX(0, bb_weights[weight_idx] / 10, bb_weights[weight_idx] % 10); 
                        break;
                }
            }
            update_screen = 0; 
        }
    }
}