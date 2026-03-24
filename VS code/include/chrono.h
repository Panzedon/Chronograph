#ifndef CHRONO_H
#define CHRONO_H

#include <stdint.h>

void CPU_Speed_Init(void);
void Enable_Interrupt(void);

/**
 * @brief Ініціалізація таймера TIM1 та оптичних датчиків
 * @note Використовує піни PC3 та PC4 для захоплення сигналу
 */
void Chrono_Init(void);

/**
 * @brief Перевіряє, чи успішно зафіксовано проліт кульки через обидва датчики
 * @retval 1 вимірювання завершено успішно
 * @retval 0 система в очікуванні або політ ще триває
 */
uint8_t Chrono_IsReady(void);

/**
 * @brief Скидає стан хронографа для фіксації наступного пострілу
 * @note Скидає прапорці та активує лише перший датчик
 * @see Chrono_IsReady
 */
void Chrono_Reset(void);

/**
 * @brief Обробник переривання захоплення луча (TIM1 CAPCOM)
 * @note Викликати з файлу stm8_interrupt_vector.c (irq12)
 */
void Chrono_HandleInterrupt(void);

/**
 * @brief Повертає сумарну кількість тіків таймера за час прольоту кульки
 * @return 32-бітне значення часу в тіках (враховуючи переповнення таймера)
 * @note Формула: (Круги * 65536) + Конец - Старт
 */
uint32_t Chrono_GetTotalTicks(void);

#endif