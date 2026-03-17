;	C STARTUP CODE - M0
;	Copyright (c) 2012 by COSMIC Software
;
	xdef	_exit, __stext
	xref.l	_main, __sram, __eram, __stack
;
__stext:
	ldr	r1,atab+0		; get start of ram
	ldr	r2,atab+4		; get end of ram
	subs	r2,r1			; byte size
	beq	init			; empty, skip
	lsrs	r2,#2			; word size
	movs	r3,#0			; to clear the bss
zbcl:
	str	r3,[r1]			; clear memory
	adds	r1,#4			; next word
	subs	r2,#1			; count down
	bne	zbcl			; and loop back
init:
	ldr	r0,atab+8		; initialize SP
	mov	sp,r0
	bl	_main			; execute main
_exit:
	b	_exit			; stay here
;
	align	4
atab:
	dc.l	__sram			; start of ram to clear
	dc.l	__eram			; end of ram to clear
	dc.l	__stack			; init value of stack pointer
;
	end
