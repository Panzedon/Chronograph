/*	IO DEFINITIONS FOR STM32G0xx
 *	Copyright (c) 2023 by COSMIC SOftware
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
	__REGW__ AWD1TR;                /* watchdog threshold register 1 */
	__REGW__ AWD2TR;                /* watchdog threshold register 2 */
	__REGW__ CHSELR;                /* channel selection register */
	__REGW__ AWD3TR;                /* watchdog threshold register 3 */
	__REGW__ reserved_2[4];
	__REGW__ DR;                    /* data register */
	__REGW__ reserved_3[40];
	__REGW__ AWD2CR;                /* watchdog configuration register 2 */
	__REGW__ AWD3CR;                /* watchdog configuration register 3 */
	__REGW__ reserved_4[3];
	__REGW__ CALFACT;               /* calibration factor register */
	__REGW__ reserved_5[148];
	__REGW__ CCR;                   /* common configuration register */
	};

struct __adc__ ADC	@0x40012400;

/*	CRC section
 */
struct __crc__ {
	__REGW__ DR;                    /* data register */
	__REGW__ IDR;                   /* independent data register */
	__REGB__ CR;                    /* control register */
	__REGB__ reserved_0;
	__REGH__ reserved_1;
	__REGW__ INIT;                  /* init register */
	__REGW__ POL;                   /* polynomial register */
	};

struct __crc__ CRC	@0x40023000;

/*	DBG section
 */
struct __dbg__ {
	__REGW__ IDCODE;                /* device ID code */
	__REGW__ CR;                    /* configuration register */
	__REGW__ APBFZ1;                /* APB freeze register 1 */
	__REGW__ APBFZ2;                /* APB freeze register 2 */
	};

struct __dbg__ DBG	@0x40015800;

/*	DMA section
 */
struct __dma__{
	__REGW__ ISR;                   /* interrupt status register */
	__REGW__ IFCR;                  /* interrupt flag clear register */
	__REGW__ CCR1;                  /* configuration register chan 1 */
	__REGW__ CNDTR1;                /* number of data register chan 1*/
	__REGW__ CPAR1;                 /* peripheral address register chan 1 */
	__REGW__ CMAR1;                 /* memory address register chan 1 */
	__REGW__ reserved_0;
	__REGW__ CCR2;                  /* configuration register chan 2 */
	__REGW__ CNDTR2;                /* number of data register chan 2 */
	__REGW__ CPAR2;                 /* peripheral address register chan 2 */
	__REGW__ CMAR2;                 /* memory address register chan 2 */
	__REGW__ reserved_1;
	__REGW__ CCR3;                  /* configuration register chan 3 */
	__REGW__ CNDTR3;                /* number of data register chan 3 */
	__REGW__ CPAR3;                 /* peripheral address register chan 3 */
	__REGW__ CMAR3;                 /* memory address register chan 3 */
	__REGW__ reserved_2;
	__REGW__ CCR4;                  /* configuration register chan 4 */
	__REGW__ CNDTR4;                /* number of data register chan 4 */
	__REGW__ CPAR4;                 /* peripheral address register chan 4 */
	__REGW__ CMAR4;                 /* memory address register chan 4 */
	__REGW__ reserved_3;
	__REGW__ CCR5;                  /* configuration register chan 5 */
	__REGW__ CNDTR5;                /* number of data register chan 5 */
	__REGW__ CPAR5;                 /* peripheral address register chan 5 */
	__REGW__ CMAR5;                 /* memory address register chan 5 */
	__REGW__ reserved_4;
	__REGW__ CCR6;                  /* configuration register chan 6 */
	__REGW__ CNDTR6;                /* number of data register chan 6 */
	__REGW__ CPAR6;                 /* peripheral address register chan 6 */
	__REGW__ CMAR6;                 /* memory address register chan 6 */
	__REGW__ reserved_5;
	__REGW__ CCR7;                  /* configuration register chan 7 */
	__REGW__ CNDTR7;                /* number of data register chan 7 */
	__REGW__ CPAR7;                 /* peripheral address register chan 7 */
	__REGW__ CMAR7;                 /* memory address register chan 7 */
	};

struct __dma__  DMA1		@0x40020000;
struct __dma__  DMA2		@0x40020400;

/*	DMAMUX section
 */
struct __dmamux__{
	__REGW__ C0CR;                  /* channel 0 configuration register */
	__REGW__ C1CR;                  /* channel 1 configuration register */
	__REGW__ C2CR;                  /* channel 2 configuration register */
	__REGW__ C3CR;                  /* channel 3 configuration register */
	__REGW__ C4CR;                  /* channel 4 configuration register */
	__REGW__ C5CR;                  /* channel 5 configuration register */
	__REGW__ C6CR;                  /* channel 6 configuration register */
	__REGW__ C7CR;                  /* channel 7 configuration register */
	__REGW__ C8CR;                  /* channel 8 configuration register */
	__REGW__ C9CR;                  /* channel 9 configuration register */
	__REGW__ C10CR;                 /* channel 10 configuration register */
	__REGW__ C11CR;                 /* channel 11 configuration register */
	__REGW__ reserved_0[20];
	__REGW__ CSR;                   /* channel status register */
	__REGW__ CFR;                   /* clear flag register */
	__REGW__ reserved_1[30];
	__REGW__ RG0CR;                 /* chan 0 configuration register*/
	__REGW__ RG1CR;                 /* chan 1 configuration register*/
	__REGW__ RG2CR;                 /* chan 2 configuration register*/
	__REGW__ RG3CR;                 /* chan 3 configuration register*/
	__REGW__ reserved_2[3];
	__REGW__ RGSR;                  /* interrupt status register */
	__REGW__ RGCFR;                 /* interrupt clear flag register */
	};

struct __dmamux__  DMAMUX	@0x40020800;

/*	EXTI section
 */
struct __exti__ {
	__REGW__ RTSR1;                 /* rising trigger selection register 1 */
	__REGW__ FTSR1;                 /* falling trigger selection register 1 */
	__REGW__ SWIER1;                /* Software interrupt event register 1 */
	__REGW__ RPR1;                  /* rising edge pending register 1 */
	__REGW__ FPR1;                  /* falling edge pending register 1 */
	__REGW__ reserved_0[19];
	__REGW__ EXTICR1;               /* external interrupt selection register 1 */
	__REGW__ EXTICR2;               /* external interrupt selection register 2 */
	__REGW__ EXTICR3;               /* external interrupt selection register 3 */
	__REGW__ EXTICR4;               /* external interrupt selection register 4 */
	__REGW__ reserved_1[4];
	__REGW__ IMR1;                  /* interrupt mask register 1 */
	__REGW__ EMR1;                  /* event mask register 1 */
	};

struct __exti__ EXTI	@0x40021800;

/*	FLASH section
 */
struct __flash__ {
	__REGW__ ACR;                   /* access control register */
	__REGW__ reserved_0;
	__REGW__ KEYR;                  /* key register */
	__REGW__ OPTKEYR;               /* option key register */
	__REGW__ SR;                    /* status register */
	__REGW__ CR;                    /* control register */
	__REGW__ EECR;                  /* eec register */
	__REGW__ EECR2;                 /* eec register 2 */
	__REGW__ OPTR;                  /* option register */
	__REGW__ reserved_1[2];
	__REGW__ WRP1AR;                /* wrp1 area a address register */
	__REGW__ WRP1BR;                /* wrp1 area b address register */
	__REGW__ WRP2AR;                /* wrp2 area a address register */
	__REGW__ WRP2BR;                /* wrp2 area b address register */
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

struct __gpio__ GPIOA	@0x50000000;
struct __gpio__ GPIOB	@0x50000400;
struct __gpio__ GPIOC	@0x50000800;
struct __gpio__ GPIOD	@0x50000c00;
struct __gpio__ GPIOE	@0x50001000;
struct __gpio__ GPIOF	@0x50001400;

/*	SYSCFG section
 */
struct __syscfg__ {
	__REGW__ CFGR1;                 /* configuration register 1 */
	__REGW__ reserved_0[5];
	__REGW__ CFGR2;                 /* configuration register 2 */
	__REGW__ reserved_1[25];
	__REGW__ EXTICR[32];            /* external interrupt config regs */
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
struct __i2c__ I2C3	@0x40008800;

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
	__REGW__ CR1;                   /* power control register 1 */
	__REGW__ CR2;                   /* power control register 2 */
	__REGW__ CR3;                   /* power control register 3 */
	__REGW__ CR4;                   /* power control register 4 */
	__REGW__ SR1;                   /* power status register 1 */
	__REGW__ SR2;                   /* power status register 2 */
	__REGW__ SCR;                   /* power status clear register */
	__REGW__ PUCRA;                 /* power porta A pull-up control register */
	__REGW__ PDCRA;                 /* power porta A pull-down control register */
	__REGW__ PUCRB;                 /* power porta B pull-up control register */
	__REGW__ PDCRB;                 /* power porta B pull-down control register */
	__REGW__ PUCRC;                 /* power porta C pull-up control register */
	__REGW__ PDCRC;                 /* power porta C pull-down control register */
	__REGW__ PUCRD;                 /* power porta D pull-up control register */
	__REGW__ PDCRD;                 /* power porta D pull-down control register */
	__REGW__ PUCRE;                 /* power porta E pull-up control register */
	__REGW__ PDCRE;                 /* power porta E pull-down control register */
	__REGW__ PUCRF;                 /* power porta F pull-up control register */
	__REGW__ PDCRF;                 /* power porta F pull-down control register */
	};

struct __pwr__ PWR	@0x40007000;

/*	RCC section
 */
struct __rcc__ {
	__REGW__ CR;                    /* clock control register */
	__REGW__ ICSCR;                 /* internal clock source calibration register */
	__REGW__ CFGR;                  /* clock configuration register */
	__REGW__ PLLCFGR;               /* pll configuration register */
	__REGW__ reserved_0[2];            
	__REGW__ CIER;                  /* clock interrupt enable register */
	__REGW__ CIFR;                  /* clock interrupt flag register */
	__REGW__ CICR;                  /* clock interrupt clear register */
	__REGW__ IOPRSTR;               /* io port reset register */
	__REGW__ AHBRSTR;               /* AHB peripheral reset register */
	__REGW__ APBRSTR1;              /* APB peripheral reset register 1 */
	__REGW__ APBRSTR2;              /* APB peripheral reset register 2 */
	__REGW__ IOPENR;                /* io port clock enable register */
	__REGW__ AHBENR;                /* AHB peripheral clock enable register */
	__REGW__ APBENR1;               /* APB peripheral clock enable register 1 */
	__REGW__ APBENR2;               /* APB peripheral clock enable register 2 */
	__REGW__ IOPSMENR;              /* io port sleep mode clock enable register */
	__REGW__ AHBSMENR;              /* AHB peripheral sleep mode clock enable register */
	__REGW__ APBSMENR1;             /* APB peripheral sleep mode clock enable register 1 */
	__REGW__ APBSMENR2;             /* APB peripheral sleep mode clock enable register 2 */
	__REGW__ CCIPR;                 /* peripheral independent clock configuration register */
	__REGW__ CCIPR2;                /* peripheral independent clock configuration 2 */
	__REGW__ BDCR;                  /* rtc domain control register */
	__REGW__ CSR;                   /* control/status register */
	};

struct __rcc__ RCC	@0x40021000;

/*	RTC section
 */
struct __rtc__ {
	__REGW__ TR;                    /* time register */
	__REGW__ DR;                    /* date register */
	__REGW__ SSR;                   /* sub second register */
	__REGW__ ICSR;                  /* initialization control and status register */
	__REGW__ PRER;                  /* prescale register */
	__REGW__ WUTR;                  /* wakeup timer register */
	__REGW__ CR;                    /* control register */
	__REGW__ reserved_0[2];            
	__REGW__ WPR;                   /* write protection register */
	__REGW__ CALR;                  /* calibration register */
	__REGW__ SHIFTR;                /* shift control register */
	__REGW__ TSTR;                  /* timestamp time register */
	__REGW__ TSDR;                  /* timestamp date register */
	__REGW__ TSSSR;                 /* timestamp sub second register */
	__REGW__ reserved_1;            
	__REGW__ ALRMAR;                /* alarm A register */
	__REGW__ ALRMASSR;              /* alarm A sub second register */
	__REGW__ ALRMBR;                /* alarm B register */
	__REGW__ ALRMBSSR;              /* alarm B sub second register */
	__REGW__ SR;                    /* status register */
	__REGW__ MISR;                  /* masked interrupt register */
	__REGW__ reserved_2;            
	__REGW__ SCR;                   /* status clear register */
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
struct __spi__ SPI3	@0x40003C00;

/*	TAMP section
 */
struct __tamp__ {
	__REGW__ CR1;                   /* control register 1 */
	__REGW__ CR2;                   /* control register 2 */
	__REGW__ FLTCR;                 /* filter control register */
	__REGW__ IER;                   /* interrupt enabke register */
	__REGW__ SR;                    /* status register */
	__REGW__ MISR;                  /* maked interrupt status register */
	__REGW__ SCR;                   /* status clear register */
	__REGW__ reserved_0[48];            
	__REGW__ BKP0R;                 /* backup register 0 */
	__REGW__ BKP1R;                 /* backup register 1 */
	__REGW__ BKP2R;                 /* backup register 2 */
	__REGW__ BKP3R;                 /* backup register 3 */
	__REGW__ BKP4R;                 /* backup register 4 */
	};

struct __tamp__ TAMP	@0x4000B000;

/*	TIM section
 */
struct __tim__ {
	__REGW__ CR1;                   /* control register 1 */
	__REGW__ CR2;                   /* control register 2 */
	__REGW__ SMCR;                  /* slave mode control register */
	__REGW__ DIER;                  /* DMA/interrupt enable register */
	__REGW__ SR;                    /* status register */
	__REGW__ EGR;                   /* event generation register */
	__REGW__ CCMR1;                 /* capture/compare mode register 1 */
	__REGW__ CCMR2;                 /* capture/compare mode register 2 */
	__REGW__ CCER;                  /* capture/compare enable register */
	__REGW__ CNT;                   /* counter register */
	__REGW__ PSC;                   /* prescaler register */
	__REGW__ ARR;                   /* auto-reload register */
	__REGW__ reserved_0;
	__REGW__ CCR1;                  /* capture/compare register 1 */
	__REGW__ CCR2;                  /* capture/compare register 2 */
	__REGW__ CCR3;                  /* capture/compare register 3 */
	__REGW__ CCR4;                  /* capture/compare register 4 */
	__REGW__ reserved_1;
	__REGW__ DCR;                   /* DMA control register */
	__REGW__ DMAR;                  /* DMA address for full transfer */
	__REGW__ OR1;                   /* option register 1 */
	__REGW__ reserved_2[3];
	__REGW__ AF1;                   /* alternate function option register 1 */
	__REGW__ reserved_3;
	__REGW__ TISEL;                 /* timer input selection register */
	};

struct __tim__ TIM1	@0x40012C00;
struct __tim__ TIM3	@0x40000400;
struct __tim__ TIM4	@0x40000800;
struct __tim__ TIM6	@0x40001000;
struct __tim__ TIM7	@0x40001400;
struct __tim__ TIM14	@0x40002000;
struct __tim__ TIM15	@0x40014000;
struct __tim__ TIM16	@0x40014400;
struct __tim__ TIM17	@0x40014800;

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
	__REGH__ PRESC;                 /* prescaler register */
	__REGH__ reserved_6;            
	};

struct __usart__ USART1	@0x40013800;
struct __usart__ USART2	@0x40004400;
struct __usart__ USART3	@0x40004800;
struct __usart__ USART4	@0x40004C00;
struct __usart__ USART5	@0x40005000;
struct __usart__ USART6	@0x40013C00;

/*	USB section
 */
struct __usb__ {
	__REGW__ CHEP0R;                /* channel endpoint register 0 */
	__REGW__ CHEP1R;                /* channel endpoint register 1 */
	__REGW__ CHEP2R;                /* channel endpoint register 2 */
	__REGW__ CHEP3R;                /* channel endpoint register 3 */
	__REGW__ CHEP4R;                /* channel endpoint register 4 */
	__REGW__ CHEP5R;                /* channel endpoint register 5 */
	__REGW__ CHEP6R;                /* channel endpoint register 6 */
	__REGW__ CHEP7R;                /* channel endpoint register 7 */
	__REGW__ reserved_0[8];
	__REGW__ CNTR;                  /* control register */
	__REGW__ ISTR;                  /* interrupt status register */
	__REGW__ FNR;                   /* frame number register */
	__REGW__ DADDR;                 /* device address register */
	__REGW__ LPMCSR;                /* lpm control/status register */
	__REGW__ BCDR;                  /* battery charging detector register */
	};

struct __usb__ USB	@0x40005C00;

/*	WWDG section
 */
struct __wwdg__ {
	__REGW__ CR;                    /* Control register */
	__REGW__ CFR;                   /* Configuration register */
	__REGW__ SR;                    /* Status register */
	};

struct __wwdg__ WWDG	@0x40002c00;

