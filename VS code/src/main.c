#include <stdint.h>
#include <iostm8s103.h>

#define LED_PIN  ( 1 << 5 )  // PB5

static void delay(uint32_t t);
void clock_init(void);

void main(void) {
    clock_init();

    PB_CR2 &= ~LED_PIN;

    PB_ODR &= ~LED_PIN;   // начальный уровень LOW
    PB_DDR |= LED_PIN;    // выход
    PB_CR1 |= LED_PIN;    // push-pull
    PB_CR2 |= LED_PIN;    // fast mode

    for(;;) {
        PB_ODR |= LED_PIN;    
        delay(15000);         
        PB_ODR &= ~LED_PIN;   
        delay(15000);         
    }
}

static void delay(uint32_t t) {
    while(--t);
}
void clock_init(void){
    CLK_ICKCR = 0x01;
    while ((CLK_ICKCR & 0x02) == 0); 

    CLK_SWR = 0xE1;
    while (CLK_CMSR != 0xE1);
    CLK_CKDIVR = 0x00; 
}