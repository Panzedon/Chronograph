#include "buttons.h"

#define BTN1_PIN (1 << 1) /* PA1 */
#define BTN2_PIN (1 << 2) /* PA2 */

#define DEBOUNCE_TIME_MS 30
#define LONG_PRESS_TIME_MS 1000

/* Використовуємо стандартні типи C, щоб не залежати від інших файлів */
typedef struct {
    unsigned int  counter;    /* Лічильник мілісекунд утримання */
    unsigned char state;      /* 0 = відпущена, 1 = натиснута, 2 = утримання */
    btn_event_t   event;      /* Готова подія для передачі в main */
} button_state_t;

static button_state_t btns[2];

/**
 * @brief Ініціалізація портів вводу/виводу для кнопок та таймера антибрязкоту.
 * @details Налаштовує піни PA1 та PA2 на вхід (без підтяжки/переривань).
 * Скидає стан внутрішніх структур кнопок. Налаштовує TIM4 для 
 * генерації переривань або встановлення прапорців кожну мілісекунду.
 */
void Buttons_Init(void) {
    PA_DDR &= ~(BTN1_PIN | BTN2_PIN);
    PA_CR1 &= ~(BTN1_PIN | BTN2_PIN);
    PA_CR2 &= ~(BTN1_PIN | BTN2_PIN);

    btns[0].counter = 0; btns[0].state = 0; btns[0].event = EVENT_NONE;
    btns[1].counter = 0; btns[1].state = 0; btns[1].event = EVENT_NONE;

    TIM4_PSCR = 0x07; 
    TIM4_ARR  = 124;  
    
    /* TIM4_IER |= 0x01; */
    TIM4_CR1 |= 0x01; 
}

/**
 * @brief Кінцевий автомат (стейт-машина) обробки фізичного стану кнопок.
 * @details Зчитує фізичний стан пінів кнопок. Фільтрує брязкіт контактів 
 * (затримка DEBOUNCE_TIME_MS). Відстежує час утримання кнопки для генерації 
 * подій короткого (EVENT_SHORT_PRESS) або довгого (EVENT_LONG_PRESS) натискання.
 * Повинна викликатися рівно раз на 1 мс.
 */
void Buttons_Tick(void) {
    unsigned char i;
    unsigned char pins_state;
    unsigned char is_pressed[2];

    pins_state = PA_IDR; /* Читаємо весь порт A один раз */

    is_pressed[0] = (pins_state & BTN1_PIN);
    is_pressed[1] = (pins_state & BTN2_PIN);

    for (i = 0; i < 2; i++) {
        if (is_pressed[i]) {
            if (btns[i].state == 0) {
                btns[i].state = 1; 
            }
            
            if (btns[i].state == 1) {
                btns[i].counter++; 
                
                if (btns[i].counter >= LONG_PRESS_TIME_MS) {
                    btns[i].event = EVENT_LONG_PRESS; 
                    btns[i].state = 2; 
                }
            }
        } else {
            if (btns[i].state == 1) {
                if (btns[i].counter >= DEBOUNCE_TIME_MS) {
                    btns[i].event = EVENT_SHORT_PRESS; 
                }
            }
            btns[i].state = 0;
            btns[i].counter = 0;
        }
    }
}

/**
 * @brief Повертає зареєстровану подію для вказаної кнопки та скидає її.
 * @details Безпечно (з відключенням переривань) читає подію з буфера кнопки.
 * Після читання подія обнуляється, щоб уникнути повторного спрацьовування.
 * @param btn_id Ідентифікатор кнопки (BTN_1_LASER або BTN_2_MENU).
 * @return btn_event_t Тип події (EVENT_NONE, EVENT_SHORT_PRESS, EVENT_LONG_PRESS).
 */
btn_event_t Buttons_GetEvent(button_id_t btn_id) {
    btn_event_t current_event;
    
    _asm("sim"); 
    
    current_event = btns[btn_id].event; 
    btns[btn_id].event = EVENT_NONE;    
    
    _asm("rim"); 
    
    return current_event;
}