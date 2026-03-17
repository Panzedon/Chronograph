#ifndef EEPROM_H
#define EEPROM_H
#include <stdint.h>

/**
 * @brief Адреса в пам'яті EEPROM для збереження режиму (Швидкість, Енергія, Скорострільність)
 */
#define EEPROM_ADDR_MODE  0x4000

/**
 * @brief Адреса в пам'яті EEPROM для збереження індексу ваги кульки
 */
#define EEPROM_ADDR_WEIGHT 0x4001

/**
 * @brief Читає один байт даних за вказаною адресою
 * @param addr Фізична адреса в просторі EEPROM STM8
 * @return Прочитаний байт
 */
uint8_t EEPROM_Read(uint16_t addr);

/**
 * @brief Записує один байт даних в EEPROM
 * @param addr Фізична адреса в просторі EEPROM STM8
 * @param data Байт даних для збереження
 * @note Функція автоматично розблоковує пам'ять (Data Unlock) і чекає завершення запису
 */
void EEPROM_Write(uint16_t addr, uint8_t data);

#endif