#ifndef TM1637_H
#define TM1637_H

#include <stdint.h>

/**
 * @brief Ініціалізація пінів та протоколу для роботи з TM1637
 */
void TM1637_Init(void);

/**
 * @brief Встановлює яскравість світіння індикатора
 * @param br Рівень яскравості від 0 (мінімум) до 7 (максимум)
 */
void TM1637_SetBrightness(uint8_t br);

/**
 * @brief Очищує екран (гасить усі сегменти)
 */
void TM1637_Clear(void);

/**
 * @brief Базова Low-Level функція виводу масиву сегментів (SOLID)
 * @param segments Вказівник на масив байтів (кодів сегментів)
 * @param length Кількість розрядів для виводу
 * @param pos Позиція (зміщення) на екрані
 */
void TM1637_SetSegments(const uint8_t *segments, uint8_t length, uint8_t pos);

/**
 * @brief Вивід цілого числа на індикатор
 * @param num Число від 0 до 9999
 */
void TM1637_DisplayInt(uint16_t num);

/**
 * @brief Універсальна функція виводу числа з довільними крапками
 * @param num Число від 0 до 9999
 * @param dot_mask Бітова маска крапок (Біт 3 -> 1-а цифра, Біт 2 -> 2-а цифра і т.д.)
 */
void TM1637_DisplayIntWithDots(uint16_t num, uint8_t dot_mask);

/**
 * @brief Специфічний вивід у форматі X.X.X
 * @param d1 Перша цифра (з крапкою)
 * @param d2 Друга цифра
 * @param d3 Третя цифра
 */
void TM1637_DisplayXXX(uint8_t d1, uint8_t d2, uint8_t d3);

/**
 * @brief Вивід трьох нулів (формат 000) для режиму очікування
 */
void TM1637_Display000(void);

/**
 * @brief Вивід нулів з крапкою (формат 0.00) для режиму енергії
 */
void TM1637_Display0_00(void);

#endif