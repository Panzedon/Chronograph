;	FLOAT TO LONG CONVERSION
;	Copyright (c) 2011 by COSMIC Software
;	- r0 = r0
;
	xdef c_ftol
	.dcall	"4,0,c_ftol"
;
c_ftol:
	cbz	r0,fini		; zero, exit
	push	{r1,r2}		; restore registers
	ubfx	r1,r0,#23,#8	; extract exponent
	subs	r1,#127		; remove offset
	blt	under		; underflow
	cmp	r1,#56		; check (32 + 23)
	bgt	over		; overflow
	mov	r2,r0		; extract
	bfc	r2,#23,#9	; mantissa
	orr	r2,#$00800000	; set hidden bit
	subs	r1,#23		; check count
	beq	merge		; no shift
	bgt	posit		; shift left
	negs	r1		; adjust count
	lsrs	r2,r1		; shift right
	b	merge		; and merge with sign
posit:
	lsls	r2,r1		; shift left
merge:
	cmp	r0,#0		; check sign
	ite	ge		; set result
	mov	r0,r2		; direct result
	neg	r0,r2		; negated result
	pop	{r1,r2}		; restore registers
fini:
	bx	lr		; and return
under:
	movs	r0,#0		; clear result
	pop	{r1,r2}		; restore registers
	bx	lr		; and return
over:
	cmp	r0,#0		; check result sign
	ite	ge		; max positive
	mvn	r0,#$80000000	; saturate +
	mov	r0,#$80000000	; saturate -
	pop	{r1,r2}		; restore registers
	bx	lr		; and return
;
	end
