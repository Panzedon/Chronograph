;	C STARTUP CODE
;	Copyright (c) 2011 by COSMIC Software
;
	xdef	_exit, __stext
	xref.l	_main, __sdata, __sram, __eram, __stack
;
__stext:
	ldr	r1,atab+4		; get start of ram
	ldr	r2,atab+8		; get end of ram
	subs	r2,r1			; byte size
	beq	init			; empty, skip
	lsrs	r2,#2			; word size
	movs	r3,#0			; to clear the bss
zbcl:
	str	r3,[r1],#4		; clear memory
	subs	r2,#1			; count down
	bne	zbcl			; and loop back
init:
	ldr	sp,atab+12		; initialize SP
	ldr	r9,atab			; initialize DP
	bl	_main			; execute main
_exit:
	b	_exit			; stay here
;
	align	4
atab:
	dc.l	__sdata			; init value of data pointer
	dc.l	__sram			; start of ram to clear
	dc.l	__eram			; end of ram to clear
	dc.l	__stack			; init value of stack pointer
;
	end
