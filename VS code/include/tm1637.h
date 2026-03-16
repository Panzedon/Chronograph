#ifndef TM1637_H
#define TM1637_H

#include <stdint.h>

/* Ініціалізація та базові налаштування */
void TM1637_Init(void);
void TM1637_SetBrightness(uint8_t br);
void TM1637_Clear(void);

/* SOLID: Єдина базова функція для виводу масиву сегментів (Low-Level) */
void TM1637_SetSegments(const uint8_t *segments, uint8_t length, uint8_t pos);

/* Вивід звичайного цілого числа (0-9999) */
void TM1637_DisplayInt(uint16_t num);

/* Універсальна функція: вивід числа з довільними крапками.
 * dot_mask: Біт 3 -> крапка на 1-й цифрі, Біт 2 -> на 2-й, і т.д.
 * Наприклад: маска 0b0110 запалить крапки на 2-й і 3-й цифрах */
void TM1637_DisplayIntWithDots(uint16_t num, uint8_t dot_mask);

/* Специфічна функція для формату X.X.X (наприклад, 1.2.3) */
void TM1637_DisplayXXX(uint8_t d1, uint8_t d2, uint8_t d3);

void TM1637_Display000(void);
void TM1637_Display0_00(void);

#endif