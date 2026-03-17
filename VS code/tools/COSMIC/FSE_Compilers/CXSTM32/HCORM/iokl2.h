/*	IO DEFINITIONS FOR KINETICS KL2
 *	Copyright (c) 2012 by COSMIC SOftware
 */
typedef volatile unsigned char __REGB__;
typedef volatile unsigned short __REGH__;
typedef volatile unsigned int __REGW__;

/*	ADC section
 */
struct __adc__ {
	__REGW__ SC1[2];                /* status and control registers 1 */
	__REGW__ CFG1;                  /* configuration register 1 */
	__REGW__ CFG2;                  /* configuration register 2 */
	__REGW__ R[2];                  /* data result register */
	__REGW__ CV1;                   /* compare value register 1 */
	__REGW__ CV2;                   /* compare value register 2 */
	__REGW__ SC2;                   /* status and control register 2 */
	__REGW__ SC3;                   /* status and control register 3 */
	__REGW__ OFS;                   /* offset correction register */
	__REGW__ PG;                    /* plus gain register */
	__REGW__ reserved_0;
	__REGW__ CLPD;                  /* plus calibration value register */
	__REGW__ CLPS;                  /* plus calibration value register */
	__REGW__ CLP4;                  /* plus calibration value register */
	__REGW__ CLP3;                  /* plus calibration value register */
	__REGW__ CLP2;                  /* plus calibration value register */
	__REGW__ CLP1;                  /* plus calibration value register */
	__REGW__ CLP0;                  /* plus calibration value register */
	};

struct __adc__ ADC0	@0x4003B000;

/*	BP section
 */
struct __bp__ {
	__REGW__ CTRL;                  /* Control Register */
 	__REGW__ COMP[2];               /* Comparator Registers */
	__REGW__ reserved_0[1008];
	__REGW__ PID4;                  /* Peripheral Identification Reg 4 */
	__REGW__ PID5;                  /* Peripheral Identification Reg 5 */
	__REGW__ PID6;                  /* Peripheral Identification Reg 6 */
	__REGW__ PID7;                  /* Peripheral Identification Reg 7 */
	__REGW__ PID0;                  /* Peripheral Identification Reg 0 */
	__REGW__ PID1;                  /* Peripheral Identification Reg 1 */
	__REGW__ PID2;                  /* Peripheral Identification Reg 2 */
	__REGW__ PID3;                  /* Peripheral Identification Reg 3 */
	__REGW__ CID0;                  /* Component Identification Reg 0 */
	__REGW__ CID1;                  /* Component Identification Reg 1 */
	__REGW__ CID2;                  /* Component Identification Reg 2 */
	__REGW__ CID3;                  /* Component Identification Reg 3 */
	};

struct __bp__ BP	@0xE0002000;

/*	CMP section
 */
struct __cmp__ {
	__REGB__ CR0;                   /* Control Register 0 */
	__REGB__ CR1;                   /* Control Register 1 */
	__REGB__ FPR;                   /* Filter Period Register */
	__REGB__ SCR;                   /* Status and Control Register */
	__REGB__ DACCR;                 /* DAC Control Register */
	__REGB__ MUXCR;                 /* MUX Control Register */
	};

struct __cmp__ CMP0	@0x40073000;

/*	CDB section
 */
struct __cdb__ {
	union {
	    __REGW__ base_DHCSR_Read;   /* Debug Halting ctrl/stat register */
	    __REGW__ base_DHCSR_Write;  /* Debug Halting ctrl/stat register */
	    };
	__REGW__ base_DCRSR;            /* Debug Core Selector Register */
	__REGW__ base_DCRDR;            /* Debug Core Data Register */
	__REGW__ base_DEMCR;            /* Debug Exception/Monitor Ctrl Reg */
	};

struct __cdb__ CoreDebug	@0xE000EDF0;

/*	DAC section
 */
struct __dac__ {
	struct {
		__REGB__ DATL;          /* Data Register Low */
		__REGB__ DATH;          /* Data Register High */
		} DAT[2];
	__REGW__ reserved_0[7];
	__REGB__ SR;                    /* Status Register */
	__REGB__ C0;                    /* Control Register */
	__REGB__ C1;                    /* Control Register 1 */
	__REGB__ C2;                    /* Control Register 2 */
	};

struct __dac__ DAC0	@0x4003F000;

/*	DMA section
 */
struct __tcd__{
	__REGW__ SAR;                   /* Source Address */
	__REGW__ DAR;                   /* Destination Address */
	union {
		__REGW__ DSR_BCR;       /* Status Reg / Byte Count */
		struct {
			__REGB__ resrved_0[3];
			__REGB__ DSR;   /* Status Byte */
			};
		} DMA_DSR_ACESS8BIT;
	__REGW__ DCR;                   /* Control Register */
	};

struct __dma__ {
	__REGB__ REQC_ARR[4];           /* Request Registers */
	__REGW__ reserved_0[63];
	struct __tcd__ DMA[4];
	};

struct __dma__ DMA	@0x40008000;

/*	DMAMUX section
 */
struct __dmamux__ {
	__REGB__ CHCFG[4];              /* Channel Configuration Register */
	};

struct __dmamux__ DMAMUX @0x40021000;

/*	DWT section
 */
struct __dwt__ {
	__REGW__ CTRL;                  /* Control Register */
	__REGW__ reserved_0[6];
	__REGW__ PCSR;                  /* Program Counter Sample Register*/
	struct {
		__REGW__ COMP;          /* Comparator Register */
		__REGW__ MASK;          /* Mask Register */
		__REGW__ FUNCTION;      /* Function Register */
		__REGW__ reserved_0;
		} COMPARATOR[2];
	};

struct __dwt__ DWT      @0xE0001000;

/*	FGPIO section
 */
struct __fgpio__ {
	__REGW__ PDOR;                   /* Port Data Output Register */
	__REGW__ PSOR;                   /* Port Set Output Register */
	__REGW__ PCOR;                   /* Port Clear Output Register */
	__REGW__ PTOR;                   /* Port Toggle Output Register */
	__REGW__ PDIR;                   /* Port Data Input Register */
	__REGW__ PDDR;                   /* Port Data Direction Register */
	};

struct __fgpio__ FPTA	@0xF80FF000;
struct __fgpio__ FPTB	@0xF80FF040;
struct __fgpio__ FPTC	@0xF80FF080;
struct __fgpio__ FPTD	@0xF80FF0C0;
struct __fgpio__ FPTE	@0xF80FF100;

/*	FTFA section
 */
struct __ftfa__ {
	__REGB__ FSTAT;                  /* Flash Status Register */
	__REGB__ FCNFG;                  /* Flash Configuration Register */
	__REGB__ FSEC;                   /* Flash Security Register */
	__REGB__ FOPT;                   /* Flash Option Register */
	__REGB__ FCCOB3;                 /* Flash Command Register 3 */
	__REGB__ FCCOB2;                 /* Flash Command Register 2 */
	__REGB__ FCCOB1;                 /* Flash Command Register 1 */
	__REGB__ FCCOB0;                 /* Flash Command Register 0 */
	__REGB__ FCCOB7;                 /* Flash Command Register 7 */
	__REGB__ FCCOB6;                 /* Flash Command Register 6 */
	__REGB__ FCCOB5;                 /* Flash Command Register 5 */
	__REGB__ FCCOB4;                 /* Flash Command Register 4 */
	__REGB__ FCCOBB;                 /* Flash Command Register 11 */
	__REGB__ FCCOBA;                 /* Flash Command Register 10 */
	__REGB__ FCCOB9;                 /* Flash Command Register 9 */
	__REGB__ FCCOB8;                 /* Flash Command Register 8 */
	__REGB__ FPROT3;                 /* Program Flash Prot Register 3 */
	__REGB__ FPROT2;                 /* Program Flash Prot Register 2 */
	__REGB__ FPROT1;                 /* Program Flash Prot Register 1 */
	__REGB__ FPROT0;                 /* Program Flash Prot Register 0 */
	};

struct __ftfa__ FTFA	@0x40020000;

/*	GPIO section
 */
struct __gpio__ {
	__REGW__ PDOR;                   /* Port Data Output Register */
	__REGW__ PSOR;                   /* Port Set Output Register */
	__REGW__ PCOR;                   /* Port Clear Output Register */
	__REGW__ PTOR;                   /* Port Toggle Output Register */
	__REGW__ PDIR;                   /* Port Data Input Register */
	__REGW__ PDDR;                   /* Port Data Direction Register */
	};

struct __gpio__ PTA	@0x400FF000;
struct __gpio__ PTB	@0x400FF040;
struct __gpio__ PTC	@0x400FF080;
struct __gpio__ PTD	@0x400FF0C0;
struct __gpio__ PTE	@0x400FF100;

/*	I2C section
 */
struct __i2c__ {
	__REGB__ A1;                    /* Address Register 1 */
	__REGB__ F;                     /* Frequency Divider register */
	__REGB__ C1;                    /* Control Register 1 */
	__REGB__ S;                     /* Status Register */
	__REGB__ D;                     /* Data I/O register */
	__REGB__ C2;                    /* Control Register 2 */
	__REGB__ FLT;                   /* Programmable Input Glitch Filter */
	__REGB__ RA;                    /* Range Address register */
	__REGB__ SMB;                   /* SMBus Control and Status register */
	__REGB__ A2;                    /* Address Register 2 */
	__REGB__ SLTH;                  /* SCL Low Timeout Register High */
	__REGB__ SLTL;                  /* SCL Low Timeout Register Low */
	};

struct __i2c__ I2C0	@0x40066000;
struct __i2c__ I2C1	@0x40067000;

/*	LLWU section
 */
struct __llwu__ {
	__REGB__ PE1;                   /* Pin Enable 1 Register */
	__REGB__ PE2;                   /* Pin Enable 2 Register */
	__REGB__ ME;                    /* Module Enable Register */
	__REGB__ F1;                    /* Flag 1 Register */
	__REGB__ F3;                    /* Flag 3 Register */
	__REGB__ FILT1;                 /* Filter 1 Register */
	__REGB__ FILT2;                 /* Filter 2 Register */
	};

struct __llwu__ LLWU	@0x4007C000;

/*	LPTMR section
 */
struct __lptmr__ {
	__REGW__ CSR;                   /* Control Status Register */
	__REGW__ PSR;                   /* Prescale Register */
	__REGW__ CMR;                   /* Compare Register */
	__REGW__ CNR;                   /* Counter Register */
	};

struct __lptmr__ LPTMR0	@0x40040000;

/*	MCG section
 */
struct __mcg__ {
	__REGB__ C1;                    /* Control Register 1 */
	__REGB__ C2;                    /* Control Register 2 */
	__REGB__ C3;                    /* Control Register 3 */
	__REGB__ C4;                    /* Control Register 4 */
	__REGB__ C5;                    /* Control Register 5 */
	__REGB__ C6;                    /* Control Register 6 */
	__REGB__ S;                     /* Status Register */
	__REGB__ reserved_0;
	__REGB__ SC;                    /* Status / Control Register */
	__REGB__ reserved_1;
	__REGB__ ATCVH;                 /* Auto Trim Compare Value High */
	__REGB__ ATCVL;                 /* Auto Trim Compare Value Low */
	__REGB__ reserved_2;
	__REGB__ C8;                    /* Control Register 8 */
	};

struct __mcg__ MCG	@0x40064000;

/*	MCM section
 */
struct __mcm__ {
	__REGW__ reserved_0[2];
	__REGH__ PLASC;                 /* Crossbar slave configuration */
	__REGH__ PLAMC;                 /* Crossbar master configuration */
	__REGW__ PLACR;                 /* Platform Control Register */
	__REGW__ reserved_1[12];
	__REGW__ CPO;                   /* Compute Operation Control Reg */
	__REGW__ reserved_2[15];
	__REGW__ MATCR[4];              /* Master Attribute Config Regs */
	};

struct __mcm__ MCM	@0xF0003000;

/*	MTB section
 */
struct __mtb__ {
	__REGW__ POSITION;              /* Position Register */
	__REGW__ MASTER;                /* Master Register */
	__REGW__ FLOW;                  /* Flow Register */
	__REGW__ BASE;                  /* Base Register */
	__REGW__ reserved_0[956];
	__REGW__ MODECTRL;              /* Integration Mode Control Register */
	__REGW__ reserved_1[39];
	__REGW__ TAGSET;                /* Claim Tag Set Register */
	__REGW__ TAGCLEAR;              /* Claim Tag Clear Register */
	__REGW__ reserved_2[2];
	__REGW__ LOCKACCESS;            /* Lock Access Register */
	__REGW__ LOCKSTAT;              /* Lock Status Register */
	__REGW__ AUTHSTAT;              /* Authentification Status Register */
	__REGW__ DEVICEARCH;            /* Device Architecture Register */
	__REGW__ reserved_3[2];
	__REGW__ DEVICECFG;             /* Device Configuration Register */
	__REGW__ DEVICETYPID;           /* Device Type Identifier Register */
	__REGW__ PERIPHID[8];           /* Peripheral Identifier Registers */
	__REGW__ COMPID[4];             /* Component Identifier Registers */
	};

struct __mtb__ MTB	@0xF0000000;

/*	MTBDWT section
 */
struct __mtbdwt__ {
	__REGW__ CTRL;                  /* Control Register */
	__REGW__ reserved_0[7];
	struct {
		__REGW__ COMP;          /* Comparator Register */
		__REGW__ MASK;          /* Mask Register */
		__REGW__ FCT;           /* Function Register */
		__REGW__ reserved_0;
		} COMPARATOR[2];
	__REGW__ reserved_1[112];
	__REGW__ TBCTRL;                /* Trace Buffer Control Register */
	__REGW__ reserved_2[881];
	__REGW__ DEVICECFG;             /* Device Configuration Register */
	__REGW__ DEVICETYPID;           /* Device Type Identifier Register */
	__REGW__ PERIPHID[8];           /* Peripheral Identifier Registers */
	__REGW__ COMPID[4];             /* Component Identifier Registers */
	};

struct __mtbdwt__ MTBDWT      @0xF0001000;

/*	NV section
 */
struct __nv__ {
	__REGB__ BACKKEY3;              /* Backdoor Compare on Key 3 */
	__REGB__ BACKKEY2;              /* Backdoor Compare on Key 2 */
	__REGB__ BACKKEY1;              /* Backdoor Compare on Key 1 */
	__REGB__ BACKKEY0;              /* Backdoor Compare on Key 0 */
	__REGB__ BACKKEY7;              /* Backdoor Compare on Key 7 */
	__REGB__ BACKKEY6;              /* Backdoor Compare on Key 6 */
	__REGB__ BACKKEY5;              /* Backdoor Compare on Key 5 */
	__REGB__ BACKKEY4;              /* Backdoor Compare on Key 4 */
	__REGB__ FPROT3;                /* Flash Protection Register 3 */
	__REGB__ FPROT2;                /* Flash Protection Register 2 */
	__REGB__ FPROT1;                /* Flash Protection Register 1 */
	__REGB__ FPROT0;                /* Flash Protection Register 0 */
	__REGB__ FSEC;                  /* Flash Security Register */
	__REGB__ FOPT;                  /* Flash OPtion Register */
	};

struct __nv__ NV      @0x400;

/*	NVIC section
 */
struct __nvic__ {
	__REGW__ ISER;                  /* Interrupt Set Enable Register */
	__REGW__ reserved_0[31];
	__REGW__ ICER;                  /* Interrupt Clear Enable Register */
	__REGW__ reserved_1[31];
	__REGW__ ISPR;                  /* Interrupt Set Pending Register */
	__REGW__ reserved_2[31];
	__REGW__ ICPR;                  /* Interrupt Clear Pending Register */
	__REGW__ reserved_3[95];
	__REGB__ IP[8];                 /* Interrupt Priority Registers */
	};

struct __nvic__ NVIC	@0xE000E100;

/*	OSC section
 */
struct __osc__ {
	__REGB__ CR;                    /* Control Register */
	};

struct __osc__ OSC	@0x40065000;

/*	PIT section
 */
struct __pit__ {
	__REGW__ MCR;                   /* Module Control Register */
	__REGW__ reserved_0[55];
	__REGW__ LTMR64H;               /* Upper Lifetime Timer Register */
	__REGW__ LTMR64L;               /* Lower Lifetime Timer Register */
	__REGW__ reserved_1[6];
	struct {
		__REGW__ LDVAL;         /* Timer Load Value Register */
		__REGW__ CVAL;          /* Current Timer Value Register */
		__REGW__ TCTRL;         /* Timer Control Register */
		__REGW__ TFLG;          /* Timer Flag Register */
		} CHANNEL[2];
	};

struct __pit__ PIT	@0x40037000;

/*	PMC section
 */
struct __pmc__ {
	__REGB__ LVDSC1;                /* Low Voltage Status/Control 1 */
	__REGB__ LVDSC2;                /* Low Voltage Status/Control 2 */
	__REGB__ REGSC;                 /* Regulator Status/Control */
	};

struct __pmc__ PMC	@0x4007D000;

/*	PORT section
 */
struct __port__ {
	__REGW__ PCR[32];               /* Pin Control Registers */
	__REGW__ GPCLR;                 /* Global Pin Control Register Low */
	__REGW__ GPCHR;                 /* Global Pin Control Register High */
	__REGW__ reserved_0[6];
	__REGW__ ISFR;                  /* Interrupt Status Flag Register */
	};

struct __port__ PORTA	@0x40049000;
struct __port__ PORTB	@0x4004A000;
struct __port__ PORTC	@0x4004B000;
struct __port__ PORTD	@0x4004C000;
struct __port__ PORTE	@0x4004D000;

/*	RCM section
 */
struct __rcm__ {
	__REGB__ SRS0;                  /* System Reset Status Register 0 */
	__REGB__ SRS1;                  /* System Reset Status Register 0 */
	__REGH__ reserved_0;
	__REGB__ RPFC;                  /* Reset Pin Filter Control Register */
	__REGB__ RPFW;                  /* Reset Pin Filter Width Register */
	};

struct __rcm__ RCM	@0x4007F000;

/*	ROM section
 */
struct __rom__ {
	__REGW__ ENTRY[3];              /* Entry Array */
	__REGW__ TABLEMARK;             /* End of Table Marker Register */
	__REGW__ reserved_0[1007];
	__REGW__ SYSACCESS;             /* System Access Register */
	__REGW__ PERIPHID4;             /* Peripheral ID Register 4 */
	__REGW__ PERIPHID5;             /* Peripheral ID Register 5 */
	__REGW__ PERIPHID6;             /* Peripheral ID Register 6 */
	__REGW__ PERIPHID7;             /* Peripheral ID Register 7 */
	__REGW__ PERIPHID0;             /* Peripheral ID Register 0 */
	__REGW__ PERIPHID1;             /* Peripheral ID Register 1 */
	__REGW__ PERIPHID2;             /* Peripheral ID Register 2 */
	__REGW__ PERIPHID3;             /* Peripheral ID Register 3 */
	__REGW__ COMPID[4];             /* Component ID Registers */
	};

struct __rom__ ROM	@0xF0002000;

/*	RTC section
 */
struct __rtc__ {
	__REGW__ TSR;                   /* Time Seconds Register */
	__REGW__ TPR;                   /* Time Prescaler Register */
	__REGW__ TAR;                   /* Time Alarm Register */
	__REGW__ TCR;                   /* Time Compensation Register */
	__REGW__ CR;                    /* Control Register */
	__REGW__ SR;                    /* Status Register */
	__REGW__ LR;                    /* Lock Register */
	__REGW__ IER;                   /* Interrupt Enable Register */
	};

struct __rtc__ RTC	@0x4003D000;

/*	SCB section
 */
struct __scb__ {
	__REGW__ reserved_0[2];
	__REGW__ ACTLR;                 /* Auxiliary Control Register */
	__REGW__ reserved_1[829];
	__REGW__ CPUID;                 /* Base Register */
	__REGW__ ICSR;                  /* Interrupt Control/State Register */
	__REGW__ VTOR;                  /* Vector Table Offset Register */
	__REGW__ SCR;                   /* System Control Register */
	__REGW__ CCR;                   /* Configuration/Control Register */
	__REGW__ reserved_2;
	__REGW__ SHPR2;                 /* System Handler Priority Reg 2 */
	__REGW__ SHPR3;                 /* System Handler Priority Reg 3 */
	__REGW__ SHCSR;                 /* System Handler Control/State Reg */
	__REGW__ reserved_3[2];
	__REGW__ DFSR;                  /* Debug Fault Status Register */
	};

struct __scb__ SCB	@0xE000E000;

/*	SIM section
 */
struct __sim__ {
	__REGW__ SOPT1;                 /* System Options Register 1 */
	__REGW__ SOPT1CFG;              /* Configuration Register 1 */
	__REGW__ reserved_0[1023];
	__REGW__ SOPT2;                 /* System Options Register 2 */
	__REGW__ reserved_1;
	__REGW__ SOPT4;                 /* System Options Register 4 */
	__REGW__ SOPT5;                 /* System Options Register 5 */
	__REGW__ reserved_2;
	__REGW__ SOPT7;                 /* System Options Register 7 */
	__REGW__ reserved_3[2];
	__REGW__ SDID;                  /* System Device Identification */
	__REGW__ reserved_4[3];
	__REGW__ SCGC4;                 /* System Clock Gating Control 4 */
	__REGW__ SCGC5;                 /* System Clock Gating Control 5 */
	__REGW__ SCGC6;                 /* System Clock Gating Control 6 */
	__REGW__ SCGC7;                 /* System Clock Gating Control 7 */
	__REGW__ CLKDIV1;               /* System Clock Divider Register 1 */
	__REGW__ reserved_5;
	__REGW__ FCFG1;                 /* Flash Configuration Register 1 */
	__REGW__ FCFG2;                 /* Flash Configuration Register 2 */
	__REGW__ reserved_6;
	__REGW__ UIDMH;                 /* Unique Id Register Mid-High */
	__REGW__ UIDML;                 /* Unique Id Register Mid Low */
	__REGW__ UIDL;                  /* Unique Id Register Low */
	};

struct __sim__ SIM	@0x40047000;

/*	SMC section
 */
struct __smc__ {
	__REGB__ PMPROT;                /* Power Mode Protection Register */
	__REGB__ PMCTRL;                /* Power Mode Control Register */
	__REGB__ STOPCTRL;              /* Stop Control Register */
	__REGB__ PMSTAT;                /* Power Mode Status Register */
	};

struct __smc__ SMC	@0x4007E000;

/*	SPI section
 */
struct __spi__ {
	__REGB__ C1;                    /* Control Register 1 */
	__REGB__ C2;                    /* Control Register 2 */
	__REGB__ BR;                    /* Baud Rate Register */
	__REGB__ S;                     /* Status Register */
	__REGB__ reserved_0;
	__REGB__ D;                     /* Data Register */
	__REGB__ reserved_1;
	__REGB__ M;                     /* Match Register */
	};

struct __spi__ SPI0	@0x40076000;
struct __spi__ SPI1	@0x40077000;

/*	SYSTICK section
 */
struct __systick__ {
	__REGW__ CSR;                   /* Control and Status Register */
	__REGW__ RVR;                   /* Reload Value Register */
	__REGW__ CVR;                   /* Current Value Register */
	__REGW__ CALIB;                 /* Calibration Value Register */
	};

struct __systick__ SysTick	@0xE000E010;

/*	TPM section
 */
struct __tpm__ {
	__REGW__ SC;                    /* Status and Control Register */
	__REGW__ CNT;                   /* Counter Register */
	__REGW__ MOD;                   /* Modulo Register */
	struct {
		__REGW__ CnSC;          /* Channel Status and Control Reg */
		__REGW__ CnV;           /* Channel Value Register */
		} CONTROLS[6];
	__REGW__ reserved_0[5];
	__REGW__ STATUS;                /* Capture and Compare Status Reg */
	__REGW__ reserved_1[12];
	__REGW__ CONF;                  /* Configuration Register */
	};

struct __tpm__ TPM0	@0x40038000;
struct __tpm__ TPM1	@0x40039000;
struct __tpm__ TPM2	@0x4003a000;

/*	TSI section
 */
struct __tsi__ {
	__REGW__ GENCS;                 /* General Control/Status Register */
	__REGW__ DATA;                  /* Data Register */
	__REGW__ TSHD;                  /* Threshold Register */
	};

struct __tsi__ TSI0	@0x40045000;


/*	UART section
 */
struct __uart__ {
	__REGB__ BDH;                   /* Baud Rate Register High */
	__REGB__ BDL;                   /* Baud Rate Registers Low */
	__REGB__ C1;                    /* Control Register 1 */
	__REGB__ C2;                    /* Control Register 2 */
	__REGB__ S1;                    /* Status Register 1 */
	__REGB__ S2;                    /* Status Register 2 */
	__REGB__ C3;                    /* Control Register 3 */
	__REGB__ D;                     /* Data Register */
	__REGB__ C4;                    /* Control Register 4 */
	};

struct __uart__ UART1	@0x4006B000;
struct __uart__ UART2	@0x4006C000;

/*	UART0 section
 */
struct __uart0__ {
	__REGB__ BDH;                   /* Baud Rate Register High */
	__REGB__ BDL;                   /* Baud Rate Registers Low */
	__REGB__ C1;                    /* Control Register 1 */
	__REGB__ C2;                    /* Control Register 2 */
	__REGB__ S1;                    /* Status Register 1 */
	__REGB__ S2;                    /* Status Register 2 */
	__REGB__ C3;                    /* Control Register 3 */
	__REGB__ D;                     /* Data Register */
	__REGB__ MA1;                   /* Match Address Registers 1 */
	__REGB__ MA2;                   /* Match Address Registers 2 */
	__REGB__ C4;                    /* Control Register 4 */
	__REGB__ C5;                    /* Control Register 4 */
	};

struct __uart0__ UART0	@0x4006A000;

/*	USB section
 */
struct __usb__ {
	__REGB__ PERID;                 /* Peripheral ID Register */
	__REGB__ reserved_0[3];
	__REGB__ IDCOMP;                /* Peripheral ID Complement Register */
	__REGB__ reserved_1[3];
	__REGB__ REV;                   /* Peripheral Revision Register */
	__REGB__ reserved_2[3];
	__REGB__ ADDINFO;               /* Peripheral Additional Info Reg */
	__REGB__ reserved_3[3];
	__REGB__ OTGISTAT;              /* OTG Interrupt Status Register */
	__REGB__ reserved_4[3];
	__REGB__ OTGICR;                /* OTG Interrupt Control Register */
	__REGB__ reserved_5[3];
	__REGB__ OTGSTAT;               /* OTG Status Register */
	__REGB__ reserved_6[3];
	__REGB__ OTGCTL;                /* OTG Control Register */
	__REGB__ reserved_7[99];
	__REGB__ ISTAT;                 /* Interrupt Status Register */
	__REGB__ reserved_8[3];
	__REGB__ INTEN;                 /* Interrupt Enable Register */
	__REGB__ reserved_9[3];
	__REGB__ ERRSTAT;               /* Error Interrupt Status Register */
	__REGB__ reserved_10[3];
	__REGB__ ERREN;                 /* Error Interrupt Enable Register */
	__REGB__ reserved_11[3];
	__REGB__ STAT;                  /* Status Register */
	__REGB__ reserved_12[3];
	__REGB__ CTL;                   /* Control Register */
	__REGB__ reserved_13[3];
	__REGB__ ADDR;                  /* Address Register */
	__REGB__ reserved_14[3];
	__REGB__ BDTPAGE1;              /* BDT Page Register 1 */
	__REGB__ reserved_15[3];
	__REGB__ FRMNUML;               /* Frame Number Register Low */
	__REGB__ reserved_16[3];
	__REGB__ FRMNUMH;               /* Frame Number Register High */
	__REGB__ reserved_17[3];
	__REGB__ TOKEN;                 /* Token Register */
	__REGB__ reserved_18[3];
	__REGB__ SOFTHLD;               /* SOF Threshold Register */
	__REGB__ reserved_19[3];
	__REGB__ BDTPAGE2;              /* BDT Page Register 2 */
	__REGB__ reserved_20[3];
	__REGB__ BDTPAGE3;              /* BDT Page Register 3 */
	__REGB__ reserved_21[11];
	struct {
		__REGB__ ENDPT;         /* Endpoint Control Registers */
		__REGB__ reserved_0[3];
		} ENDPOINT[16];
	__REGB__ USBCTRL;               /* USB Control Register */
	__REGB__ reserved_22[3];
	__REGB__ OBSERVE;               /* USB OTG Observe Register */
	__REGB__ reserved_23[3];
	__REGB__ CONTROL;               /* USB OTG Control Register */
	__REGB__ reserved_24[3];
	__REGB__ USBTRC0;               /* USB Transceiver Control Register 0 */
	};

struct __usb__ USB0	@0x40072000;
