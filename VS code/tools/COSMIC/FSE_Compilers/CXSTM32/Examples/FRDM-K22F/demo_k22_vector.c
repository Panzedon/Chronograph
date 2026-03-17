/*	INTERRUPT VECTOR TABLE FOR K22FN512
 *	Copyright (c) 2015 by COSMIC Software
 */
extern void _stext(void);	/* startup code */
extern int _stack;		/* stack address */
extern void ftm2ovf(void);

/*	dummy interrupt function
 */
@interrupt void _dummit(void)
	{
	}

#pragma section const {vector}

/*	vector table
 */
void (* const _vectab[90])(void) = {
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

/* 16 */	_dummit,		/* DMA channel 0 transfer complete */
/* 17 */	_dummit,		/* DMA channel 1 transfer complete */
/* 18 */	_dummit,		/* DMA channel 2 transfer complete */
/* 19 */	_dummit,		/* DMA channel 3 transfer complete */ 
/* 20 */	_dummit,		/* reserved */ 
/* 21 */	_dummit,		/* reserved */ 
/* 22 */	_dummit,		/* reserved */ 
/* 23 */	_dummit,		/* reserved */ 
/* 24 */	_dummit,		/* reserved */ 
/* 25 */	_dummit,		/* reserved */ 
/* 26 */	_dummit,		/* reserved */ 
/* 27 */	_dummit,		/* reserved */ 
/* 28 */	_dummit,		/* reserved */ 
/* 29 */	_dummit,		/* reserved */ 
/* 30 */	_dummit,		/* reserved */ 
/* 31 */	_dummit,		/* reserved */ 
/* 32 */	_dummit,		/* DMA error channel 0-3 */
/* 33 */	_dummit,		/* MCM */
/* 34 */	_dummit,		/* FLASH command complete */
/* 35 */	_dummit,		/* FLASH read collision */
/* 36 */	_dummit,		/* Low voltage detect */
/* 37 */	_dummit,		/* LLWU */
/* 38 */	_dummit,		/* Watchdog/EWM */
/* 39 */	_dummit,		/* RNG */
/* 40 */	_dummit,		/* I2C0 */
/* 41 */	_dummit,		/* I2C1 */
/* 42 */	_dummit,		/* SPI0 */
/* 43 */	_dummit,		/* SPI1 */
/* 44 */	_dummit,		/* I2S0 receive */
/* 45 */	_dummit,		/* I2S0 transmit */
/* 46 */	_dummit,		/* LPUART0 */
/* 47 */	_dummit,		/* UART0 status */
/* 48 */	_dummit,		/* UART0 error */
/* 49 */	_dummit,		/* UART1 status */
/* 50 */	_dummit,		/* UART1 error */
/* 51 */	_dummit,		/* UART2 status */
/* 52 */	_dummit,		/* UART2 error */
/* 53 */	_dummit,		/* reserved */
/* 54 */	_dummit,		/* reserved */
/* 55 */	_dummit,		/* ADC0 */
/* 56 */	_dummit,		/* CMP0 */
/* 57 */	_dummit,		/* CMP1 */
/* 58 */	_dummit,		/* FTM0 */
/* 59 */	_dummit,		/* FTM1 */
/* 60 */	ftm2ovf,		/* FTM2 */
/* 61 */	_dummit,		/* reserved */
/* 62 */	_dummit,		/* RTC alarm */
/* 63 */	_dummit,		/* RTC seconds */
/* 64 */	_dummit,		/* PIT channel 0 */
/* 65 */	_dummit,		/* PIT channel 1 */
/* 66 */	_dummit,		/* PIT channel 2 */
/* 67 */	_dummit,		/* PIT channel 3 */
/* 68 */	_dummit,		/* PDB */
/* 69 */	_dummit,		/* USB OTG */
/* 70 */	_dummit,		/* reserved */
/* 71 */	_dummit,		/* reserved */
/* 72 */	_dummit,		/* DAC0 */
/* 73 */	_dummit,		/* MCG */
/* 74 */	_dummit,		/* Low Power Timer */
/* 75 */	_dummit,		/* Port A Pin Detect */
/* 76 */	_dummit,		/* Port B Pin Detect */
/* 77 */	_dummit,		/* Port C Pin Detect */
/* 78 */	_dummit,		/* Port D Pin Detect */
/* 79 */	_dummit,		/* Port E Pin Detect */
/* 80 */	_dummit,		/* Software Interrupt */
/* 81 */	_dummit,		/* reserved */
/* 82 */	_dummit,		/* reserved */
/* 83 */	_dummit,		/* reserved */
/* 84 */	_dummit,		/* reserved */
/* 85 */	_dummit,		/* reserved */
/* 86 */	_dummit,		/* reserved */
/* 87 */	_dummit,		/* FTM3 */
/* 88 */	_dummit,		/* DAC1 */
/* 89 */	_dummit,		/* ADC1 */
	};
