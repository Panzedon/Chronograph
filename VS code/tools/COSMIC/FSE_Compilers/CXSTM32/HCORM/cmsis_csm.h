/*	CORE FUNCTION INTERFACE
 *	Copyright (c) 2013 by Cosmic Software
 */

#ifndef __CMSIS_CSM__
#define __CMSIS_CSM__

/*	Returns the content of the Control Register.
 */
#define __get_CONTROL()		_asm("mrs r0,control")

/*	Writes the given value to the Control Register.
 */
#define __set_CONTROL(value)	_asm("msr control,r0", value)

/*	Returns the content of the IPSR Register.
 */
#define __get_IPSR()		_asm("mrs r0,ipsr")

/*	Returns the content of the APSR Register.
 */
#define __get_APSR()		_asm("mrs r0,apsr")

/*	Returns the content of the xPSR Register.
 */
#define __get_xPSR()		_asm("mrs r0,xpsr")

/*	Returns the content of the PSP Register.
 */
#define	__get_PSP()		_asm("mrs r0,psp")

/*	Assigns the given value to the Process Stack Pointer (PSP)
 */
#define __set_PSP(value)	_asm("msr psp,r0", value)

/*	Returns the current value of the Main Stack Pointer (MSP).
 */
#define __get_MSP()		_asm("mrs r0,msp")

/*	Assigns the given value to the Main Stack Pointer (MSP).
 */
#define __set_MSP(value)	_asm("msr msp,r0", value)

/*	Returns the priority mask bits from the Priority Mask Register.
 */
#define __get_PRIMASK()		_asm("mrs r0,primask")

/*	Assigns the given value to the Priority Mask Register.
 */
#define __set_PRIMASK(value)	_asm("msr primask,r0", value)

/*	Returns the priority mask bits from the Priority Mask Register.
 */
#define __get_BASEPRI()		_asm("mrs r0,basepri")

/*	Assigns the given value to the Priority Mask Register.
 */
#define __set_BASEPRI(value)	_asm("msr basepri,r0", value)

/*	Does nothing. Can be used for code alignment purposes.
 */
#define __NOP()			_asm("nop")

/*	Wait For Interrupt is a hint instruction that suspends execution
 */
#define __WFI()			_asm("wfi")

/*	Wait For Event is a hint instruction that permits the processor to enter
 */
#define __WFE()			_asm("wfe")

/*	Send Event causes an event to be signaled to the CPU.
 */
#define __SEV()			_asm("sev")

/*	Instruction Synchronization Barrier flushes the processor pipeline
 *	so that all instructions following the ISB are fetched from cache or
 *	memory, after the instruction has been completed.
 */
#define __ISB()			_asm("isb #$0f")

/*	Data SYnchronization Barrier completes when all explicit memory
 *	accesses before this instruction complete.
 */
#define __DSB()			_asm("dsb #$0f")

/*	Ensures the apparent order of the explicit memory operations before
 *	and after the instruction, without ensuring their completion.
 */
#define __DMB()			_asm("dmb #$0f")

/*	Reverses the byte order in integer value.
 */
#define __REV(value)		_asm("rev r0,r0", value)

/*	Reverses the byte order in two unsigned short values.
 */
#ifndef __NO_EMBEDDED_ASM
#define __REV16(value)		_asm("rev16 r0,r0", value)
#endif

/*	Reverses the byte order in a signed short value with sign extension
 */
#ifndef __NO_EMBEDDED_ASM
#define __REVSH(value)		_asm("revsh r0,r0", value)
#endif

/*	Rotate Right (immediate) provides the value of the contents
 *	of a register rotated by a variable number of bits.
 */
#define __ROR(value, count)	_asm("ror r0,r0,#" #count, value)

/*	Causes the processor to enter Debug state.
 */
#define __BKPT(value)		_asm("bkpt #" #value)

#if (__CORTEX_M >= 0x03)
/*	Reverses the bit order of the given value.
 */
#define __RBIT(value)		_asm("rbit r0,r0", value)

/*	Performs a exclusive LDR command for 8 bit value.
 */
#define __LDREXB(ptr)		((uint8_t )_asm("ldrexb r0,[r0]", ptr))

/*	Performs a exclusive LDR command for 16 bit values.
 */
#define __LDREXH(ptr)		((uint16_t)_asm("ldrexh r0,[r0]", ptr))

/*	Performs a exclusive LDR command for 32 bit values.
 */
#define __LDREXW(ptr)		((uint32_t )_asm("ldrex r0,[r0]", ptr))

/*	Performs a exclusive STR command for 8 bit values.
 */
#define __STREXB(value, ptr)	_asm("strexb r0,r0,[r1]", value, ptr)

/*	Performs a exclusive STR command for 16 bit values.
 */
#define __STREXH(value, ptr)	_asm("strexh r0,r0,[r1]", value, ptr)

/*	Performs a exclusive STR command for 32 bit values.
 */
#define __STREXW(value, ptr)	_asm("strex r0,r0,[r1]", value, ptr)

/*	Removes the exclusive lock which is created by LDREX.
 */
#define __CLREX()		_asm("clrex")

/*	Saturates a signed value.
 */
#define __SSAT(value, count)	_asm("ssat r0,#" #count ",r0", value)

/*	Saturates an unsigned value.
 */
#define __USAT(value, count)	_asm("usat r0,#" #count ",r0", value)

/*	Counts the number of leading zeros of a data value.
 */
#define __CLZ(value)		_asm("clz r0,r0", value)

#endif /* (__CORTEX_M >= 0x03) */

#endif
