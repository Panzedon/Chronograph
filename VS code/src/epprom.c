#include "eeprom.h"
#include "iostm8s103.h"

uint8_t EEPROM_Read(uint16_t addr) {
    /* В STM8 данные EEPROM мапятся в адресное пространство */
    return *((volatile uint8_t*)addr);
}

void EEPROM_Write(uint16_t addr, uint8_t data) {
    /* Если данные те же, не изнашиваем память */
    if (EEPROM_Read(addr) == data) return;

    /* 1. Разблокировка Data EEPROM */
    if (!(FLASH_IAPSR & 0x08)) { // Если DUL (Data Unlock) == 0
        FLASH_DUKR = 0xAE; // Ключ 1
        FLASH_DUKR = 0x56; // Ключ 2
        while (!(FLASH_IAPSR & 0x08)); // Ждем разблокировки
    }

    /* 2. Запись */
    *((volatile uint8_t*)addr) = data;

    /* 3. Ждем окончания записи (EOP bit) */
    while (!(FLASH_IAPSR & 0x04));
    
    /* 4. Блокируем обратно (по желанию, но можно оставить открытым) */
    FLASH_IAPSR &= ~0x08; 
}