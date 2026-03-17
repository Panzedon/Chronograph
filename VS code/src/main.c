#include "iostm8s103.h"
#include "tm1637.h"
#include "buttons.h"
#include "eeprom.h" 
#include "chrono.h" 

#define VEL_CONST 800000UL /* Коефіцієнт для бази 50 мм при 16 МГц */

/* --- Шрифти --- */
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

/* --- Глобальний стан системи (Інкапсуляція) --- */
typedef struct {
    chrono_mode_t current_mode;
    chrono_mode_t prev_mode;
    uint8_t is_system_on;
    uint8_t weight_idx;
    uint16_t v_speed;
    uint16_t v_energy;
    uint16_t v_rof;
    uint8_t show_mode_name;
    uint32_t mode_name_end_ms;
    uint8_t update_screen;
} app_state_t;

static app_state_t app;
static uint8_t bb_weights[5] = {20, 23, 25, 28, 30}; 

/* Таймери */
static uint32_t global_ms = 0;
static uint32_t last_shot_ms = 0;

/* =======================================================
 * АБСТРАКЦІЇ ТА УТИЛІТИ (DIP - Dependency Inversion)
 * ======================================================= */

/**
 * @brief Допоміжна функція для виведення 3-х літерного слова на дисплей.
 * @details Формує масив сегментів з трьох переданих символів (четвертий 
 * розряд гаситься нулем) та відправляє на дисплей.
 * @param l1 Код сегментів для першої літери.
 * @param l2 Код сегментів для другої літери.
 * @param l3 Код сегментів для третьої літери.
 */
static void TM1637_ShowWord(uint8_t l1, uint8_t l2, uint8_t l3) {
    uint8_t s[4];
    s[0] = l1; s[1] = l2; s[2] = l3; s[3] = 0x00;
    TM1637_SetSegments(s, 4, 0);
}

/**
 * @brief Блокуюча затримка у мілісекундах.
 * @details Використовує вкладені цикли з інструкцією `nop` для створення 
 * програмної затримки. Калібрування підібране для частоти 16 МГц.
 * @param ms Кількість мілісекунд для затримки.
 */
static void Delay_ms_Safe(uint16_t ms) {
    uint16_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1600; j++) { ASM_("nop"); }
    }
}

/* =======================================================
 * ЗАДАЧА 1: ФІЗИКА (SRP - Single Responsibility)
 * ======================================================= */

/**
 * @brief Обробка фізичних розрахунків після фіксації пострілу.
 * @details Якщо хронограф зафіксував проліт (`Chrono_IsReady`), функція:
 * 1. Відкидає мусорні значення (надто короткі тіки).
 * 2. Розраховує швидкість (v = S/t).
 * 3. Розраховує дульну енергію (E = m*v^2 / 2).
 * 4. Розраховує скорострільність (ROF = пострілів на хвилину) на основі часу між пострілами.
 * Після розрахунків скидає стан апаратної частини для наступного пострілу.
 */
static void App_ProcessShot(void) {
    uint32_t delta_ticks;

    if (!Chrono_IsReady()) return;

    delta_ticks = Chrono_GetTotalTicks();
            
    if (delta_ticks > 3200) { /* Захист від сміття */
        uint32_t v32, w32;
        /* Швидкість */
        v32 = VEL_CONST / delta_ticks;
        if (v32 > 999) v32 = 999;
        app.v_speed = (uint16_t)v32;
        
        /* Енергія */
        w32 = bb_weights[app.weight_idx];
        app.v_energy = (uint16_t)((w32 * v32 * v32) / 2000); 
        
        /* Скорострільність */
        if (last_shot_ms > 0 && global_ms > last_shot_ms) {
            uint32_t delta_ms;
            delta_ms = global_ms - last_shot_ms;
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

/* =======================================================
 * ЗАДАЧА 2: ЛОГІКА МЕНЮ (SRP)
 * ======================================================= */

/**
 * @brief Обробка логіки інтерфейсу користувача (кнопок).
 * @details Керує станами пристрою:
 * - Кнопка 1: Коротке натискання вмикає/вимикає систему (софтверно).
 * - Кнопка 2 (коротке): Перемикає режими екрану (Швидкість -> Енергія -> ROF).
 * - Кнопка 2 (довге): Вхід в режим вибору ваги кульки.
 * Зміни зберігаються в EEPROM. Встановлює прапорці оновлення екрану.
 */
static void App_ProcessMenu(void) {
    btn_event_t btn1_event = Buttons_GetEvent(BTN_1_LASER);
    btn_event_t btn2_event = Buttons_GetEvent(BTN_2_MENU);

    /* Обробка кнопки 1 (УВІМК/ВИМК) */
    if (btn1_event == EVENT_SHORT_PRESS) {
        app.is_system_on = !app.is_system_on;
        app.update_screen = 1; 
        if (!app.is_system_on) TM1637_Clear();
        return;
    }

    if (!app.is_system_on) return;

    /* Обробка кнопки 2 (Меню) */
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
                app.show_mode_name = 0; 
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

/* =======================================================
 * ЗАДАЧА 3: ВІДМАЛЬОВКА ІНТЕРФЕЙСУ (SRP)
 * ======================================================= */

/**
 * @brief Оновлення зображення на дисплеї TM1637.
 * @details Викликається лише тоді, коли піднято прапорець `app.update_screen`.
 * Залежно від поточного режиму (`current_mode`) та стану `show_mode_name`,
 * виводить або назву режиму (SPd, EnE, roF, bb), або конкретне числове 
 * значення швидкості, енергії, скорострільності чи ваги.
 */
static void App_UpdateDisplay(void) {
    if (!app.update_screen || !app.is_system_on) return;

    if (app.show_mode_name) {
        switch (app.current_mode) {
            case MODE_SPEED:   TM1637_ShowWord(L_S, L_P, L_d); break;
            case MODE_ENERGY:  TM1637_ShowWord(L_E, L_n, L_E); break;
            case MODE_ROF:     TM1637_ShowWord(L_r, L_o, L_F); break;
            case MODE_WEIGHT:  TM1637_ShowWord(L_b, L_b, L_blank); break;
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

/* =======================================================
 * ІНІЦІАЛІЗАЦІЯ ТА ГОЛОВНИЙ ЦИКЛ
 * ======================================================= */

/**
 * @brief Глобальна ініціалізація апаратних та програмних підсистем.
 * @details Переводить мікроконтролер на частоту 16 МГц (внутрішній осцилятор).
 * Ініціалізує оптичні датчики (Chrono), дисплей (TM1637) та кнопки.
 * Встановлює початковий стан додатку.
 */
static void Sys_Init(void) { 
    CLK_CKDIVR = 0x00; 
    Chrono_Init(); 
    TM1637_Init();
    TM1637_SetBrightness(2);
    Buttons_Init();
    
    app.is_system_on = 1;
    app.update_screen = 1;
    app.show_mode_name = 1;
    app.mode_name_end_ms = 1000;
}

/**
 * @brief Головна точка входу.
 * @details Після ініціалізації завантажує налаштування з EEPROM. 
 * У нескінченному циклі реалізує архітектуру "Суперцикл з диспетчером":
 * 1. Обробка системного таймера (1 мс) для відліку часу та опитування кнопок.
 * 2. Обробка логіки меню (зміна режимів).
 * 3. Обробка фізики (розрахунки після пострілу).
 * 4. Оновлення дисплея.
 */
void main(void) {
    Sys_Init();
    ASM_("rim");

    TM1637_ShowWord(L_blank, L_H, L_I); 
    Delay_ms_Safe(1000); 

    /* Завантаження з EEPROM */
    app.current_mode = (chrono_mode_t)EEPROM_Read(EEPROM_ADDR_MODE);
    app.weight_idx = EEPROM_Read(EEPROM_ADDR_WEIGHT);
    if (app.current_mode > 3) { app.current_mode = MODE_SPEED; EEPROM_Write(EEPROM_ADDR_MODE, 0); }
    if (app.weight_idx > 4) { app.weight_idx = 0; EEPROM_Write(EEPROM_ADDR_WEIGHT, 0); }

    TM1637_Clear();

    /* ГОЛОВНИЙ ЦИКЛ - Чистий диспетчер задач */
    while (1) {
        /* 1. Системні таймери */
        if (TIM4_SR & 0x01) { 
            TIM4_SR = 0x00; 
            Buttons_Tick(); 
            global_ms++; 
            
            if (app.show_mode_name && global_ms >= app.mode_name_end_ms) {
                app.show_mode_name = 0;
                app.update_screen = 1; 
            }
        }
        
        /* 2. Логіка (Input & Physics) */
        App_ProcessMenu();
        if (app.is_system_on) {
            App_ProcessShot();
        }

        /* 3. Відмальовка (Output) */
        App_UpdateDisplay();
    }
}