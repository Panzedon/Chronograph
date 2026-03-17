;	C STARTUP CODE WITH DATA INITIALIZATION AND FPU
;	Copyright (c) 2013 by COSMIC Software
;
	xdef	_exit, __stext
	xref.l	_main, __sdata, __sram, __eram, __stack, __idesc__
;
__stext:
	ldr	r1,atab+16		; descriptor address
skip:
	ldr	r4,[r1],#4		; first image address
dbcl:
	ldr	r2,[r1],#4		; get flag word
	cbz	r2,zbss			; end, continue
	ldr	r3,[r1],#4		; ram start address
	ands	r2,#$60			; test for moveable code segment
	beq	skip			; yes, skip it
	ldr	r2,[r1],#4		; code end address
	subs	r2,r4			; block size
	lsrs	r2,#2			; word size
cbcl:
	ldr	r0,[r4],#4		; get and
	str	r0,[r3],#4		; store
	subs	r2,#1			; count down
	bne	cbcl			; and loop back
	b	dbcl			; next segment
zbss:
	ldr	r1,atab+4		; get start of ram
	ldr	r2,atab+8		; get end of ram
	subs	r2,r1			; byte size
	beq	init			; empty, skip
	lsrs	r2,#2			; word size
	movs	r0,#0			; to clear the bss
zbcl:
	str	r0,[r1],#4		; clear memory
	subs	r2,#1			; count down
	bne	zbcl			; and loop back
init:
	ldr	sp,atab+12		; initialize SP
	ldr	r9,atab			; initialize DP
	ldr	r1,atab+20		; initialize FPU
	mov	r2,#$F<<20
	str	r2,[r1]
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
	dc.l	__idesc__		; descriptor start address
	dc.l	$E000ED88		; FPU control register
;
	end
