#ifndef _APP_H_
#define _APP_H_

#include "iostm8s103.h"
#include "tm1637.h"
#include "buttons.h"
#include "eeprom.h" 
#include "chrono.h"
#include "timer.h" 

/* --- Переліки (Enums) --- */

/** * @brief Режими роботи пристрою 
 */
typedef enum { 
    MODE_SPEED = 0,  /**< Швидкість польоту (м/с) */
    MODE_ENERGY,     /**< Дульна енергія (Дж) */
    MODE_ROF,        /**< Скорострільність (постр/хв) */
    MODE_WEIGHT      /**< Вибір ваги кульки (г) */
} chrono_mode_t;

/* --- Структури --- */

/** * @brief Глобальний стан додатку 
 */
typedef struct {
    chrono_mode_t current_mode;  /**< Активний режим */
    chrono_mode_t prev_mode;     /**< Попередній режим для повернення з налаштувань */
    uint8_t is_system_on;        /**< Стан живлення системи (софтверний) */
    uint8_t weight_idx;          /**< Індекс обраної ваги */
    uint16_t v_speed;            /**< Результат останнього виміру швидкості */
    uint16_t v_energy;           /**< Результат розрахунку енергії */
    uint16_t v_rof;              /**< Результат розрахунку скорострільності */
    uint8_t show_mode_name;      /**< Прапорець: показувати назву режиму чи цифри */
    uint32_t mode_name_end_ms;   /**< Таймер завершення показу назви режиму */
    uint8_t update_screen;       /**< Прапорець необхідності оновити дисплей */
} app_state_t;

/* --- Глобальні змінні --- */

extern app_state_t app;          /**< Стан системи */
extern uint32_t global_ms;       /**< Системний час */

/* --- Прототипи функцій --- */

/** * @brief Ініціалізація всіх систем та завантаження налаштувань.
 * @note Налаштовує частоту 16 МГц та периферію.
 */
void Sys_Init(void);

/**
 * @brief Читання та валідація даних з EEPROM.
 * @note Якщо дані в пам'яті некоректні, скидає їх у 0.
 * @see EEPROM_Read, EEPROM_Write
 */
void Memory_Poll(void);

/** * @brief Головний вхідний цикл програми (суперцикл).
 */
void App_Run(void);

/** * @brief Безпечна затримка на базі nop-циклів.
 * @param ms Кількість мілісекунд.
 */
void Delay_ms_Safe(uint16_t ms);

#endif /* _APP_H_ */