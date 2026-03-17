;	WRITE A LARGE STRUCTURE IN EEPROM
;	Copyright (c) 2008 by COSMIC Software
;	- eeprom address in X extension
;	- structure address in Y
;	- structure size in X 
;
	xdef	c_eewstrl
	xref	c_eewrc, c_eewrw, c_eewrp
	xref.b	c_x, c_y
	include	"eeprom.i"
	.dcall	"6,0,1,c_eewstrl"
;
c_eewstrl:
	pushw	y		; save struct address
	ldw	y,c_x		; get eeprom address
	ldw	c_x,x		; store size
	ldw	x,y		; eeprom address in place
	popw	y		; restore struct address
	ld	a,xl		; check
	and	a,#3		; alignment
	jreq	noal		; ok, start loop
	dec	a
	jreq	alptr		; align one pointer
	dec	a
	jreq	alword		; align one word
	ld	a,(y)		; get byte
	call	c_eewrc		; program byte
	incw	y		; adjust struct address
	incw	x		; adjust eeprom address
	pushw	x		; save eeprom address
	ldw	x,c_x		; get size
	decw	x		; update
	jra	loop		; and continue
alword:
	pushw	y		; save address
	ldw	y,(y)		; get word
	pushw	y
	call	c_eewrw		; program word
	popw	y		; clean stack
	popw	y		; get address
	addw	y,#2		; update struct address
	addw	x,#4		; update eeprom address
	pushw	x		; save eeprom address
	ldw	x,c_x		; get size
	subw	x,#2		; update
	jra	loop		; and continue
alptr:
	pushw	y		; save address
	ld	a,(y)		; load
	ld	c_y,a		; value
	ldw	y,(1,y)
	call	c_eewrp		; program a far pointer
	popw	y		; restore pointer
	addw	y,#3		; update struct address
	addw	x,#4		; update eeprom address
	pushw	x		; save eeprom address
	ldw	x,c_x		; get size
	subw	x,#3		; update
	jra	loop		; and continue
noal:
	pushw	x		; save eeprom address
	ldw	x,c_x		; get size
loop:
	ldw	c_x,x		; store size
	cpw	x,#4		; check size
	jrult	last		; last bytes
bcl:
	popw	x		; restore eeprom address
	bset	CR2,#WPRG	; set word
ifndef STM8L
	bres	NCR2,#WPRG	; programming bit
endif
	ld	a,(y)		; copy
	ld	(x),a		; bytes
	ld	a,(1,y)
	ld	(1,x),a
	ld	a,(2,y)
	ld	(2,x),a
	ld	a,(3,y)
	ld	(3,x),a		; start programming
	addw	y,#4		; next struct address
	addw	x,#4		; next eeprom address
	pushw	x		; save eeprom address
	ldw	x,c_x		; update
	subw	x,#4		; count
	ldw	c_x,x
wait:
	btjf	IAPSR,#EOP,wait ; wait for completion
	cpw	x,#4		; check remaining size
	jruge	bcl		; nough, continue
last:
	popw	x		; restore eeprom address
	ld	a,c_x+1		; check size
	jreq	fini		; zero, exit
	dec	a
	jreq	byte		; one byte remaining
	dec	a
	jreq	word		; one word remaining
	ld	a,(y)		; load
	ld	c_y,a
	ldw	y,(1,y)		; value
	jp	c_eewrp		; program last pointer and exit
byte:
	ld	a,(y)		; get value
	jp	c_eewrc		; program last byte and exit
word:
	ldw	y,(y)		; get value
	pushw	y
	call	c_eewrw		; program last word
	popw	y		; clean stack
fini:
	ret			; return
;
	end
