/*	IO DEFINITIONS FOR KINETIS K60
 *	Copyright (c) 2011 by COSMIC SOftware
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
struct __adc__ ADC1	@0x400BB000;

/*	AIPS section
 */
struct __aips__ {
	__REGW__ MPRA;                  /* Master Privilege Register A */
	__REGW__ reserved_0[7];
	__REGW__ PACRA;                 /* Peripheral Access Control Register */
	__REGW__ PACRB;                 /* Peripheral Access Control Register */
	__REGW__ PACRC;                 /* Peripheral Access Control Register */
	__REGW__ PACRD;                 /* Peripheral Access Control Register */
	__REGW__ reserved_1[4];
	__REGW__ PACRE;                 /* Peripheral Access Control Register */
	__REGW__ PACRF;                 /* Peripheral Access Control Register */
	__REGW__ PACRG;                 /* Peripheral Access Control Register */
	__REGW__ PACRH;                 /* Peripheral Access Control Register */
	__REGW__ PACRI;                 /* Peripheral Access Control Register */
	__REGW__ PACRJ;                 /* Peripheral Access Control Register */
	__REGW__ PACRK;                 /* Peripheral Access Control Register */
	__REGW__ PACRL;                 /* Peripheral Access Control Register */
	__REGW__ PACRM;                 /* Peripheral Access Control Register */
	__REGW__ PACRN;                 /* Peripheral Access Control Register */
	__REGW__ PACRO;                 /* Peripheral Access Control Register */
	__REGW__ PACRP;                 /* Peripheral Access Control Register */
	};

struct __aips__ AIPS0	@0x40000000;
struct __aips__ AIPS1	@0x40080000;

/*	AXBS section
 */
struct __slave__ {
	__REGW__ PRS;                   /* Priority Registers Slave */
	__REGW__ reserved_0[3];
	__REGW__ CRS;                   /* Control Register Slave */
	__REGW__ reserved_1[59];
	};

struct __axbs__ {
	struct __slave__ SLAVE[5];
	__REGW__ reserved_0[192];
	__REGW__ MGPCR0;                /* Master General Purpose Control 0 */
	__REGW__ reserved_1[63];
	__REGW__ MGPCR1;                /* Master General Purpose Control 1 */
	__REGW__ reserved_2[63];
	__REGW__ MGPCR2;                /* Master General Purpose Control 2 */
	__REGW__ reserved_3[63];
	__REGW__ MGPCR3;                /* Master General Purpose Control 3 */
	__REGW__ reserved_4[63];
	__REGW__ MGPCR4;                /* Master General Purpose Control 4 */
	__REGW__ reserved_5[63];
	__REGW__ MGPCR5;                /* Master General Purpose Control 5 */
	};

struct __axbs__ AXBS	@0x40004000;

/*	CAN section
 */
struct __buf__ {
	__REGW__ CS;                    /* Message Buffer CS Register */
	__REGW__ ID;                    /* Message Buffer ID Register */
	__REGW__ WORD0;                 /* Message Buffer WORD0 Register */
	__REGW__ WORD1;                 /* Message Buffer WORD1 Register */
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
	__REGW__ IMASK2;                /* Interrupt Masks 2 Register */
	__REGW__ IMASK1;                /* Interrupt Masks 1 Register */
	__REGW__ IFLAG2;                /* Interrupt Flags 2 Register */
	__REGW__ IFLAG1;                /* Interrupt Flags 1 Register */
	__REGW__ CTRL2;                 /* Control 2 Register */
	__REGW__ ESR2;                  /* Error and Status 2 Register */
	__REGW__ reserved_1[2];
	__REGW__ CRCR;                  /* CRC Register */
	__REGW__ RXFGMASK;              /* Rx FIFO Global Mask Register */
	__REGW__ RXFIR;                 /* Rx FIFO Information Register */
	__REGW__ reserved_2[12];
	struct __buf__ MB[16];          /* Message Buffers */
	__REGW__ reserved_3[448];
	__REGW__ RXIMR[16];             /* Rx Individual Mask Registers */
	};

struct __can__ CAN0	@0x40024000;
struct __can__ CAN1	@0x400A4000;

/*	CAU section
 */
struct __cau__ {
	__REGW__ DIRECT[16];            /* Direct access registers */
	__REGW__ reserved_0[512];
	__REGW__ LDR_CASR;              /* Status - Load command */
	__REGW__ LDR_CAA;               /* Accumulator - Load command */
	__REGW__ LDR_CA[9];             /* General Purpose Regs - Load  */
	__REGW__ reserved_1[5];
	__REGW__ STR_CASR;              /* Status - Store command */
	__REGW__ STR_CAA;               /* Accumulator - Store command */
	__REGW__ STR_CA[9];             /* General Purpose Regs - Store */
	__REGW__ reserved_2[5];
	__REGW__ ADR_CASR;              /* Status - Add command */
	__REGW__ ADR_CAA;               /* Accumulator - Add command */
	__REGW__ ADR_CA[9];             /* General Purpose Regs - Add */
	__REGW__ reserved_3[5];
	__REGW__ RADR_CASR;             /* Status - Reverse command */
	__REGW__ RADR_CAA;              /* Accumulator - Reverse  */
	__REGW__ RADR_CA[9];            /* General Purpose Regs - Reverse */
	__REGW__ reserved_4[21];
	__REGW__ XOR_CASR;              /* Status - Exclusive command */
	__REGW__ XOR_CAA;               /* Accumulator - Exclusive  */
	__REGW__ XOR_CA[9];             /* General Purpose Regs - Exclusive */
	__REGW__ reserved_5[5];
	__REGW__ ROTL_CASR;             /* Status - Rotate Left command */
	__REGW__ ROTL_CAA;              /* Accumulator - Rotate Left command */
	__REGW__ ROTL_CA[9];            /* General Purpose Regs - Rotate Left */
	__REGW__ reserved_6[69];
	__REGW__ AESC_CASR;             /* Status - AES command */
	__REGW__ AESC_CAA;              /* Accumulator - AES command */
	__REGW__ AESC_CA[9];            /* General Purpose Regs - AES */
	__REGW__ reserved_7[5];
	__REGW__ AESIC_CASR;            /* Status - AES Inv command */
	__REGW__ AESIC_CAA;             /* Accumulator - AES Inv command */
	__REGW__ AESIC_CA[9];           /* General Purpose Regs - AES Inv */
	};

struct __cau__ CAU	@0xE0081000;

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
struct __cmp__ CMP2	@0x40073010;

/*	CMT section
 */
struct __cmt__ {
	__REGB__ CGH1;                  /* Carrier Generator High Data 1 */
	__REGB__ CGL1;                  /* Carrier Generator Low Data 1 */
	__REGB__ CGH2;                  /* Carrier Generator High Data 2 */
	__REGB__ CGL2;                  /* Carrier Generator Low Data 2 */
	__REGB__ OC;                    /* Output Control Register */
	__REGB__ MSC;                   /* Modulator Status and Control */
	__REGB__ CMD1;                  /* Modulator Data Register Mark High */
	__REGB__ CMD2;                  /* Modulator Data Register Mark Low */
	__REGB__ CMD3;                  /* Modulator Data Register Space High */
	__REGB__ CMD4;                  /* Modulator Data Register Space Low */
	__REGB__ PPS;                   /* Primary Prescaler Register */
	__REGB__ DMA;                   /* Direct Memory Access */
	};

struct __cmt__ CMT	@0x40062000;

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

struct __dac__ DAC0	@0x400CC000;
struct __dac__ DAC1	@0x400CD000;

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

/*	ENET section
 */
struct __enet__ {
	__REGW__ reserved_0;
	__REGW__ EIR;                   /* Interrupt Event Register */
	__REGW__ EIMR;                  /* Interrupt Mask Register */
	__REGW__ reserved_1;
	__REGW__ RDAR;                  /* Receive Descriptor Active Reg */
	__REGW__ TDAR;                  /* Transmit Descriptor Active Reg */
	__REGW__ reserved_2[3];
	__REGW__ ECR;                   /* Ethernet Control Register */
	__REGW__ reserved_3[6];
	__REGW__ MMFR;                  /* MII Management Frame Register */
	__REGW__ MSCR;                  /* MII Speed Control Register */
	__REGW__ reserved_4[7];
	__REGW__ MIBC;                  /* MIB Control Register */
	__REGW__ reserved_5[6];
	__REGW__ RCR;                   /* Receive Control Register */
	__REGW__ reserved_6[15];
	__REGW__ TCR;                   /* Transmit Control Register */
	__REGW__ reserved_7[7];
	__REGW__ PALR;                  /* Physical Address Lower Register */
	__REGW__ PAUR;                  /* Physical Address Upper Register */
	__REGW__ OPD;                   /* Opcode/Pause Duration Register */
	__REGW__ reserved_8[10];
	__REGW__ IAUR;                  /* Desc Individual Upper Address Reg */
	__REGW__ IALR;                  /* Desc Individual Lower Address Reg */
	__REGW__ GAUR;                  /* Desc Group Upper Address Reg */
	__REGW__ GALR;                  /* Desc Group Lower Address Reg */
	__REGW__ reserved_9[7];
	__REGW__ TFWR;                  /* Transmit FIFO Watermark Register */
	__REGW__ reserved_10[14];
	__REGW__ RDSR;                  /* Receive Descriptor Ring Start Reg */
	__REGW__ TDSR;                  /* Transmit Buffer Desc Ring Start */
	__REGW__ MRBR;                  /* Maximum Receive Buffer Size Reg */
	__REGW__ reserved_11;
	__REGW__ RSFL;                  /* Receive FIFO Full Threshold */
	__REGW__ RSEM;                  /* Receive FIFO Empty Threshold */
	__REGW__ RAEM;                  /* Receive FIFO Almost Empty Thrs. */
	__REGW__ RAFL;                  /* Receive FIFO Almost Full Thrs. */
	__REGW__ TSEM;                  /* Transmit FIFO Section Empty Thrs. */
	__REGW__ TAEM;                  /* Transmit FIFO Almost Empty Thrs. */
	__REGW__ TAFL;                  /* Transmit FIFO Almost Full Thrs. */
	__REGW__ TIPG;                  /* Transmit Inter-Packet Gap */
	__REGW__ FTRL;                  /* Frame Truncation Length */
	__REGW__ reserved_12[3];
	__REGW__ TACC;                  /* Transmit Accelerator Config */
	__REGW__ RACC;                  /* Receive Accelerator Config */
	__REGW__ reserved_13[14];
	__REGW__ RMON_T_DROP;           /* frames not counted correctly */
	__REGW__ RMON_T_PACKETS;        /* Tx packet count */
	__REGW__ RMON_T_BC_PKT;         /* Tx Broadcast Packets */
	__REGW__ RMON_T_MC_PKT;         /* Tx Multicast Packets */
	__REGW__ RMON_T_CRC_ALIGN;      /* Tx Packets w CRC/Align error */
	__REGW__ RMON_T_UNDERSIZE;      /* Tx Packets < 64 bytes, good CRC */
	__REGW__ RMON_T_OVERSIZE;       /* Tx Packets > MAX bytes, good CRC */
	__REGW__ RMON_T_FRAG;           /* Tx Packets < 64 bytes, bad CRC */
	__REGW__ RMON_T_JAB;            /* Tx Packets > MAX bytes, bad CRC */
	__REGW__ RMON_T_COL;            /* Tx collision count */
	__REGW__ RMON_T_P64;            /* Tx 64 byte packets */
	__REGW__ RMON_T_P65TO127;       /* Tx 65 to 127 byte packets */
	__REGW__ RMON_T_P128TO255;      /* Tx 128 to 255 byte packets */
	__REGW__ RMON_T_P256TO511;      /* Tx 256 to 511 byte packets */
	__REGW__ RMON_T_P512TO1023;     /* Tx 512 to 1023 byte packets */
	__REGW__ RMON_T_P1024TO2047;    /* Tx 1024 to 2047 byte packets */
	__REGW__ RMON_T_P_GTE2048;      /* Tx packets w > 2048 bytes */
	__REGW__ RMON_T_OCTETS;         /* Tx Octets */
	__REGW__ IEEE_T_DROP;           /* frames not counted correctly */
	__REGW__ IEEE_T_FRAME_OK;       /* Frames Transmitted OK */
	__REGW__ IEEE_T_1COL;           /* Frames with Single Collision */
	__REGW__ IEEE_T_MCOL;           /* Frames with Multiple Collisions */
	__REGW__ IEEE_T_DEF;            /* Frames after Deferral Delay */
	__REGW__ IEEE_T_LCOL;           /* Frames with Late Collision */
	__REGW__ IEEE_T_EXCOL;          /* Frames with Excessive Collisions */
	__REGW__ IEEE_T_MACERR;         /* Frames with Tx FIFO Underrun */
	__REGW__ IEEE_T_CSERR;          /* Frames with Carrier Sense Error */
	__REGW__ IEEE_T_SQE;            /* Frames with SQE Error */
	__REGW__ IEEE_T_FDXFC;          /* Flow Control Pause frames */
	__REGW__ IEEE_T_OCTETS_OK;      /* Octet count for Frames w/o Error */
	__REGW__ reserved_14[3];
	__REGW__ RMON_R_PACKETS;        /* Rx packet count */
	__REGW__ RMON_R_BC_PKT;         /* Rx Broadcast Packets */
	__REGW__ RMON_R_MC_PKT;         /* Rx Multicast Packets */
	__REGW__ RMON_R_CRC_ALIGN;      /* Rx Packets w CRC/Align error */
	__REGW__ RMON_R_UNDERSIZE;      /* Rx Packets < 64 bytes, good CRC */
	__REGW__ RMON_R_OVERSIZE;       /* Rx Packets > MAX bytes, good CRC */
	__REGW__ RMON_R_FRAG;           /* Rx Packets < 64 bytes, bad CRC */
	__REGW__ RMON_R_JAB;            /* Rx Packets > MAX bytes, bad CRC */
	__REGW__ RMON_R_RESVD_0;        /* Reserved */
	__REGW__ RMON_R_P64;            /* Rx 64 byte packets */
	__REGW__ RMON_R_P65TO127;       /* Rx 65 to 127 byte packets */
	__REGW__ RMON_R_P128TO255;      /* Rx 128 to 255 byte packets */
	__REGW__ RMON_R_P256TO511;      /* Rx 256 to 511 byte packets */
	__REGW__ RMON_R_P512TO1023;     /* Rx 512 to 1023 byte packets */
	__REGW__ RMON_R_P1024TO2047;    /* Rx 1024 to 2047 byte packets */
	__REGW__ RMON_R_P_GTE2048;      /* Rx packets w > 2048 bytes */
	__REGW__ RMON_R_OCTETS;         /* Rx Octets */
	__REGW__ RMON_R_DROP;           /* Frames not counted correctly */
	__REGW__ RMON_R_FRAME_OK;       /* Frames Received OK */
	__REGW__ IEEE_R_CRC;            /* Frames with CRC Error */
	__REGW__ IEEE_R_ALIGN;          /* Frames with Alignment Error */
	__REGW__ IEEE_R_MACERR;         /* Receive Fifo Overflow count */
	__REGW__ IEEE_R_FDXFC;          /* Flow Control Pause frames received */
	__REGW__ IEEE_R_OCTETS_OK;      /* Count for Frames Rcvd w/o Error */
	__REGW__ reserved_15[71];
	__REGW__ ATCR;                  /* Timer Control Register */
	__REGW__ ATVR;                  /* Timer Value Register */
	__REGW__ ATOFF;                 /* Timer Offset Register */
	__REGW__ ATPER;                 /* Timer Period Register */
	__REGW__ ATCOR;                 /* Timer Correction Register */
	__REGW__ ATINC;                 /* Timestamp Clock Period Register */
	__REGW__ ATSTMP;                /* Timestamp of Last TransmitFrame */
	__REGW__ reserved_16[122];
	__REGW__ TGSR;                  /* Timer Global Status Registe */
	struct {
    		__REGW__ TCSR;          /* Timer Control Status Register */
    		__REGW__ TCCR;          /* Timer Compare Capture Register */
  		} CHANNEL[4];
	};

struct __enet__ ENET	@0x400C0000;

/*	ETB section
 */
struct __etb__ {
	__REGW__ reserved_0;
	__REGW__ RDP;                   /* RAM Depth Register */
	__REGW__ reserved_1;
	__REGW__ STS;                   /* Status Register*/
	__REGW__ RRD;                   /* RAM Read Data Register */
	__REGW__ RRP;                   /* RAM Read Pointer Register */
	__REGW__ RWP;                   /* RAM Write Pointer Register */
	__REGW__ TRG;                   /* Trigger Counter Register */
	__REGW__ CTL;                   /* Control Register */
	__REGW__ RWD;                   /* RAM Write Data Register */
	__REGW__ reserved_2[182];
	__REGW__ FFSR;                  /* Formatter and Flush Status Reg */
	__REGW__ FFCR;                  /* Formatter and Flush Control Reg */
	__REGW__ reserved_3[758];
	__REGW__ ITMISCOP0;             /* Integration Register */
	__REGW__ ITTRFLINACK;           /* Integration Register */
	__REGW__ ITTRFLIN;              /* Integration Register */
	__REGW__ ITATBDATA0;            /* Integration Registe */
	__REGW__ ITATBCTR2;             /* Integration Register */
	__REGW__ ITATBCTR1;             /* Integration Register */
	__REGW__ ITATBCTR0;             /* Integration Register */
	__REGW__ reserved_4;
	__REGW__ ITCTRL;                /* Integration Mode Control Register */
	__REGW__ reserved_5[39];
	__REGW__ CLAIMSET;              /* Claim Tag Set Register */
	__REGW__ CLAIMCLR;              /* Claim Tag Clear Register */
	__REGW__ reserved_6[2];
	__REGW__ LAR;                   /* Lock Access Register */
	__REGW__ LSR;                   /* Lock Status Register */
	__REGW__ AUTHSTATUS;            /* Authentication Status Register */
	__REGW__ reserved_7[3];
	__REGW__ DEVID;                 /* Device ID Register */
	__REGW__ DEVTYPE;               /* Device Type Identifier Register */
	__REGW__ PIDR4;                 /* Peripheral Identification Reg 4 */
	__REGW__ PIDR5;                 /* Peripheral Identification Reg 5 */
	__REGW__ PIDR6;                 /* Peripheral Identification Reg 6 */
	__REGW__ PIDR7;                 /* Peripheral Identification Reg 7 */
	__REGW__ PIDR0;                 /* Peripheral Identification Reg 0 */
	__REGW__ PIDR1;                 /* Peripheral Identification Reg 1 */
	__REGW__ PIDR2;                 /* Peripheral Identification Reg 2 */
	__REGW__ PIDR3;                 /* Peripheral Identification Reg 3 */
	__REGW__ CIDR0;                 /* Component Identification Reg 0 */
	__REGW__ CIDR1;                 /* Component Identification Reg 1 */
	__REGW__ CIDR2;                 /* Component Identification Reg 2 */
	__REGW__ CIDR3;                 /* Component Identification Reg 3 */
	};

struct __etb__ ETB	@0xE0042000;

/*	ETF section
 */
struct __etf__ {
	__REGW__ FCR;                   /* Funnel Control Register */
	__REGW__ PCR;                   /* Priority Control Register */
	__REGW__ reserved_0[953];
	__REGW__ ITATBDATA0;            /* Integration Register */
	__REGW__ ITATBCTR2;             /* Integration Register */
	__REGW__ ITATBCTR1;             /* Integration Register */
	__REGW__ ITATBCTR0;             /* Integration Register */
	__REGW__ RESERVED_1;
	__REGW__ ITCTRL;                /* Integration Mode Control Register */
	__REGW__ reserved_2[39];
	__REGW__ CLAIMSET;              /* Claim Tag Set Register */
	__REGW__ CLAIMCLR;              /* Claim Tag Clear Register */
	__REGW__ reserved_3[2];
	__REGW__ LAR;                   /* Lock Access Register */
	__REGW__ LSR;                   /* Lock Status Register */
	__REGW__ AUTHSTATUS;            /* Authentication Status Register */
	__REGW__ reserved_4[3];
	__REGW__ DEVID;                 /* Device ID Register */
	__REGW__ DEVTYPE;               /* Device Type Identifier Register */
	__REGW__ PIDR4;                 /* Peripheral Identification Reg 4 */
	__REGW__ PIDR5;                 /* Peripheral Identification Reg 5 */
	__REGW__ PIDR6;                 /* Peripheral Identification Reg 6 */
	__REGW__ PIDR7;                 /* Peripheral Identification Reg 7 */
	__REGW__ PIDR0;                 /* Peripheral Identification Reg 0 */
	__REGW__ PIDR1;                 /* Peripheral Identification Reg 1 */
	__REGW__ PIDR2;                 /* Peripheral Identification Reg 2 */
	__REGW__ PIDR3;                 /* Peripheral Identification Reg 3 */
	__REGW__ CIDR0;                 /* Component Identification Reg 0 */
	__REGW__ CIDR1;                 /* Component Identification Reg 1 */
	__REGW__ CIDR2;                 /* Component Identification Reg 2 */
	__REGW__ CIDR3;                 /* Component Identification Reg 3 */
	};

struct __etf__ ETF	@0xE0043000;

/*	ETM section
 */
struct __etm__ {
	__REGW__ CR;                    /* Main Control Register*/
	__REGW__ CCR;                   /* Configuration Code Register */
	__REGW__ TRIGGER;               /* Trigger Event Register */
	__REGW__ reserved_0;
	__REGW__ SR;                    /* ETM Status Register */
	__REGW__ SCR;                   /* System Configuration Register */
	__REGW__ reserved_1[2];
	__REGW__ EEVR;                  /* Trace Enable Event Register */
	__REGW__ TECR1;                 /* Trace Enable Control 1 Register */
	__REGW__ FFLR;                  /* FIFOFULL Level Register */
	__REGW__ reserved_2[69];
	__REGW__ CNTRLDVR1;             /* Free-running counter reload value */
	__REGW__ reserved_3[39];
	__REGW__ SYNCFR;                /* Synchronization Frequency Register */
	__REGW__ IDR;                   /* ID Register */
	__REGW__ CCER;                  /* Configuration Code Extension Reg */
	__REGW__ reserved_4;
	__REGW__ TESSEICR;              /* TraceEnable Start/Stop Control Reg */
	__REGW__ reserved_5;
	__REGW__ TSEVR;                 /* Timestamp Event Register */
	__REGW__ reserved_6;
	__REGW__ TRACEIDR;              /* CoreSight Trace ID Register */
	__REGW__ reserved_7;
	__REGW__ IDR2;                  /* ETM ID Register 2 */
	__REGW__ reserved_8[66];
	__REGW__ PDSR;                  /* Device Power-Down Status Register */
	__REGW__ reserved_9[754];
	__REGW__ ITMISCIN;              /* Integration Test Misc Inputs Reg */
	__REGW__ reserved_10;
	__REGW__ ITTRIGOUT;             /* Integration Test Trigger Out Reg */
	__REGW__ reserved_11;
	__REGW__ ITATBCTR2;             /* ETM Integration Test ATB Control 2 */
	__REGW__ reserved_12;
	__REGW__ ITATBCTR0;             /* ETM Integration Test ATB Control 0 */
	__REGW__ reserved_13;
	__REGW__ ITCTRL;                /* Integration Mode Control Register */
	__REGW__ reserved_14[39];
	__REGW__ CLAIMSET;              /* Claim Tag Set Register */
	__REGW__ CLAIMCLR;              /* Claim Tag Clear Register */
	__REGW__ reserved_15[2];
	__REGW__ LAR;                   /* Lock Access Register */
	__REGW__ LSR;                   /* Lock Status Register */
	__REGW__ AUTHSTATUS;            /* Authentication Status Register */
	__REGW__ reserved_16[4];
	__REGW__ DEVTYPE;               /* CoreSight Device Type Register */
	__REGW__ PIDR4;                 /* Peripheral Identification Reg 4 */
	__REGW__ PIDR5;                 /* Peripheral Identification Reg 5 */
	__REGW__ PIDR6;                 /* Peripheral Identification Reg 6 */
	__REGW__ PIDR7;                 /* Peripheral Identification Reg 7 */
	__REGW__ PIDR0;                 /* Peripheral Identification Reg 0 */
	__REGW__ PIDR1;                 /* Peripheral Identification Reg 1 */
	__REGW__ PIDR2;                 /* Peripheral Identification Reg 2 */
	__REGW__ PIDR3;                 /* Peripheral Identification Reg 3 */
	__REGW__ CIDR0;                 /* Component Identification Reg 0 */
	__REGW__ CIDR1;                 /* Component Identification Reg 1 */
	__REGW__ CIDR2;                 /* Component Identification Reg 2 */
	__REGW__ CIDR3;                 /* Component Identification Reg 3 */
	};

struct __etm__ ETM	@0xE0041000;

/*	EWM section
 */
struct __ewm__ {
	__REGB__ CTRL;                  /* Control Register */
	__REGB__ SERV;                  /* Service Register */
	__REGB__ CMPL;                  /* Compare Low Register */
	__REGB__ CMPH;                  /* Compare High Register */
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

struct __nv__ NV	@0x400;

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
struct __ftm__ FTM2	@0x400B8000;

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
	__REGW__ TX0;                   /* Transmit Data Register 0 */
	__REGW__ TX1;                   /* Transmit Data Register 1 */
	__REGW__ RX0;                   /* Receive Data Register 0 */
	__REGW__ RX1;                   /* Receive Data Register 1 */
	__REGW__ CR;                    /* Control Register */
	__REGW__ ISR;                   /* Interrupt Status Register */
	__REGW__ IER;                   /* Interrupt Enable Register */
	__REGW__ TCR;                   /* Transmit Configuration Register */
	__REGW__ RCR;                   /* Receive Configuration Register */
	__REGW__ TCCR;                  /* Transmit Clock Control Register */
	__REGW__ RCCR;                  /* Receive Clock Control Register */
	__REGW__ FCSR;                  /* FIFO Control/Status Register */
	__REGW__ reserved_0[2];
	__REGW__ ACNT;                  /* AC97 Control Register */
	__REGW__ ACADD;                 /* AC97 Command Address Register */
	__REGW__ ACDAT;                 /* AC97 Command Data Register */
	__REGW__ ATAG;                  /* AC97 Tag Register */
	__REGW__ TMSK;                  /* Transmit Time Slot Mask Register */
	__REGW__ RMSK;                  /* Receive Time Slot Mask Register */
	__REGW__ ACCST;                 /* AC97 Channel Status Register */
	__REGW__ ACCEN;                 /* AC97 Channel Enable Register */
	__REGW__ ACCDIS;                /* AC97 Channel Disable Register */
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

/*	MC section
 */
struct __mc__ {
	__REGB__ SRSH;                  /* System Reset Status Register High */
	__REGB__ SRSL;                  /* System Reset Status Register Low */
	__REGB__ PMPROT;                /* Power Mode Protection Register */
	__REGB__ PMCTRL;                /* Power Mode Control Register */
	};

struct __mc__ MC	@0x4007E000;

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
	__REGB__ ATC;                   /* Auto Trim Control Register */
	__REGB__ reserved_1;
	__REGB__ ATCVH;                 /* Auto Trim Compare Value High */
	__REGB__ ATCVL;                 /* Auto Trim Compare Value Low */
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

/*	MPU section
 */
struct __mpu__ {
	__REGW__ CESR;                  /* Control/Error Status Register */
	__REGW__ reserved_0[3];
	struct {
		__REGW__ EAR;           /* Error Address Register */
		__REGW__ EDR;           /* Error Detail Register */
		} SP[5];
	__REGW__ reserved_1[242];
	__REGW__ WORD[12][4];           /* Region Descriptor/Word */
	__REGW__ reserved_2[208];
	__REGW__ RGDAAC[12];            /* Region Desc Alt Access Control */
	};

struct __mpu__ MPU	@0x4000D000;

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
	__REGW__ VER;                   /* Version ID Register */
	__REGW__ CMD;                   /* Command Register */
	__REGW__ CR;                    /* Control Register */
	__REGW__ SR;                    /* Status Register */
	__REGW__ ESR;                   /* Error Status Register */
	__REGW__ OUT;                   /* Output FIFO */
	};

struct __rng__ RNG	@0x400A0000;

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

/*	SDHC section
 */
struct __shdc__ {
	__REGW__ DSADDR;                /* DMA System Address Register */
	__REGW__ BLKATTR;               /* Block Attributes Register */
	__REGW__ CMDARG;                /* Command Argument Register */
	__REGW__ XFERTYP;               /* Transfer Type Register */
	__REGW__ CMDRSP[4];             /* Command Response registers */
	__REGW__ DATPORT;               /* Buffer Data Port Register */
	__REGW__ PRSSTAT;               /* Present State Register */
	__REGW__ PROCTL;                /* Protocol Control Register */
	__REGW__ SYSCTL;                /* System Control Register */
	__REGW__ IRQSTAT;               /* Interrupt Status Register */
	__REGW__ IRQSTATEN;             /* Interrupt Status Enable Register */
	__REGW__ IRQSIGEN;              /* Interrupt Signal Enable Register */
	__REGW__ AC12ERR;               /* Auto CMD12 Error Status Register */
	__REGW__ HTCAPBLT;              /* Host Controller Capabilities */
	__REGW__ WML;                   /* Watermark Level Register */
	__REGW__ reserved_0[2];
	__REGW__ FEVT;                  /* Force Event Register*/
	__REGW__ ADMAES;                /* ADMA Error Status Register */
	__REGW__ ADSADDR;               /* ADMA System Address Register */
	__REGW__ reserved_1[25];
	__REGW__ VENDOR;                /* Vendor Specific Register */
	__REGW__ MMCBOOT;               /* MMC Boot Register */
	__REGW__ reserved_2[13];
	__REGW__ HOSTVER;               /* Host Controller Version */
	};

struct __shdc__ SDHC	@0x400B1000;

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
struct __spi__ SPI2	@0x400AC000;

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

/*	TSI section
 */
struct __tsi__ {
	__REGW__ GENCS;                 /* General Control/Status Register */
	__REGW__ SCANC;                 /* SCAN control register */
	__REGW__ PEN;                   /* Pin enable register */
	__REGW__ STATUS;                /* Status Register */
	__REGW__ reserved_0[60];
	__REGW__ CNTR1;                 /* Counter Register 1 */
	__REGW__ CNTR3;                 /* Counter Register 3 */
	__REGW__ CNTR5;                 /* Counter Register 5 */
	__REGW__ CNTR7;                 /* Counter Register 7 */
	__REGW__ CNTR9;                 /* Counter Register 9 */
	__REGW__ CNTR11;                /* Counter Register 11 */
	__REGW__ CNTR13;                /* Counter Register 13 */
	__REGW__ CNTR15;                /* Counter Register 15 */
	__REGW__ THRESHLD[16];          /* Channel threshold registers */
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
struct __uart__ UART3	@0x4006D000;
struct __uart__ UART4	@0x400EA000;
struct __uart__ UART5	@0x400EB000;

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

/*	USBDCD section
 */
struct __usbdcd__ {
	__REGW__ CONTROL;               /* Control Register */
	__REGW__ CLOCK;                 /* Clock Register */
	__REGW__ STATUS;                /* Status Register */
	__REGW__ reserved_0;
	__REGW__ TIMER0;                /* TIMER 0 Register */
	__REGW__ TIMER1;                /* TIMER 1 Register */
	__REGW__ TIMER2;                /* TIMER 2 Register */
	};

struct __usbdcd__ USBDCD @0x40035000;

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
