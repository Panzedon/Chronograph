;	WRITE A FAR POINTER IN EEPROM
;	Copyright (c) 2008 by COSMIC Software
;	- eeprom address in X
;	- value in Y and extension
;
	xdef	d_eewrp
	xref	d_eewrc, d_eewrw, d_eewrd
	xref.b	c_lreg, c_y
	include	"eeprom.i"
	.dcall	"8,0,1,d_eewrp"
;
d_eewrp:
	ld	a,xl		; check address
	and	a,#3		; for word boundary
	jreq	left		; left aligned, skip
	dec	a
	jreq	right		; right aligned, skip
	dec	a
	jreq	woby		; word then byte
	ld	a,c_y		; byte
	callf	d_eewrc
	pushw	y		; then
	incw	x
	callf	d_eewrw		; word
	popw	y
	retf			; and return
woby:
	ld	a,c_y		; high byte
	rrwa	y,a		; adjust
	ld	c_y,a		; save
	pushw	y
	callf	d_eewrw		; word
	popw	y
	addw	x,#4		; then
	ld	a,c_y
	jpf	d_eewrc		; byte
left:
	mov	c_lreg,c_y	; set buffer
	ldw	c_lreg+1,y
	ld	a,(3,x)
	ld	c_lreg+3,a
	jpf	d_eewrd		; program and return
right:
	decw	x		; adjust pointer
	ld	a,(x)		; set buffer
	ld	c_lreg,a
	mov	c_lreg+1,c_y
	ldw	c_lreg+2,y
	jpf	d_eewrd		; program and return
;
	end
