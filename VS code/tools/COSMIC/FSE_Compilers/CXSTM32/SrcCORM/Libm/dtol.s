;	DOUBLE TO LONG CONVERSION
;	Copyright (c) 2011 by COSMIC Software
;	- r0 = r0:r1
;
	xdef c_dtol
	.dcall  "8,0,c_dtol"
;
c_dtol:
	cmp	r0,#0		; test value
	beq	fini		; zero, exit
	push	{r2}		; save register
	ubfx	r2,r0,#20,#11	; extract exponent
	subw	r2,#1023	; remove offset
	cmp	r2,#0		; check
	blt	under		; underflow
	cmp	r2,#84		; check (32 + 52)
	bgt	over		; overflow
	cmp	r2,#52		; check count
	beq	merge		; result ok
	bge	posit		; left shift
	orr	r0,#$00100000	; set hidden bit
	subs	r2,#20		; check count
	ble	fast		; shift only MSW
	push	{r3}		; save register
	mov	r3,r0		; extract
	bfc	r3,#21,#11	; mantissa MSW
	lsl	r3,r2		; shift MSW
	rsbs	r2,#32		; revert count
	lsrs	r1,r2		; shift LSW
	orrs	r1,r3		; merge values
	pop	{r3}		; save register
	b	merge		; and merge with sign
fast:
	mov	r1,r0		; extract
	bfc	r1,#21,#11	; mantissa MSW
	negs	r2		; adjust count
	lsrs	r1,r2		; shift right
	b	merge		; and merge with sign
posit:
	sub	r2,#52		; adjust count
	lsls	r1,r2		; shift left
merge:
	cmp	r0,#0		; check sign
	ite	ge		; set result
	mov	r0,r1		; direct result
	neg	r0,r1		; negated result
	pop	{r2}		; restore register
fini:
	bx	lr		; and return
under:
	movs	r0,#0		; clear result
	pop	{r2}		; restore register
	bx	lr		; and return
over:
	cmp	r0,#0		; check result sign
	ite	ge		; max positive
	mvn	r0,#$80000000	; saturate +
	mov	r0,#$80000000	; saturate -
	pop	{r2}		; restore register
	bx	lr		; and return
;
	end
