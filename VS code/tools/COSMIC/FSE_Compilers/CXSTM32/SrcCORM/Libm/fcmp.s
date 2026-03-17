;	FLOAT COMPARE
;	Copyright (c) 2011 by COSMIC Software
;	- r0 <> r1
;
	xdef c_fcmp
;
c_fcmp:
	tst	r0,r1		; both negative
	bpl	noneg		; no, normal compare
rev:
	cmp	r1,r0		; reverse compare value
	bx	lr		; and return
noneg:
	cmp	r0,r1		; compare value
	bx	lr		; and return
;
	end
