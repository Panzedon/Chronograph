#ifndef __IOSTM8S103_H__
#define __IOSTM8S103_H__

/* * IO DEFINITIONS FOR STM8 S103 (MOCK for Cppcheck)
 * Cleaned version without @ addresses
 */
#ifdef __INTELLISENSE__
    #define INTERRUPT_
    #define FAR_
    #define NEAR_
    #define TINY_
    #define ASM_(x)
#endif

/* Это видит ТОЛЬКО компилятор Cosmic. 
   VS Code проигнорирует этот блок, потому что он всегда 
   считает __INTELLISENSE__ истиной. */
#ifndef __INTELLISENSE__
    #define INTERRUPT_ @interrupt
    #define FAR_       @far
    #define NEAR_      @near
    #define TINY_      @tiny
    #define ASM_(x)    _asm(x)
#endif
/* PORTS section */
/* Port A */
extern volatile unsigned char PA_ODR;    /* Data Output Latch reg */
extern volatile unsigned char PA_IDR;    /* Input Pin Value reg */
extern volatile unsigned char PA_DDR;    /* Data Direction */
extern volatile unsigned char PA_CR1;    /* Control register 1 */
extern volatile unsigned char PA_CR2;    /* Control register 2 */

/* Port B */
extern volatile unsigned char PB_ODR;    /* Data Output Latch reg */
extern volatile unsigned char PB_IDR;    /* Input Pin Value reg */
extern volatile unsigned char PB_DDR;    /* Data Direction */
extern volatile unsigned char PB_CR1;    /* Control register 1 */
extern volatile unsigned char PB_CR2;    /* Control register 2 */

/* Port C */
extern volatile unsigned char PC_ODR;    /* Data Output Latch reg */
extern volatile unsigned char PC_IDR;    /* Input Pin Value reg */
extern volatile unsigned char PC_DDR;    /* Data Direction */
extern volatile unsigned char PC_CR1;    /* Control register 1 */
extern volatile unsigned char PC_CR2;    /* Control register 2 */

/* Port D */
extern volatile unsigned char PD_ODR;    /* Data Output Latch reg */
extern volatile unsigned char PD_IDR;    /* Input Pin Value reg */
extern volatile unsigned char PD_DDR;    /* Data Direction */
extern volatile unsigned char PD_CR1;    /* Control register 1 */
extern volatile unsigned char PD_CR2;    /* Control register 2 */

/* Port E */
extern volatile unsigned char PE_ODR;    /* Data Output Latch reg */
extern volatile unsigned char PE_IDR;    /* Input Pin Value reg */
extern volatile unsigned char PE_DDR;    /* Data Direction */
extern volatile unsigned char PE_CR1;    /* Control register 1 */
extern volatile unsigned char PE_CR2;    /* Control register 2 */

/* Port F */
extern volatile unsigned char PF_ODR;    /* Data Output Latch reg */
extern volatile unsigned char PF_IDR;    /* Input Pin Value reg */
extern volatile unsigned char PF_DDR;    /* Data Direction */
extern volatile unsigned char PF_CR1;    /* Control register 1 */
extern volatile unsigned char PF_CR2;    /* Control register 2 */

/* FLASH section */
extern volatile unsigned char FLASH_CR1;     /* Flash Control Register 1 */
extern volatile unsigned char FLASH_CR2;     /* Flash Control Register 2 */
extern volatile unsigned char FLASH_NCR2;    /* Flash Complementary Control Reg 2 */
extern volatile unsigned char FLASH_FPR;     /* Flash Protection reg */
extern volatile unsigned char FLASH_NFPR;    /* Flash Complementary Protection reg */
extern volatile unsigned char FLASH_IAPSR;   /* Flash in-appl Prog. Status reg */
extern volatile unsigned char FLASH_PUKR;    /* Flash Program memory unprotection reg */
extern volatile unsigned char FLASH_DUKR;    /* Data EEPROM unprotection reg */

/* External Interrupt Controller section */
extern volatile unsigned char EXTI_CR1;      /* Ext Int Ctrl reg 1 */
extern volatile unsigned char EXTI_CR2;      /* Ext Int Ctrl reg 2 */

/* RSTC section */
extern volatile unsigned char RST_SR;        /* Reset Status register */

/* CLOCK section */
extern volatile unsigned char CLK_ICKCR;     /* Internal Clock Control reg */
extern volatile unsigned char CLK_ECKCR;     /* External Clock Control reg */
extern volatile unsigned char CLK_CMSR;      /* Master Status reg */
extern volatile unsigned char CLK_SWR;       /* Master Switch reg */
extern volatile unsigned char CLK_SWCR;      /* Switch Control reg */
extern volatile unsigned char CLK_CKDIVR;    /* Divider register */
extern volatile unsigned char CLK_PCKENR1;   /* Peripheral Clock Gating reg 1 */
extern volatile unsigned char CLK_CSSR;      /* Security System register */
extern volatile unsigned char CLK_CCOR;      /* Configurable Clock Ctrl reg */
extern volatile unsigned char CLK_PCKENR2;   /* Peripheral Clock Gating reg 2 */
extern volatile unsigned char CLK_CANCCR;    /* Can Clock Control reg */
extern volatile unsigned char CLK_HSITRIMR;  /* HSI Calibration Trimming reg */
extern volatile unsigned char CLK_SWIMCCR;   /* SWIM Clock Control reg */

/* WATCHDOG section */
extern volatile unsigned char WWDG_CR;       /* WWDG Control register */
extern volatile unsigned char WWDG_WR;       /* WWDG Window register */
extern volatile unsigned char IWDG_KR;       /* IWDG Key register */
extern volatile unsigned char IWDG_PR;       /* IWDG Prescaler register */
extern volatile unsigned char IWDG_RLR;      /* IWDG Reload register */

/* AWU section */
extern volatile unsigned char AWU_CSR1;      /* AWU Control/Status reg 1 */
extern volatile unsigned char AWU_APR;       /* AWU Async Prescale Buffer reg */
extern volatile unsigned char AWU_TBR;       /* AWU Timebase selection reg */
extern volatile unsigned char BEEP_CSR;      /* BEEP control/status reg */

/* SPI section */
extern volatile unsigned char SPI_CR1;       /* SPI Control register 1 */
extern volatile unsigned char SPI_CR2;       /* SPI Control register 2 */
extern volatile unsigned char SPI_ICR;       /* SPI Interrupt/Ctrl reg */
extern volatile unsigned char SPI_SR;        /* SPI Status register */
extern volatile unsigned char SPI_DR;        /* SPI Data I/O reg */
extern volatile unsigned char SPI_CRCPR;     /* SPI CRC Polynomial reg */
extern volatile unsigned char SPI_RXCRCR;    /* SPI Rx CRC register */
extern volatile unsigned char SPI_TXCRCR;    /* SPI Tx CRC register */

/* I2C section */
extern volatile unsigned char I2C_CR1;       /* Control register 1 */
extern volatile unsigned char I2C_CR2;       /* Control register 2 */
extern volatile unsigned char I2C_FREQR;     /* Frequency register */
extern volatile unsigned char I2C_OARL;      /* Own Address reg low */
extern volatile unsigned char I2C_OARH;      /* Own Address reg high */
extern volatile unsigned char I2C_DR;        /* Data Register */
extern volatile unsigned char I2C_SR1;       /* Status Register 1 */
extern volatile unsigned char I2C_SR2;       /* Status Register 2 */
extern volatile unsigned char I2C_SR3;       /* Status Register 3 */
extern volatile unsigned char I2C_ITR;       /* Interrupt Control reg */
extern volatile unsigned char I2C_CCRL;      /* Clock Control reg low */
extern volatile unsigned char I2C_CCRH;      /* Clock Control reg high */
extern volatile unsigned char I2C_TRISER;    /* Trise reg */
extern volatile unsigned char I2C_PECR;      /* Packet Error Checking reg */

/* UART1 section */
extern volatile unsigned char UART1_SR;      /* Status register */
extern volatile unsigned char UART1_DR;      /* Data register */
extern volatile unsigned char UART1_BRR1;    /* Baud Rate reg 1 */
extern volatile unsigned char UART1_BRR2;    /* Baud Rate reg 2 */
extern volatile unsigned char UART1_CR1;     /* Control register 1 */
extern volatile unsigned char UART1_CR2;     /* Control register 2 */
extern volatile unsigned char UART1_CR3;     /* Control register 3 */
extern volatile unsigned char UART1_CR4;     /* Control register 4 */
extern volatile unsigned char UART1_CR5;     /* Control register 5 */
extern volatile unsigned char UART1_GTR;     /* Guard Time register */
extern volatile unsigned char UART1_PSCR;    /* Prescaler register */

/* TIMER 1 section */
extern volatile unsigned char TIM1_CR1;      /* Control register 1 */
extern volatile unsigned char TIM1_CR2;      /* Control register 2 */
extern volatile unsigned char TIM1_SMCR;     /* Slave Mode Control reg */
extern volatile unsigned char TIM1_ETR;      /* External Trigger reg */
extern volatile unsigned char TIM1_IER;      /* Interrupt Enable reg */
extern volatile unsigned char TIM1_SR1;      /* Status register 1 */
extern volatile unsigned char TIM1_SR2;      /* Status register 2 */
extern volatile unsigned char TIM1_EGR;      /* Event Generation reg */
extern volatile unsigned char TIM1_CCMR1;    /* Capture/Compare Mode reg 1 */
extern volatile unsigned char TIM1_CCMR2;    /* Capture/Compare Mode reg 2 */
extern volatile unsigned char TIM1_CCMR3;    /* Capture/Compare Mode reg 3 */
extern volatile unsigned char TIM1_CCMR4;    /* Capture/Compare Mode reg 4 */
extern volatile unsigned char TIM1_CCER1;    /* Capture/Compare Enable reg 1 */
extern volatile unsigned char TIM1_CCER2;    /* Capture/Compare Enable reg 2 */
extern volatile unsigned char TIM1_CNTRH;    /* Counter reg High */
extern volatile unsigned char TIM1_CNTRL;    /* Counter reg Low */
extern volatile unsigned char TIM1_PSCRH;    /* Prescaler reg High */
extern volatile unsigned char TIM1_PSCRL;    /* Prescaler reg Low */
extern volatile unsigned char TIM1_ARRH;     /* Auto-reload reg High */
extern volatile unsigned char TIM1_ARRL;     /* Auto-reload reg Low */
extern volatile unsigned char TIM1_RCR;      /* Repetition Counter reg */
extern volatile unsigned char TIM1_CCR1H;    /* Capture/Compare reg 1 High */
extern volatile unsigned char TIM1_CCR1L;    /* Capture/Compare reg 1 Low */
extern volatile unsigned char TIM1_CCR2H;    /* Capture/Compare reg 2 High */
extern volatile unsigned char TIM1_CCR2L;    /* Capture/Compare reg 2 Low */
extern volatile unsigned char TIM1_CCR3H;    /* Capture/Compare reg 3 High */
extern volatile unsigned char TIM1_CCR3L;    /* Capture/Compare reg 3 Low */
extern volatile unsigned char TIM1_CCR4H;    /* Capture/Compare reg 4 High */
extern volatile unsigned char TIM1_CCR4L;    /* Capture/Compare reg 4 Low */
extern volatile unsigned char TIM1_BKR;      /* Break register */
extern volatile unsigned char TIM1_DTR;      /* Dead Time register */
extern volatile unsigned char TIM1_OISR;     /* Output Idle State reg */

/* TIMER 2 section */
extern volatile unsigned char TIM2_CR1;      /* Control register 1 */
extern volatile unsigned char TIM2_IER;      /* Interrupt Enable reg */
extern volatile unsigned char TIM2_SR1;      /* Status Register 1 */
extern volatile unsigned char TIM2_SR2;      /* Status Register 2 */
extern volatile unsigned char TIM2_EGR;      /* Event Generation reg */
extern volatile unsigned char TIM2_CCMR1;    /* Capture/Compare Mode reg 1 */
extern volatile unsigned char TIM2_CCMR2;    /* Capture/Compare Mode reg 2 */
extern volatile unsigned char TIM2_CCMR3;    /* Capture/Compare Mode reg 3 */
extern volatile unsigned char TIM2_CCER1;    /* Capture/Compare Enable reg 1 */
extern volatile unsigned char TIM2_CCER2;    /* Capture/Compare Enable reg 2 */
extern volatile unsigned char TIM2_CNTRH;    /* Counter reg High */
extern volatile unsigned char TIM2_CNTRL;    /* Counter reg Low */
extern volatile unsigned char TIM2_PSCR;     /* Prescaler register */
extern volatile unsigned char TIM2_ARRH;     /* Auto-reload reg High */
extern volatile unsigned char TIM2_ARRL;     /* Auto-reload reg Low */
extern volatile unsigned char TIM2_CCR1H;    /* Capture/Compare Reg 1 High */
extern volatile unsigned char TIM2_CCR1L;    /* Capture/Compare Reg 1 Low */
extern volatile unsigned char TIM2_CCR2H;    /* Capture/Compare Reg 2 High */
extern volatile unsigned char TIM2_CCR2L;    /* Capture/Compare Reg 2 Low */
extern volatile unsigned char TIM2_CCR3H;    /* Capture/Compare Reg 3 High */
extern volatile unsigned char TIM2_CCR3L;    /* Capture/Compare Reg 3 Low */

/* TIMER 4 section */
extern volatile unsigned char TIM4_CR1;      /* Control register 1 */
extern volatile unsigned char TIM4_IER;      /* Interrupt enable reg */
extern volatile unsigned char TIM4_SR;       /* Status register */
extern volatile unsigned char TIM4_EGR;      /* Event Generation reg */
extern volatile unsigned char TIM4_CNTR;     /* Counter register */
extern volatile unsigned char TIM4_PSCR;     /* Prescaler register */
extern volatile unsigned char TIM4_ARR;      /* Auto-reload register */

/* ADC section */
extern volatile unsigned char ADC_DBR[19];   /* data buffer registers */
extern volatile unsigned char ADC_CSR;       /* Control/Status reg */
extern volatile unsigned char ADC_CR1;       /* Configuration reg 1 */
extern volatile unsigned char ADC_CR2;       /* Configuration reg 2 */
extern volatile unsigned char ADC_CR3;       /* Configuration reg 3 */
extern volatile unsigned char ADC_DRH;       /* Data reg high */
extern volatile unsigned char ADC_DRL;       /* Data reg low */
extern volatile unsigned char ADC_TDRH;      /* Schmitt Trigger Disable reg high */
extern volatile unsigned char ADC_TDRL;      /* Schmitt Trigger Disable reg low */
extern volatile unsigned char ADC_HTRH;      /* high threshold reg high */
extern volatile unsigned char ADC_HTRL;      /* high threshold reg low */
extern volatile unsigned char ADC_LTRH;      /* low threshold reg high */
extern volatile unsigned char ADC_LTRL;      /* low threshold reg low */
extern volatile unsigned char ADC_AWSRH;     /* analog watchdog status reg high */
extern volatile unsigned char ADC_AWSRL;     /* analog watchdog status reg low */
extern volatile unsigned char ADC_AWCRH;     /* analog watchdog control reg high */
extern volatile unsigned char ADC_AWCRL;     /* analog watchdog control reg low */

/* CFG section */
extern volatile unsigned char CFG_GCR;       /* Global Configuration register */

/* ITC section */
extern volatile unsigned char ITC_SPR1;      /* Interrupt Software Priority Reg 1 */
extern volatile unsigned char ITC_SPR2;      /* Interrupt Software Priority Reg 2 */
extern volatile unsigned char ITC_SPR3;      /* Interrupt Software Priority Reg 3 */
extern volatile unsigned char ITC_SPR4;      /* Interrupt Software Priority Reg 4 */
extern volatile unsigned char ITC_SPR5;      /* Interrupt Software Priority Reg 5 */
extern volatile unsigned char ITC_SPR6;      /* Interrupt Software Priority Reg 6 */
extern volatile unsigned char ITC_SPR7;      /* Interrupt Software Priority Reg 7 */
extern volatile unsigned char ITC_SPR8;      /* Interrupt Software Priority Reg 8 */

/* SWIM section */
extern volatile unsigned char SWIM_CSR;      /* SWIM Control Status Register */

/* In-Circuit Debugging section */
extern volatile unsigned char DM_BK1RE;      /* IC Debugging Breakpoint 1 ESB Reg */
extern volatile unsigned char DM_BK1RH;      /* IC Debugging Breakpoint 1 High */
extern volatile unsigned char DM_BK1RL;      /* IC Debugging Breakpoint 1 Low */
extern volatile unsigned char DM_BK2RE;      /* IC Debugging Breakpoint 2 ESB Reg */
extern volatile unsigned char DM_BK2RH;      /* IC Debugging Breakpoint 2 High */
extern volatile unsigned char DM_BK2RL;      /* IC Debugging Breakpoint 2 Low */
extern volatile unsigned char DM_CR1;        /* IC Debugging Control register 1 */
extern volatile unsigned char DM_CR2;        /* IC Debugging Control register 2 */
extern volatile unsigned char DM_CSR1;       /* IC Debugging Control/Status reg 1 */
extern volatile unsigned char DM_CSR2;       /* IC Debugging Control/Status reg 2 */
extern volatile unsigned char DM_ENFCTR;     /* IC Debugging Function Enable Reg 2 */

#endif