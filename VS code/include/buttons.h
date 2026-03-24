#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#include "iostm8s103.h"

/**
 * @brief Ідентифікатори апаратних кнопок системи
 */
typedef enum {
    BTN_1_LASER = 0,
    BTN_2_MENU  = 1
} button_id_t;

/**
 * @brief Можливі стани та події, згенеровані кнопками
 */
typedef enum {
    EVENT_NONE = 0,
    EVENT_SHORT_PRESS,
    EVENT_LONG_PRESS
} btn_event_t;

/**
 * @brief Ініціалізує GPIO піни кнопок та таймер антибрязкоту (TIM4)
 */
void Buttons_Init(void);

/**
 * @brief Обробник станів кнопок 
 * @note Повинен викликатися кожну 1 мілісекунду в головному циклі 
 */
void Buttons_Tick(void);

/**
 * @brief Отримує подію натискання для конкретної кнопки
 * @param btn_id Ідентифікатор кнопки (наприклад, BTN_1_LASER)
 * @return Подія (EVENT_NONE, EVENT_SHORT_PRESS або EVENT_LONG_PRESS)
 * @note Після зчитування подія автоматично скидається в EVENT_NONE
 */
btn_event_t Buttons_GetEvent(button_id_t btn_id);

#endif /* _BUTTONS_H_ */