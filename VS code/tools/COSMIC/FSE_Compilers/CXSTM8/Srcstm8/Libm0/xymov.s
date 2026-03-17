;	STRUCTURE COPY
;	Copyright (c) 2020 by COSMIC Software
;	- source ptr in Y
;	- destination ptr in X
;	- size in A
;
	xdef	c_xymov
	xref.b	c_x
	.dcall	"4,0,c_xymov"
;
c_xymov:
	pushw	x		; save destination
bcl:
	ld	c_x,a		; copy size
	cp	a,#4		; check fast copy
	jrult	last		; no skip
	ld	a,(y)		; load byte
	ld	(x),a		; store byte
	ld	a,(1,y)		; load byte
	ld	(1,x),a		; store byte
	ld	a,(2,y)		; load byte
	ld	(2,x),a		; store byte
	ld	a,(3,y)		; load byte
	ld	(3,x),a		; store byte
	addw	x,#4		; next word
	addw	y,#4		; next word
	ld	a,c_x		; update
	sub	a,#4		; count
	jrne	bcl		; and loop back
	popw	x		; restore pointer
	ret			; and return
last:
	ld	a,(y)		; load byte
	ld	(x),a		; store byte
	dec	c_x		; count down
	jreq	fini		; zero, exit
	ld	a,(1,y)		; load byte
	ld	(1,x),a		; store byte
	dec	c_x		; count down
	jreq	fini		; zero, exit
	ld	a,(2,y)		; load byte
	ld	(2,x),a		; store byte
fini:
	popw	x		; restore pointer
	ret			; and return
;
	end
