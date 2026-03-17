;	LONG TO DOUBLE CONVERSION
;	Copyright (c) 2011 by COSMIC Software
;	- r0:r1 = r0
;
	xdef c_ltod, c_ultod
	.dcall  "4,0,c_ltol"
	.dcall  "4,0,c_ultol"
;
c_ultod:
	cbz	r0,zero		; zero, clear result
	push	{r2}		; save register
	movw	r2,#1023+20	; start exponent
	b	pos		; and continue
zero:
	movs	r1,#0		; complete result
	bx	lr		; and return
c_ltod:
	cmp	r0,#0		; test value
	beq	zero		; zero, clear result
	push	{r2}		; save register
	movw	r2,#1023+20	; start exponent
	bge	pos		; check sign
	negs	r0		; positive
	orr	r2,#$0800	; set sign bit
pos:
	clz	r1,r0		; leading zeros
	subs	r1,#11		; central position
	sub	r2,r1		; adjust exponent
	beq	nosh		; no shift
	bgt	left		; shift left
	negs	r1		; rotate count
	rors	r0,r1		; rotate
	mov	r1,r0		; set
	bfc	r1,#0,#21	; mantissa LSW
nosh:
	bfi	r0,r2,#20,#12	; insert sign and exponent
	pop	{r2}		; restore register
	bx	lr		; and return
left:
	lsls	r0,r1		; align
	movs	r1,#0		; complete
	b	nosh		; and termminate
;
	end
