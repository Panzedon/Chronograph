;	DOUBLE MULTIPLY
;	Copyright (c) 2011 by COSMIC Software
;	- r0:r1 *= r2:r3
;
	xdef c_dmul
	.dcall  "24,0,c_dmul"
;
c_dmul:
	cbz	r0,fini		; 1st operand zero, exit
	cbnz	r2,next		; 2nd operand zero, copy
	movs	r0,#0		; zero result
	movs	r1,#0
fini:
	bx	lr		; and return
next:
	push	{r4-r7,r10,r11}	; save registers
	ubfx	r6,r0,#20,#11	; extract first exponent
	ubfx	r7,r2,#20,#11	; extract second exponent
	adds	r6,r7		; result exponent
	subw	r10,r6,#1023	; remove one offset
	eor	r11,r0,r2	; result sign
	and	r11,#$80000000	; isolated
;
	movs	r4,#1		; prepare hidden bit
	bfi	r0,r4,#20,#12	; extract mantissa
	bfi	r2,r4,#20,#12	; extract mantissa
	umull	r7,r6,r1,r3	; set 3rd word
	umull	r5,r4,r0,r2	; set 1st and 2nd word
	umull	r1,r7,r1,r2	; cross product 1
	adds	r6,r1
	adcs	r5,r7
	adcs	r4,#0
	umull	r3,r7,r3,r0	; cross product 2
	adds	r6,r3
	adcs	r5,r7
	adcs	r4,#0
;
	clz	r1,r4		; leading zeros
	subs	r1,#11		; align count
	cmp	r1,#12
	it	ne		; prepare
	add	r10,#1		; exponent
	mov	r3,r5		; copy 2nd word
	lsls	r4,r1		; shift
	lsls	r5,r1		; words
	rsb	r1,#32		; 32 - count
	lsrs	r3,r1		; shift
	lsrs	r6,r1		; words
	orr	r0,r4,r3	; merge
	orr	r1,r5,r6	; result
;
	cmp	r10,#0		; check exponent
	blt	under		; underflow, zero
	movw	r4,#$7ff	; check
	cmp	r10,r4		; overflow
	bhi	over		; yes, saturate
	bfi	r0,r10,#20,#11	; insert exponent
	orr	r0,r11		; merge sign
fin:
	pop	{r4-r7,r10,r11}	; restore registers
	bx	lr		; and return
under:
	movs	r0,#0		; zero result
	movs	r1,#0
	b	fin		; and exit
over:
	orn	r0,r11,#$80000000 ; merge sign
	orr	r1,r0,#$80000000
	b	fin		; and exit
;
	end
