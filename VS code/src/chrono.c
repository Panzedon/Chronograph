#include "chrono.h"
#include "iostm8s103.h"

volatile uint8_t shot_ready = 0;
volatile uint16_t time_start = 0;
volatile uint16_t time_end = 0;
volatile uint16_t overflow_count = 0; /* Счетчик кругов таймера */

void Chrono_Init(void) {
    CLK_PCKENR1 |= 0x80;
    TIM1_PSCRH = 0;      
    TIM1_PSCRL = 0;      
    TIM1_ARRH = 0xFF;    
    TIM1_ARRL = 0xFF;    

    PC_CR2 &= ~((1<<3) | (1<<4));
    EXTI_CR1 &= ~(0x30);          

    PC_DDR &= ~((1<<3) | (1<<4)); 
    PC_CR1 |= ((1<<3) | (1<<4)); 
    
    TIM1_CCMR3 = 0x31; 
    TIM1_CCMR4 = 0x31; 
    TIM1_CCER2 = 0x33; 

    /* Включаем захват только для 1-го луча при старте */
    TIM1_IER = (1<<3); 
    TIM1_CR1 |= 0x01;  
}

uint8_t Chrono_IsReady(void) {
    return shot_ready;
}

/* Склеиваем круги и тики в одно большое 32-битное число */
uint32_t Chrono_GetTotalTicks(void) {
    uint32_t total;
    /* Формула: (Круги * 65536) + Конец - Старт */
    total = ((uint32_t)overflow_count * 65536UL) + time_end - time_start;
    return total;
}

void Chrono_Reset(void) {
    shot_ready = 0;
    
    /* Глушим оба луча и прерывание переполнения (UIE) */
    TIM1_IER &= (uint8_t)(~((1<<3) | (1<<4) | 0x01)); 
    TIM1_SR1 = (uint8_t)(~((1<<3) | (1<<4) | 0x01));  
    
    /* Взводим ТОЛЬКО ПЕРВЫЙ луч для нового выстрела */
    TIM1_IER |= (1<<3); 
}

/* --------------------------------------------------------
 * ПРЕРЫВАНИЕ ПЕРЕПОЛНЕНИЯ (Считает круги, пока летит шар)
 * -------------------------------------------------------- */
@far @interrupt void Chrono_OverflowInterrupt(void) {
    overflow_count++;
    TIM1_SR1 = (uint8_t)(~0x01); /* Быстро сбрасываем флаг UIF */
}

/* --------------------------------------------------------
 * ПРЕРЫВАНИЕ ЗАХВАТА ЛУЧЕЙ
 * -------------------------------------------------------- */
@far @interrupt void Chrono_HandleInterrupt(void) {
    uint8_t flags = TIM1_SR1;
    
    /* СРАБОТАЛ ПЕРВЫЙ ДАТЧИК (ВХОД) */
    if (flags & (1<<3)) {
        time_start = ((uint16_t)TIM1_CCR3H << 8) | TIM1_CCR3L; 
        
        /* Защелка: Глушим 1-й, чистим 2-й, Включаем 2-й */
        TIM1_IER &= (uint8_t)(~(1<<3)); 
        TIM1_SR1 = (uint8_t)(~(1<<4)); 
        TIM1_IER |= (1<<4); 
        
        /* Запускаем счетчик кругов! */
        overflow_count = 0; 
        TIM1_SR1 = (uint8_t)(~0x01); // Чистим мусорный флаг переполнения
        TIM1_IER |= 0x01;            // Включаем прерывание Update (UIE)

        TIM1_SR1 = (uint8_t)(~(1<<3)); // Чистим флаг 1-го луча
    }
    
    /* СРАБОТАЛ ВТОРОЙ ДАТЧИК (ВЫХОД) */
    else if (flags & (1<<4)) {
        time_end = ((uint16_t)TIM1_CCR4H << 8) | TIM1_CCR4L;
        shot_ready = 1; 
        
        /* Защелка: Глушим 2-й луч и останавливаем счетчик кругов (UIE) */
        TIM1_IER &= (uint8_t)(~((1<<4) | 0x01)); 
        
        TIM1_SR1 = (uint8_t)(~(1<<4)); // Чистим флаг 2-го луча
    }
}