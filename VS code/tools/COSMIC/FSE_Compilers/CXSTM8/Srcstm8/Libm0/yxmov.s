;	STRUCTURE COPY
;	Copyright (c) 2020 by COSMIC Software
;	- source ptr in X
;	- destination ptr in Y
;	- size in A
;
	xdef	c_yxmov
	xref.b	c_x
	.dcall	"4,0,c_yxmov"
;
c_yxmov:
	pushw	y		; save dest pointer
bcl:
	ld	c_x,a		; copy size
	cp	a,#4		; check fast copy
	jrult	last		; no skip
	ld	a,(x)		; load byte
	ld	(y),a		; store byte
	ld	a,(1,x)		; load byte
	ld	(1,y),a		; store byte
	ld	a,(2,x)		; load byte
	ld	(2,y),a		; store byte
	ld	a,(3,x)		; load byte
	ld	(3,y),a		; store byte
	addw	x,#4		; next word
	addw	y,#4		; next word
	ld	a,c_x		; update
	sub	a,#4		; count
	jrne	bcl		; and loop back
	popw	y		; restore pointer
	ret			; and return
last:
	ld	a,(x)		; load byte
	ld	(y),a		; store byte
	dec	c_x		; count down
	jreq	fini		; zero, exit
	ld	a,(1,x)		; load byte
	ld	(1,y),a		; store byte
	dec	c_x		; count down
	jreq	fini		; zero, exit
	ld	a,(2,x)		; load byte
	ld	(2,y),a		; store byte
fini:
	popw	y		; restore pointer
	ret			; and return
;
	end
