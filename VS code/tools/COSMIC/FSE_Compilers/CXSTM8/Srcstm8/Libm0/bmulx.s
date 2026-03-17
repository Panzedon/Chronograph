;	MULTIPLY 16 x 8 -> 16
;	Copyright (c) 2017 by COSMIC Software
;	- 1st operand and result in X
;	- 2nd operand in A
;
	xdef	c_bmulx
	xref.b	c_x
	.dcall	"4,0,c_bmulx"
;
c_bmulx:
	pushw	x		; save operand
	mul	x,a		; L * B
	ldw	c_x,x		; save result
	popw	x		; restore operand
	swapw	x		; get high byte
	mul	x,a		; H * B
	clr	a		; shift
	rlwa	x,a		; result
	addw	x,c_x		; accumulate
	ret			; and return
;
	end
