;	FAST STRING COPY
;	Copyright (c) 2020 by COSMIC Software
;	- destination address in Y
;	- source address in X
;
	xdef	d_strcpy
	.dcall	"2,0,d_strcpy"
;
d_strcpy:
bcl:
	ld	a,(x)		; load character
	ld	(y),a		; store character
	jreq	fini		; nul, exit
	ld	a,(1,x)		; load character
	ld	(1,y),a		; store character
	jreq	fini		; nul, exit
	ld	a,(2,x)		; load character
	ld	(2,y),a		; store character
	jreq	fini		; nul, exit
	ld	a,(3,x)		; load character
	ld	(3,y),a		; store character
	jreq	fini		; nul, exit
	addw	y,#4		; next word
	addw	x,#4		; next word
	jra	bcl		; loop back
fini:
	retf			; and return
;
	end
