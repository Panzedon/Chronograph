#include "tm1637.h"
#include "iostm8s103.h"

#define CLK_PIN (1 << 4) /* PB4 */
#define DIO_PIN (1 << 5) /* PB5 */

/* Коди символів: 0-9 */
const uint8_t SEG[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

static uint8_t _brightness = 7;

/**
 * @brief Мікрозатримка для програмного I2C (bit-banging).
 * @details Формує таймінг, необхідний для стабільної роботи шини 
 * між мікроконтролером та мікросхемою TM1637.
 */
static void _delay(void) { 
    uint8_t i;
    for(i=0; i<200; i++) { 
        _asm("nop"); 
    }
}

/**
 * @brief Генерація сигналу START для протоколу TM1637.
 * @details Сигнал DIO переходить з високого в низький рівень 
 * при високому рівні на лінії CLK.
 */
static void _start(void) {
    PB_ODR |= DIO_PIN; PB_ODR |= CLK_PIN; _delay();
    PB_ODR &= ~DIO_PIN; _delay();
    PB_ODR &= ~CLK_PIN; _delay();
}

/**
 * @brief Генерація сигналу STOP для протоколу TM1637.
 * @details Сигнал DIO переходить з низького в високий рівень 
 * при високому рівні на лінії CLK.
 */
static void _stop(void) {
    PB_ODR &= ~CLK_PIN; _delay();
    PB_ODR &= ~DIO_PIN; _delay();
    PB_ODR |= CLK_PIN;  _delay();
    PB_ODR |= DIO_PIN;  _delay();
}

/**
 * @brief Відправка одного байта даних на контролер дисплея.
 * @details Відправляє 8 біт даних (починаючи з молодшого), керуючи лініями 
 * CLK та DIO. На дев'ятому такті генерує імпульс для зчитування біта 
 * підтвердження (ACK) від TM1637, хоча сам ACK апаратно ігнорується кодом.
 * @param data Байт даних для відправки.
 */
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

/**
 * @brief Ініціалізація портів для керування TM1637.
 * @details Налаштовує піни PB4 (CLK) та PB5 (DIO) на вихід (Push-Pull).
 * Встановлює високий рівень на обох лініях за замовчуванням.
 */
void TM1637_Init(void) {
    PB_DDR |= (CLK_PIN | DIO_PIN);
    PB_CR1 |= (CLK_PIN | DIO_PIN);
    PB_ODR |= (CLK_PIN | DIO_PIN);
}

/**
 * @brief Встановлює яскравість дисплея у пам'яті контролера (локально).
 * @details Яскравість застосується лише під час наступного виклику `TM1637_SetSegments`.
 * @param br Рівень яскравості від 0 (мінімум) до 7 (максимум).
 */
void TM1637_SetBrightness(uint8_t br) {
    _brightness = (br > 7) ? 7 : br;
}

/* ====================================================================
 * CORE FUNCTION 
 * ==================================================================== */

/**
 * @brief Базова функція для виведення довільних сегментів на екран.
 * @details Виконує повну транзакцію по I2C-подібній шині:
 * 1. Команда "Авто-інкремент адреси" (0x40).
 * 2. Команда "Адреса стартового розряду" (0xC0 + pos).
 * 3. Передача масиву байтів (сегментів).
 * 4. Команда "Увімкнути дисплей + яскравість" (0x88 + brightness).
 * @param segments Вказівник на масив байтів (кожен біт відповідає за 1 сегмент).
 * @param length Кількість символів для виведення.
 * @param pos Зміщення (від 0) з якого почати виведення.
 */
void TM1637_SetSegments(const uint8_t *segments, uint8_t length, uint8_t pos) {
    uint8_t i;
    
    _start(); 
    _write_byte(0x40); /* Команда: автоінкремент адреси */
    _stop();
    
    _start(); 
    _write_byte(0xC0 + pos); /* Команда: встановлення стартової адреси */
    for (i = 0; i < length; i++) {
        _write_byte(segments[i]);
    }
    _stop();
    
    _start(); 
    _write_byte(0x88 + _brightness); /* Команда: увімкнути дисплей + яскравість */
    _stop();
}

/**
 * @brief Очищення всіх сегментів на екрані.
 * @details Виводить 4 нульових байти на дисплей, щоб погасити усі світлодіоди.
 */
void TM1637_Clear(void) {
    static const uint8_t empty[4] = {0, 0, 0, 0};
    TM1637_SetSegments(empty, 4, 0);
}

/* ====================================================================
 * ФУНКЦІЇ АДАПТОВАНІ ПІД 3-РОЗРЯДНИЙ ІНДИКАТОР
 * ==================================================================== */

/**
 * @brief Конвертує число у масив сегментів та виводить з кастомними крапками.
 * @details Розбиває число на 3 розряди. Динамічно гасить незначащі нулі (зліва),
 * якщо в їх позиції не вимагається відображення десяткової крапки. 
 * Четвертий розряд апаратно гаситься (0x00), оскільки використовується 3-цифровий екран.
 * @param num Число від 0 до 999.
 * @param dot_mask Бітова маска (0x04 - перша цифра, 0x02 - друга, 0x01 - третя).
 */
void TM1637_DisplayIntWithDots(uint16_t num, uint8_t dot_mask) {
    uint8_t d[3];
    uint8_t segs[4];

    if (num > 999) num = 999;
    
    /* Б'ємо на 3 цифри */
    d[2] = num % 10;          /* Одиниці */
    d[1] = (num / 10) % 10;   /* Десятки */
    d[0] = (num / 100) % 10;  /* Сотні */

    /* Гасимо незначащі нулі, АЛЕ залишаємо їх, якщо там є крапка (для 0.XX) */
    segs[0] = (num < 100 && !(dot_mask & 0x04)) ? 0x00 : SEG[d[0]];
    segs[1] = (num < 10  && !(dot_mask & 0x02)) ? 0x00 : SEG[d[1]];
    segs[2] = SEG[d[2]]; /* Одиниці горять завжди */
    segs[3] = 0x00;      /* 4-го розряду немає */

    /* Ставимо крапки: 0x04 -> segs[0], 0x02 -> segs[1], 0x01 -> segs[2] */
    if (dot_mask & 0x04) segs[0] |= 0x80;
    if (dot_mask & 0x02) segs[1] |= 0x80;
    if (dot_mask & 0x01) segs[2] |= 0x80;
    
    TM1637_SetSegments(segs, 4, 0);
}

/**
 * @brief Обгортка для виведення цілого числа (до 999) без крапок.
 * @param num Число для виведення.
 */
void TM1637_DisplayInt(uint16_t num) {
    TM1637_DisplayIntWithDots(num, 0x00);
}

/**
 * @brief Виводить на екран три нулі (000) для режиму очікування пострілу.
 */
void TM1637_Display000(void) {
    static const uint8_t s[4] = {0x3F, 0x3F, 0x3F, 0x00};
    TM1637_SetSegments(s, 4, 0);
}

/**
 * @brief Виводить на екран формат 0.00 для режиму енергії до пострілу.
 */
void TM1637_Display0_00(void) {
    static const uint8_t s[4] = {0x3F | 0x80, 0x3F, 0x3F, 0x00};
    TM1637_SetSegments(s, 4, 0);
}

/**
 * @brief Пряме виведення трьох цифр у форматі X.XX (з фіксованою крапкою).
 * @details Використовується переважно для відображення ваги кульки (наприклад, 0.25).
 * @param d1 Перша цифра (до неї додається крапка).
 * @param d2 Друга цифра.
 * @param d3 Третя цифра.
 */
void TM1637_DisplayXXX(uint8_t d1, uint8_t d2, uint8_t d3) {
    uint8_t segs[4];
    segs[0] = SEG[d1 % 10] | 0x80; /* Перша цифра + крапка */
    segs[1] = SEG[d2 % 10];        /* Друга цифра */
    segs[2] = SEG[d3 % 10];        /* Третя цифра */
    segs[3] = 0x00;                /* Четвертий розряд відсутній */
    TM1637_SetSegments(segs, 4, 0);
}