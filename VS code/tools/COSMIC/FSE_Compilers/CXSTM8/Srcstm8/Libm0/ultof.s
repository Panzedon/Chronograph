;	UNSIGNED LONG INTEGER TO FLOAT CONVERSION
;	Copyright (c) 2006 by COSMIC Software
;	- operand and result in ACCU
;
	xdef	c_ultof
	xref.b	c_lreg
	.dcall	"6,0,1,c_ultof"
;
c_ultof:
	pushw	x		; save
	pushw	y		; registers
	ld	a,#23		; start exponent
	ldw	y,c_lreg+2	; load LSW
	tnz	c_lreg		; check MSB
	jrne	panul		; not nul, continue
	ldw	x,c_lreg	; test zero
	jrne	fasta
	tnzw	y
	jreq	fini		; zero, exit
fasta:
	tnz	c_lreg+1	; check MSB
	jrmi	panor		; normalize ok
	jrne	bcla		; not nul, slow shift
	ldw	c_lreg+1,y	; byte shift
	clr	c_lreg+3
	ldw	y,c_lreg+2
	sub	a,#8		; update exponent
	jra	fasta
bcla:
	dec	a		; update exponent
	sllw	y		; shift value
	rlc	c_lreg+1
	jrpl	bcla		; and loop again
	jra	panor		; and continue
panul:
	ldw	x,c_lreg
	ldw	y,c_lreg+2
bclb:
	inc	a		; update exponent
	srlw	x		; shift value
	rrcw	y
	srl	c_lreg		; if MSB not nul
	jrne	bclb		; loop again
	exg	a,xl
	ld	c_lreg+1,a
	exg	a,xl
panor:
	sll	c_lreg+1	; remove hidden bit
	add	a,#127		; add offset
	srl	a		; exponent ok
	rrc	c_lreg+1	; align mantissa
	ld	c_lreg,a	; store result
	ldw	c_lreg+2,y
fini:
	popw	y		; restore
	popw	x		; registers
	ret			; and return
;
	end
