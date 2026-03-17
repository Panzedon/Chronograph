/*	DEMO PROGRAM FOR DISCOVERY-F4
 *	Copyright (c) 2015 by COSMIC Software
 */
#include <iosf4.h>
 
#define RCC_AHB1ENR_PORTD	0x00000008L
#define RCC_APB1ENR_TIM2	0x00000001L
#define RCC_APB1ENR_PWR		0x10000000L

#define TIM_CR1_CEN	0x0001
#define TIM_DIER_UIE	0x0001
#define TIM_SR_UIF	0x0001

#define LED1    12	/* green */
#define LED2    13	/* orange */
#define LED3    14	/* red */
#define LED4    15	/* blue */

#define LED1_MASK    (1L << LED1)
#define LED2_MASK    (1L << LED2)
#define LED3_MASK    (1L << LED3)
#define LED4_MASK    (1L << LED4)

#define LED1_ON    GPIOD.BSRR = LED1_MASK
#define LED2_ON    GPIOD.BSRR = LED2_MASK
#define LED3_ON    GPIOD.BSRR = LED3_MASK
#define LED4_ON    GPIOD.BSRR = LED4_MASK

#define LED1_OFF   GPIOD.BSRR = LED1_MASK << 16
#define LED2_OFF   GPIOD.BSRR = LED2_MASK << 16
#define LED3_OFF   GPIOD.BSRR = LED3_MASK << 16
#define LED4_OFF   GPIOD.BSRR = LED4_MASK << 16

#define EnableInterrupts()	_asm("cpsie i")

volatile int timcnt;		/* timer counter */

/*	set pll for 168Mhz
 */
void pllinit(void)
	{
	RCC.CR |= 1;
	RCC.CFGR = 0;			/* Reset CFGR register */
	RCC.CR &= 0xFEF6FFFF;		/* Reset HSEON, CSSON and PLLON bits */
	RCC.PLLCFGR = 0x24003010;	/* Reset PLLCFGR register */
	RCC.CR &= 0xFFFBFFFF;		/* Reset HSEBYP bit */
	RCC.CIR = 0;			/* Disable all interrupts */

	RCC.CR |= 1L << 16;		/* Enable HSE */
	while (!(RCC.CR & (1L << 17)))	/* Wait till HSE is ready */

	RCC.APB1ENR |= RCC_APB1ENR_PWR;	/* Enable high performance mode, System frequency up to 168 MHz */
	PWR.CR |= 0x4000;  

	RCC.CFGR |= (5 << 9) | (4 << 13);	/* HCLK=SYSCLK/1, PCLK1=HCLK/4, PCLK2=HCLK/2, */
 	RCC.PLLCFGR = 8 | (336 << 6) |		/* Configure the main PLL */
		(((2 >> 1) - 1) << 16) |
		1 << 22 | (7 << 24);

	RCC.CR |= 1L << 24;		/* Enable the main PLL */
	while(!(RCC.CR & (1L << 25)))	/* Wait till the main PLL is ready */
		;

   	FLASH.ACR = 0x605;	/* Configure Flash prefetch, cache and wait state */

	RCC.CFGR &= ~3;		/* Select the main PLL as system clock source */
	RCC.CFGR |= 2;
	while ((RCC.CFGR & 12) != 8)    /* Wait till the main PLL is used as system clock source */
		;
	}

/*	NVIC registers
 */
unsigned long NVIC_ISER @0xE000E100;
unsigned long NVIC_ICPR @0xE000E280;

/*	enable interrupt system
 */
void enable_irq(int irq)
	{
	unsigned long msk;

	msk = 1L << (irq & 31);
	NVIC_ICPR = msk;
	NVIC_ISER = msk;
	}

/*	system initialization
 */
 void sysinit(void)
	{
	RCC.AHB1ENR |= RCC_AHB1ENR_PORTD;	/* enable PORTD clock */
	RCC.APB1ENR |= RCC_APB1ENR_TIM2;	/* enable TIM2 clock */

	GPIOD.MODER = 0x55000000;		/* set LED pin to output */
	GPIOD.OSPEEDR = 0xFF000000;		/* set Port speed */

	LED1_OFF;				/* turn off LED's */
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;

	*(unsigned long *)&TIM2.ARR = 168000;	/* 1ms @168MHz */
	TIM2.CR1 |= TIM_CR1_CEN;		/* enable TIM2 */
	TIM2.DIER |= TIM_DIER_UIE;		/* enable interrupt */

	enable_irq(28);
	EnableInterrupts();
	}

/*	timer overflow interrupt
 */
@interrupt void tim2ovf(void)
	{
	TIM2.SR &= ~TIM_SR_UIF;		/* Clear Flag */
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
