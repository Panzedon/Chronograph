/*	IO DEFINITIONS FOR KINETIS SKEAZ1284
 *	Copyright (c) 2014 by COSMIC Software
 */
typedef volatile unsigned char __REGB__;
typedef volatile unsigned short __REGH__;
typedef volatile unsigned int __REGW__;

/*	ACMP section
 */
struct __acmp__ {
	__REGB__ CS;                    /* Control and Status Register */
	__REGB__ C0;                    /* Control Register 0 */
	__REGB__ C1;                    /* Control Register 1 */
	__REGB__ C2;                    /* Control Register 2 */
	};

struct __acmp__ ACMP0	@0x40073000;
struct __acmp__ ACMP1	@0x40074000;

/*	ADC section
 */
struct __adc__ {
	__REGW__ SC1;                   /* Status and Control Register 1 */
	__REGW__ SC2;                   /* Status and Control Register 2 */
	__REGW__ SC3;                   /* Status and Control Register 3 */
	__REGW__ SC4;                   /* Status and Control Register 4 */
	__REGW__ R;                     /* Conversion Result Register */
	__REGW__ CV;                    /* Compare Value Register */
	__REGW__ APCTL1;                /* Pin Control 1 Register */
	__REGW__ SC5;                   /* Status and Control Register 5 */
	};

struct __adc__ ADC	@0x4003B000;

/*	BP section
 */
struct __bp__ {
	__REGW__ CTRL;                  /* FlashPatch Control Register */
	__REGW__ reserved_0;
	__REGW__ COMP[2];               /* FlashPatch Comparator Registers */
	__REGW__ reserved_1[1008];
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

/*	CRC section
 */
struct __crc__ {
	union {
		struct {
			__REGH__ DATAL;      /* CRC_DATAL register */
			__REGH__ DATAH;      /* CRC_DATAH register */
			} ACCESS16BIT;
		__REGW__ DATA;               /* CRC Data register */
		struct {
			__REGB__ DATALL;     /* CRC_DATALL register */
			__REGB__ DATALU;     /* CRC_DATALU register */
			__REGB__ DATAHL;     /* CRC_DATAHL register */
			__REGB__ DATAHU;     /* CRC_DATAHU register */
			} ACCESS8BIT;
		};
	union {
		struct {
			__REGH__ GPOLYL;     /* CRC_GPOLYL register */
			__REGH__ GPOLYH;     /* CRC_GPOLYH register */
			} GPOLY_ACCESS16BIT;
		__REGW__ GPOLY;              /* CRC Polynomial register */
		struct {
			__REGB__ GPOLYLL;    /* CRC_GPOLYLL register */
			__REGB__ GPOLYLU;    /* CRC_GPOLYLU register */
			__REGB__ GPOLYHL;    /* CRC_GPOLYHL register */
			__REGB__ GPOLYHU;    /* CRC_GPOLYHU register */
			} GPOLY_ACCESS8BIT;
		};
	union {
		__REGW__ CTRL;               /* CRC Control register */
		struct {
			__REGB__ reserved_0[3];
			__REGB__ CTRLHU;     /* CRC_CTRLHU register */
			} CTRL_ACCESS8BIT;
		};
	};

struct __crc__ CRC	@0x40032000;

/*	CORE DEBUG section
 */
struct __cdbg__ {
	union {
		__REGW__ base_DHCSR_Read;   /* Halting Control/Status Reg */
		__REGW__ base_DHCSR_Write;  /* Halting Control/Status Reg */
		};
	__REGW__ base_DCRSR;                /* Core Register Selector Reg */
	__REGW__ base_DCRDR;                /* Core Register Data Register */
	__REGW__ base_DEMCR;                /* Exception and Monitor Ctrl Reg */
	};

struct __cdbg__ CDBG	@0xE000EDF0;

/*	DWT section
 */
struct __dwt__ {
	__REGW__ CTRL;                 /* Control Register */
	__REGW__ reserved_0[6];
	__REGW__ PCSR;                 /* Program Counter Sample Register */
	struct {
		__REGW__ COMP;         /* Comparator Registers */
		__REGW__ MASK;         /* Mask Registers */
		__REGW__ FUNCTION;     /* Function Registers */
		__REGW__ reserved_0;
		} COMPARATOR[2];
	};

struct __dwt__ DWT	@0xE0001000;

/*	FGPIO section
 */
struct __fgpio__ {
	__REGW__ PDOR;                 /* Port Data Output Register */
	__REGW__ PSOR;                 /* Port Set Output Register */
	__REGW__ PCOR;                 /* Port Clear Output Register */
	__REGW__ PTOR;                 /* Port Toggle Output Register */
	__REGW__ PDIR;                 /* Port Data Input Register */
	__REGW__ PDDR;                 /* Port Data Direction Register */
	__REGW__ PIDR;                 /* Port Input Disable Register */
	};

struct __fgpio__ FGPIOA	@0xF8000000;
struct __fgpio__ FGPIOB	@0xF8000040;
struct __fgpio__ FGPIOC	@0xF8000080;

/*	FTM section
 */
struct __ftm__ {
	__REGW__ SC;                  /* Status And Control */
	__REGW__ CNT;                 /* Counter */
	__REGW__ MOD;                 /* Modulo */
	struct {
		__REGW__ CnSC;        /* Channel Status And Control */
		__REGW__ CnV;         /* Channel Value */
		} CONTROLS[6];
	__REGW__ reserved_0[4];
	__REGW__ CNTIN;               /* Counter Initial Value */
	__REGW__ STATUS;              /* Capture And Compare Status */
	__REGW__ MODE;                /* Features Mode Selection */
	__REGW__ SYNC;                /* Synchronization */
	__REGW__ OUTINIT;             /* Initial State For Channels Output */
	__REGW__ OUTMASK;             /* Output Mask */
	__REGW__ COMBINE;             /* Function For Linked Channels */
	__REGW__ DEADTIME;            /* Deadtime Insertion Control */
	__REGW__ EXTTRIG;             /* FTM External Trigger */
	__REGW__ POL;                 /* Channels Polarity */
	__REGW__ FMS;                 /* Fault Mode Status */
	__REGW__ FILTER;              /* Input Capture Filter Control */
	__REGW__ FLTCTRL;             /* Fault Control */
	__REGW__ reserved_1;
	__REGW__ CONF;                /* Configuration */
	__REGW__ FLTPOL;              /* FTM Fault Input Polarity */
	__REGW__ SYNCONF;             /* Synchronization Configuration */
	__REGW__ INVCTRL;             /* FTM Inverting Control */
	__REGW__ SWOCTRL;             /* FTM Software Output Control */
	__REGW__ PWMLOAD;             /* FTM PWM Load */
	};

struct __ftm__ FTM0	@0x40038000;
struct __ftm__ FTM1	@0x40039000;
struct __ftm__ FTM2	@0x4003A000;

/*	FTMRE section
 */
struct __ftmre__ {
	__REGB__ reserved_0;
	__REGB__ FCCOBIX;             /* CCOB Index Register */
	__REGB__ FSEC;                /* Security Register */
	__REGB__ FCLKDIV;             /* Clock Divider Register */
	__REGB__ reserved_1;
	__REGB__ FSTAT;               /* Status Register */
	__REGB__ reserved_2;
	__REGB__ FCNFG;               /* Configuration Register */
	__REGB__ FCCOBLO;             /* Common Command Object Register Low */
	__REGB__ FCCOBHI;             /* Common Command Object Register High */
	__REGB__ reserved_3;
	__REGB__ FPROT;               /* Protection Register */
	__REGB__ reserved_4[3];
	__REGB__ FOPT;                /* Option Register */
	};

struct __ftmre__ FTMRE	@0x40020000;

/*	GPIO section
 */
struct __gpio__ {
	__REGW__ PDOR;                /* Port Data Output Register */
	__REGW__ PSOR;                /* Port Set Output Register */
	__REGW__ PCOR;                /* Port Clear Output Register */
	__REGW__ PTOR;                /* Port Toggle Output Register */
	__REGW__ PDIR;                /* Port Data Input Register0 */
	__REGW__ PDDR;                /* Port Data Direction Register4 */
	__REGW__ PIDR;                /* Port Input Disable Register8 */
	};

struct __gpio__ GPIOA	@0x400FF000;
struct __gpio__ GPIOB	@0x400FF040;
struct __gpio__ GPIOC	@0x400FF080;

/*	I2C section
 */
struct __i2c__ {
	__REGB__ A1;                  /* Address Register 1 */
	__REGB__ F;                   /* Frequency Divider register */
	__REGB__ C1;                  /* Control Register 1 */
	__REGB__ S;                   /* Status register */
	__REGB__ D;                   /* Data I/O register */
	__REGB__ C2;                  /* Control Register 2 */
	__REGB__ FLT;                 /* Input Glitch Filter register */
	__REGB__ RA;                  /* Range Address register */
	__REGB__ SMB;                 /* SMBus Control and Status register */
	__REGB__ A2;                  /* Address Register 2 */
	__REGB__ SLTH;                /* SCL Low Timeout Register High */
	__REGB__ SLTL;                /* SCL Low Timeout Register Low */
	};

struct __i2c__ I2C0	@0x40066000;
struct __i2c__ I2C1	@0x40067000;

/*	ICS section
 */
struct __ics__ {
	__REGB__ C1;                  /* Control Register 1 */
	__REGB__ C2;                  /* Control Register 2 */
	__REGB__ C3;                  /* Control Register 3 */
	__REGB__ C4;                  /* Control Register 4 */
	__REGB__ S;                   /* Status Register */
	};

struct __ics__ ICS	@0x40064000;

/*	IRQ section
 */
struct __irq__ {
	__REGB__ SC;                  /* IT Pin Request Status/Control Reg */
	};

struct __irq__ IRQ	@0x40031000;

/*	KBI section
 */
struct __bki__ {
	__REGB__ SC;                  /* Status and Control Register */
	__REGB__ PE;                  /* Pin Enable Register */
	__REGB__ ES;                  /* Edge Select Register */
	__REGB__ SP;                  /* Source Pin Register */
	};

struct __kbi__ KBI0	@0x40079000;
struct __kbi__ KBI1	@0x4007A000;

/*	MCM section
 */
struct __mcm__ {
	__REGW__ reserved_0[2];
	__REGH__ PLASC;               /* Crossbar Switch Slave Config */
	__REGH__ PLAMC;               /* Crossbar Switch Master Config */
	__REGW__ PLACR;               /* Platform Control Register */
	};

struct __mcm__ MCM	@0xF0003000;

/*	MSCAN section
 */
struct __mscan__ {
	__REGB__ CANCTL0;             /* Control Register 0 */
	__REGB__ CANCTL1;             /* Control Register 1 */
	__REGB__ CANBTR0;             /* Bus Timing Register 0 */
	__REGB__ CANBTR1;             /* Bus Timing Register 1 */
	__REGB__ CANRFLG;             /* Receiver Flag Register */
	__REGB__ CANRIER;             /* Receiver Interrupt Enable Register */
	__REGB__ CANTFLG;             /* Transmitter Flag Register */
	__REGB__ CANTIER;             /* Transmitter Interrupt Enable Reg */
	__REGB__ CANTARQ;             /* Transmitter Message Abort Req Reg */
	__REGB__ CANTAAK;             /* Transmitter Message Abort Ack Reg */
	__REGB__ CANTBSEL;            /* Transmit Buffer Selection Register */
	__REGB__ CANIDAC;             /* Identifier Acceptance Control Reg */
	__REGB__ RESERVED_0[1];
	__REGB__ CANMISC;             /* Miscellaneous Register */
	__REGB__ CANRXERR;            /* Receive Error Counter */
	__REGB__ CANTXERR;            /* Transmit Error Counter */
	__REGB__ CANIDAR_BANK_1[4];   /* ID Acceptance Regs of First Bank */
	__REGB__ CANIDMR_BANK_1[4];   /* ID Mask Regs of First Bank */
	__REGB__ CANIDAR_BANK_2[4];   /* ID Acceptance Regs of Second Bank */
	__REGB__ CANIDMR_BANK_2[4];   /* ID Mask Regs of Second Bank */
	union {
		__REGB__ REIDR0;      /* Extended Identifier Register 0 */
		__REGB__ RSIDR0;      /* Standard Identifier Register 0 */
		};
	union {
		__REGB__ REIDR1;      /* Receive Extended Identifier Reg 1 */
		__REGB__ RSIDR1;      /* Standard Identifier Register 1 */
		__REGB__ TSIDR1;      /* Transmit Standard Identifier Reg 1 */
		};
	__REGB__ REIDR2;              /* Receive Extended Identifier Reg 2 */
	__REGB__ REIDR3;              /* Receive Extended Identifier Reg 3 */
	__REGB__ REDSR[8];            /* Receive Extended Data Segment Regs */
	__REGB__ RDLR;                /* Receive Data Length Register */
	__REGB__ RESERVED_1[1];
	__REGB__ RTSRH;               /* Receive Time Stamp Register High */
	__REGB__ RTSRL;               /* Receive Time Stamp Register Low */
	union {
		__REGB__ TEIDR0;      /* Transmit Extended Identifier Reg 0 */
		__REGB__ TSIDR0;      /* Transmit Standard Identifier Reg 0 */
		};
	__REGB__ TEIDR1;              /* Transmit Extended Identifier Reg 1 */
	__REGB__ TEIDR2;              /* Transmit Extended Identifier Reg 2 */
	__REGB__ TEIDR3;              /* Transmit Extended Identifier Reg 3 */
	__REGB__ TEDSR[8];            /* Transmit Extended Data Segment Regs */
	__REGB__ TDLR;                /* Data length field Register */
	__REGB__ TBPR;                /* Transmit Buffer Priority Register */
	__REGB__ TTSRH;               /* Transmit Time Stamp Register High */
	__REGB__ TTSRL;               /* Transmit Time Stamp Register Low */
	};

struct __mscan__ MSCAN	@0x40024000;

/*	NV section
 */
struct __nv__ {
	__REGB__ BACKKEY0;            /* Backdoor Comparison Key 0 */
	__REGB__ BACKKEY1;            /* Backdoor Comparison Key 1 */
	__REGB__ BACKKEY2;            /* Backdoor Comparison Key 2 */
	__REGB__ BACKKEY3;            /* Backdoor Comparison Key 3 */
	__REGB__ BACKKEY4;            /* Backdoor Comparison Key 4 */
	__REGB__ BACKKEY5;            /* Backdoor Comparison Key 5 */
	__REGB__ BACKKEY6;            /* Backdoor Comparison Key 6 */
	__REGB__ BACKKEY7;            /* Backdoor Comparison Key 7 */
	__REGB__ reserved_0[5];
	__REGB__ FPROT;               /* Non-volatile P-Flash Prot Reg */
	__REGB__ FSEC;                /* Non-volatile Flash Security Reg */
	__REGB__ FOPT;                /* Non-volatile Flash Option Reg */
	};

struct __nv__ NV	@0x400;

/*	NVIC section
 */
struct __nvic__ {
	__REGW__ ISER;                /* Interrupt Set Enable Register */
	__REGW__ reserved_0[31];
	__REGW__ ICER;                /* Interrupt Clear Enable Register */
	__REGW__ reserved_1[31];
	__REGW__ ISPR;                /* Interrupt Set Pending Register */
	__REGW__ reserved_2[31];
	__REGW__ ICPR;                /* Interrupt Clear Pending Register */
	__REGW__ reserved_3[95];
	__REGW__ IP[8];               /* Interrupt Priority Registers */
	};

struct __nvic__ NVIC	@0xE000E100;

/*	OSC section
 */
struct __osc__ {
	__REGB__ CR;                  /* OSC Control Register */
	};

struct __osc__ OSC	@0x40065000;

/*	PIT section
 */
struct __pit__ {
	__REGW__ MCR;                 /* Module Control Register */
	__REGW__ reserved_0[63];
	struct {
		__REGW__ LDVAL;       /* Timer Load Value Registers */
		__REGW__ CVAL;        /* Current Timer Value Registers */
		__REGW__ TCTRL;       /* Timer Control Registers */
		__REGW__ TFLG;        /* Timer Flag Registers */
		} CHANNEL[2];
	};

struct __pit__ PIT	@0x40037000;

/*	PMC section
 */
struct __pmc__ {
	__REGB__ SPMSC1;              /* Status and Control 1 Register */
	__REGB__ SPMSC2;              /* Status and Control 2 Register */
	};

struct __pmc__ PMC	@0x4007D000;

/*	PORT section
 */
struct __port__ {
	__REGW__ IOFLT0;              /* Port Filter Register 0 */
	__REGW__ IOFLT1;              /* Port Filter Register 1 */
	__REGW__ PUE0;                /* Port Pullup Register 0 */
	__REGW__ PUE1;                /* Port Pullup Register 1 */
	__REGW__ PUE2;                /* Port Pullup Register 2 */
	__REGW__ HDRVE;               /* Port High Drive Enable Register */
	};

struct __port__ PORT	@0x40049000;

/*	PWT section
 */
struct __pwt__ {
	__REGW__ R1;                  /* Pulse Width Timer Register 1 */
	__REGW__ R2;                  /* Pulse Width Timer Register 2 */
	};

struct __pwt__ PWT	@0x40033000;

/*	ROM section
 */
struct __rom__ {
	__REGW__ ENTRY[1];            /* Entry */
	__REGW__ TABLEMARK;           /* End of Table Marker Register */
	__REGW__ reserved_0[1009];
	__REGW__ SYSACCESS;           /* System Access Register */
	__REGW__ PERIPHID4;           /* Peripheral ID Register */
	__REGW__ PERIPHID5;           /* Peripheral ID Register */
	__REGW__ PERIPHID6;           /* Peripheral ID Register */
	__REGW__ PERIPHID7;           /* Peripheral ID Register */
	__REGW__ PERIPHID0;           /* Peripheral ID Register */
	__REGW__ PERIPHID1;           /* Peripheral ID Register */
	__REGW__ PERIPHID2;           /* Peripheral ID Register */
	__REGW__ PERIPHID3;           /* Peripheral ID Register */
	__REGW__ COMPID[4];           /* Component ID Registers */
	};

struct __rom__ ROM	@0xF0002000;

/*	RTC section
 */
struct __rtc__ {
	__REGW__ SC;                  /* Status and Control Register */
	__REGW__ MOD;                 /* Modulo Register */
	__REGW__ CNT;                 /* Counter Register */
	};

struct __rtc__ RTC	@0x4003D000;

/*	SCB section
 */
struct __scb__ {
	__REGW__ reserved_0[2];
	__REGW__ ACTLR;               /* Auxiliary Control Register */
	__REGW__ reserved_1[829];
	__REGW__ CPUID;               /* CPUID Base Register */
	__REGW__ ICSR;                /* Interrupt Control and State Reg */
	__REGW__ VTOR;                /* Vector Table Offset Register */
	__REGW__ AIRCR;               /* Application Interrupt/Reset Reg */
	__REGW__ SCR;                 /* System Control Register */
	__REGW__ CCR;                 /* Configuration and Control Register */
	__REGW__ reserved_2;
	__REGW__ SHPR2;               /* System Handler Priority Register 2 */
	__REGW__ SHPR3;               /* System Handler Priority Register 3 */
	__REGW__ SHCSR;               /* System Handler Control/State Reg */
	__REGW__ reserved_3[2];
	__REGW__ DFSR;                /* Debug Fault Status Register */
	};

struct __scb__ SCB	@0xE000E000;

/*	SIM section
 */
struct __sim__ {
	__REGW__ SRSID;               /* System Reset Status and ID Register */
	__REGW__ SOPT0;               /* System Options Register 0 */
	__REGW__ SOPT1;               /* System Options Register 1 */
	__REGW__ PINSEL0;             /* Pin Selection Register 0 */
	__REGW__ PINSEL1;             /* Pin Selection Register 1 */
	__REGW__ SCGC;                /* System Clock Gating Control Reg */
	__REGW__ UUIDL;               /* Universally Unique ID Low Register */
	__REGW__ UUIDML;              /* Universally Unique ID Mid Low Reg */
	__REGW__ UUIDMH;              /* Universally Unique ID Mid High Reg */
	__REGW__ CLKDIV;              /* Clock Divider Register */
	};

struct __sim__ SIM	@0x40048000;

/*	SPI section
 */
struct __spi__ {
	__REGB__ C1;                  /* Control Register 1 */
	__REGB__ C2;                  /* Control Register 2 */
	__REGB__ BR;                  /* Baud Rate Register */
	__REGB__ S;                   /* Status Register */
	__REGB__ reserved_0;
	__REGB__ D;                   /* Data Register */
	__REGB__ reserved_1;
	__REGB__ M;                   /* Match Register */
	};

struct __spi__ SPI0	@0x40076000;
struct __spi__ SPI1	@0x40077000;

/*	SYSTICK section
 */
struct __syst__ {
	__REGW__ CSR;                 /* Control and Status Register */
	__REGW__ RVR;                 /* Reload Value Register */
	__REGW__ CVR;                 /* Current Value Register */
	__REGW__ CALIB;               /* Calibration Value Register */
	};

struct __syst__ SYST	@0xE000E010;

/*	UART section
 */
struct __uart__ {
	__REGB__ BDH;                 /* Baud Rate Register High */
	__REGB__ BDL;                 /* Baud Rate Register Low */
	__REGB__ C1;                  /* Control Register 1 */
	__REGB__ C2;                  /* Control Register 2 */
	__REGB__ S1;                  /* Status Register 1 */
	__REGB__ S2;                  /* Status Register 2 */
	__REGB__ C3;                  /* Control Register 3 */
	__REGB__ D;                   /* Data Register */
	};

struct __uart__ UART0	@0x4006A000;
struct __uart__ UART1	@0x4006B000;
struct __uart__ UART2	@0x4006C000;

/*	WDOG section
 */
struct __wdog__ {
	__REGB__ CS1;                 /* Control and Status Register 1 */
	__REGB__ CS2;                 /* Control and Status Register 2 */
	union {
		__REGH__ CNT;               /* WDOG_CNT register */
		struct {
			__REGB__ CNTH;      /* Counter Register High */
			__REGB__ CNTL;      /* Counter Register Low */
			} CNT8B;
		};
	union {
		__REGH__ TOVAL;             /* WDOG_TOVAL register */
		struct {
			__REGB__ TOVALH;    /* Timeout Value Register High */
			__REGB__ TOVALL;    /* Timeout Value Register Low */
			} TOVAL8B;
		};
	union {
		__REGH__ WIN;               /* WDOG_WIN register */
		struct {
			__REGB__ WINH;      /* Window Register High */
			__REGB__ WINL;      /* Window Register Low */
			} WIN8B;
		};
	};

struct __wdog__ WDOG	@0x40052000;
