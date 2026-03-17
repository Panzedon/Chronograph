;	DOUBLE DIVISION
;	Copyright (c) 2011 by COSMIC Software
;	- r0:r1 /= r2:r3
;
	xdef c_ddiv
	.dcall  "20,0,c_ddiv"
;
c_ddiv:
	cbz	r0,fini		; 1st operand zero, exit
	cbnz	r2,nover	; 2nd operand zero, saturate
	orn	r0,r2,#$80000000 ; merge sign
	orr	r1,r0,#$80000000
fini:
	bx	lr		; and return
nover:
	push	{r4-r8}		; save registers
	ubfx	r7,r0,#20,#11	; extract first exponent
	ubfx	r6,r2,#20,#11	; extract second exponent
	subs	r7,r6		; result exponent
	add	r7,#1023	; restore offset
	eor	r8,r0,r2	; result sign
	and	r8,#$80000000	; isolated
;
	movs	r4,#1		; prepare hidden bit
	bfi	r0,r4,#20,#12	; extract mantissa
	bfi	r2,r4,#20,#12	; extract mantissa
	movs	r6,#0		; clear result LSW
	movs	r4,#53		; set counter
bcl:
	adds	r6,r6		; shift left
	adcs	r5,r5		; result
	cmp	r0,r2		; compare MSW
	blo	next		; smaller, skip
	bhi	oks		; larger, subtract
	cmp	r1,r3		; compare LSW
	blo	next		; smaller next
oks:
	subs	r1,r3		; subtract
	sbcs	r0,r2		; divisor
	adds	r6,#1		; set result bit;
next:
	adds	r1,r1		; shift
	adcs	r0,r0		; dividend
	subs	r4,#1		; count down
	bne	bcl		; and loop back
;
	clz	r4,r5		; leading zeros
	cmp	r4,#11
	beq	okn
	sub	r7,#1		; update exponent
	adds	r6,r6		; shift
	adcs	r5,r5		; result
okn:
	cmp	r7,#0		; check exponent
	blt	under		; underflow, zero
	movw	r4,#$7ff	; check
	cmp	r7,r4		; overflow
	bhi	over		; yes, saturate
	mov	r0,r5		; set result
	mov	r1,r6		; in place
	bfi	r0,r7,#20,#11	; insert exponent
	orr	r0,r8		; merge sign
fin:
	pop	{r4-r8}		; restore registers
	bx	lr		; and return
under:
	movs	r0,#0		; zero result
	movs	r1,#0
	b	fin		; and exit
over:
	orn	r0,r7,#$80000000 ; merge sign
	orr	r1,r0,#$80000000
	b	fin		; and exit
;
	end
