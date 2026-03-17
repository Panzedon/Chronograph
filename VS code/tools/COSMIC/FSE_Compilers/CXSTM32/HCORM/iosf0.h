/*	IO DEFINITIONS FOR STM32F0xx
 *	Copyright (c) 2012 by COSMIC SOftware
 */
typedef volatile unsigned char __REGB__;
typedef volatile unsigned short __REGH__;
typedef volatile unsigned int __REGW__;

/*	ADC section 
 */
struct __adc__ {
	__REGW__ ISR;                   /* interrupt and status register */
	__REGW__ IER;                   /* interrupt enable register */      
	__REGW__ CR;                    /* control register */
	__REGW__ CFGR1;                 /* configuration register 1 */
	__REGW__ CFGR2;                 /* configuration register 2 */
	__REGW__ SMPR;                  /* sampling time register */
	__REGW__ reserved_0[2];
	__REGW__ TR;                    /* watchdog threshold register */
	__REGW__ reserved_1;
	__REGW__ CHSELR;                /* channel selection register */
	__REGW__ reserved_2[5];
	__REGW__ DR;                    /* data register */
	__REGW__ reserved_3[177];
	__REGW__ CCR;                   /* common configuration register */
	};

struct __adc__ ADC	@0x40012400;

/*	CEC section
 */
struct __cec__ {
	__REGW__ CR;                    /* control register */
	__REGW__ CFGR;                  /* configuration register */
	__REGB__ TXDR;                  /* transmit data register */
	__REGB__ reserved_0;
	__REGH__ reserved_1;
	__REGB__ RXDR;                  /* receive data register */
	__REGB__ reserved_2;
	__REGH__ reserved_3;
	__REGH__ ISR;                   /* interrupt and status register */
	__REGH__ reserved_4;
	__REGH__ IER;                   /* interrupt enable register */
	__REGH__ reserved_5;
	};

struct __cec__ CEC	@0x40007800;

/*	CRC section
 */
struct __crc__ {
	__REGW__ DR;                    /* Data register */
	__REGB__ IDR;                   /* Independent data register */
	__REGB__ reserved_0;
	__REGH__ reserved_1;
	__REGB__ CR;                    /* Control register */
	__REGB__ reserved_2;
	__REGH__ reserved_3;
	__REGW__ INIT;                  /* Init register */
	};

struct __crc__ CRC	@0x40023000;

/*	DAC section
 */
struct __dac__ {
	__REGW__ CR;                    /* control register */
	__REGW__ SWTRIGR;               /* software trigger register */
	__REGW__ DHR12R1;               /* chan 1 12-bit right align data reg */
	__REGW__ DHR12L1;               /* chan 1 12-bit left align data reg */
	__REGW__ DHR8R1;                /* chan 1 8-bit right align data reg */
	__REGW__ DOR1;                  /* chan 1 data output register */
	__REGW__ SR;                    /* status register */
	};

struct __dac__ DAC	@0x40007400;

/*	DBGMCU section
 */
struct __dbgmcu__ {
	__REGW__ IDCODE;                /* device ID code */
	__REGW__ CR;                    /* configuration register */
	__REGW__ APB1FZ;                /* APB1 freeze register */
	__REGW__ APB2FZ;                /* APB2 freeze register */
	};

struct __dbgmcu__ DBGMCU	@0x40015800;

/*	DMA section
 */
struct __dma__{
	__REGW__ ISR;                   /* interrupt status register */
	__REGW__ IFCR;                  /* interrupt flag clear register */
	__REGW__ CCR1;                  /* configuration register chan 1 */
	__REGW__ CNDTR1;                /* number of data register chan 1*/
	__REGW__ CPAR1;                 /* peripheral address register chan 1 */
	__REGW__ CMAR1;                 /* memory address register chan 1 */
	__REGW__ CCR2;                  /* configuration register chan 2 */
	__REGW__ CNDTR2;                /* number of data register chan 2 */
	__REGW__ CPAR2;                 /* peripheral address register chan 2 */
	__REGW__ CMAR2;                 /* memory address register chan 2 */
	__REGW__ CCR3;                  /* configuration register chan 3 */
	__REGW__ CNDTR3;                /* number of data register chan 3 */
	__REGW__ CPAR3;                 /* peripheral address register chan 3 */
	__REGW__ CMAR3;                 /* memory address register chan 3 */
	__REGW__ CCR4;                  /* configuration register chan 4 */
	__REGW__ CNDTR4;                /* number of data register chan 4 */
	__REGW__ CPAR4;                 /* peripheral address register chan 4 */
	__REGW__ CMAR4;                 /* memory address register chan 4 */
	__REGW__ CCR5;                  /* configuration register chan 5 */
	__REGW__ CNDTR5;                /* number of data register chan 5 */
	__REGW__ CPAR5;                 /* peripheral address register chan 5 */
	__REGW__ CMAR5;                 /* memory address register chan 5 */
	};

struct __dma__  DMA		@0x40020000;

/*	EXTI section
 */
struct __exti__ {
	__REGW__ IMR;                   /* Interrupt mask register */
	__REGW__ EMR;                   /* Event mask register */
	__REGW__ RTSR;                  /* Rising trigger selection register */
	__REGW__ FTSR;                  /* Falling trigger selection register */
	__REGW__ SWIER;                 /* Software interrupt event register */
	__REGW__ PR;                    /* Pending register */
	};

struct __exti__ EXTI	@0x40010400;

/*	FLASH section
 */
struct __flash__ {
	__REGW__ ACR;                   /* access control register */
	__REGW__ KEYR;                  /* key register */
	__REGW__ OPTKEYR;               /* option key register */
	__REGW__ SR;                    /* status register */
	__REGW__ CR;                    /* control register */
	__REGW__ AR;                    /* address register */
	__REGW__ OBR;                   /* option byte register */
	__REGW__ WRPR;                  /* write protection register */
	};

struct __flash__ FLASH	@0x40022000;
 
/*	GPIO section
 */
struct __gpio__ {
	__REGW__ MODER;                 /* port mode register */
	__REGW__ OTYPER;                /* port output type register */
	__REGW__ OSPEEDR;               /* port output speed register */
	__REGW__ PUPDR;                 /* port pull-up/pull-down register */
	__REGW__ IDR;                   /* port input data register */
	__REGW__ ODR;                   /* port output data register */
	__REGW__ BSRR;                  /* port bit set/reset register */
	__REGW__ LCKR;                  /* port configuration lock register */
	__REGW__ AFRL;                  /* alternate function low register */
	__REGW__ AFRH;                  /* alternate function low register */
	__REGW__ BRR;                   /* port bit reset register */
	};

struct __gpio__ GPIOA	@0x48000000;
struct __gpio__ GPIOB	@0x48000400;
struct __gpio__ GPIOC	@0x48000800;
struct __gpio__ GPIOD	@0x48000c00;
struct __gpio__ GPIOF	@0x48001400;

/*	SYSCFG section
 */
struct __syscfg__ {
	__REGW__ CFGR1;                 /* configuration register 1 */
	__REGW__ EXTICR[4];             /* external interrupt config regs */
	__REGW__ CFGR2;                 /* configuration register 2 */
	__REGW__ reserved_0;
	__REGW__ CMPCSR;                /* CMP control status register */
	};

struct __syscfg__ SYSCFG	@0x40010000;

/*	I2C section
 */
struct __i2c__ {
	__REGW__ CR1;                   /* Control register 1 */
	__REGW__ CR2;                   /* Control register 2 */
	__REGH__ OAR1;                  /* Own address register 1 */
	__REGH__ reserved_0;             
	__REGH__ OAR2;                  /* Own address register 2 */
	__REGH__ reserved_1;             
	__REGW__ TIMINGR;               /* Timing register */
	__REGW__ TIMOUTR;               /* Timeout register */
	__REGW__ ISR;                   /* Interrupt and status register */
	__REGH__ ICR;                   /* Interrupt clear register */
	__REGH__ reserved_2;             
	__REGB__ PECR;                  /* PEC register */
	__REGB__ reserved_3;             
	__REGH__ reserved_4;             
	__REGB__ RXDR;                  /* receive data register */
	__REGB__ reserved_5;             
	__REGH__ reserved_6;             
	__REGB__ TXDR;                  /* transmit data register */
	__REGB__ reserved_7;             
	__REGH__ reserved_8;             
	};

struct __i2c__ I2C1	@0x40005400;
struct __i2c__ I2C2	@0x40005800;

/*	IWDG section
 */
struct __iwdg__ {
	__REGW__ KR;                    /* Key register */
	__REGW__ PR;                    /* Prescaler register */
	__REGW__ RLR;                   /* Reload register */
	__REGW__ SR;                    /* Status register */
	__REGW__ WINR;                  /* Window register */
	};

struct __iwdg__ IWDG	@0x40003000;

/*	PWR section
 */
struct __pwr__ {
	__REGW__ CR;                    /* power control register */
	__REGW__ CSR;                   /* power control/status register */
	};

struct __pwr__ PWR	@0x40007000;

/*	RCC section
 */
struct __rcc__ {
	__REGW__ CR;                    /* Clock control register */
	__REGW__ CFGR;                  /* Clock configuration register */
	__REGW__ CIR;                   /* Clock interrupt register */
	__REGW__ APB2RSTR;              /* APB2 peripheral reset register */
	__REGW__ APB1RSTR;              /* APB1 peripheral reset register */
	__REGW__ AHBENR;                /* AHB peripheral clock enable reg. */
	__REGW__ APB2ENR;               /* APB2 peripheral clock enable reg. */
	__REGW__ APB1ENR;               /* APB1 peripheral clock enable reg. */
	__REGW__ BDCR;                  /* Backup domain control register */
	__REGW__ CSR;                   /* clock control & status register */
	__REGW__ AHBRSTR;               /* AHB peripheral reset register */
	__REGW__ CFGR2;                 /* Clock configuration register 2 */
	__REGW__ CFGR3;                 /* Clock configuration register 3 */
	__REGW__ CR2;                   /* Clock control register 2 */
	};

struct __rcc__ RCC	@0x40021000;

/*	RTC section
 */
struct __rtc__ {
	__REGW__ TR;                    /* time register */
	__REGW__ DR;                    /* date register */
	__REGW__ CR;                    /* control register */
	__REGW__ ISR;                   /* initialization and status register */
	__REGW__ PRER;                  /* prescaler register */
	__REGW__ ALRMAR;                /* alarm A register */
	__REGW__ WPR;                   /* write protection register */
	__REGW__ SSR;                   /* sub second register */
	__REGW__ SHIFTR;                /* shift control register */
	__REGW__ TSTR;                  /* time stamp time register */
	__REGW__ TSSSR;                 /* time stamp sub second register */
	__REGW__ CALR;                  /* calibration register */
	__REGW__ TAFCR;                 /* tamper/alt function config reg */
	__REGW__ ALRMASSR;              /* alarm A sub second register */
	__REGW__ BKP0R;                 /* backup register 0 */
	__REGW__ BKP1R;                 /* backup register 1 */
	__REGW__ BKP2R;                 /* backup register 2 */
	__REGW__ BKP3R;                 /* backup register 3 */
	__REGW__ BKP4R;                 /* backup register 4 */
	};

struct __rtc__ RTC	@0x40002800;

/*	SPI section
 */
struct __spi__ {
	__REGH__ CR1;                   /* control register 1 */
	__REGH__ reserved_0;            
	__REGH__ CR2;                   /* control register 2 */
	__REGH__ reserved_1;            
	__REGH__ SR;                    /* status register */
	__REGH__ reserved_2;            
	__REGH__ DR;                    /* data register */
	__REGH__ reserved_3;            
	__REGH__ CRCPR;                 /* CRC polynomial register */
	__REGH__ reserved_4;            
	__REGH__ RXCRCR;                /* RX CRC register */
	__REGH__ reserved_5;            
	__REGH__ TXCRCR;                /* TX CRC register */
	__REGH__ reserved_6;            
	__REGH__ I2SCFGR;               /* I2S configuration register */
	__REGH__ reserved_7;            
	__REGH__ I2SPR;                 /* I2S prescaler register */
	__REGH__ reserved_8;
	};

struct __spi__ SPI1	@0x40013000;
struct __spi__ SPI2	@0x40003800;

/*	TIM section
 */
struct __tim__ {
	__REGH__ CR1;                   /* control register 1 */
	__REGH__ reserved_0;            
	__REGH__ CR2;                   /* control register 2 */
	__REGH__ reserved_1;            
	__REGH__ SMCR;                  /* slave mode control register */
	__REGH__ reserved_2;            
	__REGH__ DIER;                  /* DMA/interrupt enable registerC */
	__REGH__ reserved_3;            
	__REGH__ SR;                    /* status register */
	__REGH__ reserved_4;            
	__REGH__ EGR;                   /* event generation register */
	__REGH__ reserved_5;            
	__REGH__ CCMR1;                 /* capture/compare mode register 1 */
	__REGH__ reserved_6;            
	__REGH__ CCMR2;                 /* capture/compare mode register 2 */
	__REGH__ reserved_7;            
	__REGH__ CCER;                  /* capture/compare enable register */
	__REGH__ reserved_8;            
	__REGW__ CNT;                   /* counter register */
	__REGH__ PSC;                   /* prescaler */
	__REGH__ reserved_9;            
	__REGH__ ARR;                   /* auto-reload register */
	__REGH__ reserved_10;           
	__REGH__ RCR;                   /* repetition counter register */
	__REGH__ reserved_11;           
	__REGH__ CCR1;                  /* capture/compare register 1 */
	__REGH__ reserved_12;           
	__REGH__ CCR2;                  /* capture/compare register 2 */
	__REGH__ reserved_13;           
	__REGH__ CCR3;                  /* capture/compare register 3 */
	__REGH__ reserved_14;           
	__REGH__ CCR4;                  /* capture/compare register 4 */
	__REGH__ reserved_15;           
	__REGH__ BDTR;                  /* break and dead-time register */
	__REGH__ reserved_16;           
	__REGH__ DCR;                   /* DMA control register */
	__REGH__ reserved_17;           
	__REGH__ DMAR;                  /* DMA address for full transfer */
	__REGH__ reserved_18;           
	};

struct __tim__ TIM1	@0x40012C00;
struct __tim__ TIM2	@0x40000000;
struct __tim__ TIM3	@0x40000400;
struct __tim__ TIM6	@0x40001000;
struct __tim__ TIM14	@0x40002000;
struct __tim__ TIM15	@0x40014000;
struct __tim__ TIM16	@0x40014400;
struct __tim__ TIM17	@0x40014800;

/*	TSC section
 */
struct __tsc__ {
	__REGW__ CR;                    /* Control register */
	__REGW__ IER;                   /* Interrupt enable register */
	__REGW__ ICR;                   /* Interrupt clear register */
	__REGW__ ISR;                   /* Interrupt status register */
	__REGW__ IOHCR;                 /* IO hysteresis control register */
	__REGW__ IOASCR;                /* IO analog switch control register */
	__REGW__ IOSCR;                 /* IO sampling control register */
	__REGW__ IOCCR;                 /* IO channel control register */
	__REGW__ IOGCSR;                /* IO group control status register */
	__REGH__ IOG1CR;                /* IO group 1 counter register */
	__REGH__ reserved_0;
	__REGH__ IOG2CR;                /* IO group 2 counter register */
	__REGH__ reserved_1;
	__REGH__ IOG3CR;                /* IO group 3 counter register */
	__REGH__ reserved_2;
	__REGH__ IOG4CR;                /* IO group 4 counter register */
	__REGH__ reserved_3;
	__REGH__ IOG5CR;                /* IO group 5 counter register */
	__REGH__ reserved_4;
	__REGH__ IOG6CR;                /* IO group 6 counter register */
	__REGH__ reserved_5;
	};

struct __tsc__ TSC	@0x40024000;

/*	USART section
 */
struct __usart__ {
	__REGW__ CR1;                   /* control register 1 */
	__REGW__ CR2;                   /* control register 2 */
	__REGW__ CR3;                   /* control register 3 */
	__REGH__ BRR;                   /* Baud rate register */
	__REGH__ reserved_0;
	__REGH__ GTPR;                  /* Guard time and prescaler register */
	__REGH__ reserved_1;
	__REGW__ RTOR;                  /* receiver timeout register */
	__REGB__ RQR;                   /* request register */
	__REGB__ reserved_2;
	__REGH__ reserved_3;
	__REGW__ ISR;                   /* interrupt and status register */
	__REGW__ ICR;                   /* interrupt flag clear register */
	__REGH__ RDR;                   /* receive data register */
	__REGH__ reserved_4;            
	__REGH__ TDR;                   /* transmit data register */
	__REGH__ reserved_5;            
	};

struct __usart__ USART1	@0x40013800;
struct __usart__ USART2	@0x40004400;

/*	WWDG section
 */
struct __wwdg__ {
	__REGW__ CR;                    /* Control register */
	__REGW__ CFR;                   /* Configuration register */
	__REGW__ SR;                    /* Status register */
	};

struct __wwdg__ WWDG	@0x40002c00;

