;	STACK POINTER CHECKING
;	Copyright (c) 2006 by COSMIC Software
;
	xdef	c_check
	.dcall	"4,0,c_check"
;
c_check:
	pushw	y		; save offset
	ldw	y,sp		; get stack pointer
	subw	y,(1,sp)	; compute limit
;
; compare here Y with the minimum stack value, and if ok...
;
	popw	y		; clean stack
	ret			; and return
;
; otherwise, the behaviour is application dependant
;
	end
