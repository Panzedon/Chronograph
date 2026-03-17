;	LONG MULTIPLY SIGNED 16 x 16 -> 32
;	Copyright (c) 2009 by COSMIC Software
;	- 1st operand in X
;	- 2nd operand in Y
;	- result in long accumulator
;
	xdef	d_vmul
	xref.b	c_x, c_y, c_lreg
	.dcall	"4,0,1,d_vmul"
;
d_vmul:
	push	a		; save register
	ldw	c_x,x		; copy
	ldw	c_y,y		; operands
	ld	a,yl		; load LSB2
	mul	x,a		; L * L
	ldw	c_lreg+2,x	; save result
	ld	a,c_x		; load MSB1
	ld	xl,a
	ld	a,c_y		; load MSB2
	mul	x,a		; H * H
	ldw	c_lreg,x	; save result
	tnz	a		; test MSB2
	jreq	next		; nul, continue
	jrpl	pos2		; positive, skip
	subw	x,c_x		; subtract 1st operand
	ldw	c_lreg,x	; save MSW
pos2:
	ld	xl,a
	ld	a,c_x+1		; load LSB1
	jreq	next		; nul, continue
	mul	x,a		; H * L
	addw	x,c_lreg+1	; accumulate
	ldw	c_lreg+1,x	; in memory
	jrnc	next		; propagate carry
	inc	c_lreg		; if any
next:
	ld	a,c_x		; load MSB1
	jreq	fini		; exit if nul
	jrpl	pos1		; positive, skip
	ldw	x,c_lreg	; get MSW
	subw	x,c_y		; subtract 2nd operand
	ldw	c_lreg,x	; save MSW
pos1:
	ld	xl,a
	ld	a,c_y+1		; load LSB2
	jreq	fini		; nul, exit
	mul	x,a		; H * L
	addw	x,c_lreg+1	; accumulate
	ldw	c_lreg+1,x	; in memory
	jrnc	fini		; propagate carry
	inc	c_lreg		; if any
fini:
	pop	a		; restore register
	retf			; and return
;
	end
