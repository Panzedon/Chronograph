/*	DEMO PROGRAM FOR TWR-K60N512
 *	Copyright (c) 2015 by COSMIC Software
 */
#include <iok60.h>
 
#define SIM_SCGC5_PORTA_MASK	0x200
#define SIM_SCGC3_FTM2_MASK	0x1000000
#define MUX_GPIO		0x100
#define FTM_SC_TOF		0x80
#define FTM_SC_TIE		0x40
#define MCG_S_CLKST		0x0c
#define MCG_S_IREFST		0x10
#define MCG_S_PLLST		0x20
#define MCG_S_LOCK		0x40
#define MCG_C6_PLLS		0x40

#define LED1    11	/* orange */
#define LED2    28	/* yellow */
#define LED3    29	/* green */
#define LED4    10	/* blue */

#define LED1_MASK    (1L << LED1)
#define LED2_MASK    (1L << LED2)
#define LED3_MASK    (1L << LED3)
#define LED4_MASK    (1L << LED4)

#define LED1_ON    PTA.PCOR = LED1_MASK
#define LED2_ON    PTA.PCOR = LED2_MASK
#define LED3_ON    PTA.PCOR = LED3_MASK
#define LED4_ON    PTA.PCOR = LED4_MASK

#define LED1_OFF   PTA.PSOR = LED1_MASK
#define LED2_OFF   PTA.PSOR = LED2_MASK
#define LED3_OFF   PTA.PSOR = LED3_MASK
#define LED4_OFF   PTA.PSOR = LED4_MASK

#define EnableInterrupts()	_asm("cpsie i")

volatile int timcnt;		/* timer counter */

/*	set pll for 96MHz
 */
void pllinit(void)
	{
	MCG.C2 = 0;
	MCG.C1 = 0x98;				/* CLKS=2 FRDIV=3 IREFS=0 IRCLKEN=0 IREFSTEN=0 */
	while (MCG.S & MCG_S_IREFST)		/* wait for Reference clock Status bit to clear */
		;

	while ((MCG.S & MCG_S_CLKST) != 0x8)	/* Wait for clock status bits to show clock source is ext ref clk */
		;
	MCG.C5 = 0x18;
	MCG.C6 = 0;
	SIM.CLKDIV1 = 0x01130000;		/* MCG=PLL core=MCG bus=MCG/2 FlexBus=MCG/2 Flash clock=MCG/4 */
	MCG.C6 = MCG_C6_PLLS | 24; 		/* enable PLL for 96MHz LOLIE=0 PLLS=1 CME=0 VDIV=24 */

	while (!(MCG.S & MCG_S_PLLST))		/* wait for PLL status bit to set */
		;
	while (!(MCG.S & MCG_S_LOCK))		/* Wait for LOCK bit to set */
		;
	MCG.C1 &= 0x3f;				/* CLKS=0, FRDIV=3, IREFS=0, IRCLKEN=0, IREFSTEN=0 */
	while ((MCG.S & MCG_S_CLKST) != 0xc)	/* Wait for clock status bits to update */
		;
	}

/*	enable interrupt system
 */
void enable_irq(int irq)
	{
	int msk, i;

	msk = 1L << (irq & 31);
	i = irq >> 5;
	NVIC.ICPR[i] = msk;
	NVIC.ISER[i] = msk;
	}

/*	system initialization
 */
 void sysinit(void)
	{
	SIM.SCGC5 |= SIM_SCGC5_PORTA_MASK;	/* Clock for PORTA */
	SIM.SCGC3 |= SIM_SCGC3_FTM2_MASK;	/* Clock for FTM2 */

	PORTA.PCR[LED1] = MUX_GPIO;		/* LED's MUX */
	PORTA.PCR[LED2] = MUX_GPIO;
	PORTA.PCR[LED3] = MUX_GPIO;
	PORTA.PCR[LED4] = MUX_GPIO;

	PTA.PDDR |= (LED1_MASK | LED2_MASK | LED3_MASK | LED4_MASK);	/* Set pin to OUTPUT */

	LED1_OFF;		/* turn off all LED's */
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;

	FTM2.SC = 0;		/* setup timer */
	FTM2.CNT = 0;
	FTM2.SC |= 0x07;
	FTM2.MOD = 375;		/* 1ms @96MHz */
	FTM2.SC |= 0x08;
	FTM2.SC |= FTM_SC_TIE;	/* enable interrupts */

	enable_irq(64);
	EnableInterrupts();
	}

/*	disable watchdog
 */
void wdog_disable(void)
	{
	WDOG.UNLOCK = 0xc520;
	WDOG.UNLOCK = 0xd928;
	WDOG.STCTRLH &= ~1;
	}

/*	timer overflow interrupt
 */
@interrupt void ftm2ovf(void)
	{
	FTM2.SC &= ~FTM_SC_TOF;	/* Clear Flag */
	FTM2.CNT = 0;
	if (timcnt)
		--timcnt;
	}

/*	delay in millisecond
 */
void delayms(int delay)
	{
	timcnt = delay;
	while (timcnt)
		;
	}

/*	main program
 */
 void main(void)
	{
	int cnt;

	wdog_disable();
	pllinit();
	sysinit();
	cnt = 0;
	for (;;)
		{
		switch (cnt)
			{
		case 0:
			LED1_ON;
			LED4_OFF;
			break;
		case 1:
			LED2_ON;
			LED1_OFF;
			break;
		case 2:
			LED3_ON;
			LED2_OFF;
			break;
		case 3:
			LED4_ON;
			LED3_OFF;
			break;
			}
		delayms(250);
		cnt = (cnt + 1) & 3;
		}
	}
