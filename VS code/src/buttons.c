
#include "buttons.h"

#define BTN1_PIN (1 << 1) /* PA1 */
#define BTN2_PIN (1 << 2) /* PA2 */

#define DEBOUNCE_TIME_MS 30
#define LONG_PRESS_TIME_MS 1000

/* Используем стандартные типы C, чтобы не зависеть от других файлов */
typedef struct {
    unsigned int  counter;    /* Счетчик миллисекунд удержания */
    unsigned char state;      /* 0 = отпущена, 1 = нажата, 2 = удержание */
    btn_event_t   event;      /* Готовое событие для передачи в main */
} button_state_t;

static button_state_t btns[2];

void Buttons_Init(void) {
    PA_DDR &= ~(BTN1_PIN | BTN2_PIN);
    PA_CR1 &= ~(BTN1_PIN | BTN2_PIN);
    PA_CR2 &= ~(BTN1_PIN | BTN2_PIN);

    btns[0].counter = 0; btns[0].state = 0; btns[0].event = EVENT_NONE;
    btns[1].counter = 0; btns[1].state = 0; btns[1].event = EVENT_NONE;

    TIM4_PSCR = 0x07; 
    TIM4_ARR  = 124;  
    
    //TIM4_IER |= 0x01; 
    TIM4_CR1 |= 0x01; 
}

void Buttons_Tick(void) {
    /* СТРОГИЙ C89: Все переменные объявляются в самом начале */
    unsigned char i;
    unsigned char pins_state;
    unsigned char is_pressed[2];

    pins_state = PA_IDR; /* Читаем весь порт A один раз */

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

btn_event_t Buttons_GetEvent(button_id_t btn_id) {
    /* СТРОГИЙ C89: Переменная в начале */
    btn_event_t current_event;
    
    _asm("sim"); 
    
    current_event = btns[btn_id].event; 
    btns[btn_id].event = EVENT_NONE;    
    
    _asm("rim"); 
    
    return current_event;
}