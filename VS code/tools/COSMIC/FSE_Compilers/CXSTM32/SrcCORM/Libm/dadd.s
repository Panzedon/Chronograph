;	DOUBLE ADDITION
;	Copyright (c) 2011 by COSMIC Software
;	- r0:r1 += r2:r3
;
	xdef c_dadd, c_dsub
	.dcall  "12,0,c_dadd"
	.dcall  "12,0,c_dsub"
;
c_dsub:
	cbz	r2,fini		; 2nd operand zero, exit
	eor	r2,#$80000000	; invert sign bit
	b	next		; and continue
c_dadd:
	cbz	r2,fini		; 2nd operand zero, exit
next:
	cbnz	r0,cont		; 1st operand zero, copy 2nd
	mov	r0,r2		; copy
	mov	r1,r3		; operand
fini:
	bx	lr		; and return
cont:
	push	{r4-r6}		; save registers
	ubfx	r5,r0,#20,#11	; extract first exponent
	ubfx	r6,r2,#20,#11	; extract second exponent
	movs	r4,#1		; prepare hidden bit
	cmp	r0,#0		; test sign
	bfi	r0,r4,#20,#12	; extract mantissa
	bge	pos1		; if negative
	negs	r1		; negate
	ite	ne		; operand
	mvn	r0,r0
	neg	r0
pos1:
	cmp	r2,#0		; test sign
	bfi	r2,r4,#20,#12	; extract mantissa
	bge	pos2		; if negative
	negs	r3		; negate
	ite	ne		; operand
	mvn	r2,r2
	neg	r2
pos2:
	subs	r4,r5,r6	; shift difference
	beq	oper		; skip shift
	bgt	direct		; shift second operand
	negs	r4		; positive shift count
	mov	r5,r6		; set resulting exponent
	mov	r6,r0		; invert
	mov	r0,r2		; operands
	mov	r2,r6
	mov	r6,r1
	mov	r1,r3
	mov	r3,r6
direct:
	cmp	r4,#31		; test for single word
	ble	dbl		; no, double word
	mov	r3,r2		; copy MSW
	asrs	r2,#31		; sign extend
	subs	r4,#32		; adjust count
	cmp	r4,#31		; check overflow
	bgt	res		; skip addition
	asrs	r3,r4		; shift result
	b	oper		; and continue
dbl:
	mov	r6,r2		; copy MSW
	asrs	r2,r4		; shift
	lsrs	r3,r4		; value
	rsb	r4,#32		; 32 - count
	lsls	r6,r4
	orrs	r3,r6
oper:
	adds	r1,r3		; add
	adcs	r0,r2		; mantissas
res:
	and	r2,r0,#$80000000 ; prepare sign bit
	bge	pos3		; if negative
	negs	r1		; negate
	ite	ne		; result
	mvn	r0,r0
	neg	r0
pos3:
	orrs	r3,r0,r1	; check result
	beq	fin		; zero, exit
	cbnz	r0,nozer	; MSW not zero, ok
	mov	r0,r1		; shift by 32
	movs	r1,#0
	subs	r5,#32		; adjust exponent
nozer:
	clz	r4,r0		; leading zeros
	subs	r4,#11		; check result
	beq	merge		; equal, no shift
	blt	right		; right shift
	subs	r5,r4		; adjust exponent
	mov	r6,r1		; copy LSW
	lsls	r0,r4		; shift
	lsls	r1,r4		; value
	rsb	r4,#32		; 32 - count
	lsrs	r6,r4
	orrs	r0,r6
	b	merge		; and merge exponent
right:
	negs	r4		; positive count
	adds	r5,r4		; adjust exponent
	mov	r6,r0		; copy MSW
	lsrs	r0,r4		; shift
	lsrs	r1,r4		; value
	rsb	r4,#32		; 32 - count
	lsls	r6,r4
	orrs	r1,r6
merge:
	cmp	r5,#0		; check exponent
	blt	under		; underflow, zero
	movw	r4,#$7ff	; check
	cmp	r5,r4		; overflow
	bhi	over		; yes, saturate
	bfi	r0,r5,#20,#11	; insert exponent
	orrs	r0,r2		; merge sign
fin:
	pop	{r4-r6}		; restore registers
	bx	lr		; and return
under:
	movs	r0,#0		; zero result
	movs	r1,#0
	b	fin		; and exit
over:
	orn	r0,r2,#$80000000 ; saturate + sign
	orr	r1,r0,#$80000000
	b	fin		; and exit
;
	end
