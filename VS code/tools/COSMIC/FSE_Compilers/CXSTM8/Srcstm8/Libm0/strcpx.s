;	FAST STRING COPY
;	Copyright (c) 2020 by COSMIC Software
;	- destination address in X
;	- source address in Y
;
	xdef	c_strcpx
	.dcall	"2,0,c_strcpx"
;
c_strcpx:
bcl:
	ld	a,(y)		; load character
	ld	(x),a		; store character
	jreq	fini		; nul, exit
	ld	a,(1,y)		; load character
	ld	(1,x),a		; store character
	jreq	fini		; nul, exit
	ld	a,(2,y)		; load character
	ld	(2,x),a		; store character
	jreq	fini		; nul, exit
	ld	a,(3,y)		; load character
	ld	(3,x),a		; store character
	jreq	fini		; nul, exit
	addw	x,#4		; next word
	addw	y,#4		; next word
	jra	bcl		; loop back
fini:
	ret			; and return
;
	end
