/*	INTERRUPT VECTOR TABLE FOR STM32F407
 *	Copyright (c) 2015 by COSMIC Software
 */
extern void _stext(void);	/* startup code */
extern int _stack;		/* stack address */
extern void tim2ovf(void);

/*	dummy interrupt function
 */
@interrupt void _dummit(void)
	{
	}

#pragma section const {vector}

/*	vector table
 */
void (* const _vectab[98])(void) = {
/* 0 */		(void *)&_stack,	/* Initial Stack Pointer */
/* 1 */		_stext,			/* Initial Program Counter */
/* 2 */		_dummit,		/* Non-maskable Interrupt (NMI) */
/* 3 */		_dummit,		/* Hard Fault */
/* 4 */		_dummit,		/* MemManage Fault */
/* 5 */		_dummit,		/* Bus Fault */
/* 6 */		_dummit,		/* Usage fault */
/* 7 */		_dummit,		/* reserved */
/* 8 */		_dummit,		/* reserved */
/* 9 */		_dummit,		/* reserved */
/* 10 */	_dummit,		/* reserved */
/* 11 */	_dummit,		/* Supervisor Call (SVCall) */
/* 12 */	_dummit,		/* Debug Monitor */
/* 13 */	_dummit,		/* reserved */
/* 14 */	_dummit,		/* Pendable Service Request */
/* 15 */	_dummit,		/* System Tick Timer */

/* 16 */	_dummit,		/* Watchdog */
/* 17 */	_dummit,		/* PVD */
/* 18 */	_dummit,		/* TAMPER/STAMP */
/* 19 */	_dummit,		/* RTC wakeup */ 
/* 20 */	_dummit,		/* FLASH */
/* 21 */	_dummit,		/* RCC */
/* 22 */	_dummit,		/* EXTI0 */
/* 23 */	_dummit,		/* EXTI1 */
/* 24 */	_dummit,		/* EXTI2/TS */
/* 25 */	_dummit,		/* EXTI3 */
/* 26 */	_dummit,		/* EXTI4 */
/* 27 */	_dummit,		/* DMA1 stream 0 */
/* 28 */	_dummit,		/* DMA1 stream 1 */
/* 29 */	_dummit,		/* DMA1 stream 2 */
/* 30 */	_dummit,		/* DMA1 stream 3 */
/* 31 */	_dummit,		/* DMA1 stream 4 */
/* 32 */	_dummit,		/* DMA1 stream 5 */
/* 33 */	_dummit,		/* DMA1 stream 6 */
/* 34 */	_dummit,		/* ADC1/ADC2/ADC3 */
/* 35 */	_dummit,		/* CAN1 TX */
/* 36 */	_dummit,		/* CAN1 RX0 */
/* 37 */	_dummit,		/* CAN1 RX1 */
/* 38 */	_dummit,		/* CAN1 SCE */
/* 39 */	_dummit,		/* EXTI5_9 */
/* 40 */	_dummit,		/* TIM1 break /TIM9 */
/* 41 */	_dummit,		/* TIM1 update /TIM10 */
/* 42 */	_dummit,		/* TIM1 trigger /TIM11 */
/* 43 */	_dummit,		/* TIM1 capture compare */
/* 44 */	tim2ovf,		/* TIM2 */
/* 45 */	_dummit,		/* TIM3 */
/* 46 */	_dummit,		/* TIM4 */
/* 47 */	_dummit,		/* I2C1 event */
/* 48 */	_dummit,		/* I2C1 error */
/* 49 */	_dummit,		/* I2C2 event */
/* 50 */	_dummit,		/* I2C2 error */
/* 51 */	_dummit,		/* SPI1 */
/* 52 */	_dummit,		/* SPI2 */
/* 53 */	_dummit,		/* USART1 */
/* 54 */	_dummit,		/* USART2 */
/* 55 */	_dummit,		/* USART3 */
/* 56 */	_dummit,		/* EXTI10_15 */
/* 57 */	_dummit,		/* RTC alarm */
/* 58 */	_dummit,		/* USB wakeup */
/* 59 */	_dummit,		/* TIM8 break /TIM12 */
/* 60 */	_dummit,		/* TIM8 update /TIM13 */
/* 61 */	_dummit,		/* TIM8 trigger /TIM14 */
/* 62 */	_dummit,		/* TIM8 capture compare */
/* 63 */	_dummit,		/* DMA1 stream 7 */
/* 64 */	_dummit,		/* FSMC */
/* 65 */	_dummit,		/* SDIO */
/* 66 */	_dummit,		/* TIM5 */
/* 67 */	_dummit,		/* SPI3 */
/* 68 */	_dummit,		/* UART4 */
/* 69 */	_dummit,		/* UART5 */
/* 70 */	_dummit,		/* TIM6/DAC */
/* 71 */	_dummit,		/* TIM7 */
/* 72 */	_dummit,		/* DMA2 stream 0 */
/* 73 */	_dummit,		/* DMA2 stream 1 */
/* 74 */	_dummit,		/* DMA2 stream 2 */
/* 75 */	_dummit,		/* DMA2 stream 3 */
/* 76 */	_dummit,		/* DMA2 stream 4 */
/* 77 */	_dummit,		/* ETH */
/* 78 */	_dummit,		/* ETH wakeup */
/* 79 */	_dummit,		/* CAN2 TX */
/* 80 */	_dummit,		/* CAN2 RX0 */
/* 81 */	_dummit,		/* CAN2 RX1 */
/* 82 */	_dummit,		/* CAN2 SCE */
/* 83 */	_dummit,		/* USB OTG FS */
/* 84 */	_dummit,		/* DMA2 stream 5 */
/* 85 */	_dummit,		/* DMA2 stream 6 */
/* 86 */	_dummit,		/* DMA2 stream 7 */
/* 87 */	_dummit,		/* USART6 */
/* 88 */	_dummit,		/* I2C3 event */
/* 89 */	_dummit,		/* I2C3 error */
/* 90 */	_dummit,		/* USB HS ep1 out */
/* 91 */	_dummit,		/* USB HS ep1 in */
/* 92 */	_dummit,		/* USB HS wakeup */
/* 93 */	_dummit,		/* USB HS */
/* 94 */	_dummit,		/* DCMI */
/* 95 */	_dummit,		/* CRYP */
/* 96 */	_dummit,		/* HASH/RNG */
/* 97 */	_dummit,		/* FPU */
	};
