;	DOUBLE TO FLOAT CONVERSION
;	Copyright (c) 2011 by COSMIC Software
;	- r0 = r0:r1
;
	xdef c_dtof
	.dcall  "4,0,c_dtof"
;
c_dtof:
	cbz	r0,fini		; zero, exit
	push	{r2}		; save register
	ubfx	r2,r0,#20,#11	; extract exponent
	subs	r2,#1023-127	; change offset
	blt	under		; underflow
	cmp	r2,#$ff		; check
	bgt	over		; overflow
	bfi	r0,r2,#23,#8	; insert exponent
	bfi	r0,r0,#3,#20	; insert mantissa
	lsrs	r1,#29		; complete
	bfi	r0,r1,#0,#3	; mantissa
	pop	{r2}		; restore register
fini:
	bx	lr		; and return
under:
	movs	r0,#0		; clear result
	pop	{r2}		; restore register
	bx	lr		; and return
over:
	orn	r0,#$80000000	; saturate
	pop	{r2}		; restore register
	bx	lr		; and return
;
	end
