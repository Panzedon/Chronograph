#include "eeprom.h"
#include "iostm8s103.h"


uint8_t EEPROM_Read(uint16_t addr) {
    /* У STM8 дані EEPROM відображаються в адресний простір */
    return *((volatile uint8_t*)addr);
}


void EEPROM_Write(uint16_t addr, uint8_t data) {
    /* Якщо дані ті самі, не зношуємо пам'ять */
    if (EEPROM_Read(addr) == data) return;

    /* 1. Розблокування Data EEPROM */
    if (!(FLASH_IAPSR & 0x08)) { /* Якщо DUL (Data Unlock) == 0 */
        FLASH_DUKR = 0xAE; /* Ключ 1 */
        FLASH_DUKR = 0x56; /* Ключ 2 */
        while (!(FLASH_IAPSR & 0x08)); /* Чекаємо розблокування */
    }

    /* 2. Запис */
    *((volatile uint8_t*)addr) = data;

    /* 3. Чекаємо закінчення запису (EOP bit) */
    while (!(FLASH_IAPSR & 0x04));
    
    /* 4. Блокуємо назад (за бажанням, але можна залишити відкритим) */
    FLASH_IAPSR &= ~0x08; 
}