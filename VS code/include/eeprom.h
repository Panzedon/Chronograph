#ifndef EEPROM_H
#define EEPROM_H
#include <stdint.h>

/* Адрес в EEPROM для хранения режима (0=m/s, 1=J, 2=FPS) */
#define EEPROM_ADDR_MODE  0x4000

/* Адрес в EEPROM для хранения индекса веса (0..4) */
#define EEPROM_ADDR_WEIGHT 0x4001

/* Чтение байта */
uint8_t EEPROM_Read(uint16_t addr);

/* Запись байта (с разблокировкой) */
void EEPROM_Write(uint16_t addr, uint8_t data);

#endif
