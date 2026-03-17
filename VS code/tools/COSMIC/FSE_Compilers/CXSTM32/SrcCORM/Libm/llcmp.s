;	LONG LONG COMPARE
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 <> r2:r3
;
	xdef c_llcmp
;
c_llcmp:
	subs	r0,r2		; subtract
	sbcs	r1,r3		; values
	bne	ok		; not zero, exit
	rrxs	r1		; keep carry and sign
	cbz	r0,zero		; if not zero
	adds	r1,#1		; update resuly
zero:
	lsls	r1,#1		; restore flags
ok:
	bx	lr		; and return
;
	end
