/*	IO DEFINITIONS FOR STM32F2xx
 *	Copyright (c) 2011 by COSMIC SOftware
 */
typedef volatile unsigned char __REGB__;
typedef volatile unsigned short __REGH__;
typedef volatile unsigned int __REGW__;

/*	ADC section 
 */
struct __adc__ {
	__REGW__ SR;                    /* status register */
	__REGW__ CR1;                   /* control register 1 */      
	__REGW__ CR2;                   /* control register 2 */
	__REGW__ SMPR1;                 /* sample time register 1 */
	__REGW__ SMPR2;                 /* sample time register 2 */
	__REGW__ JOFR1;                 /* injected channel data offset reg 1 */
	__REGW__ JOFR2;                 /* injected channel data offset reg 2 */
	__REGW__ JOFR3;                 /* injected channel data offset reg 3 */
	__REGW__ JOFR4;                 /* injected channel data offset reg 4 */
	__REGW__ HTR;                   /* watchdog higher threshold register */
	__REGW__ LTR;                   /* watchdog lower threshold register */
	__REGW__ SQR1;                  /* regular sequence register 1 */
	__REGW__ SQR2;                  /* regular sequence register 2 */
	__REGW__ SQR3;                  /* regular sequence register 3 */
	__REGW__ JSQR;                  /* injected sequence register */
	__REGW__ JDR1;                  /* injected data register 1 */
	__REGW__ JDR2;                  /* injected data register 2 */
	__REGW__ JDR3;                  /* injected data register 3 */
	__REGW__ JDR4;                  /* injected data register 4 */
	__REGW__ DR;                    /* regular data register */
	};

struct __adc__ ADC1	@0x40012000;
struct __adc__ ADC2	@0x40012100;
struct __adc__ ADC3	@0x40012200;

struct __adcc__ {
	__REGW__ CSR;                   /* common status register */
	__REGW__ CCR;                   /* common control register */
	__REGW__ CDR;                   /* common data reg dual/triple modes */
	};

struct __adcc__ ADC	@0x40012300;

/*	CAN section
 */
struct __cantmb__ {
	__REGW__ TIR;                   /* TX mailbox identifier register */
	__REGW__ TDTR;                  /* data length and time stamp reg */
	__REGW__ TDLR;                  /* data low register */
	__REGW__ TDHR;                  /* data high register */
	};

struct __canfmb__ {
	__REGW__ RIR;                   /* RX FIFO mailbox identifier reg */
	__REGW__ RDTR;                  /* data length  and time stamp reg */
	__REGW__ RDLR;                  /* data low register */
	__REGW__ RDHR;                  /* data high register */
	};

struct __canfr__ {
	__REGW__ FR1;                   /* Filter bank register 1 */
	__REGW__ FR2;                   /* Filter bank register 2 */
	};

struct __can__
	{
	__REGW__  MCR;                  /* master control register */
	__REGW__  MSR;                  /* master status register */
	__REGW__  TSR;                  /* transmit status register */
	__REGW__  RF0R;                 /* receive FIFO 0 register */
	__REGW__  RF1R;                 /* receive FIFO 1 register */
	__REGW__  IER;                  /* interrupt enable register */
	__REGW__  ESR;                  /* error status register */
	__REGW__  BTR;                  /* bit timing register */
	__REGW__  reserved_0[88];
	struct __cantmb__ sTxMailBox[3];   /* Tx MailBox */
	struct __canfmb__ sFIFOMailBox[2]; /* FIFO MailBox */
	__REGW__  reserved_1[12];
	__REGW__  FMR;                  /* filter master register */
	__REGW__  FM1R;                 /* filter mode register */
	__REGW__  reserved_2;
	__REGW__  FS1R;                 /* filter scale register */
	__REGW__  reserved_3;
	__REGW__  FFA1R;                /* filter FIFO assignment register */
	__REGW__  reserved_4;
	__REGW__  FA1R;                 /* filter activation register */
	__REGW__  reserved_5[8];
	struct __canfr__ sFilterRegister[28]; /* Filter Register */
	};

struct __can__ CAN1	@0x40006400;
struct __can__ CAN2	@0x40006800;

/*	CRC section
 */
struct __crc__ {
	__REGW__ DR;                    /* Data register */
	__REGB__ IDR;                   /* Independent data register */
	__REGB__ reserved_0;
	__REGH__ reserved_1;
	__REGW__ CR;                    /* Control register */
	};

struct __crc__ CRC	@0x40003000;

/*	DAC section
 */
struct __dac__ {
	__REGW__ CR;                    /* control register */
	__REGW__ SWTRIGR;               /* software trigger register */
	__REGW__ DHR12R1;               /* chan 1 12-bit right align data reg */
	__REGW__ DHR12L1;               /* chan 1 12-bit left align data reg */
	__REGW__ DHR8R1;                /* chan 1 8-bit right align data reg */
	__REGW__ DHR12R2;               /* chan 2 12-bit right align data reg */
	__REGW__ DHR12L2;               /* chan 2 12-bit left align data reg */
	__REGW__ DHR8R2;                /* chan 2 8-bit right align data reg */
	__REGW__ DHR12RD;               /*l DAC 12-bit right align reg */
	__REGW__ DHR12LD;               /*L DAC 12-bit left align data reg */
	__REGW__ DHR8RD;                /*L DAC 8-bit right align data reg */
	__REGW__ DOR1;                  /* chan 1 data output register */
	__REGW__ DOR2;                  /* chan 2 data output register */
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

struct __dbgmcu__ DBGMCU	@0xe0042000;

/*	DCMI section
 */
struct __dcmi__{
	__REGW__ CR;                    /* control register 1 */
	__REGW__ SR;                    /* status register */
	__REGW__ RISR;                  /* raw interrupt status register */
	__REGW__ IER;                   /* interrupt enable register */
	__REGW__ MISR;                  /* masked interrupt status register */
	__REGW__ ICR;                   /* interrupt clear register */
	__REGW__ ESCR;                  /* embedded synchronization code register */
	__REGW__ ESUR;                  /* embedded synchronization unmask register */
	__REGW__ CWSTRTR;               /* crop window start */
	__REGW__ CWSIZER;               /* crop window size */
	__REGW__ DR;                    /* data register */
	};

struct __dcmi__ DCMI	@0x50050000;

/*	DMA section
 */
struct __dmas__ {
	__REGW__ CR;                    /* configuration register */
	__REGW__ NDTR;                  /* number of data register */
	__REGW__ PAR;                   /* peripheral address register */
	__REGW__ M0AR;                  /* memory 0 address register */
	__REGW__ M1AR;                  /* memory 1 address register */
	__REGW__ FCR;                   /* FIFO control register */
	};

struct __dma__{
	__REGW__ LISR;                  /* low interrupt status register*/
	__REGW__ HISR;                  /* high interrupt status register */
	__REGW__ LIFCR;                 /* low interrupt flag clear register */
	__REGW__ HIFCR;                 /* high interrupt flag clear register */
	};

struct __dma__  DMA1		@0x40026000;
struct __dmas__ DMA1_Stream0	@0x40026010;
struct __dmas__ DMA1_Stream1	@0x40026028;
struct __dmas__ DMA1_Stream2	@0x40026040;
struct __dmas__ DMA1_Stream3	@0x40026058;
struct __dmas__ DMA1_Stream4	@0x40026070;
struct __dmas__ DMA1_Stream5	@0x40026088;
struct __dmas__ DMA1_Stream6	@0x400260A0;
struct __dmas__ DMA1_Stream7	@0x400260B8;
struct __dma__  DMA2            @0x40026400;
struct __dmas__ DMA2_Stream0	@0x40026410;
struct __dmas__ DMA2_Stream1	@0x40026428;
struct __dmas__ DMA2_Stream2	@0x40026440;
struct __dmas__ DMA2_Stream3	@0x40026458;
struct __dmas__ DMA2_Stream4	@0x40026470;
struct __dmas__ DMA2_Stream5	@0x40026488;
struct __dmas__ DMA2_Stream6	@0x400264A0;
struct __dmas__ DMA2_Stream7	@0x400264B8;

/*	ETHERNET section
 */
struct __eth__ {
	__REGW__ MACCR;
	__REGW__ MACFFR;
	__REGW__ MACHTHR;
	__REGW__ MACHTLR;
	__REGW__ MACMIIAR;
	__REGW__ MACMIIDR;
	__REGW__ MACFCR;
	__REGW__ MACVLANTR;
	__REGW__ reserved_0[2];
	__REGW__ MACRWUFFR;
	__REGW__ MACPMTCSR;
	__REGW__ reserved_1[2];
	__REGW__ MACSR;
	__REGW__ MACIMR;
	__REGW__ MACA0HR;
	__REGW__ MACA0LR;
	__REGW__ MACA1HR;
	__REGW__ MACA1LR;
	__REGW__ MACA2HR;
	__REGW__ MACA2LR;
	__REGW__ MACA3HR;
	__REGW__ MACA3LR;
	__REGW__ reserved_2[40];
	__REGW__ MMCCR;
	__REGW__ MMCRIR;
	__REGW__ MMCTIR;
	__REGW__ MMCRIMR;
	__REGW__ MMCTIMR;
	__REGW__ reserved_3[14];
	__REGW__ MMCTGFSCCR;
	__REGW__ MMCTGFMSCCR;
	__REGW__ reserved_4[5];
	__REGW__ MMCTGFCR;
	__REGW__ reserved_5[10];
	__REGW__ MMCRFCECR;
	__REGW__ MMCRFAECR;
	__REGW__ reserved_6[10];
	__REGW__ MMCRGUFCR;
	__REGW__ reserved_7[334];
	__REGW__ PTPTSCR;
	__REGW__ PTPSSIR;
	__REGW__ PTPTSHR;
	__REGW__ PTPTSLR;
	__REGW__ PTPTSHUR;
	__REGW__ PTPTSLUR;
	__REGW__ PTPTSAR;
	__REGW__ PTPTTHR;
	__REGW__ PTPTTLR;
	__REGW__ reserved_8;
	__REGW__ PTPTSSR;
	__REGW__ reserved_9[565];
	__REGW__ DMABMR;
	__REGW__ DMATPDR;
	__REGW__ DMARPDR;
	__REGW__ DMARDLAR;
	__REGW__ DMATDLAR;
	__REGW__ DMASR;
	__REGW__ DMAOMR;
	__REGW__ DMAIER;
	__REGW__ DMAMFBOCR;
	__REGW__ DMARSWTR;
	__REGW__ reserved_10[8];
	__REGW__ DMACHTDR;
	__REGW__ DMACHRDR;
	__REGW__ DMACHTBAR;
	__REGW__ DMACHRBAR;
	};

struct __eth__ ETH	@0x40028000;


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

struct __exti__ EXTI	@0x40013c00;

/*	FLASH section
 */
struct __flash__ {
	__REGW__ ACR;                   /* access control register */
	__REGW__ KEYR;                  /* key register */
	__REGW__ OPTKEYR;               /* option key register */
	__REGW__ SR;                    /* status register */
	__REGW__ CR;                    /* control register */
	__REGW__ OPTCR;                 /* option control register */
	};

struct __flash__ FLASH	@0x40023c00;
 
/*	FSMC section
 */
struct __fsmcb1__
	{
	__REGW__ BTCR[8];               /* chip select control/timing reg */   
	}; 

struct __fsmc1e__ {
	__REGW__ BWTR[7];               /* write timing registers */
	};

struct __fsmcb2__ {
	__REGW__ PCR2;                  /* Flash control register */
	__REGW__ SR2;                   /* Flash FIFO status and interrupt reg */
	__REGW__ PMEM2;                 /* Flash Common memory timing reg */
	__REGW__ PATT2;                 /* Flash Attribute memory timing reg */
	__REGW__ reserved_0;             
	__REGW__ ECCR2;                 /* Flash ECC result registers */
	};

struct __fsmcb3__ {
	__REGW__ PCR3;                  /* Flash control register */
	__REGW__ SR3;                   /* Flash FIFO status and interrupt reg */
	__REGW__ PMEM3;                 /* Flash Common memory timing reg */
	__REGW__ PATT3;                 /* Flash Attribute memory timing reg */
	__REGW__ reserved_0;
	__REGW__ ECCR3;                 /* Flash ECC result registers */
	};

struct __fsmcb4__ {
	__REGW__ PCR4;                  /* control register */
	__REGW__ SR4;                   /* FIFO status and interrupt reg */
	__REGW__ PMEM4;                 /* Common memory space timing reg */
	__REGW__ PATT4;                 /* Attribute memory space timing reg */
	__REGW__ PIO4;                  /* I/O space timing register */
	}; 

struct __fsmcb1__ FSMC_Bank1	@0xa0000000;
struct __fsmcb1e__ FSMC_Bank1E	@0xa0000104;
struct __fsmcb2__ FSMC_Bank2	@0xa0000060;
struct __fsmcb3__ FSMC_Bank3	@0xa0000080;
struct __fsmcb4__ FSMC_Bank4	@0xa00000a0;

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
	__REGW__ AFR[2];                /* alternate function registers, */
	};

struct __gpio__ GPIOA	@0x40020000;
struct __gpio__ GPIOB	@0x40020400;
struct __gpio__ GPIOC	@0x40020800;
struct __gpio__ GPIOD	@0x40020c00;
struct __gpio__ GPIOE	@0x40021000;
struct __gpio__ GPIOF	@0x40021400;
struct __gpio__ GPIOG	@0x40021800;
struct __gpio__ GPIOH	@0x40021c00;
struct __gpio__ GPIOI	@0x40022000;

/*	SYSCFG section
 */
struct __syscfg__ {
	__REGW__ MEMRMP;                /* memory remap register */
	__REGW__ PMC;                   /* peripheral mode config register */
	__REGW__ EXTICR[4];             /* external interrupt config regs */
	__REGW__ reserved_0[2];          
	__REGW__ CMPCR;                 /* Compensation cell control register */
	};

struct __syscfg__ SYSCFG	@0x40013800;

/*	I2C section
 */
struct __i2c__ {
	__REGH__ CR1;                   /* Control register 1*/
	__REGH__ reserved_0;             
	__REGH__ CR2;                   /* Control register 2 */
	__REGH__ reserved_1;             
	__REGH__ OAR1;                  /* Own address register 1 */
	__REGH__ reserved_2;             
	__REGH__ OAR2;                  /* Own address register 2 */
	__REGH__ reserved_3;             
	__REGH__ DR;                    /* Data register */
	__REGH__ reserved_4;             
	__REGH__ SR1;                   /* Status register 1 */
	__REGH__ reserved_5;             
	__REGH__ SR2;                   /* Status register 2 */
	__REGH__ reserved_6;             
	__REGH__ CCR;                   /* Clock control register */
	__REGH__ reserved_7;             
	__REGH__ TRISE;                 /* TRISE register */
	__REGH__ reserved_8;
	};

struct __i2c__ I2C1	@0x40005400;
struct __i2c__ I2C2	@0x40005800;
struct __i2c__ I2C3	@0x40005c00;

/*	IWDG section
 */
struct __iwdg__ {
	__REGW__ KR;                    /* Key register */
	__REGW__ PR;                    /* Prescaler register */
	__REGW__ RLR;                   /* Reload register */
	__REGW__ SR;                    /* Status register */
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
	__REGW__ CR;                    /* clock control register */
	__REGW__ PLLCFGR;               /* PLL configuration register */
	__REGW__ CFGR;                  /* clock configuration register */
	__REGW__ CIR;                   /* clock interrupt register */
	__REGW__ AHB1RSTR;              /* AHB1 peripheral reset register */
	__REGW__ AHB2RSTR;              /* AHB2 peripheral reset register */
	__REGW__ AHB3RSTR;              /* AHB3 peripheral reset register */
	__REGW__ reserved_0;            
	__REGW__ APB1RSTR;              /* APB1 peripheral reset register */
	__REGW__ APB2RSTR;              /* APB2 peripheral reset register */
	__REGW__ reserved_1[2];         
	__REGW__ AHB1ENR;               /* AHB1 peripheral clock register */
	__REGW__ AHB2ENR;               /* AHB2 peripheral clock register */
	__REGW__ AHB3ENR;               /* AHB3 peripheral clock register */
	__REGW__ reserved_2;            
	__REGW__ APB1ENR;               /* APB1 peripheral clock enable register */
	__REGW__ APB2ENR;               /* APB2 peripheral clock enable register */
	__REGW__ reserved_3[2];         
	__REGW__ AHB1LPENR;             /* AHB1 peripheral clock enable in low power mode register */
	__REGW__ AHB2LPENR;             /* AHB2 peripheral clock enable in low power mode register */
	__REGW__ AHB3LPENR;             /* AHB3 peripheral clock enable in low power mode register */
	__REGW__ reserved_4;            
	__REGW__ APB1LPENR;             /* APB1 peripheral clock enable in low power mode register */
	__REGW__ APB2LPENR;             /* APB2 peripheral clock enable in low power mode register */
	__REGW__ reserved_5[2];         
	__REGW__ BDCR;                  /* Backup domain control register */
	__REGW__ CSR;                   /* clock control & status register */
	__REGW__ reserved_6[2];         
	__REGW__ SSCGR;                 /* spread spectrum clock generation register */
	__REGW__ PLLI2SCFGR;            /* PLLI2S configuration register */
	};

struct __rcc__ RCC	@0x40023800;

/*	RTC section
 */
struct __rtc__ {
	__REGW__ TR;                    /* time register */
	__REGW__ DR;                    /* date register */
	__REGW__ CR;                    /* control register */
	__REGW__ ISR;                   /* initialization and status register */
	__REGW__ PRER;                  /* prescaler register */
	__REGW__ WUTR;                  /* wakeup timer register */
	__REGW__ CALIBR;                /* calibration register */
	__REGW__ ALRMAR;                /* alarm A register */
	__REGW__ ALRMBR;                /* alarm B register */
	__REGW__ WPR;                   /* write protection register4 */
	__REGW__ reserved_1;
	__REGW__ reserved_2;
	__REGW__ TSTR;                  /*C time stamp time register */
	__REGW__ TSDR;                  /*C time stamp date register */
	__REGW__ reserved_3;
	__REGW__ reserved_4;
	__REGW__ TAFCR;                 /* tamper/alt function config reg */
	__REGW__ reserved_5;
	__REGW__ reserved_6;
	__REGW__ reserved_7;
	__REGW__ BKP0R;                 /* backup register 0 */
	__REGW__ BKP1R;                 /* backup register 1 */
	__REGW__ BKP2R;                 /* backup register 2 */
	__REGW__ BKP3R;                 /* backup register 3 */
	__REGW__ BKP4R;                 /* backup register 4 */
	__REGW__ BKP5R;                 /* backup register 5 */
	__REGW__ BKP6R;                 /* backup register 6 */
	__REGW__ BKP7R;                 /* backup register 7 */
	__REGW__ BKP8R;                 /* backup register 8 */
	__REGW__ BKP9R;                 /* backup register 9 */
	__REGW__ BKP10R;                /* backup register 10 */
	__REGW__ BKP11R;                /* backup register 11 */
	__REGW__ BKP12R;                /* backup register 12 */
	__REGW__ BKP13R;                /* backup register 13 */
	__REGW__ BKP14R;                /* backup register 14 */
	__REGW__ BKP15R;                /* backup register 15 */
	__REGW__ BKP16R;                /* backup register 16 */
	__REGW__ BKP17R;                /* backup register 17 */
	__REGW__ BKP18R;                /* backup register 18 */
	__REGW__ BKP19R;                /* backup register 19 */
	};

struct __rtc__ RTC	@0x40002800;

/*	SDIO section
 */
struct __sdio__ {
	__REGW__ POWER;                 /* power control register */
	__REGW__ CLKCR;                 /* clock control register */
	__REGW__ ARG;                   /* argument register */
	__REGW__ CMD;                   /* command register */
	__REGW__ RESPCMD;               /* command response register */
	__REGW__ RESP1;                 /* response 1 register */
	__REGW__ RESP2;                 /* response 2 register */
	__REGW__ RESP3;                 /* response 3 register */
	__REGW__ RESP4;                 /* response 4 register */
	__REGW__ DTIMER;                /* data timer register */
	__REGW__ DLEN;                  /* data length register */
	__REGW__ DCTRL;                 /* data control registerC */
	__REGW__ DCOUNT;                /* data counter register0 */
	__REGW__ STA;                   /* status register */
	__REGW__ ICR;                   /* interrupt clear register */
	__REGW__ MASK;                  /* mask register */
	__REGW__ reserved_0[2];         
	__REGW__ FIFOCNT;               /* FIFO counter register */
	__REGW__ reserved_1[13];        
	__REGW__ FIFO;                  /* data FIFO register */
	};

struct __sdio__ SDIO	@0x40012c00;

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
struct __spi__ SPI3	@0x40003c00;

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
	__REGW__ ARR;                   /* auto-reload register */
	__REGH__ RCR;                   /* repetition counter register */
	__REGH__ reserved_10;           
	__REGW__ CCR1;                  /* capture/compare register 1 */
	__REGW__ CCR2;                  /* capture/compare register 2 */
	__REGW__ CCR3;                  /* capture/compare register 3 */
	__REGW__ CCR4;                  /* capture/compare register 4 */
	__REGH__ BDTR;                  /* break and dead-time register */
	__REGH__ reserved_11;           
	__REGH__ DCR;                   /* DMA control register */
	__REGH__ reserved_12;           
	__REGH__ DMAR;                  /* DMA address for full transfer */
	__REGH__ reserved_13;           
	__REGH__ OR;                    /* option register */
	__REGH__ reserved_14;
	};

struct __tim__ TIM1	@0x40010000;
struct __tim__ TIM2	@0x40000000;
struct __tim__ TIM3	@0x40000400;
struct __tim__ TIM4	@0x40000800;
struct __tim__ TIM5	@0x40000c00;
struct __tim__ TIM6	@0x40001000;
struct __tim__ TIM7	@0x40001400;
struct __tim__ TIM8	@0x40010400;
struct __tim__ TIM9	@0x40014000;
struct __tim__ TIM10	@0x40014400;
struct __tim__ TIM11	@0x40014800;
struct __tim__ TIM12	@0x40001800;
struct __tim__ TIM13	@0x40001c00;
struct __tim__ TIM14	@0x40002000;

/*	USART section
 */
struct __usart__ {
	__REGH__ SR;                    /* Status register */
	__REGH__ reserved_0;            
	__REGH__ DR;                    /* Data register */
	__REGH__ reserved_1;            
	__REGH__ BRR;                   /* Baud rate register */
	__REGH__ reserved_2;            
	__REGH__ CR1;                   /* Control register 1 */
	__REGH__ reserved_3;            
	__REGH__ CR2;                   /* Control register 2 */
	__REGH__ reserved_4;            
	__REGH__ CR3;                   /* Control register 3 */
	__REGH__ reserved_5;            
	__REGH__ GTPR;                  /* Guard time and prescaler register */
	__REGH__ reserved_6;
	};

struct __usart__ USART1	@0x40011000;
struct __usart__ USART2	@0x40004400;
struct __usart__ USART3	@0x40004800;
struct __usart__ USART4	@0x40004c00;
struct __usart__ USART5	@0x40005000;
struct __usart__ USART6	@0x40011400;

/*	WWDG section
 */
struct __wwdg__ {
	__REGW__ CR;                    /* Control register */
	__REGW__ CFR;                   /* Configuration register */
	__REGW__ SR;                    /* Status register */
	};

struct __wwdg__ WWDG	@0x40002c00;

/*	CRYP section
 */
struct __cryp__ {
	__REGW__ CR;                    /* control register */
	__REGW__ SR;                    /* status register */
	__REGW__ DR;                    /* data input register */
	__REGW__ DOUT;                  /* data output register */
	__REGW__ DMACR;                 /* DMA control register */
	__REGW__ IMSCR;                 /* interrupt mask set/clear register */
	__REGW__ RISR;                  /* raw interrupt status register */
	__REGW__ MISR;                  /* masked interrupt status register */
	__REGW__ K0LR;                  /* key left  register 0 */
	__REGW__ K0RR;                  /* key right register 0 */
	__REGW__ K1LR;                  /* key left  register 1 */
	__REGW__ K1RR;                  /* key right register 1 */
	__REGW__ K2LR;                  /* key left  register 2 */
	__REGW__ K2RR;                  /* key right register 2 */
	__REGW__ K3LR;                  /* key left  register 3 */
	__REGW__ K3RR;                  /* key right register 3 */
	__REGW__ IV0LR;                 /* init vector left-word  register 0 */
	__REGW__ IV0RR;                 /* init vector right-word register 0 */
	__REGW__ IV1LR;                 /* init vector left-word  register 1 */
	__REGW__ IV1RR;                 /* init vector right-word register 1 */
	};

struct __cryp__ CRYP	@0x50060000;

/*	HASH section
 */
struct __hash__ {
	__REGW__ CR;                    /* control register */
	__REGW__ DIN;                   /* data input register */
	__REGW__ STR;                   /* start register */
	__REGW__ HR[5];                 /* digest registers */
	__REGW__ IMR;                   /* interrupt enable register */
	__REGW__ SR;                    /* status register */
	__REGW__ reserved_0[52];
	__REGW__ CSR[51];               /* context swap registers */  
	};

struct __hash__ HASH	@0x50060400;
  
/*	RNG section
 */
struct __rng__ {
	__REGW__ CR;  /* control register */
	__REGW__ SR;  /* status register */
	__REGW__ DR;  /* data register */
	};

struct __rng__ RNG	@0x50060800;
