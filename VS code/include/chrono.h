#ifndef CHRONO_H
#define CHRONO_H

#include <stdint.h>

/* Ініціалізація таймера і датчиків */
void Chrono_Init(void);

/* Повертає 1, якщо вимірювання завершено */
uint8_t Chrono_IsReady(void);

/* Повертає розраховану швидкість (м/с) */
//uint16_t Chrono_GetVelocity(void);

/* Скидання стану для нового пострілу */
void Chrono_Reset(void);

/* Обробник переривання (викликати з stm8_interrupt_vector.c) */
void Chrono_HandleInterrupt(void);

//uint16_t Chrono_GetRawTicks(void);

uint32_t Chrono_GetTotalTicks(void); /* ТЕПЕРЬ 32 БИТА! */

#endif