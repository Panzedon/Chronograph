;	MULTIPLY 16 x 8 -> 16
;	Copyright (c) 2017 by COSMIC Software
;	- 1st operand and result in X
;	- 2nd operand in A
;
	xdef	d_bmulx
	xref.b	c_x
	.dcall	"5,0,d_bmulx"
;
d_bmulx:
	pushw	x		; save operand
	mul	x,a		; L * B
	ldw	c_x,x		; save result
	popw	x		; restore operand
	swapw	x		; get high byte
	mul	x,a		; H * B
	clr	a		; shift
	rlwa	x,a		; result
	addw	x,c_x		; accumulate
	retf			; and return
;
	end
