;	LONG LONG TO HARDWARE FLOAT CONVERSION
;	Copyright (c) 2013 by COSMIC Software
;	- s0 = r0:r1
;
	xdef c_lltos, c_ulltos
	.dcall  "12,0,c_lltos"
	.dcall  "12,0,c_ulltos"
;
c_ulltos:
	cbnz	r1,uok		; not zero, continue
	cbz	r0,fini		; zero, exit
uok:
	push	{r2}		; save register
	movs	r2,#0		; sign indicator
	b	pos		; and continue
c_lltos:
	cbnz	r1,sok		; not zero, continue
	cbnz	r0,sok		; not zero, continue
fini:
	vmov	s0,r0		; set result
	bx	lr		; and return
sok:
	push	{r2}		; save register
	movs	r2,r1		; result sign
	bge	pos		; positive, skip
	negs	r1		; set positive
	negs	r0
	sbcs	r1,#0
pos:
	vmov	s0,r0		; convert
	vcvt.fu	s0,s0		; low word
	cbz	r1,small	; check MSW
	vpush	{s1-s2}		; save registers
	vmov	s1,r1		; convert
	vcvt.fu	s1,s1		; high word
	vldr	s2,LD0		; multiplicator
	vmla	s0,s1,s2	; apply and accumulate
	vpop	{s1-s2}		; restore registers
small:
	cmp	r2,#0		; check sign
	it	lt		; if negative
	vneg	s0,s0		; invert
	pop	{r2}		; restore register
	bx	lr		; and return
;
	align	4
LD0:
	dc.l	0x4f800000	; 2**32
;
	end
