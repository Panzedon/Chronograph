;	HARDWARE FLOAT TO LONG LONG CONVERSION
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 = s0
;
	xdef c_stoll
	.dcall	"12,0,c_stoll"
;
c_stoll:
	vcmp	s0,#0		; if zero
	vmrs	apsr,fpsr
	bne	nozer
	movs	r0,#0		; clear result
	movs	r1,#0
	bx	lr		; and return
nozer:
	vpush	{s1-s3}		; save registers
	vabs	s1,s0		; copy input
	vldr	s2,LD0		; divisor
	vdiv	s3,s1,s2	; apply
	vcvt.uf	s3,s3		; convert to int
	vmov	r1,s3		; set MSW
	vcvt.fu	s3,s3		; back to float
	vmls	s1,s3,s2	; apply and subtract
	vcvt.uf	s1,s1		; convert to int
	vmov	r0,s1		; set LSW
	bge	pos		; if negative
	negs	r1		; negate
	negs	r0		; result
	sbcs	r1,#0
pos:
	vpop	{s1-s3}		; restore registers
	bx	lr		; and return
;
	align	4
LD0:
	dc.l	0x4f800000	; 2**32
;
	end
