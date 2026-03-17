;	EEPROM WRITE ROUTINES
;	Copyright (c) 2008 by COSMIC Software
;	- eeprom address in X
;	- value in A (char) or on stack (int)
;
	xdef	d_eewrc, d_eewrw, d_eewrd
	xref.b	c_lreg
	include	"eeprom.i"
	.dcall	"3,2,1,d_eewrw"
	.dcall	"3,0,d_eewrc"
;
;	program a word
;
d_eewrw:
	ld	a,xl		; check word address
	and	a,#3		; offset
	jreq	left		; left aligned
	dec	a
	jreq	middle		; middle aligned
	dec	a
	jreq	right		; right aligned
	ld	a,(4,sp)	; LSB
	ld	(x),a		; store and start programming
	ld	a,(5,sp)	; prepare MSB
	incw	x		; adjust address
wait:
	btjf	IAPSR,#EOP,wait ; wait for completion
;
;	program one byte
;
d_eewrc:
	ld	(x),a		; store value
wai2:
	btjf	IAPSR,#EOP,wai2 ; wait for completion
	retf			; and return
;
;	program a modified long word
;
left:
	ldw	y,x
	ldw	x,(4,sp)	; get word
	ldw	c_lreg,x
	ldw	x,y
	ldw	x,(2,x)		; complete
	ldw	c_lreg+2,x	; buffer
	jra	prog		; and continue
middle:
	decw	x		; adjust address
	ldw	y,x
	ldw	x,(4,sp)	; get word
	ldw	c_lreg+1,x
	ldw	x,y
	ld	a,(x)		; complete
	ld	c_lreg,a	; buffer
	ld	a,(3,x)
	ld	c_lreg+3,a
	jra	prog		; and continue
right:
	subw	x,#2		; adjust address
	ldw	y,x
	ldw	x,(4,sp)	; get word
	ldw	c_lreg+2,x
	ldw	x,y
	ldw	x,(x)		; complete
	ldw	c_lreg,x	; buffer
prog:
	ldw	x,y		; set address
d_eewrd:
	bset	CR2,#WPRG	; set word
ifndef STM8L
	bres	NCR2,#WPRG	; programming bit
endif
	ld	a,c_lreg	; copy
	ld	(x),a		; bytes
	ld	a,c_lreg+1
	ld	(1,x),a
	ld	a,c_lreg+2
	ld	(2,x),a
	ld	a,c_lreg+3
	ld	(3,x),a
wai3:
	btjf	IAPSR,#EOP,wai3 ; wait for completion
	retf			; and return
;
	end
