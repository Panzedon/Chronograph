;	STACK POINTER CHECKING
;	Copyright (c) 2006 by COSMIC Software
;
	xdef	d_check
	.dcall	"5,0,d_check"
;
d_check:
	pushw	y		; save offset
	ldw	y,sp		; get stack pointer
	subw	y,(1,sp)	; compute limit
;
; compare here Y with the minimum stack value, and if ok...
;
	popw	y		; clean stack
	retf			; and return
;
; otherwise, the behaviour is application dependant
;
	end
