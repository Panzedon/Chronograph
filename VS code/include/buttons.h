#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#include "iostm8s103.h"

/* Идентификаторы наших кнопок */
typedef enum {
    BTN_1_LASER = 0,
    BTN_2_MENU  = 1
} button_id_t;

/* Возможные события от кнопок */
typedef enum {
    EVENT_NONE = 0,
    EVENT_SHORT_PRESS,
    EVENT_LONG_PRESS
} btn_event_t;

void Buttons_Init(void);
void Buttons_Tick(void);
btn_event_t Buttons_GetEvent(button_id_t btn_id);

#endif /* _BUTTONS_H_ */
