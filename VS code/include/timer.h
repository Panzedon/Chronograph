#ifndef _TIMER_H_
#define _TIMER_H_

#include "iostm8s103.h"
#include <stdint.h>

/**
 * @brief Задавання частоти роботи МК.
 */
void CPU_Speed_Init(void);

/**
 * @brief Дозволяємо переривання
 */
void Enable_Interrupt(void);

/**
 * @brief Перевірка переповнення таймера TIM4
 */
uint8_t Timer_IsTickElapsed(void);

#endif