#include "timer.h"

void CPU_Speed_Init(void){
    CLK_CKDIVR = 0x00;
}


void Enable_Interrupt(void){
    ASM_("rim");
}


uint8_t Timer_IsTickElapsed(void) {
    if (TIM4_SR & 0x01) {
        //TIM4_SR &= ~0x01; // Скидаємо прапор
        TIM4_SR = 0x00; 
        return 1;
    }
    return 0;
}

