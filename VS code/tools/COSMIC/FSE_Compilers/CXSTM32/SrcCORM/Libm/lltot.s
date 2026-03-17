;	LONG LONG TO HARDWARE DOUBLE CONVERSION
;	Copyright (c) 2016 by COSMIC Software
;	- d0 = r0:r1
;
	xdef c_lltot, c_ulltot
	.dcall  "20,0,c_lltot"
	.dcall  "20,0,c_ulltot"
;
c_ulltot:
	cbnz	r1,uok		; not zero, continue
	cbz	r0,fini		; zero, exit
uok:
	push	{r2}		; save register
	movs	r2,#0		; sign indicator
	b	pos		; and continue
c_lltot:
	cbnz	r1,sok		; not zero, continue
	cbnz	r0,sok		; not zero, continue
fini:
	vmov	d0,r0,r1	; set result
	bx	lr		; and return
sok:
	push	{r2}		; save register
	movs	r2,r1		; result sign
	bge	pos		; positive, skip
	negs	r1		; set positive
	negs	r0
	sbcs	r1,#0
pos:
	vmov	s1,r0		; convert
	vcvt.fu	d0,s1		; low word
	cbz	r1,small	; check MSW
	vpush	{d1-d2}		; save registers
	vmov	s3,r1		; convert
	vcvt.fu	d1,s3		; high word
	vldr	d2,LD0		; multiplicator
	vmla	d0,d1,d2	; apply and accumulate
	vpop	{d1-d2}		; restore registers
small:
	cmp	r2,#0		; check sign
	it	lt		; if negative
	vneg	d0,d0		; invert
	pop	{r2}		; restore register
	bx	lr		; and return
;
	align	4
LD0:
	dc.l	0x41f00000	; 2**32
	dc.l	0x00000000
;
	end
