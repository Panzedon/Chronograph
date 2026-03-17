/*	IO DEFINITIONS FOR KINETIS K22FN512
 *	Copyright (c) 2015 by COSMIC SOftware
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
	__REGW__ MG;                    /* minus gain register */
	__REGW__ CLPD;                  /* plus calibration value register */
	__REGW__ CLPS;                  /* plus calibration value register */
	__REGW__ CLP4;                  /* plus calibration value register */
	__REGW__ CLP3;                  /* plus calibration value register */
	__REGW__ CLP2;                  /* plus calibration value register */
	__REGW__ CLP1;                  /* plus calibration value register */
	__REGW__ CLP0;                  /* plus calibration value register */
	__REGW__ PGA;                   /* PGA register */
	__REGW__ CLMD;                  /* minus calibration value register */
	__REGW__ CLMS;                  /* minus calibration value register */
	__REGW__ CLM4;                  /* minus calibration value register */
	__REGW__ CLM3;                  /* minus calibration value register */
	__REGW__ CLM2;                  /* minus calibration value register */
	__REGW__ CLM1;                  /* minus calibration value register */
	__REGW__ CLM0;                  /* minus calibration value register */
	};

struct __adc__ ADC0	@0x4003B000;
struct __adc__ ADC1	@0x40027000;

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
struct __cmp__ CMP1	@0x40073008;

/*	CRC section
 */
struct __crc__ {
	union {
		__REGW__ CRC;               /* Data Register word */
		struct {
			__REGH__ CRCL;      /* Data register half word low */
			__REGH__ CRCH;      /* Data register half word high */
			} ACCESS16BIT;
		struct {
			__REGB__ CRCLL;     /* Data register byte low lower*/
			__REGB__ CRCLU;     /* Data register byte low upper */
			__REGB__ CRCHL;     /* Data register byte high lower */
			__REGB__ CRCHU;     /* Data register byte highupper */
			} ACCESS8BIT;
		};
	union {
		__REGW__ GPOLY;             /* Polynomial Register */
		struct {
			__REGH__ GPOLYL;    /* Poly register half word low */
			__REGH__ GPOLYH;    /* Poly register half word high */
			} GPOLY_ACCESS16BIT;
		struct {
			__REGB__ GPOLYLL;   /* Poly register byte low lower */
			__REGB__ GPOLYLU;   /* Poly register byte low upper */
			__REGB__ GPOLYHL;   /* Poly register byte high lower */
			__REGB__ GPOLYHU;   /* Poly register byte high upper */
			} GPOLY_ACCESS8BIT;
  		};
	__REGW__ CTRL;                      /* Control Register */
	};

struct __crc__ CRC	@0x40032000;

/*	DAC section
 */
struct __dac__ {
	struct {
		__REGB__ DATL;          /* Data Register Low */
		__REGB__ DATH;          /* Data Register High */
		} DAT[16];
	__REGB__ SR;                    /* Status Register */
	__REGB__ C0;                    /* Control Register */
	__REGB__ C1;                    /* Control Register 1 */
	__REGB__ C2;                    /* Control Register 2 */
	};

struct __dac__ DAC0	@0x4003F000;
struct __dac__ DAC1	@0x40028000;

/*	DMA section
 */
struct __tcd__{
	__REGW__ SADDR;                      /* Source Address */
	__REGH__ SOFF;                       /* Signed Source Address Offset */
	__REGH__ ATTR;                       /* Transfer Attributes */
	union {
		__REGW__ NBYTES_MLNO;        /* Minor Byte Count */
		__REGW__ NBYTES_MLOFFNO;     /* Signed Minor Loop Offset */
		__REGW__ NBYTES_MLOFFYES;    /* Signed Minor Loop Offset */
		};
	__REGW__ SLAST;                      /* Last Source Address Adjust */
	__REGW__ DADDR;                      /* Destination Address */
	__REGH__ DOFF;                       /* Signed Dest Address Offset */
	union {
		__REGH__ CITER_ELINKYES;     /* Current Minor Loop Link */
		__REGH__ CITER_ELINKNO;      /* Current Minor Loop Link */
		};
	__REGW__ DLAST_SGA;                  /* Last Dest Address Adjustment */
	__REGH__ CSR;                        /* Control and Status */
	union {
		__REGH__ BITER_ELINKNO;      /* Beginning Minor Loop Link */
		__REGH__ BITER_ELINKYES;     /* Beginning Minor Loop Link */
		};
	};

struct __dma__ {
	__REGW__ CR;                    /* Control Register */
	__REGW__ ES;                    /* Error Status Register */
	__REGW__ reserved_0;
	__REGW__ ERQ;                   /* Enable Request Register */
	__REGW__ reserved_1;
	__REGW__ EEI;                   /* Enable Error Interrupt Register */
	__REGB__ CEEI;                  /* Clear Enable Error Interrupt */
	__REGB__ SEEI;                  /* Set Enable Error Interrupt */
	__REGB__ CERQ;                  /* Clear Enable Request Register */
	__REGB__ SERQ;                  /* Set Enable Request Register */
	__REGB__ CDNE;                  /* Clear DONE Status Bit Register */
	__REGB__ SSRT;                  /* Set START Bit Register */
	__REGB__ CERR;                  /* Clear Error Register */
	__REGB__ CINT;                  /* Clear Interrupt Request Register */
	__REGW__ reserved_2;
	__REGW__ INT;                   /* Interrupt Request Register */
	__REGW__ reserved_3;
	__REGW__ ERR;                   /* Error Register */
	__REGW__ reserved_4;
	__REGW__ HRS;                   /* Hardware Request Status Register */
	__REGW__ reserved_5[50];
	__REGB__ DCHPRI3;               /* Channel 3 Priority Register */
	__REGB__ DCHPRI2;               /* Channel 2 Priority Register */
	__REGB__ DCHPRI1;               /* Channel 1 Priority Register */
	__REGB__ DCHPRI0;               /* Channel 0 Priority Register */
	__REGB__ DCHPRI7;               /* Channel 7 Priority Register */
	__REGB__ DCHPRI6;               /* Channel 6 Priority Register */
	__REGB__ DCHPRI5;               /* Channel 5 Priority Register */
	__REGB__ DCHPRI4;               /* Channel 4 Priority Register */
	__REGB__ DCHPRI11;              /* Channel 11 Priority Register */
	__REGB__ DCHPRI10;              /* Channel 10 Priority Register */
	__REGB__ DCHPRI9;               /* Channel 9 Priority Register */
	__REGB__ DCHPRI8;               /* Channel 8 Priority Register */
	__REGB__ DCHPRI15;              /* Channel 15 Priority Register */
	__REGB__ DCHPRI14;              /* Channel 14 Priority Register */
	__REGB__ DCHPRI13;              /* Channel 13 Priority Register */
	__REGB__ DCHPRI12;              /* Channel 12 Priority Register */
	__REGW__ reserved_6[956];
	struct __tcd__ TCD[16];
	};

struct __dma__ DMA	@0x40008000;

/*	DMAMUX section
 */
struct __dmamux__ {
	__REGB__ CHCFG[16];             /* Channel Configuration Register */
	};

struct __dmamux__ DMAMUX @0x40021000;

/*	DWT section
 */
struct __dwt__ {
	__REGW__ CTRL;                  /* Control Register */
	__REGW__ CYCCNT;                /* Cycle Count Register */
	__REGW__ CPICNT;                /* CPI Count Register */
	__REGW__ EXCCNT;                /* Exception Overhead Count Register */
	__REGW__ SLEEPCNT;              /* Sleep Count Register */
	__REGW__ LSUCNT;                /* LSU Count Register */
	__REGW__ FOLDCNT;               /* Folded-instruction Count Register */
	__REGW__ PCSR;                  /* Program Counter Sample Register */
	struct {
 		__REGW__ COMP;          /* Comparator Register */
 		__REGW__ MASK;          /* Mask Register */
 		__REGW__ FUNCTION;      /* Function Register */
		__REGW__ reserved_0;
		} COMPARATOR[4];
	__REGW__ reserved_1[988];
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

struct __dwt__ DWT	@0xE0001000;

/*	EWM section
 */
struct __ewm__ {
	__REGB__ CTRL;                  /* Control Register */
	__REGB__ SERV;                  /* Service Register */
	__REGB__ CMPL;                  /* Compare Low Register */
	__REGB__ CMPH;                  /* Compare High Register */
	__REGB__ reserved_0;
	__REGB__ CLKPRESCALER;          /* Clock Prescaler Register */
	};

struct __ewm__ EWM	@0x40061000;

/*	FB section
 */
struct __fb__ {
	struct {
    		__REGW__ CSAR;          /* Chip select address register */
    		__REGW__ CSMR;          /* Chip select mask register */
    		__REGW__ CSCR;          /* Chip select control register */
		} CS[6];
	__REGW__ reserved_0[6];
	__REGW__ CSPMCR;                /* port multiplexing control register */
	};

struct __fb__ FB	@0x4000C000;

/*	FMC section
 */
struct __fmc__ {
	__REGW__ PFAPR;                 /* Flash Access Protection Register */
	__REGW__ PFB0CR;                /* Flash Bank 0 Control Register */
	__REGW__ PFB1CR;                /* Flash Bank 1 Control Register */
	__REGW__ reserved_0[61];
	__REGW__ TAGVD[4][8];           /* Cache Directory Storage */
	__REGW__ reserved_1[32];
	struct {
		__REGW__ DATA_U;        /* Cache Data Storage upper */
		__REGW__ DATA_L;        /* Cache Data Storage lower */
		} SET[4][8];
	};

struct __fmc__ FMC	@0x4001F000;

/*	FPB section
 */
struct __fpb__ {
	__REGW__ CTRL;                  /*< FlashPatch Control Register */
	__REGW__ REMAP;                 /*< FlashPatch Remap Register */
	__REGW__ COMP[8];               /*< FlashPatch Comparator Registers */
	__REGW__ reserved_0[1002];
	__REGW__ PID4;                  /*< Peripheral Identification Reg 4 */
	__REGW__ PID5;                  /*< Peripheral Identification Reg 5 */
	__REGW__ PID6;                  /*< Peripheral Identification Reg 6 */
	__REGW__ PID7;                  /*< Peripheral Identification Reg 7 */
	__REGW__ PID0;                  /*< Peripheral Identification Reg 0 */
	__REGW__ PID1;                  /*< Peripheral Identification Reg 1 */
	__REGW__ PID2;                  /*< Peripheral Identification Reg 2 */
	__REGW__ PID3;                  /*< Peripheral Identification Reg 3 */
	__REGW__ CID0;                  /*< Component Identification Reg 0 */
	__REGW__ CID1;                  /*< Component Identification Reg 1 */
	__REGW__ CID2;                  /*< Component Identification Reg 2 */
	__REGW__ CID3;                  /*< Component Identification Reg 3 */
	};

struct __fpb__ FPB	@0xE0002000;

/*	FTFL section
 */
struct __ftfl__ {
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
	__REGB__ reserved_0[2];
	__REGB__ FEPROT;                 /* EEPROM Protection Register */
	__REGB__ FDPROT;                 /* Data Flash Protection Register */
	};

struct __ftfl__ FTFL	@0x40020000;

/*	FTM section
 */
struct __ftm__ {
	__REGW__ SC;                    /* Status and Control */
	__REGW__ CNT;                   /* Counter */
	__REGW__ MOD;                   /* Modulo */
	struct {
		__REGW__ CnSC;          /* Channel Status and Control */
		__REGW__ CnV;           /* Channel Value */
		} CONTROLS[8];
	__REGW__ CNTIN;                 /* Counter Initial Value */
	__REGW__ STATUS;                /* Capture and Compare Status */
	__REGW__ MODE;                  /* Features Mode Selection */
	__REGW__ SYNC;                  /* Synchronization */
	__REGW__ OUTINIT;               /* Initial State for Channels Output */
	__REGW__ OUTMASK;               /* Output Mask */
	__REGW__ COMBINE;               /* Function for Linked Channels */
	__REGW__ DEADTIME;              /* Deadtime Insertion Control */
	__REGW__ EXTTRIG;               /* FTM External Trigger */
	__REGW__ POL;                   /* Channels Polarity */
	__REGW__ FMS;                   /* Fault Mode Status */
	__REGW__ FILTER;                /* Input Capture Filter Control */
	__REGW__ FLTCTRL;               /* Fault Control */
	__REGW__ QDCTRL;                /* Quadrature Decoder Control/Status */
	__REGW__ CONF;                  /* Configuration */
	__REGW__ FLTPOL;                /* FTM Fault Input Polarity */
	__REGW__ SYNCONF;               /* Synchronization Configuration */
	__REGW__ INVCTRL;               /* FTM Inverting Control */
	__REGW__ SWOCTRL;               /* FTM Software Output Control */
	__REGW__ PWMLOAD;               /* FTM PWM Load */
	};

struct __ftm__ FTM0	@0x40038000;
struct __ftm__ FTM1	@0x40039000;
struct __ftm__ FTM2	@0x4003A000;
struct __ftm__ FTM3	@0x40026000;

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

/*	I2S section
 */
struct __i2s__ {
	__REGW__ TCSR;                  /* Transmit Control Register */
	__REGW__ TCR1;                  /* Transmit Configuration Register 1 */
	__REGW__ TCR2;                  /* Transmit Configuration Register 2 */
	__REGW__ TCR3;                  /* Transmit Configuration Register 3 */
	__REGW__ TCR4;                  /* Transmit Configuration Register 4 */
	__REGW__ TCR5;                  /* Transmit Configuration Register 5 */
	__REGW__ reserved_0[2];
	__REGW__ TDR0;                  /* Transmit Data Register */
	__REGW__ reserved_1[7];
	__REGW__ TFR0;                  /* Transmit FIFO Register */
	__REGW__ reserved_2[7];
	__REGW__ TMR;                   /* Transmit Mask Register */
	__REGW__ reserved_3[7];
	__REGW__ RCSR;                  /* Receive Control Register */
	__REGW__ RCR1;                  /* Receive Configuration Register 1 */
	__REGW__ RCR2;                  /* Receive Configuration Register 2 */
	__REGW__ RCR3;                  /* Receive Configuration Register 3 */
	__REGW__ RCR4;                  /* Receive Configuration Register 4 */
	__REGW__ RCR5;                  /* Receive Configuration Register 5 */
	__REGW__ reserved_4[2];
	__REGW__ RDR0;                  /* Receive Data Register */
	__REGW__ reserved_5[7];
	__REGW__ RFR0;                  /* Receive FIFO Register */
	__REGW__ reserved_6[7];
	__REGW__ RMR;                   /* Receive Mask Register */
	__REGW__ reserved_7[7];
	__REGW__ MCR;                   /* MCLK Control Register */
	__REGW__ MDR;                   /* MCLK Divide Register */
	};

struct __i2s__ I2S0	@0x4002F000;

/*	ITM section
 */
struct __itm__ {
	union {
		__REGW__ STIM_READ[32];  /* Stimulus Port Registers */
		__REGW__ STIM_WRITE[32]; /* Stimulus Port Registers */
		};
	__REGW__ reserved_0[864];
	__REGW__ TER;                   /* Trace Enable Register */
	__REGW__ reserved_1[15];
	__REGW__ TPR;                   /* Trace Privilege Register */
	__REGW__ reserved_2[15];
	__REGW__ TCR;                   /* Trace Control Register */
	__REGW__ reserved_3[75];
	__REGW__ LAR;                   /* Lock Access Register */
	__REGW__ LSR;                   /* Lock Status Register */
	__REGW__ reserved_4[6];
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

struct __itm__ ITM	@0xE0000000;

/*	LLWU section
 */
struct __llwu__ {
	__REGB__ PE1;                   /* Pin Enable 1 Register */
	__REGB__ PE2;                   /* Pin Enable 2 Register */
	__REGB__ PE3;                   /* Pin Enable 3 Register */
	__REGB__ PE4;                   /* Pin Enable 4 Register */
	__REGB__ ME;                    /* Module Enable Register */
	__REGB__ F1;                    /* Flag 1 Register */
	__REGB__ F2;                    /* Flag 2 Register */
	__REGB__ F3;                    /* Flag 3 Register */
	__REGB__ CS;                    /* Control and Status Register */
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

/*	LPUART section
 */
struct __lpuart__ {
	__REGW__ BAUD;                   /* Baud Rate Register */
	__REGW__ STAT;                   /* Status Register */
	__REGW__ CTRL;                   /* Control Register */
	__REGW__ DATA;                   /* Data Register */
	__REGW__ MATCH;                  /* Match Register */
	__REGW__ MODIR;                  /* Modem IrDA Register */
	};

struct __lpuart__ LPUART0	@0x4002A000;

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
	__REGB__ C7;                    /* Control Register 7 */
	__REGB__ C8;                    /* Control Register 8 */
	};

struct __mcg__ MCG	@0x40064000;

/*	MCM section
 */
struct __mcm__ {
	__REGW__ reserved_0[2];
	__REGH__ PLASC;                 /* Crossbar slave configuration */
	__REGH__ PLAMC;                 /* Crossbar master configuration */
	__REGW__ SRAMAP;                /* SRAM arbitration and protection */
	__REGW__ ISR;                   /* Interrupt status register */
	__REGW__ ETBCC;                 /* ETB counter control register */
	__REGW__ ETBRL;                 /* ETB reload register */
	__REGW__ ETBCNT;                /* ETB counter value register */
	};

struct __mcm__ MCM	@0xE0080000;

/*	NVIC section
 */
struct __nvic__ {
	__REGW__ ISER[4];               /* Interrupt Set Enable Registers */
	__REGW__ reserved_0[28];
	__REGW__ ICER[4];               /* Interrupt Clear Enable Registers */
	__REGW__ reserved_1[28];
	__REGW__ ISPR[4];               /* Interrupt Set Pending Registers */
	__REGW__ reserved_2[28];
	__REGW__ ICPR[4];               /* Interrupt Clear Pending Registers */
	__REGW__ reserved_3[28];
	__REGW__ IABR[4];               /* Interrupt Active bit Registers */
	__REGW__ reserved_4[60];
	__REGB__ IP[104];               /* Interrupt Priority Registers */
	__REGW__ reserved_5[678];
	__REGW__ STIR[1];               /* Soft Trigger Interrupt Registers */
	};

struct __nvic__ NVIC	@0xE000E100;

/*	OSC section
 */
struct __osc__ {
	__REGB__ CR;                    /* Control Register */
	__REGB__ reserved_0;
	__REGB__ DIV;                   /* Divide Register */
	};

struct __osc__ OSC	@0x40065000;

/*	PDB section
 */
struct __pdb__ {
	__REGW__ SC;                    /* Status and Control Register */
	__REGW__ MOD;                   /* Modulus Register */
	__REGW__ CNT;                   /* Counter Register */
	__REGW__ IDLY;                  /* Interrupt Delay Register */
	struct {
		__REGW__ C1;            /* Channel Control Registers 1 */
		__REGW__ S;             /* Channel Status Register */
		__REGW__ DLY[2];        /* Channel Delay Registers */
		__REGW__ reserved_0[6];
		} CH[2];
	__REGW__ reserved_0[60];
	struct {
		__REGW__ INTC;          /* DAC Interval Trigger Control */
		__REGW__ INT;           /* DAC Interval Registers */
		} DAC[2];
	__REGW__ reserved_1[12];
	__REGW__ POEN;                  /* Pulse-Out n Enable Register */
	__REGW__ PODLY;                 /* Pulse-Out n Delay Register */
	};

struct __pdb__ PDB0	@0x40036000;

/*	PIT section
 */
struct __pit__ {
	__REGW__ MCR;                   /* PIT Module Control Register */
	__REGW__ reserved_0[63];
	struct {
		__REGW__ LDVAL;         /* Timer Load Value Register */
		__REGW__ CVAL;          /* Current Timer Value Register */
		__REGW__ TCTRL;         /* Timer Control Register */
		__REGW__ TFLG;          /* Timer Flag Register */
		} CHANNEL[4];
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
	__REGW__ reserved_1[7];
	__REGW__ DFER;                  /* Digital Filter Enable Register */
	__REGW__ DFCR;                  /* Digital Filter Clock Register */
	__REGW__ DFWR;                  /* Digital Filter Width Register */
	};

struct __port__ PORTA	@0x40049000;
struct __port__ PORTB	@0x4004A000;
struct __port__ PORTC	@0x4004B000;
struct __port__ PORTD	@0x4004C000;
struct __port__ PORTE	@0x4004D000;

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

/*	RCM section
 */
struct __rcm__ {
	__REGB__ SRS0;                  /* System Reset Status Register 0 */
	__REGB__ SRS1;                  /* System Reset Status Register 1 */
	__REGB__ reserved_0[2];
	__REGB__ RPFC;                  /* Reset Pin Filter Control Register */
	__REGB__ RPFW;                  /* Reset Pin Filter Width Register */
	__REGB__ reserved_1;
	__REGB__ MR;                    /* Mode Register */
	__REGB__ SSRS0;                 /* Sticky Reset Status Register 0 */
	__REGB__ SSRS1;                 /* Sticky Reset Status Register 1 */
	};

struct __rcm__ RCM	@0x4007F000;

/*	RFSYS section
 */
struct __rfsys__ {
	__REGW__ REG[8];                /* SYS register file */
	};

struct __rfsys__ RFSYS	@0x40041000;

/*	RFVBAT section
 */
struct __rfvbat__ {
	__REGW__ REG[8];                /* VBAT register file */
	};

struct __rfvbat__ RFVBAT	@0x4003E000;

/*	RNG section
 */
struct __rng__ {
	__REGW__ CR;                    /* Control Register */
	__REGW__ SR;                    /* Status Register */
	__REGW__ ER;                    /* Entropy Register */
	__REGW__ OR;                    /* Output Register */
	};

struct __rng__ RNG	@0x40029000;

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
	__REGW__ CCR;                   /* Chip Configuration Register */
	__REGW__ reserved_0[504];
	__REGW__ WAR;                   /* Write Access Register */
	__REGW__ RAR;                   /* Read Access Register */
	};

struct __rtc__ RTC	@0x4003D000;

/*	SIM section
 */
struct __sim__ {
	__REGW__ SOPT1;                 /* System Options Register 1 */
	__REGW__ reserved_0[1024];
	__REGW__ SOPT2;                 /* System Options Register 2 */
	__REGW__ reserved_1;
	__REGW__ SOPT4;                 /* System Options Register 4 */
	__REGW__ SOPT5;                 /* System Options Register 5 */
	__REGW__ SOPT6;                 /* System Options Register 6 */
	__REGW__ SOPT7;                 /* System Options Register 7 */
	__REGW__ reserved_2[2];
	__REGW__ SDID;                  /* System Device Identification */
	__REGW__ SCGC1;                 /* System Clock Gating Control 1 */
	__REGW__ SCGC2;                 /* System Clock Gating Control 2 */
	__REGW__ SCGC3;                 /* System Clock Gating Control 3 */
	__REGW__ SCGC4;                 /* System Clock Gating Control 4 */
	__REGW__ SCGC5;                 /* System Clock Gating Control 5 */
	__REGW__ SCGC6;                 /* System Clock Gating Control 6 */
	__REGW__ SCGC7;                 /* System Clock Gating Control 7 */
	__REGW__ CLKDIV1;               /* System Clock Divider Register 1 */
	__REGW__ CLKDIV2;               /* System Clock Divider Register 2 */
	__REGW__ FCFG1;                 /* Flash Configuration Register 1 */
	__REGW__ FCFG2;                 /* Flash Configuration Register 2 */
	__REGW__ UIDH;                  /* Unique Id Register High */
	__REGW__ UIDMH;                 /* Unique Id Register Mid-High */
	__REGW__ UIDML;                 /* Unique Id Register Mid Low */
	__REGW__ UIDL;                  /* Unique Id Register Low */
	};

struct __sim__ SIM	@0x40047000;

/*	SMC section
 */
struct __smc__ {
	__REGW__ PMPROT;                 /* Power Mode Protection Register */
	__REGW__ PMCTRL;                 /* Power Mode Control Register */
	__REGW__ STOPCTRL;               /* Stop Control Register */
	__REGW__ PMSTAT;                 /* Power Mode Satatus Register */
	};

struct __smc__ SMC	@0x4007E000;

/*	SPI section
 */
struct __spi__ {
	__REGW__ MCR;                   /* Module Configuration Register */
	__REGW__ reserved_0;
	__REGW__ TCR;                   /* Transfer Count Register */
	union {
		__REGW__ CTAR[2];       /* Clock/Transfer Master */
		__REGW__ CTAR_SLAVE[1]; /* Clock/Transfer Slave */
		};
	__REGW__ reserved_1[6];
	__REGW__ SR;                    /* Status Register */
	__REGW__ RSER;                  /* DMA/Interrupt Req Select/Enable */
	union {
		__REGW__ PUSHR;         /* PUSH TX FIFO Register Master */
		__REGW__ PUSHR_SLAVE;   /* PUSH TX FIFO Register Slave */
		};
	__REGW__ POPR;                  /* POP RX FIFO Register */
	__REGW__ TXFR0;                 /* Transmit FIFO Register 0 */
	__REGW__ TXFR1;                 /* Transmit FIFO Register 1 */
	__REGW__ TXFR2;                 /* Transmit FIFO Register 2 */
	__REGW__ TXFR3;                 /* Transmit FIFO Register 3 */
	__REGW__ reserved_2[12];
	__REGW__ RXFR0;                 /* Receive FIFO Register 0 */
	__REGW__ RXFR1;                 /* Receive FIFO Register 1 */
	__REGW__ RXFR2;                 /* Receive FIFO Register 2 */
	__REGW__ RXFR3;                 /* Receive FIFO Register 3 */
	};

struct __spi__ SPI0	@0x4002C000;
struct __spi__ SPI1	@0x4002D000;

/*	SYSTICK section
 */
struct __systick__ {
	__REGW__ CSR;                   /* Control and Status Register */
	__REGW__ RVR;                   /* Reload Value Register */
	__REGW__ CVR;                   /* Current Value Register */
	__REGW__ CALIB;                 /* Calibration Value Register */
	};

struct __systick__ SysTick	@0xE000E010;

/*	SCB section
 */
struct __scb__ {
	__REGW__ reserved_0[2];
	__REGW__ ACTLR;                 /* Auxiliary Control Register*/
	__REGW__ reserved_1[829];
	__REGW__ CPUID;                 /* CPUID Base Register */
	__REGW__ ICSR;                  /* Interrupt Control/State Register */
	__REGW__ VTOR;                  /* Vector Table Offset Register */
	__REGW__ AIRCR;                 /* Application Interrupt/Reset Ctrl */
	__REGW__ SCR;                   /* System Control Register */
	__REGW__ CCR;                   /* Configuration and Control Reg */
	__REGW__ SHPR1;                 /* System Handler Prio Register 1 */
	__REGW__ SHPR2;                 /* System Handler Prio Register 2 */
	__REGW__ SHPR3;                 /* System Handler Prio Register 3 */
	__REGW__ SHCSR;                 /* System Handler Control/State Reg */
	__REGW__ CFSR;                  /* Configurable Fault Status Reg */
	__REGW__ HFSR;                  /* HardFault Status register */
	__REGW__ DFSR;                  /* Debug Fault Status Register */
	__REGW__ MMFAR;                 /* MemManage Address Register */
	__REGW__ BFAR;                  /* BusFault Address Register */
	__REGW__ AFSR;                  /* Auxiliary Fault Status Register */
	};

struct __scb__ SystemControl	@0xE000E000;

/*	TPIU section
 */
struct __tpiu__ {
	__REGW__ SSPSR;                 /* Supported Parallel Port Size Reg */
	__REGW__ CSPSR;                 /* Current Parallel Port Size Reg */
	__REGW__ reserved_0[2];
	__REGW__ ACPR;                  /* Asynchronous Clock Prescaler Reg */
	__REGW__ reserved_1[55];
	__REGW__ SPPR;                  /* Selected Pin Protocol Register */
	__REGW__ reserved_2[131];
	__REGW__ FFSR;                  /* Formatter and Flush Status Reg */
	__REGW__ FFCR;                  /* Formatter and Flush Control Reg */
	__REGW__ FSCR;                  /* Formatter Synchronization Counter */
	__REGW__ reserved_3[759];
	__REGW__ TRIGGER;               /* Trigger Register */
	__REGW__ FIFODATA0;             /* FIFODATA0 Register */
	__REGW__ ITATBCTR2;             /* Integration Test ATB Control 2 */
	__REGW__ reserved_4;
	__REGW__ ITATBCTR0;             /* Integration Test ATB Control 0 */
	__REGW__ FIFODATA1;             /* FIFODATA1 Register */
	__REGW__ ITCTRL;                /* Integration Mode Control Register */
	__REGW__ reserved_5[39];
	__REGW__ CLAIMSET;              /* Claim Tag Set Register */
	__REGW__ CLAIMCLR;              /* Claim Tag Clear Register */
	__REGW__ reserved_6[8];
	__REGW__ DEVID;                 /* TPIU_DEVID Register */
	__REGW__ reserved;
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
	__REGW__ CID4;                  /* Component Identification Reg 3 */
	};

struct __tpiu__ TPIU	@0xE0040000;

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
	__REGB__ MA1;                   /* Match Address Registers 1 */
	__REGB__ MA2;                   /* Match Address Registers 2 */
	__REGB__ C4;                    /* Control Register 4 */
	__REGB__ C5;                    /* Control Register 5 */
	__REGB__ ED;                    /* Extended Data Register */
	__REGB__ MODEM;                 /* Modem Register */
	__REGB__ IR;                    /* Infrared Register */
	__REGB__ reserved_0;
	__REGB__ PFIFO;                 /* FIFO Parameters */
	__REGB__ CFIFO;                 /* FIFO Control Register */
	__REGB__ SFIFO;                 /* FIFO Status Registe */
	__REGB__ TWFIFO;                /* FIFO Transmit Watermark */
	__REGB__ TCFIFO;                /* FIFO Transmit Count */
	__REGB__ RWFIFO;                /* FIFO Receive Watermark */
	__REGB__ RCFIFO;                /* FIFO Receive Count */
	__REGB__ reserved_1;
	__REGB__ C7816;                 /* 7816 Control Register */
	__REGB__ IE7816;                /* 7816 Interrupt Enable Register */
	__REGB__ IS7816;                /* 7816 Interrupt Status Register */
	union {
		__REGB__ WP7816_T_TYPE0; /* 7816 Wait Parameter Register */
		__REGB__ WP7816_T_TYPE1; /* 7816 Wait Parameter Register */
		};
	__REGB__ WN7816;               /* 7816 Wait N Register */
	__REGB__ WF7816;               /* 7816 Wait FD Register */
	__REGB__ ET7816;               /* 7816 Error Threshold Register */
	__REGB__ TL7816;               /* 7816 Transmit Length Register */
	};

struct __uart__ UART0	@0x4006A000;
struct __uart__ UART1	@0x4006B000;
struct __uart__ UART2	@0x4006C000;

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

/*	VREF section
 */
struct __vref__ {
	__REGB__ reserved_0;
	__REGB__ SC;                    /* Status and Control Register */
	};

struct __vref__ VREF	@0x40074000;

/*	WDOG section
 */
struct __wdog__ {
	__REGH__ STCTRLH;               /* Status and Control Register High */
	__REGH__ STCTRLL;               /* Status and Control Register Low */
	__REGH__ TOVALH;                /* Time-out Value Register High */
	__REGH__ TOVALL;                /* Time-out Value Register Low */
	__REGH__ WINH;                  /* Window Register High */
	__REGH__ WINL;                  /* Window Register Low */
	__REGH__ REFRESH;               /* Refresh Register */
	__REGH__ UNLOCK;                /* Unlock Register */
	__REGH__ TMROUTH;               /* Timer Output Register High */
	__REGH__ TMROUTL;               /* Timer Output Register Low */
	__REGH__ RSTCNT;                /* Reset Count Register */
	__REGH__ PRESC;                 /* Prescaler Register */
	};

struct __wdog__ WDOG	@0x40052000;
