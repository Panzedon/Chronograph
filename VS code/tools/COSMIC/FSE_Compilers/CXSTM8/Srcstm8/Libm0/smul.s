;	LONG MULTIPLY BY A BYTE
;	Copyright (c) 2006 by COSMIC Software
;	- 1st arg and result in LONG ACCU
;	- 2nd arg in A
;
	xdef	c_smul
	xref.b	c_lreg
	.dcall	"6,0,1,c_smul"
;
c_smul:
	pushw	x		; save registers
	pushw	y
	ld	yl,a		; save operand
	ld	xl,a
	ld	a,c_lreg	; HH
	mul	x,a
	ld	a,xl
	ld	c_lreg,a
	ldw	x,y
	ld	a,c_lreg+1	; HL
	clr	c_lreg+1
	mul	x,a
	addw	x,c_lreg
	ldw	c_lreg,x
	ldw	x,y
	ld	a,c_lreg+2	; LH
	clr	c_lreg+2
	mul	x,a
	addw	x,c_lreg+1
	ldw	c_lreg+1,x
	jrnc	ok1
	inc	c_lreg
ok1:
	ld	a,c_lreg+3	; LL
	ldw	x,y
	clr	c_lreg+3
	mul	x,a
	addw	x,c_lreg+2
	ldw	c_lreg+2,x
	jrnc	ok2
	ldw	x,c_lreg
	incw	x
	ldw	c_lreg,x
ok2:
	popw	y		; restore registers
	popw	x
	ret			; and return
;
	end
