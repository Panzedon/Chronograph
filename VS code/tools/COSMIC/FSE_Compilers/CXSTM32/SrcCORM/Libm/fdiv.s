;	FLOAT DIVISION
;	Copyright (c) 2011 by COSMIC Software
;	- r0 /= r1
;
	xdef c_fdiv
	.dcall  "20,0,c_fdiv"
;
c_fdiv:
	cmp	r0,#0		; test 1st operand
	beq	fini		; zero, exit
	cmp	r1,#0		; test 2nd operand
	beq	ov1		; zero, saturate
	push	{r2-r5}		; save registers
	ubfx	r4,r0,#23,#8	; extract first exponent
	ubfx	r5,r1,#23,#8	; extract second exponent
	subs	r4,r5		; result exponent
	adds	r4,#127		; restore offset
	eor	r5,r0,r1	; result sign
	and	r5,#$80000000	; isolated
;
	movs	r2,#1		; prepare hidden bit
	bfi	r0,r2,#23,#9	; extract mantissa
	bfi	r1,r2,#23,#9	; extract mantissa
	movs	r2,#26		; set counter
	movs	r3,#0		; clear result
bcl:
	lsls	r3,#1		; shift result
	cmp	r0,r1		; compare values
	blo	next		; smaller, continue
	subs	r0,r1		; subtract
	adds	r3,#1		; set bit
next:
	lsls	r0,#1		; shift dividend
	subs	r2,#1		; count down
	bne	bcl		; and loop back
;
	clz	r2,r3		; leading zeros
	cmp	r2,#6		; align count
	beq	nos		; correct, continue
	subs	r4,#1		; update exponent
	lsls	r3,#1		; shift
nos:
	lsrs	r3,#2		; align
	bcc	nornd		; if round
	adds	r3,#1		; propagate
	ands	r2,r3,#$ff000000 ; too high
	beq	nornd		; yes
	adds	r4,#1		; adjust exponent
nornd:
	cmp	r4,#0		; check exponent
	blt	under		; underflow, zero
	cmp	r4,#$ff		; check overflow
	bhi	over		; overflow, saturate
	mov	r0,r3		; set result
	bfi	r0,r4,#23,#8	; insert exponent
	orrs	r0,r5		; merge sign
fin:
	pop	{r2-r5}		; restore registers
fini:
	bx	lr		; and return
under:
	movs	r0,#0		; zero result
	b	fin		; and exit
over:
	orn	r0,r5,#$80000000 ; merge sign
	b	fin		; and exit
ov1:
	orn	r0,#$80000000	; saturate + sign
	bx	lr		; and return
;
	end
