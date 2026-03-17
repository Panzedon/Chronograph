/*	IO DEFINITIONS FOR KINETIS SKEAZN642
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

/*	FTMRH section
 */
struct __ftmrh__ {
	__REGB__ FCLKDIV;             /* Clock Divider Register */
	__REGB__ FSEC;                /* Security Register */
	__REGB__ FCCOBIX;             /* CCOB Index Register */
	__REGB__ reserved_0;
	__REGB__ FCNFG;               /* Configuration Register */
	__REGB__ FERCNFG;             /* Error Configuration Register */
	__REGB__ FSTAT;               /* Status Register */
	__REGB__ FERSTAT;             /* Error Status Register */
	__REGB__ FPROT;               /* Protection Register */
	__REGB__ EEPROT;              /* EEPROM Protection Register */
	__REGB__ FCCOBHI;             /* Common Command Object Register:High */
	__REGB__ FCCOBLO;             /* Common Command Object Register: Low */
	__REGB__ FOPT;                /* Option Register */
	};

struct __ftmrh__ FTMRH	@0x40020000;

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

/* ----------------------------------------------------------------------------
   -- NV
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Peripheral NV
 * @{
 */

/** NV - Peripheral register structure */
struct __nv__ {
	__REGB__ BACKKEY0;            /* Backdoor Comparison Key 0 */
	__REGB__ BACKKEY1;            /* Backdoor Comparison Key 1 */
	__REGB__ BACKKEY2;            /* Backdoor Comparison Key 2 */
	__REGB__ BACKKEY3;            /* Backdoor Comparison Key 3 */
	__REGB__ BACKKEY4;            /* Backdoor Comparison Key 4 */
	__REGB__ BACKKEY5;            /* Backdoor Comparison Key 5 */
	__REGB__ BACKKEY6;            /* Backdoor Comparison Key 6 */
	__REGB__ BACKKEY7;            /* Backdoor Comparison Key 7 */
	__REGW__ reserved_0;
	__REGB__ EEPROT;              /* Non-volatile E-Flash Prot Reg */
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
	__REGW__ IOFLT;               /* Port Filter Register */
	__REGW__ PUEL;                /* Port Pullup Enable Low Register */
	__REGW__ PUEH;                /* Port Pullup Enable High Register */
	__REGW__ HDRVE;               /* Port High Drive Enable Register */
	};

struct __port__ PORT	@0x40049000;

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
	__REGW__ SOPT;                /* System Options Register */
	__REGW__ PINSEL;              /* Pin Selection Register */
	__REGW__ SCGC;                /* System Clock Gating Control Reg */
	__REGW__ UUIDL;               /* Universally Unique ID Low Register */
	__REGW__ UUIDH;               /* Universally Unique ID High Register */
	__REGW__ BUSDIV;              /* BUS Clock Divider Register */
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
