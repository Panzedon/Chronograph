;	LONG LONG TO FLOAT CONVERSION
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 = r0
;
	xdef c_lltof, c_ulltof
	.dcall  "8,0,c_lltof"
	.dcall  "8,0,c_ulltof"
;
c_ulltof:
	cbnz	r1,uok		; not zero, continue
	cbz	r0,fini		; zero, exit
uok:
	push	{r2,r3}		; save registers
	movs	r2,#127+55	; start exponent
	cmp	r1,#0		; check MSW
	b	pos		; and continue
c_lltof:
	cbnz	r1,sok		; not zero, continue
	cbnz	r0,sok		; not zero, continue
fini:
	bx	lr		; return
sok:
	push	{r2,r3}		; save registers
	movs	r2,#127+55	; start exponent
	cmp	r1,#0		; check sign
	bge	pos		; positive, skip
	orr	r2,#$0100	; set sign bit
	negs	r1		; set positive
	negs	r0
	sbcs	r1,#0
pos:
	bne	small		; MSW small enough
	mov	r1,r0		; shift left
	movs	r0,#0
	subs	r2,#32		; adjust exponent
small:
	clz	r3,r1		; leading zeros
	subs	r3,#8		; central position
	sub	r2,r3		; adjust exponent
	beq	nosh		; no shift
	bgt	left		; shift left
	negs	r3		; count
	lsrs	r1,r3		; align
	b	nosh		; and continue
left:
	lsls	r1,r3		; align MSW
	rsbs	r3,#32		; revert count
	lsrs	r0,r3		; shift LSW
	orrs	r1,r0		; merge
nosh:
	bfi	r1,r2,#23,#9	; insert sign and exponent
	mov	r0,r1		; result in place
	pop	{r2,r3}		; restore register
	bx	lr		; and return
;
	end
