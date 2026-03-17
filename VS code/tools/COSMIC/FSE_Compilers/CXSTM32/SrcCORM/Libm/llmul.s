;	LONG LONG MULTIPLY
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 *= r2:r3
;
	xdef c_llmul
;
c_llmul:
	muls	r3,r0		; H * L
	muls	r1,r2		; L * H
	adds	r3,r1		; accumulate MSW
	umull	r0,r1,r0,r2	; L * L
	adds	r1,r3		; complete MSW
	bx	lr		; and return
;
	end
