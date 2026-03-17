;	LONG LONG TO DOUBLE CONVERSION
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 = r0:r1
;
	xdef c_lltod, c_ulltod
	.dcall  "12,0,c_lltod"
	.dcall  "12,0,c_ulltod"
;
c_ulltod:
	cbnz	r1,uok		; not zero, continue
	cbnz	r0,uok		; not zero, continue
	bx	lr		; zero, return
uok:
	push	{r2-r4}		; save register
	movw	r2,#1023+52	; start exponent
	cmp	r1,#0		; prepare MSW test
	b	pos		; and continue
c_lltod:
	cbnz	r1,sok		; not zero, continue
	cbnz	r0,sok		; not zero, continue
	bx	lr		; zero, return
sok:
	push	{r2-r4}		; save register
	movw	r2,#1023+52	; start exponent
	cmp	r1,#0
	bge	pos		; check sign
	orr	r2,#$0800	; set sign bit
	negs	r1		; positive
	negs	r0
	sbcs	r1,#0
pos:
	mov	r3,r0		; copy LSW
	bne	large		; MSW not zero, continue
	mov	r1,r3		; shift
	movs	r3,#0		; left
	subs	r2,#32		; adjust exponent
large:
	clz	r0,r1		; leading zeros
	subs	r0,#11		; central position
	sub	r2,r0		; adjust exponent
	beq	nosh		; no shift
	bgt	left		; shift left
	negs	r0		; rotate count
	mov	r4,r1		; copy MSW
	lsrs	r1,r0		; shift
	lsrs	r3,r0		; right
	rsbs	r0,#32		; revert count
	lsls	r4,r0
	orrs	r3,r4		; merge
nosh:
	bfi	r1,r2,#20,#12	; insert sign and exponent
	mov	r0,r1		; result
	mov	r1,r3		; in place
	pop	{r2-r4}		; restore register
	bx	lr		; and return
left:
	mov	r4,r3		; copy LSW
	lsls	r1,r0		; shift
	lsls	r3,r0		; left
	rsbs	r0,#32		; revert count
	lsrs	r4,r0
	orrs	r1,r4		; merge
	b	nosh		; and termminate
;
	end
