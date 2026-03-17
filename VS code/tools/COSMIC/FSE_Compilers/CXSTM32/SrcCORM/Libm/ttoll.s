;	HARDWARE DOUBLE TO LONG LONG CONVERSION
;	Copyright (c) 2016 by COSMIC Software
;	- r0:r1 = d0
;
	xdef c_ttoll
	.dcall	"24,0,c_ttoll"
;
c_ttoll:
	vcmp	d0,#0		; if zero
	vmrs	apsr,fpsr
	bne	nozer
	movs	r0,#0		; clear result
	movs	r1,#0
	bx	lr		; and return
nozer:
	vpush	{d1-d3}		; save registers
	vabs	d1,d0		; copy input
	vldr	d2,LD0		; divisor
	vdiv	d3,d1,d2	; apply
	vcvt.uf	s7,d3		; convert to int
	vmov	r1,s7		; set MSW
	vcvt.fu	d3,s7		; back to double
	vmls	d1,d3,d2	; apply and subtract
	vcvt.uf	s3,d1		; convert to int
	vmov	r0,s3		; set LSW
	bge	pos		; if negative
	negs	r1		; negate
	negs	r0		; result
	sbcs	r1,#0
pos:
	vpop	{d1-d3}		; restore registers
	bx	lr		; and return
;
	align	4
LD0:
	dc.l	0x41f00000	; 2**32
	dc.l	0x00000000
;
	end
