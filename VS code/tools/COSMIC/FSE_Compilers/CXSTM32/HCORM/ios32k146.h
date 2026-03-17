/*	IO DEFINITIONS FOR S32K146
 *	Copyright (c) 2018 by COSMIC SOftware
 */
typedef volatile unsigned char __REGB__;
typedef volatile unsigned short __REGH__;
typedef volatile unsigned int __REGW__;

/*	ADC section
 */
struct __adc__ {
	__REGW__ SC1[16];               /* status and control registers 1 */
	__REGW__ CFG1;                  /* configuration register 1 */
	__REGW__ CFG2;                  /* configuration register 2 */
	__REGW__ R[16];                 /* data result register */
	__REGW__ CV[2];                 /* compare value register 1 */
	__REGW__ SC2;                   /* status and control register 2 */
	__REGW__ SC3;                   /* status and control register 3 */
	__REGW__ BASE_OFS;              /* offset correction register */
	__REGW__ OFS;                   /* offset correction register */
	__REGW__ USR_OFS;               /* user offset correction register */
	__REGW__ XOFS;                  /* X offset correction register */
	__REGW__ YOFS;                  /* Y offset correction register */
	__REGW__ G;                     /* gain register */
	__REGW__ UG;                    /* user gain register */
	__REGW__ CLPS;                  /* general calibration value register */
	__REGW__ CLP3;                  /* plus calibration value register */
	__REGW__ CLP2;                  /* plus calibration value register */
	__REGW__ CLP1;                  /* plus calibration value register */
	__REGW__ CLP0;                  /* plus calibration value register */
	__REGW__ CLPX;                  /* plus calibration value register */
	__REGW__ CLP9;                  /* plus calibration value register */
	__REGW__ CLPS_OFS;              /* general calibration value register */
	__REGW__ CLP3_OFS;              /* plus calibration value register */
	__REGW__ CLP2_OFS;              /* plus calibration value register */
	__REGW__ CLP1_OFS;              /* plus calibration value register */
	__REGW__ CLP0_OFS;              /* plus calibration value register */
	__REGW__ CLPX_OFS;              /* plus calibration value register */
	__REGW__ CLP9_OFS;              /* plus calibration value register */
	};

struct __adc__ ADC0	@0x4003B000;
struct __adc__ ADC1	@0x40027000;

/*	AIPS section
 */
struct __aips__ {
	__REGW__ MPRA;                  /* Master Privilege Register A */
	__REGW__ reserved_0[7];
	__REGW__ PACR[4];               /* Peripheral Access Control Register */
	__REGW__ reserved_1[4];
	__REGW__ OPACR[16];             /* Off-Platform Peripheral Access Control Register */
	__REGW__ PACRU;                 /* Peripheral Access Control Register */
	};

struct __aips__ AIPS	@0x40000000;

/*	CAN section
 */
struct __buf__ {
	__REGW__ CS;                    /* Message Buffer CS Register */
	__REGW__ ID;                    /* Message Buffer ID Register */
	__REGW__ D03;                   /* Message Buffer Data 0-3 Register */
	__REGW__ D47;                   /* Message Buffer Data 4-7 Register */
	};

struct __can__ {
	__REGW__ MCR;                   /* Module Configuration Register */
	__REGW__ CTRL1;                 /* Control 1 Register */
	__REGW__ TIMER;                 /* Free Running Timer */
	__REGW__ reserved_0;
	__REGW__ RXMGMASK;              /* Rx Mailboxes Global Mask Register */
	__REGW__ RX14MASK;              /* Rx 14 Mask Register */
	__REGW__ RX15MASK;              /* Rx 15 Mask Register */
	__REGW__ ECR;                   /* Error Counter */
	__REGW__ ESR1;                  /* Error and Status 1 Register */
	__REGW__ reserved_1;
	__REGW__ IMASK1;                /* Interrupt Masks 1 Register */
	__REGW__ reserved_2;
	__REGW__ IFLAG1;                /* Interrupt Flags 1 Register */
	__REGW__ CTRL2;                 /* Control 2 Register */
	__REGW__ ESR2;                  /* Error and Status 2 Register */
	__REGW__ reserved_3[2];
	__REGW__ CRCR;                  /* CRC Register */
	__REGW__ RXFGMASK;              /* Rx FIFO Global Mask Register */
	__REGW__ RXFIR;                 /* Rx FIFO Information Register */
	__REGW__ reserved_4[11];
	__REGW__ RAMn[64];              /* Embedded RAM */
	__REGW__ reserved_5[448];
	__REGW__ RXIMR[16];             /* Rx Individual Mask Registers */
	__REGW__ reserved_6[144];
	__REGW__ CTRL1_PN;              /* Pretended Networking Control 1 Register */
	__REGW__ CTRL2_PN;              /* Pretended Networking Control 2 Register */
	__REGW__ WU_MTC;                /* Pretended Networking Wake Up Match Register */
	__REGW__ FLT_ID1;               /* Pretended Networking ID Filter 1 Register */
	__REGW__ FLT_DLC;               /* Pretended Networking DLC Filter Register */
	__REGW__ PL1_LO;                /* Pretended Networking Payload Low Filter 1 Register */
	__REGW__ PL1_HI;                /* Pretended Networking Payload High Filter 1 Register */
	__REGW__ FLT_ID2_IDMASK;        /* Pretended Networking ID Filter 2 Register / ID Mask Register */
	__REGW__ PL2_PLMASK_LO;         /* Pretended Networking Payload Low Filter 2 Register / Payload Low Mask Register */
	__REGW__ PL2_PLMASK_HI;         /* Pretended Networking Payload High Filter 2 low order bits / Payload High Mask Register */
	__REGW__ reserved_7[6];
	struct __buf__ WMB[4];          /* Wake Up Message Buffers */
	__REGW__ reserved_8[32];
	__REGW__ FDCTRL;                /* CAN FD Control Register */
	__REGW__ FDCBT;                 /* CAN FD Bit Timing Register */
	__REGW__ FDCRC;                 /* CAN FD CRC Register */
	};

struct __can__ CAN0	@0x40024000;
struct __can__ CAN1	@0x40025000;
struct __can__ CAN2	@0x4002B000;

/*	CMP section
 */
struct __cmp__ {
	__REGW__ C0;                    /* Control Register 0 */
	__REGW__ C1;                    /* Control Register 1 */
	__REGW__ C2;                    /* Control Register 2 */
	};

struct __cmp__ CMP0	@0x40073000;

/*	CRC section
 */
struct __crc__ {
	union {
		__REGW__ DATA;              /* Data Register word */
		struct {
			__REGH__ L;             /* Data register half word low */
			__REGH__ H;             /* Data register half word high */
			} DATA_16;
		struct {
			__REGB__ LL;            /* Data register byte low lower*/
			__REGB__ LU;            /* Data register byte low upper */
			__REGB__ HL;            /* Data register byte high lower */
			__REGB__ HU;            /* Data register byte highupper */
			} DATA_8;
		} DATAu;
	__REGW__ GPOLY;                 /* Polynomial Register */
	__REGW__ CTRL;                  /* Control Register */
	};

struct __crc__ CRC	@0x40032000;

/*	DMA section
 */
struct __tcd__{
	__REGW__ SADDR;                 /* Source Address */
	__REGH__ SOFF;                  /* Signed Source Address Offset */
	__REGH__ ATTR;                  /* Transfer Attributes */
	union {
		__REGW__ MLNO;              /* Minor Byte Count */
		__REGW__ MLOFFNO;           /* Signed Minor Loop Offset */
		__REGW__ MLOFFYES;          /* Signed Minor Loop Offset */
		} NBYTES;
	__REGW__ SLAST;                 /* Last Source Address Adjust */
	__REGW__ DADDR;                 /* Destination Address */
	__REGH__ DOFF;                  /* Signed Dest Address Offset */
	union {
		__REGH__ ELINKNO;           /* Current Minor Loop Link */
		__REGH__ ELINKYES;          /* Current Minor Loop Link */
		} CITER;
	__REGW__ DLASTSGA;              /* Last Dest Address Adjustment */
	__REGH__ CSR;                   /* Control and Status */
	union {
		__REGH__ ELINKNO;           /* Beginning Minor Loop Link */
		__REGH__ ELINKYES;          /* Beginning Minor Loop Link */
		} BITER;
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
	__REGW__ reserved_5[3];
	__REGW__ EARS;                  /* Enable Asynchronous Request in Stop Register */
	__REGW__ reserved_6[46];
	__REGB__ DCHPRI[16];            /* Channel n Priority Register */
	__REGW__ reserved_7[956];
	struct __tcd__ TCD[16];
	};

struct __dma__ DMA	@0x40008000;

/*	DMAMUX section
 */
struct __dmamux__ {
	__REGB__ CHCFG[16];             /* Channel Configuration Register */
	};

struct __dmamux__ DMAMUX @0x40021000;

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

/*	FLEXIO section
 */
struct __flexio__ {
	__REGW__ VERID;                 /* Version ID Register */
	__REGW__ PARAM;                 /* Parameter Register */
	__REGW__ CTRL;                  /* FlexIO Control Register */
	__REGW__ PIN;                   /* Pin State Register */
	__REGW__ SHIFTSTAT;             /* Shifter Status Register */
	__REGW__ SHIFTERR;              /* Shifter Error Register */
	__REGW__ TIMSTAT;               /* Timer Status Register */
	__REGW__ reserved_0;
	__REGW__ SHIFTSIEN;             /* Shifter Status Interrupt Enable */
	__REGW__ SHIFTEIEN;             /* Shifter Error Interrupt Enable */
	__REGW__ TIMIEN;                /* Timer Interrupt Enable Register */
	__REGW__ reserved_1;
	__REGW__ SHIFTSDEN;             /* Shifter Status DMA Enable */
	__REGW__ reserved_2[3];
	__REGW__ SHIFTSTATE;            /* Shifter State Register */
	__REGW__ reserved_3[15];
	__REGW__ SHIFTCTL[4];           /* Shifter Control N Register */
	__REGW__ reserved_4[28];
	__REGW__ SHIFTCFG[4];           /* Shifter Configuration N Register */
	__REGW__ reserved_5[60];
	__REGW__ SHIFTBUF[4];           /* Shifter Buffer N Register */
	__REGW__ reserved_6[28];
	__REGW__ SHIFTBUFBIS[4];        /* Shifter Buffer N Bit Swapped Register */
	__REGW__ reserved_7[28];
	__REGW__ SHIFTBUFBYS[4];        /* Shifter Buffer N Byte Swapped Register */
	__REGW__ reserved_8[28];
	__REGW__ SHIFTBUFBBS[4];        /* Shifter Buffer N Bit Byte Swapped Register */
	__REGW__ reserved_9[28];
	__REGW__ TIMCTL[4];             /* Timer Control N Register */
	__REGW__ reserved_10[28];
	__REGW__ TIMCFG[4];             /* Timer Configuration N Register */
	__REGW__ reserved_11[28];
	__REGW__ TIMCMP[4];             /* Timer Compare N Register */
	};

struct __flexio__ FLEXIO	@0x4005A000;

/*	FSL_NVIC section
 */
struct __fsl_nvic__ {
	__REGW__ ISER[4];               /* Interrupt Set Enable Register n */
	__REGW__ reserved_0[28];
	__REGW__ ICER[4];               /* Interrupt Clear Enable Register n */
	__REGW__ reserved_1[28];
	__REGW__ ISPR[4];               /* Interrupt Set Pending Register n */
	__REGW__ reserved_2[28];
	__REGW__ ICPR[4];               /* Interrupt Clear Pending Register n */
	__REGW__ reserved_3[28];
	__REGW__ IABR[4];               /* Interrupt Active bit Register n */
	__REGW__ reserved_4[60];
	__REGB__ IP[106];               /* Interrupt Priority Register n */
	__REGB__ reserved_5[2710];
	__REGW__ STIR[1];               /* Software Trigger Interrupt Register */
	};

struct __fsl_nvic__ FSL_NVIC	@0xE000E100;

/*	FSL_SCB section
 */
struct __fsl_scb__ {
	__REGW__ reserved_0[2];
	__REGW__ ACTLR;                 /* Auxiliary Control Register */
	__REGW__ reserved_1[829];
	__REGW__ CPUID;                 /* CPUID Base Register */
	__REGW__ ICSR;                  /* Interrupt Control and State Register */
	__REGW__ VTOR;                  /* Vector Table Offset Register */
	__REGW__ AIRCR;                 /* Application Interrupt and Reset Control Register */
	__REGW__ SCR;                   /* System Control Register */
	__REGW__ CCR;                   /* Configuration and Control Register */
	__REGW__ SHPR1;                 /* System Handler Priority Register 1 */
	__REGW__ SHPR2;                 /* System Handler Priority Register 2 */
	__REGW__ SHPR3;                 /* System Handler Priority Register 3 */
	__REGW__ SHCSR;                 /* System Handler Control and State Register */
	__REGW__ CFSR;                  /* Configurable Fault Status Registers */
	__REGW__ HFSR;                  /* HardFault Status register */
	__REGW__ DFSR;                  /* Debug Fault Status Register */
	__REGW__ MMFAR;                 /* MemManage Address Register */
	__REGW__ BFAR;                  /* BusFault Address Register */
	__REGW__ AFSR;                  /* Auxiliary Fault Status Register */
	__REGW__ reserved_2[18];
	__REGW__ CPACR;                 /* Coprocessor Access Control Register */
	__REGW__ reserved_3[106];
	__REGW__ FPCCR;                 /* Floating-point Context Control Register */
	__REGW__ FPCAR;                 /* Floating-point Context Address Register */
	__REGW__ FPDSCR;                /* Floating-point Default Status Control Register */
	};

struct __fsl_scb__ FSL_SCB	@0xE000E100;

/*	FSL_SysTick section
 */
struct __fsl_systick__ {
	__REGW__ CSR;                   /* SysTick Control and Status Register */
	__REGW__ RVR;                   /* SysTick Reload Value Register */
	__REGW__ CVR;                   /* SysTick Current Value Register */
	__REGW__ CALIB;                 /* SysTick Calibration Value Register */
	};

struct __fsl_systick__ FSL_SysTick	@0xE000E010;

/*	FTFE section
 */
struct __ftfe__ {
	__REGB__ FSTAT;                  /* Flash Status Register */
	__REGB__ FCNFG;                  /* Flash Configuration Register */
	__REGB__ FSEC;                   /* Flash Security Register */
	__REGB__ FOPT;                   /* Flash Option Register */
	__REGB__ FCCOB[12];              /* Flash Command Register */
	__REGB__ FPROT[4];               /* Program Flash Prot Register */
	__REGB__ reserved_0[2];
	__REGB__ FEPROT;                 /* EEPROM Protection Register */
	__REGB__ FDPROT;                 /* Data Flash Protection Register */
	__REGB__ reserved_1[22];
	__REGB__ FERSTAT;                /* Flash Error Status Register */
	__REGB__ FERCNFG;                /* Flash Error Configuration Register */
	};

struct __ftfe__ FTFE	@0x40020000;

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
	__REGW__ HCR;                   /* Half Cycle Register */
	};

struct __ftm__ FTM0	@0x40038000;
struct __ftm__ FTM1	@0x40039000;
struct __ftm__ FTM2	@0x4003A000;
struct __ftm__ FTM3	@0x40026000;

/*	GPIO section
 */
struct __gpio__ {
	__REGW__ PDOR;                  /* Port Data Output Register */
	__REGW__ PSOR;                  /* Port Set Output Register */
	__REGW__ PCOR;                  /* Port Clear Output Register */
	__REGW__ PTOR;                  /* Port Toggle Output Register */
	__REGW__ PDIR;                  /* Port Data Input Register */
	__REGW__ PDDR;                  /* Port Data Direction Register */
	};

struct __gpio__ PTA	@0x400FF000;
struct __gpio__ PTB	@0x400FF040;
struct __gpio__ PTC	@0x400FF080;
struct __gpio__ PTD	@0x400FF0C0;
struct __gpio__ PTE	@0x400FF100;

/*	LMEM section
 */
struct __lmem__ {
	__REGW__ PCCCR;                 /* Cache control register */
	__REGW__ PCCLCR;                /* Cache line control register */
	__REGW__ PCCSAR;                /* Cache search address register */
	__REGW__ PCCCVR;                /* Cache read/write value register */
	__REGW__ reserved_0[4];
	__REGW__ PCCRMR;                /* Cache regions mode register */
	};

struct __lmem__ LMEM	@0xE0082000;

/*	LPI2C section
 */
struct __lpi2c__ {
	__REGW__ VERID;                 /* Version ID Register */
	__REGW__ PARAM;                 /* Parameter Register */
	__REGW__ reserved_0[2];
	__REGW__ MCR;                   /* Master Control Register */
	__REGW__ MSR;                   /* Master Status Register */
	__REGW__ MIER;                  /* Master Interrupt Enable Register */
	__REGW__ MDER;                  /* Master DMA Enable Register */
	__REGW__ MCFGR0;                /* Master Configuration Register 0 */
	__REGW__ MCFGR1;                /* Master Configuration Register 1 */
	__REGW__ MCFGR2;                /* Master Configuration Register 2 */
	__REGW__ MCFGR3;                /* Master Configuration Register 3 */
	__REGW__ reserved_1[4];
	__REGW__ MDMR;                  /* Master Data Match Register */
	__REGW__ reserved_2;
	__REGW__ MCCR0;                 /* Master Clock Configuration Register 0 */
	__REGW__ reserved_3;
	__REGW__ MCCR1;                 /* Master Clock Configuration Register 1 */
	__REGW__ reserved_4;
	__REGW__ MFCR;                  /* Master FIFO Control Register */
	__REGW__ MFSR;                  /* Master FIFO Status Register */
	__REGW__ MTDR;                  /* Master Transmit Data Register */
	__REGW__ reserved_5[3];
	__REGW__ MRDR;                  /* Master Receive Data Register */
	__REGW__ reserved_6[39];
	__REGW__ SCR;                   /* Slave Control Register */
	__REGW__ SSR;                   /* Slave Status Register */
	__REGW__ SIER;                  /* Slave Interrupt Enable Register */
	__REGW__ SDER;                  /* Slave DMA Enable Register */
	__REGW__ reserved_7;
 	__REGW__ SCFGR1;                /* Slave Configuration Register 1 */
 	__REGW__ SCFGR2;                /* Slave Configuration Register 2 */
	__REGW__ reserved_8[5];
	__REGW__ SAMR;                  /* Slave Address Match Register */
	__REGW__ reserved_9[3];
 	__REGW__ SASR;                  /* Slave Address Status Register */
 	__REGW__ STAR;                  /* Slave Transmit ACK Register */
	__REGW__ reserved_10[2];
	__REGW__ STDR;                  /* Slave Transmit Data Register */
	__REGW__ reserved_11[3];
	__REGW__ SRDR;                  /* Slave Receive Data Register */
	};

struct __lpi2c__ LPI2C0	@0x40066000;
struct __lpi2c__ LPI2C1	@0x40067000;

/*	LPIT section
 */
struct __lpit__ {
	__REGW__ VERID;                 /* Version ID Register */
	__REGW__ PARAM;                 /* Parameter Register */
	__REGW__ MCR;                   /* Module Control Register */
	__REGW__ MSR;                   /* Module Status Register */
	__REGW__ MIER;                  /* Module Interrupt Enable Register */
	__REGW__ SETTEN;                /* Set Timer Enable Register */
	__REGW__ CLRTEN;                /* Clear Timer Enable Register */
	__REGW__ reserved_0;
	struct {
		__REGW__ TVAL;              /* Timer Value Register */
		__REGW__ CVAL;              /* Current Timer Value */
		__REGW__ TCTRL;             /* Timer Control Register */
		__REGW__ reserved_1;
 		} TVAL_CVAL_TCTRL[4];
	};

struct __lpit__ LPIT0	@0x40037000;

/*	LPSPI section
 */
struct __lpspi__ {
	__REGW__ VERID;                 /* Version ID Register */
	__REGW__ PARAM;                 /* Parameter Register */
	__REGW__ reserved_0[2];
	__REGW__ CR;                    /* Control Register */
	__REGW__ SR;                    /* Status Register */
	__REGW__ IER;                   /* Interrupt Enable Register */
	__REGW__ DER;                   /* DMA Enable Register */
	__REGW__ CFGR0;                 /* Configuration Register 0 */
	__REGW__ CFGR1;                 /* Configuration Register 1 */
	__REGW__ reserved_1[2];
	__REGW__ DMR0;                  /* Data Match Register 0 */
	__REGW__ DMR1;                  /* Data Match Register 1 */
	__REGW__ reserved_2[2];
	__REGW__ CCR;                   /* Clock Configuration Register */
	__REGW__ reserved_3[5];
	__REGW__ FCR;                   /* FIFO Control Register */
	__REGW__ FSR;                   /* FIFO Status Register */
	__REGW__ TCR;                   /* Transmit Command Register */
	__REGW__ TDR;                   /* Transmit Data Register */
	__REGW__ reserved_4[2];
	__REGW__ RSR;                   /* Receive Status Register */
	__REGW__ RDR;                   /* Receive Data Register */
	};

struct __lpspi__ LPSP0	@0x4002C000;
struct __lpspi__ LPSP1	@0x4002D000;
struct __lpspi__ LPSP2	@0x4002E000;

/*	LPTMR section
 */
struct __lptmr__ {
	__REGW__ CSR;                   /* Low Power Timer Control Status Register */
	__REGW__ PSR;                   /* Low Power Timer Prescale Register */
	__REGW__ CMR;                   /* Low Power Timer Compare Register */
	__REGW__ CNR;                   /* Low Power Timer Counter Register */
	};

struct __lptmr__ LPTMR0	@0x40040000;

/*	LPUART section
 */
struct __lpuart__ {
	__REGW__ VERID;                 /* Version ID Register */
	__REGW__ PARAM;                 /* Parameter Register */
	__REGW__ GLOBAL;                /* LPUART Global Register */
	__REGW__ PINCFG;                /* LPUART Pin Configuration Register */
	__REGW__ BAUD;                  /* LPUART Baud Rate Register */
	__REGW__ STAT;                  /* LPUART Status Register */
	__REGW__ CTRL;                  /* LPUART Control Register */
	__REGW__ DATA;                  /* LPUART Data Register */
	__REGW__ MATCH;                 /* LPUART Match Address Register */
	__REGW__ MODIR;                 /* LPUART Modem IrDA Register */
	__REGW__ FIFO;                  /* LPUART FIFO Register */
	__REGW__ WATER;                 /* LPUART Watermark Register */
	};

struct __lpuart__ LPUART0	@0x4006A000;
struct __lpuart__ LPUART1	@0x4006B000;
struct __lpuart__ LPUART2	@0x4006C000;
struct __lpuart__ LPUART3	@0x4006D000;

/*	MCM section
 */
struct __mcm__ {
 	__REGW__ reserved_0[2];
	__REGH__ PLASC;                 /* Crossbar Switch (AXBS) Slave Configuration */
	__REGH__ PLAMC;                 /* Crossbar Switch (AXBS) Master Configuration */
	__REGW__ CPCR;                  /* Core Platform Control Register */
	__REGW__ ISCR;                  /* Interrupt Status and Control Register */
 	__REGW__ reserved_1[3];
	__REGW__ FADR;                  /* Store Buffer Fault address register */
	__REGW__ FATR;                  /* Store Buffer Fault Attributes register */
	__REGW__ FDR;                   /* Store Buffer Fault Data Register */
 	__REGW__ reserved_2;
	__REGW__ PID;                   /* Process ID register */
 	__REGW__ reserved_3[3];
	__REGW__ CPO;                   /* Compute Operation Control Register */
 	__REGW__ reserved_4[239];
	__REGW__ LMDR[3];               /* Local Memory Descriptor Register */
 	__REGW__ reserved_5[29];
	__REGW__ LMPECR;                /* LMEM Parity & ECC Control Register */
 	__REGW__ reserved_6;
	__REGW__ LMPEIR;                /* LMEM Parity & ECC Interrupt Register */
 	__REGW__ reserved_7;
	__REGW__ LMFAR;                 /* LMEM Fault Address Register */
	__REGW__ LMFATR;                /* LMEM Fault Attribute Register */
 	__REGW__ reserved_8[2];
	__REGW__ LMFDHR;                /* LMEM Fault Data High Register */
	__REGW__ LMFDLR;                /* LMEM Fault Data Low Register */
	};

struct __mcm__ MCM	@0xE0080000;

/*	MPU section
 */
struct __mpu__ {
	__REGW__ CESR;                  /* Control/Error Status Register */
	__REGW__ reserved_0[3];
	struct {
		__REGW__ EAR;               /* Error Address Register */
		__REGW__ EDR;               /* Error Detail Register */
		} EAR_EDR[8];
	__REGW__ reserved_1[236];
	struct {
		__REGW__ WORD0;             /* Region Descriptor n, Word 0 */
		__REGW__ WORD1;             /* Region Descriptor n, Word 1 */
		__REGW__ WORD2;             /* Region Descriptor n, Word 2 */
		__REGW__ WORD3;             /* Region Descriptor n, Word 3 */
		} RGD[8];
	__REGW__ reserved_2[224];
	__REGW__ RGDAAC[8];             /* Region Desc Alt Access Control */
	};

struct __mpu__ MPU	@0x4000D000;

/*	MSCM section
 */
struct __mscm__ {
	__REGW__ CPxTYPE;               /* Processor X Type Register */
	__REGW__ CPxNUM;                /* Processor X Number Register */
	__REGW__ CPxMASTER;             /* Processor X Master Register */
	__REGW__ CPxCOUNT;              /* Processor X Count Register */
	__REGW__ CPxCFG[4];             /* Processor X Configuration Register */
	__REGW__ CP0TYPE;               /* Processor 0 Type Register */
	__REGW__ CP0NUM;                /* Processor 0 Number Register */
	__REGW__ CP0MASTER;             /* Processor 0 Master Register */
	__REGW__ CP0COUNT;              /* Processor 0 Count Register */
	__REGW__ CP0CFG[4];             /* Processor 0 Configuration Register */
	__REGW__ reserved_0[240];
	__REGW__ OCMDR[4];              /* On-Chip Memory Descriptor Register */
	};

struct __mscm__ MSCM	@0x40001000;

/*	PCC section
 */
struct __pcc__ {
	__REGW__ PCCn[128];             /* PCC Register..PCC Register */
	};

struct __pcc__ PCC	@0x40065000;

/*	PDB section
 */
struct __pdb__ {
	__REGW__ SC;                    /* Status and Control Register */
	__REGW__ MOD;                   /* Modulus Register */
	__REGW__ CNT;                   /* Counter Register */
	__REGW__ IDLY;                  /* Interrupt Delay Register */
	struct {
		__REGW__ C1;                /* Channel Control Registers 1 */
		__REGW__ S;                 /* Channel Status Register */
		__REGW__ DLY[8];            /* Channel Delay Registers */
		} CH[2];
	__REGW__ reserved_0[76];
	__REGW__ POEN;                  /* Pulse-Out n Enable Register */
	__REGW__ PODLY;                 /* Pulse-Out n Delay Register */
	};

struct __pdb__ PDB0	@0x40036000;
struct __pdb__ PDB1	@0x40031000;

/*	PMC section
 */
struct __pmc__ {
	__REGB__ LVDSC1;                /* Low Voltage Status/Control 1 */
	__REGB__ LVDSC2;                /* Low Voltage Status/Control 2 */
	__REGB__ REGSC;                 /* Regulator Status/Control */
	__REGB__ reserved_0;
	__REGB__ LPOTRIM;               /* Low Power Oscillator Trim Register */
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

/*	RCM section
 */
struct __rcm__ {
	__REGW__ VERID;                 /* Version ID Register */
	__REGW__ PARAM;                 /* Parameter Register */
	__REGW__ SRS;                   /* System Reset Status Register */
	__REGW__ RPC;                   /* Reset Pin Control register */
	__REGW__ reserved_0[2];
	__REGW__ SSRS;                  /* Sticky System Reset Status Register */
	__REGW__ SRIE;                  /* System Reset Interrupt Enable Register */
	};

struct __rcm__ RCM	@0x4007F000;

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
	__REGW__ IER;                   /* RTC Interrupt Enable Register */
	};

struct __rtc__ RTC	@0x4003D000;

/*	SCG section
 */
struct __scg__ {
	__REGW__ VERID;                 /* Version ID Register */
	__REGW__ PARAM;                 /* Parameter Register */
	__REGW__ reserved_0[2];
	__REGW__ CSR;                   /* Clock Status Register */
	__REGW__ RCCR;                  /* Run Clock Control Register */
	__REGW__ VCCR;                  /* VLPR Clock Control Register */
	__REGW__ HCCR;                  /* HSRUN Clock Control Register */
	__REGW__ reserved_1[56];
	__REGW__ SOSCCSR;               /* System OSC Control Status Register */
	__REGW__ SOSCDIV;               /* System OSC Divide Register */
	__REGW__ SOSCCFG;               /* System Oscillator Configuration Register */
	__REGW__ reserved_2[61];
	__REGW__ SIRCCSR;               /* Slow IRC Control Status Register */
	__REGW__ SIRCDIV;               /* Slow IRC Divide Register */
	__REGW__ SIRCCFG;               /* Slow IRC Configuration Register */
	__REGW__ reserved_3[61];
	__REGW__ FIRCCSR;               /* Fast IRC Control Status Register */
	__REGW__ FIRCDIV;               /* Fast IRC Divide Register */
	__REGW__ FIRCCFG;               /* Fast IRC Configuration Register */
	__REGW__ FIRCTCFG;              /* Fast IRC Trim Configuration Register */
	__REGW__ reserved_4[2];
	__REGW__ FIRCSTAT;              /* Fast IRC Status Register */
	__REGW__ reserved_5[185];
 	__REGW__ SPLLCSR;               /* System PLL Control Status Register */
 	__REGW__ SPLLDIV;               /* System PLL Divide Register */
 	__REGW__ SPLLCFG;               /* System PLL Configuration Register */
	};

struct __scg__ SCG	@0x40064000;

/*	SIM section
 */
struct __sim__ {
	__REGW__ reserved_0;
 	__REGW__ CHIPCTL;               /* Chip Control register */
	__REGW__ reserved_1;            
 	__REGW__ FTMOPT0;               /* FTM Option Register 0 */
 	__REGW__ LPOCLKS;               /* LPO Clock Select Register */
	__REGW__ reserved_2;            
 	__REGW__ ADCOPT;                /* ADC Options Register */
 	__REGW__ FTMOPT1;               /* FTM Option Register 1 */
	__REGW__ reserved_3;            
 	__REGW__ SDID;                  /* System Device Identification Register */
	__REGW__ reserved_4[6];         
 	__REGW__ PLATCGC;               /* Platform Clock Gating Control Register */
	__REGW__ reserved_5[2];         
  	__REGW__ FCFG1;                 /* Flash Configuration Register 1 */
  	__REGW__ FCFG2;                 /* Flash Configuration Register 2 */
  	__REGW__ UIDH;                  /* Unique Identification Register High */
  	__REGW__ UIDMH;                 /* Unique Identification Register Mid-High */
  	__REGW__ UIDML;                 /* Unique Identification Register Mid Low */
  	__REGW__ UIDL;                  /* Unique Identification Register Low */
	__REGW__ reserved_6;            
  	__REGW__ CLKDIV4;               /* System Clock Divider Register 4 */
  	__REGW__ MISCTRL;               /* Miscellaneous Control register */
	};

struct __sim__ SIM	@0x40048000;

/*	SMC section
 */
struct __smc__ {
	__REGW__ VERID;                 /* SMC Version ID Register */
	__REGW__ PARAM;                 /* SMC Parameter Register */
	__REGW__ PMPROT;                /* Power Mode Protection register */
	__REGW__ PMCTRL;                /* Power Mode Control register */
	__REGW__ STOPCTRL;              /* Stop Control Register */
	__REGW__ PMSTAT;                /* Power Mode Status register */
	};

struct __smc__ SMC	@0x4007E000;

/*	TRGMUX section
 */
struct __trgmux__ {
	__REGW__ TRGMUXn[26];           /* TRGMUX DMAMUX_CH0 Register..TRGMUX LPTMR0 Register */
	};

struct __trgmux__ TRGMUX	@0x40063000;

/*	WDOG section
 */
struct __wdog__ {
	__REGW__ CS;                     /* Watchdog Control and Status Register */
	__REGW__ CNT;                    /* Watchdog Counter Register */
	__REGW__ TOVAL;                  /* Watchdog Timeout Value Register */
	__REGW__ WIN;                    /* Watchdog Window Register */
	};

struct __wdog__ WDOG	@0x40052000;
