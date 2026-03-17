/*	INTERRUPT VECTOR TABLE FOR K60DN512
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
void (* const _vectab[111])(void) = {
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
/* 20 */	_dummit,		/* DMA channel 4 transfer complete */ 
/* 21 */	_dummit,		/* DMA channel 5 transfer complete */ 
/* 22 */	_dummit,		/* DMA channel 6 transfer complete */ 
/* 23 */	_dummit,		/* DMA channel 7 transfer complete */ 
/* 24 */	_dummit,		/* DMA channel 8 transfer complete */ 
/* 25 */	_dummit,		/* DMA channel 9 transfer complete */ 
/* 26 */	_dummit,		/* DMA channel 10 transfer complete */ 
/* 27 */	_dummit,		/* DMA channel 11 transfer complete */ 
/* 28 */	_dummit,		/* DMA channel 12 transfer complete */ 
/* 29 */	_dummit,		/* DMA channel 13 transfer complete */ 
/* 30 */	_dummit,		/* DMA channel 14 transfer complete */ 
/* 31 */	_dummit,		/* DMA channel 15 transfer complete */ 
/* 32 */	_dummit,		/* DMA error channel 0-15 */
/* 33 */	_dummit,		/* MCM */
/* 34 */	_dummit,		/* FLASH command complete */
/* 35 */	_dummit,		/* FLASH read collision */
/* 36 */	_dummit,		/* Low voltage detect */
/* 37 */	_dummit,		/* LLWU */
/* 38 */	_dummit,		/* Watchdog */
/* 39 */	_dummit,		/* RNG */
/* 40 */	_dummit,		/* I2C0 */
/* 41 */	_dummit,		/* I2C1 */
/* 42 */	_dummit,		/* SPI0 */
/* 43 */	_dummit,		/* SPI1 */
/* 44 */	_dummit,		/* SPI2 */
/* 45 */	_dummit,		/* CAN0 message buffer 0-15 */
/* 46 */	_dummit,		/* CAN0 bus off */
/* 47 */	_dummit,		/* CAN0 error */
/* 48 */	_dummit,		/* CAN0 transmit */
/* 49 */	_dummit,		/* CAN0 receive */
/* 50 */	_dummit,		/* CAN0 wake up */
/* 51 */	_dummit,		/* reserved */
/* 52 */	_dummit,		/* reserved */
/* 53 */	_dummit,		/* CAN1 message buffer 0-15 */
/* 54 */	_dummit,		/* CAN1 bus off */
/* 55 */	_dummit,		/* CAN1 error */
/* 56 */	_dummit,		/* CAN1 transmit */
/* 57 */	_dummit,		/* CAN1 receive */
/* 58 */	_dummit,		/* CAN1 wake up */
/* 59 */	_dummit,		/* reserved */
/* 60 */	_dummit,		/* reserved */
/* 61 */	_dummit,		/* UART0 status */
/* 62 */	_dummit,		/* UART0 error */
/* 63 */	_dummit,		/* UART1 status */
/* 64 */	_dummit,		/* UART1 error */
/* 65 */	_dummit,		/* UART2 status */
/* 66 */	_dummit,		/* UART2 error */
/* 67 */	_dummit,		/* UART3 status */
/* 68 */	_dummit,		/* UART3 error */
/* 69 */	_dummit,		/* UART4 status */
/* 70 */	_dummit,		/* UART4 error */
/* 71 */	_dummit,		/* UART5 status */
/* 72 */	_dummit,		/* UART5 error */
/* 73 */	_dummit,		/* ADC0 */
/* 74 */	_dummit,		/* ADC1 */
/* 75 */	_dummit,		/* CMP0 */
/* 76 */	_dummit,		/* CMP1 */
/* 77 */	_dummit,		/* CMP2 */
/* 78 */	_dummit,		/* FTM0 */
/* 79 */	_dummit,		/* FTM1 */
/* 80 */	ftm2ovf,		/* FTM2 */
/* 81 */	_dummit,		/* CMT */
/* 82 */	_dummit,		/* RTC */
/* 83 */	_dummit,		/* reserved */
/* 84 */	_dummit,		/* PIT channel 0 */
/* 85 */	_dummit,		/* PIT channel 1 */
/* 86 */	_dummit,		/* PIT channel 2 */
/* 87 */	_dummit,		/* PIT channel 3 */
/* 88 */	_dummit,		/* PDB */
/* 89 */	_dummit,		/* USB OTG */
/* 90 */	_dummit,		/* USB charger detect */
/* 91 */	_dummit,		/* ETH timer */
/* 92 */	_dummit,		/* ETH transmit */
/* 93 */	_dummit,		/* ETH receive */
/* 94 */	_dummit,		/* ETH error */
/* 95 */	_dummit,		/* I2S0 */
/* 96 */	_dummit,		/* SDHC */
/* 97 */	_dummit,		/* DAC0 */
/* 98 */	_dummit,		/* DAC1 */
/* 99 */	_dummit,		/* TSI */
/* 100 */	_dummit,		/* MCG */
/* 101 */	_dummit,		/* Low Power Timer */
/* 102 */	_dummit,		/* reserved */
/* 103 */	_dummit,		/* Port A Pin Detect */
/* 104 */	_dummit,		/* Port B Pin Detect */
/* 105 */	_dummit,		/* Port C Pin Detect */
/* 106 */	_dummit,		/* Port D Pin Detect */
/* 107 */	_dummit,		/* Port E Pin Detect */
/* 108 */	_dummit,		/* reserved */
/* 109 */	_dummit,		/* reserved */
/* 110 */	_dummit,		/* Software Interrupt */
	};
