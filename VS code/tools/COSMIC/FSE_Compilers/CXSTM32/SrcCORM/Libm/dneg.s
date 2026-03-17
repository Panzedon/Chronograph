;	DOUBLE/FLOAT NEGATE
;	Copyright (c) 2011 by COSMIC Software
;	- r0(:r1) = -r0(:r1)
;
	xdef c_dneg, c_fneg
;
c_dneg:
c_fneg:
	cbz	r0,fini		; zero, exit
	eor	r0,#$80000000	; invert sign
fini:
	bx	lr		; and return
;
	end
