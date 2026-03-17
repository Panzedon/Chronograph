;	WRITE A STRUCTURE IN EEPROM
;	Copyright (c) 2008 by COSMIC Software
;	- eeprom address in X
;	- structure address in Y
;	- structure size in A
;
	xdef	d_eewstr
	xref	d_eewrc, d_eewrw, d_eewrp
	xref.b	c_x, c_y
	include	"eeprom.i"
	.dcall	"8,0,1,d_eewstr"
;
d_eewstr:
	cp	a,#4		; check size
	jruge	start		; enough, start
last:
	dec	a
	jreq	byte		; just a byte
	dec	a
	jreq	word		; just a word
	ld	a,(y)		; load
	ld	c_y,a		; value
	ldw	y,(1,y)
	jpf	d_eewrp		; program a far pointer
byte:
	ld	a,(y)		; load value
	jpf	d_eewrc		; program byte
word:
	ldw	y,(y)		; load value
	pushw	y		; on the stack
	callf	d_eewrw
	popw	y		; clean stack
	retf			; and return
start:
	ld	c_x,a		; copy count
	ld	a,xl		; check
	and	a,#3		; alignment
	jreq	loop		; ok, start loop
	dec	a
	jreq	alptr		; align one pointer
	dec	a
	jreq	alword		; align one word
	ld	a,(y)		; get byte
	callf	d_eewrc		; program byte
	incw	y		; adjust struct address
	incw	x		; adjust eeprom address
	dec	c_x		; adjust count
	jra	loop		; and continue
alword:
	pushw	y		; save address
	ldw	y,(y)		; get word
	pushw	y
	callf	d_eewrw		; program word
	popw	y		; clean stack
	popw	y		; get address
	addw	y,#2		; update struct address
	ld	a,c_x		; update
	sub	a,#2
	jra	loop2		; and continue
alptr:
	pushw	y		; save address
	ld	a,(y)		; load
	ld	c_y,a		; value
	ldw	y,(1,y)
	callf	d_eewrp		; program a far pointer
	popw	y		; restore pointer
	addw	y,#3		; update struct address
	ld	a,c_x		; update
	sub	a,#3		; count
loop2:
	ld	c_x,a
	addw	x,#4		; update eeprom address
loop:
	ld	a,c_x		; check
	cp	a,#4		; size
	jrult	last		; last bytes
bcl:
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
	ld	a,c_x		; update
	sub	a,#4		; count
	ld	c_x,a
wait:
	btjf	IAPSR,#EOP,wait ; wait for completion
	cp	a,#4		; check remaining size
	jruge	bcl		; nough, continue
	tnz	a		; check size
	jreq	fini		; zero, exit
	jpf	last		; program last and return
fini:
	retf			; return
;
	end
