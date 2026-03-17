;	FLOAT TO DOUBLE CONVERSION
;	Copyright (c) 2011 by COSMIC Software
;	- r0:r1 = r0
;
	xdef c_ftod
        .dcall  "4,0,c_ftod"
;
c_ftod:
	movs	r1,r0		; copy mantisa
	beq	fini		; zero, exit
	push	{r2}		; save register
	ubfx	r2,r0,#23,#8	; extract exponent
	add	r2,#1023-127	; change offset
	lsls	r1,#29		; align
	asrs	r0,#3		; mantissa
	bfi	r0,r2,#20,#11	; insert exponent
	pop	{r2}		; restore register
fini:
	bx	lr		; and return
;
	end
