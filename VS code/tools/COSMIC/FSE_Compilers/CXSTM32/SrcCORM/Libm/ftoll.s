;	FLOAT TO LONG LONG CONVERSION
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 = r0
;
	xdef c_ftoll
	.dcall	"8,0,c_ftoll"
;
c_ftoll:
	cbz	r0,zero		; zero, exit
	push	{r2,r3}		; save registers
	ubfx	r2,r0,#23,#8	; extract exponent
	subs	r2,#127		; remove offset
	blt	under		; underflow
	cmp	r2,#87		; check (64 + 23)
	bgt	over		; overflow
	mov	r1,r0		; extract
	bfc	r1,#23,#9	; mantissa
	orr	r1,#$00800000	; set hidden bit
	movs	r3,#0		; set MSW
	subs	r2,#23		; check count
	beq	merge		; no shift
	bgt	posit		; shift left
	negs	r2		; adjust count
	lsrs	r1,r2		; shift right
	b	merge		; and merge with sign
zero:
	movs	r1,#0
	bx	lr		; and return
lfast:
	subs	r2,#32		; adjust count
	lsl	r3,r1,r2	; shift left
	movs	r1,#0		; set LSW
	b	merge		; and merge with sign
posit:
	cmp	r2,#32		; check count
	bge	lfast		; fast shift
	rsbs	r3,r2,#32	; reverted count
	lsrs	r3,r1,r3	; set MSW
	lsls	r1,r2		; shift LSW
merge:
	cmp	r0,#0		; check sign
	mov	r0,r1		; copy
	mov	r1,r3		; result
	bge	rpos		; if negative
	negs	r1		; negate
	negs	r0		; result
	sbcs	r1,#0
rpos:
	pop	{r2,r3}		; restore registers
	bx	lr		; and return
under:
	movs	r0,#0		; clear result
	movs	r1,#0
	pop	{r2,r3}		; restore registers
	bx	lr		; and return
over:
	cmp	r0,#0		; check result sign
	ittee	ge		; max positive
	mvn	r1,#$80000000	; saturate +
	mvn	r0,#0
	mov	r1,#$80000000	; saturate -
	mov	r0,#0
	pop	{r2,r3}		; restore registers
	bx	lr		; and return
;
	end
