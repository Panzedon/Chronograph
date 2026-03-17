;	C STARTUP CODE WITH DATA INITIALIZATION - M0
;	Copyright (c) 2012 by COSMIC Software
;
	xdef	_exit, __stext
	xref.l	_main, __sram, __eram, __stack, __idesc__
;
__stext:
	ldr	r1,atab+12		; descriptor address
skip:
	ldr	r4,[r1]			; first image address
	adds	r1,#4
dbcl:
	ldr	r2,[r1]			; get flag word
	adds	r1,#4
	cmp	r2,#0			; end
	beq	zbss			; yes, continue
	ldr	r3,[r1]			; ram start address
	adds	r1,#4
	movs	r0,#$60			; test for
	ands	r2,r0			; moveable code segment
	beq	skip			; yes, skip it
	ldr	r2,[r1]			; code end address
	adds	r1,#4
	subs	r2,r4			; block size
	lsrs	r2,#2			; word size
cbcl:
	ldr	r0,[r4]			; get and
	str	r0,[r3]			; store
	adds	r4,#4
	adds	r3,#4
	subs	r2,#1			; count down
	bne	cbcl			; and loop back
	b	dbcl			; next segment
zbss:
	ldr	r1,atab+0		; get start of ram
	ldr	r2,atab+4		; get end of ram
	subs	r2,r1			; byte size
	beq	init			; empty, skip
	lsrs	r2,#2			; word size
	movs	r0,#0			; to clear the bss
zbcl:
	str	r0,[r1]			; clear memory
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
	dc.l	__idesc__		; descriptor start address
;
	end
