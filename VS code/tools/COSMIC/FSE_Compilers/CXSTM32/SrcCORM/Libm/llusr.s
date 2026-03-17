;	UNSIGNED LONG LONG SHIFT RIGHT
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 = r0:r1 >> r2(:r3)
;
	xdef c_llusr
;
c_llusr:
	cbz	r2,fini		; zero, exit
	cmp	r2,#32		; check middle
	bge	half		; higher, skip
	lsrs	r0,r2		; shift LSW
	rsb	r3,r2,#32	; complementary count
	lsl	r3,r1,r3	; complementary shift
	lsrs	r1,r2		; shift MSW
	orrs	r0,r3		; merge LSW
	bx	lr		; and return
half:
	sub	r3,r2,#32	; adjust count
	lsr	r0,r1,r3	; shift to LSW
	movs	r1,#0		; set MSW
fini:
	bx	lr		; and return
;
	end
