;	FLOAT MULTIPLY
;	Copyright (c) 2011 by COSMIC Software
;	- r0 *= r1
;
	xdef c_fmul
	.dcall  "12,0,c_fmul"
;
c_fmul:
	cbz	r0,fini		; 1st operand zero, exit
	cbnz	r1,cont		; 2nd operand zero, copy
	movs	r0,#0		; zero result
fini:
	bx	lr		; and return
cont:
	push	{r2-r4}		; save registers
	ubfx	r3,r0,#23,#8	; extract first exponent
	ubfx	r4,r1,#23,#8	; extract second exponent
	adds	r3,r4		; result exponent
	subs	r3,#127		; remove one offset
	eor	r4,r0,r1	; result sign
	and	r4,#$80000000	; isolated
;
	movs	r2,#1		; prepare hidden bit
	bfi	r0,r2,#23,#9	; extract mantissa
	bfi	r1,r2,#23,#9	; extract mantissa
	umull	r1,r0,r0,r1	; long product
;
	clz	r2,r0		; leading zeros
	subs	r2,#8		; align count
	cmp	r2,#9
	it	ne		; update
	add	r3,#1		; exponent
	lsls	r0,r2		; shift
	rsbs	r2,#32		; 32 - count
	lsrs	r1,r2		; shift
	orr	r0,r1		; merge
	bcc	nornd		; round
	adds	r0,#1		; propagate
	ands	r2,r0,#$ff000000 ; too high
	beq	nornd		; yes
	adds	r3,#1		; adjust exponent
nornd:
;
	cmp	r3,#0		; check exponent
	blt	under		; underflow, zero
	cmp	r3,#$ff		; check overflow
	bhi	over		; overflow, saturate
	bfi	r0,r3,#23,#8	; insert exponent
	orrs	r0,r4		; merge sign
fin:
	pop	{r2-r4}		; restore registers
	bx	lr		; and return
under:
	movs	r0,#0		; zero result
	b	fin		; and exit
over:
	orn	r0,r4,#$80000000 ; saturate + sign
	b	fin		; and exit
;
	end
