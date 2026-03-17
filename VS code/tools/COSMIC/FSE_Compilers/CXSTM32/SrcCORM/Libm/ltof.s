;	LONG TO FLOAT CONVERSION
;	Copyright (c) 2011 by COSMIC Software
;	- r0 = r0
;
	xdef c_ltof, c_ultof
	.dcall  "8,0,c_ltof"
	.dcall  "8,0,c_ultof"
;
c_ultof:
	cbz	r0,fini		; zero, exit
	push	{r1,r2}		; save registers
	movs	r1,#127+23	; start exponent
	b	pos		; and continue
c_ltof:
	cbz	r0,fini		; zero, exit
	push	{r1-r2}		; save registers
	movs	r1,#127+23	; start exponent
	cmp	r0,#0		; check sign
	bge	pos		; positive, skip
	negs	r0		; set positive
	orr	r1,#$0100	; set sign bit
pos:
	clz	r2,r0		; leading zeros
	subs	r2,#8		; central position
	sub	r1,r2		; adjust exponent
	beq	nosh		; no shift
	bgt	left		; shift left
	negs	r2		; count
	lsrs	r0,r2		; align
	b	nosh		; and continue
left:
	lsls	r0,r2		; align
nosh:
	bfi	r0,r1,#23,#9	; insert sign and exponent
	pop	{r1,r2}		; restore register
fini:
	bx	lr		; and return
;
	end
