;	WRITE A LONG IN EEPROM
;	Copyright (c) 2008 by COSMIC Software
;	- eeprom address in X
;	- value in LONG accu
;
	xdef	d_eewrl
	xref	d_eewrd
	xref.b	c_lreg, c_x
	include	"eeprom.i"
	.dcall	"9,0,1,d_eewrl"
;
d_eewrl:
	ld	a,xl		; check address
	and	a,#3		; for word boundary
	jreq	last		; no, two words needed
	exg	a,xl		; align
	and	a,#$FC		; word
	exg	a,xl		; address
	ld	c_x,a		; stack offset
	ldw	y,x		; save address
	ldw	x,c_lreg+2	; stack value
	pushw	x
	ldw	x,c_lreg
	pushw	x
	ldw	x,y		; load buffer
	ldw	x,(x)
	ldw	c_lreg,x
	ldw	x,y
	ldw	x,(2,x)
	ldw	c_lreg+2,x
	clrw	x		; set index
	ld	xl,a
bcl1:
	pop	a		; get byte
	ld	(c_lreg,x),a	; store in buffer
	incw	x		; next index
	cpw	x,#4		; check end
	jrne	bcl1		; no loop back
	ldw	x,y		; set address
	callf	d_eewrd		; program word
	addw	x,#4		; next word
	ldw	y,x		; save address
	ldw	x,(x)		; load buffer
	ldw	c_lreg,x
	ldw	x,y
	ldw	x,(2,x)
	ldw	c_lreg+2,x
	ldw	x,#c_lreg
bcl2:
	pop	a		; get byte
	ld	(x),a		; store in buffer
	incw	x		; next byte
	dec	c_x		; count down
	jrne	bcl2		; and loop back
	ldw	x,y		; set address
last:
	jpf	d_eewrd		; program and return
;
	end
