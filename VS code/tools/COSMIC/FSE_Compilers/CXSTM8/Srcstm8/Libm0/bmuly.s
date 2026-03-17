;	MULTIPLY 16 x 8 -> 16
;	Copyright (c) 2017 by COSMIC Software
;	- 1st operand and result in Y
;	- 2nd operand in A
;
	xdef	c_bmuly
	xref.b	c_y
	.dcall	"4,0,c_bmuly"
;
c_bmuly:
	exgw	x,y		; for efficiency
	pushw	x		; save operand
	mul	x,a		; L * B
	ldw	c_y,x		; save result
	popw	x		; restore operand
	swapw	x		; get high byte
	mul	x,a		; H * B
	clr	a		; shift
	rlwa	x,a		; result
	addw	x,c_y		; accumulate
	exgw	x,y		; result in place
	ret			; and return
;
	end
