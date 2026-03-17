;	INTEGER MULTIPLY
;	Copyright (c) 2006 by COSMIC Software
;	- 1st operand in X
;	- 2nd operand in Y
;
	xdef	d_imul
	xref.b	c_x
	.dcall	"3,0,d_imul"
;
d_imul:
	rrwa	y,a		; save a and get LSB
	ldw	c_x+1,x		; save operand
	swapw	x
	mul	x,a		; H * L
	ldw	c_x,x		; save in memory
	rrwa	y,a		; load MSB
	tnz	a
	jreq	zok		; nul, skip
	ldw	x,c_x+1		; load LSB
	mul	x,a		; L * H
	addw	x,c_x		; accumulate
	ldw	c_x,x		; and store
zok:
	rlwa	y,a		; load LSB
	ldw	x,c_x+1		; load LSB
	clr	c_x+2		; prepare
	mul	x,a		; L * L
	addw	x,c_x+1		; accumulate
	rlwa	y,a		; restore register
	retf			; and return
;
	end
