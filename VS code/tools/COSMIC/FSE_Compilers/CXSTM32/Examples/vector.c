/*	INTERRUPT VECTOR TABLES
 *	Copyright (c) 2011 by COSMIC Software
 */

extern void _stext(void);	/* startup code */
extern int _stack;		/* stack address */

extern void recept(void);	/* receive routine */

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
/* 32 */	_dummit,		/* DMA error interrupt channel 0-15 */
/* 33 */	_dummit,		/* MCM Normal interrupt */
/* 34 */	_dummit,		/* FLASH Command complete */
/* 35 */	_dummit,		/* FLASH Read collision */
/* 36 */	_dummit,		/* Low voltage warning */
/* 37 */	_dummit,		/* Low Leakage Wakeup */
/* 38 */	_dummit,		/* Watchdog */
/* 39 */	_dummit,		/* Random Number Generator */
/* 40 */	_dummit,		/* I2C0 */
/* 41 */	_dummit,		/* I2C1 */
/* 42 */	_dummit,		/* SPI0 */
/* 43 */	_dummit,		/* SPI1 */
/* 44 */	_dummit,		/* SPI2 */
/* 45 */	_dummit,		/* CAN0 OR'ed message buffer */
/* 46 */	_dummit,		/* CAN0 Buss Off */
/* 47 */	_dummit,		/* CAN0 Error */
/* 48 */	_dummit,		/* CAN0 Transmit Warning */
/* 49 */	_dummit,		/* CAN0 Receive Warning */
/* 50 */	_dummit,		/* CAN0 Wake Up */
/* 51 */	_dummit,		/* reserved */
/* 52 */	_dummit,		/* reserved */
/* 53 */	_dummit,		/* CAN1 OR'ed message buffer */
/* 54 */	_dummit,		/* CAN1 Buss Off */
/* 55 */	_dummit,		/* CAN1 Error */
/* 56 */	_dummit,		/* CAN1 Transmit Warning */
/* 57 */	_dummit,		/* CAN1 Receive Warning */
/* 58 */	_dummit,		/* CAN1 Wake Up */
/* 59 */	_dummit,		/* reserved */
/* 60 */	_dummit,		/* reserved */
/* 61 */	recept,			/* UART0 Status */
/* 62 */	_dummit,		/* UART0 Error */
/* 63 */	_dummit,		/* UART1 Status */
/* 64 */	_dummit,		/* UART1 Error */
/* 65 */	_dummit,		/* UART2 Status */
/* 66 */	_dummit,		/* UART2 Error */
/* 67 */	_dummit,		/* UART3 Status */
/* 68 */	_dummit,		/* UART3 Error */
/* 69 */	_dummit,		/* UART4 Status */
/* 70 */	_dummit,		/* UART4 Error */
/* 71 */	_dummit,		/* UART5 Status */
/* 72 */	_dummit,		/* UART5 Error */
/* 73 */	_dummit,		/* ADC0 */
/* 74 */	_dummit,		/* ADC1 */
/* 75 */	_dummit,		/* CMP0 */
/* 76 */	_dummit,		/* CMP1 */
/* 77 */	_dummit,		/* CMP2 */
/* 78 */	_dummit,		/* FTM0 */
/* 79 */	_dummit,		/* FTM1 */
/* 80 */	_dummit,		/* FTM2 */
/* 81 */	_dummit,		/* CMT */
/* 82 */	_dummit,		/* RTC Alarm interrupt */
/* 83 */	_dummit,		/* reserved */
/* 84 */	_dummit,		/* PIT Channel 0 */
/* 85 */	_dummit,		/* PIT Channel 1 */
/* 86 */	_dummit,		/* PIT Channel 2 */
/* 87 */	_dummit,		/* PIT Channel 3 */
/* 88 */	_dummit,		/* PDB */
/* 89 */	_dummit,		/* USB OTG */
/* 90 */	_dummit,		/* USB Charger Detect */
/* 91 */	_dummit,		/* Ether MAC IEEE 1588 Timer */
/* 92 */	_dummit,		/* Ether MAC Transmit Interrupt */
/* 93 */	_dummit,		/* Ether MAC Receive Interrupt */
/* 94 */	_dummit,		/* Ether MAC Error Interrupt */
/* 95 */	_dummit,		/* I2S0 */
/* 96 */	_dummit,		/* SDHC fill */
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
