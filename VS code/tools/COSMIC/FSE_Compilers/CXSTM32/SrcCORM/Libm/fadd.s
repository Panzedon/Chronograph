;	FLOAT ADDITION
;	Copyright (c) 2011 by COSMIC Software
;	- r0 += r1
;
	xdef c_fadd, c_fsub
	.dcall  "12,0,c_fadd"
	.dcall  "12,0,c_fsub"
;
c_fsub:
	cbz	r1,fini		; 2nd operand zero, exit
	eor	r1,#$80000000	; invert sign bit
	b	next		; and continue
c_fadd:
	cbz	r1,fini		; 2nd operand zero, exit
next:
	cbnz	r0,cont		; 1st operand zero, copy 2nd
	mov	r0,r1		; copy
fini:
	bx	lr		; and return
cont:
	push	{r2-r4}		; save registers
	ubfx	r3,r0,#23,#8	; extract first exponent
	ubfx	r4,r1,#23,#8	; extract second exponent
;
	movs	r2,#1		; prepare hidden bit
	cmp	r0,#0		; test sign
	bfi	r0,r2,#23,#9	; extract mantissa
	it	mi		; set
	neg	r0		; signed value
	lsls	r0,#6		; align
	cmp	r1,#0		; test sign
	bfi	r1,r2,#23,#9	; extract mantissa
	it	mi		; set
	neg	r1		; signed value
	lsls	r1,#6		; align
	subs	r2,r3,r4	; shift difference
	beq	oper		; skip shift
	bgt	direct		; shift second operand
	negs	r2		; positive shift count
	mov	r3,r4		; set resulting exponent
	mov	r4,r0		; invert
	mov	r0,r1		; operands
	mov	r1,r4
direct:
	cmp	r2,#31		; test for overflow
	bgt	res		; skip addition
	asrs	r1,r2		; shift result
oper:
	adds	r0,r1		; add mantissas
res:
	cmp	r0,#0		; check result
	beq	fin		; zero, exit
	and	r1,r0,#$80000000 ; prepare sign bit
	it	mi		; get
	neg	r0		; abs value
	clz	r2,r0		; leading zeros
	subs	r2,#8		; check result
	beq	merge		; equal, no shift
	blt	right		; right shift
	lsls	r0,r2		; shift
	subs	r3,r2		; adjust exponent
	b	merge		; and merge exponent
right:
	negs	r2		; positive count
	adds	r3,r2		; adjust exponent
	mov	r4,r0		; keep for rounding
	lsrs	r0,r2		; shift
	bcc	merge		; check round
	rsb	r2,#33		; revert count
	lsls	r4,r2		; rounding bits
	bne	rok		; round if not zero
	lsrs	r4,r0,#1	; last bit
	bcc	merge		; must be zero
rok:
	adds	r0,#1		; propagate
	ands	r2,r0,#$ff000000 ; too high
	it	ne		; yes
	adds	r3,#1		; update exponent
merge:
	subs	r3,#6		; adjust exponent
	blt	under		; underflow, zero
	cmp	r3,#$ff		; check overflow
	bhi	over		; overflow, saturate
	bfi	r0,r3,#23,#8	; insert exponent
	orrs	r0,r1		; merge sign
fin:
	pop	{r2-r4}		; restore registers
	bx	lr		; and return
under:
	movs	r0,#0		; zero result
	b	fin		; and exit
over:
	orn	r0,r1,#$80000000 ; saturate + sign
	b	fin		; and exit
;
	end
