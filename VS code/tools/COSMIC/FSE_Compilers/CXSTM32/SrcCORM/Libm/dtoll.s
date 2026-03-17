;	DOUBLE TO LONG LONG CONVERSION
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 = r0:r1
;
	xdef c_dtoll
	.dcall  "12,0,c_dtoll"
;
c_dtoll:
	cmp	r0,#0		; test value
	beq	fini		; zero, exit
	push	{r2-r4}		; save register
	ubfx	r2,r0,#20,#11	; extract exponent
	subw	r2,#1023	; remove offset
	cmp	r2,#0		; check
	blt	under		; underflow
	cmp	r2,#116		; check (64 + 52)
	bgt	over		; overflow
	mov	r3,r0		; extract
	bfc	r3,#21,#11	; mantissa MSW
	orr	r3,#$00100000	; set hidden bit
	cmp	r2,#52		; check count
	beq	merge		; result ok
	bge	posit		; left shift
	subs	r2,#20		; check count
	ble	rfast		; shift only MSW
	lsls	r4,r3,r2	; shifted copy
	rsbs	r2,#32		; revert count
	lsrs	r1,r2		; shift LSW
	lsrs	r3,r2		; shift MSW
	orrs	r1,r4		; merge LSW
	b	merge		; and merge with sign
rfast:
	negs	r2		; adjust count
	lsrs	r1,r3,r2	; shift right
	movs	r3,#0		; set MSW
	b	merge		; and merge with sign
lfast:
	subs	r2,#32		; adjust count
	lsls	r3,r1,r2	; shift left
	movs	r1,#0		; set LSW
	b	merge		; and merge with sign
posit:
	subs	r2,#52		; adjust count
	cmp	r2,#32		; check count
	bge	lfast		; fast left
	mov	r4,r1		; copy LSW
	lsls	r1,r2		; shift left
	lsls	r3,r2
	rsbs	r2,#32		; revert count
	lsrs	r4,r2
	orrs	r3,r4		; merge MSW
merge:
	cmp	r0,#0		; check sign
	mov	r0,r1		; copy
	mov	r1,r3		; result
	bge	rpos		; if negative
	negs	r1		; negate
	negs	r0		; result
	sbcs	r1,#0
rpos:
	pop	{r2-r4}		; restore register
	bx	lr		; and return
under:
	movs	r0,#0		; clear result
fini:
	movs	r1,#0
	pop	{r2-r4}		; restore register
	bx	lr		; and return
over:
	cmp	r0,#0		; check result sign
	ittee	ge		; max positive
	mvn	r1,#$80000000	; saturate +
	mvn	r0,#0
	mov	r1,#$80000000	; saturate -
	mov	r0,#0
	pop	{r2-r4}		; restore register
	bx	lr		; and return
;
	end
