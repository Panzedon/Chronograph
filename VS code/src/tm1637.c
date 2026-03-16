#include "tm1637.h"
#include "iostm8s103.h"

#define CLK_PIN (1 << 4) // PB4
#define DIO_PIN (1 << 5) // PB5

/* Коди символів: 0-9 */
const uint8_t SEG[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

static uint8_t _brightness = 7;

static void _delay(void) { 
    uint8_t i;
    for(i=0; i<200; i++) { 
        _asm("nop"); 
    }
}

static void _start(void) {
    PB_ODR |= DIO_PIN; PB_ODR |= CLK_PIN; _delay();
    PB_ODR &= ~DIO_PIN; _delay();
    PB_ODR &= ~CLK_PIN; _delay();
}

static void _stop(void) {
    PB_ODR &= ~CLK_PIN; _delay();
    PB_ODR &= ~DIO_PIN; _delay();
    PB_ODR |= CLK_PIN;  _delay();
    PB_ODR |= DIO_PIN;  _delay();
}

static void _write_byte(uint8_t data) {
    uint8_t i;
    for (i = 0; i < 8; i++) {
        PB_ODR &= ~CLK_PIN;
        if (data & 0x01) PB_ODR |= DIO_PIN;
        else             PB_ODR &= ~DIO_PIN;
        _delay();
        PB_ODR |= CLK_PIN; _delay();
        data >>= 1;
    }
    PB_ODR &= ~CLK_PIN; PB_ODR |= DIO_PIN; PB_DDR &= ~DIO_PIN; _delay();
    PB_ODR |= CLK_PIN; _delay(); PB_ODR &= ~CLK_PIN;
    PB_DDR |= DIO_PIN;
}

void TM1637_Init(void) {
    PB_DDR |= (CLK_PIN | DIO_PIN);
    PB_CR1 |= (CLK_PIN | DIO_PIN);
    PB_ODR |= (CLK_PIN | DIO_PIN);
}

void TM1637_SetBrightness(uint8_t br) {
    _brightness = (br > 7) ? 7 : br;
}

/* ====================================================================
 * CORE FUNCTION (SOLID)
 * ==================================================================== */
void TM1637_SetSegments(const uint8_t *segments, uint8_t length, uint8_t pos) {
    uint8_t i;
    
    _start(); 
    _write_byte(0x40); // Command: auto-increment address
    _stop();
    
    _start(); 
    _write_byte(0xC0 + pos); // Command: set start address
    for (i = 0; i < length; i++) {
        _write_byte(segments[i]);
    }
    _stop();
    
    _start(); 
    _write_byte(0x88 + _brightness); // Command: display ON + brightness
    _stop();
}

void TM1637_Clear(void) {
    uint8_t empty[4] = {0, 0, 0, 0};
    TM1637_SetSegments(empty, 4, 0);
}

/* ====================================================================
 * ФУНКЦІЇ АДАПТОВАНІ ПІД 3-РОЗРЯДНИЙ ІНДИКАТОР
 * ==================================================================== */

/* Вивід числа (до 999) з маскою крапок */
void TM1637_DisplayIntWithDots(uint16_t num, uint8_t dot_mask) {
    uint8_t d[3];
    uint8_t segs[4];

    if (num > 999) num = 999;
    
    /* Б'ємо на 3 цифри */
    d[2] = num % 10;          // Одиниці
    d[1] = (num / 10) % 10;   // Десятки
    d[0] = (num / 100) % 10;  // Сотні

    /* Гасимо незначащі нулі, АЛЕ залишаємо їх, якщо там є крапка (для 0.XX) */
    segs[0] = (num < 100 && !(dot_mask & 0x04)) ? 0x00 : SEG[d[0]];
    segs[1] = (num < 10  && !(dot_mask & 0x02)) ? 0x00 : SEG[d[1]];
    segs[2] = SEG[d[2]]; // Одиниці горять завжди
    segs[3] = 0x00;      // 4-го розряду немає

    /* Ставимо крапки: 0x04 -> segs[0], 0x02 -> segs[1], 0x01 -> segs[2] */
    if (dot_mask & 0x04) segs[0] |= 0x80;
    if (dot_mask & 0x02) segs[1] |= 0x80;
    if (dot_mask & 0x01) segs[2] |= 0x80;
    
    TM1637_SetSegments(segs, 4, 0);
}

/* Обгортка для звичайного числа без крапок */
void TM1637_DisplayInt(uint16_t num) {
    TM1637_DisplayIntWithDots(num, 0x00);
}

/* Явні нулі для режиму очікування пострілу */
void TM1637_Display000(void) {
    uint8_t s[4] = {0x3F, 0x3F, 0x3F, 0x00};
    TM1637_SetSegments(s, 4, 0);
}

void TM1637_Display0_00(void) {
    uint8_t s[4] = {0x3F | 0x80, 0x3F, 0x3F, 0x00};
    TM1637_SetSegments(s, 4, 0);
}

/* Прямий вивід у форматі X.XX (Тільки одна крапка для ваги кульки 0.25) */
void TM1637_DisplayXXX(uint8_t d1, uint8_t d2, uint8_t d3) {
    uint8_t segs[4];
    segs[0] = SEG[d1 % 10] | 0x80; // Перша цифра + крапка
    segs[1] = SEG[d2 % 10];        // Друга цифра
    segs[2] = SEG[d3 % 10];        // Третя цифра
    segs[3] = 0x00;                // Четвертий розряд відсутній
    TM1637_SetSegments(segs, 4, 0);
}