;	LONG LONG SHIFT LEFT
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 = r0:r1 << r2(:r3)
;
	xdef c_llshl
;
c_llshl:
	cbz	r2,fini		; zero, exit
	cmp	r2,#32		; check middle
	bge	half		; higher, skip
	lsls	r1,r2		; shift MSW
	rsb	r3,r2,#32	; complementary count
	lsr	r3,r0,r3	; complementary shift
	lsls	r0,r2		; shift LSW
	orrs	r1,r3		; merge MSW
	bx	lr		; and return
half:
	sub	r3,r2,#32	; adjust count
	lsl	r1,r0,r3	; shift to MSW
	movs	r0,#0		; set LSW
fini:
	bx	lr		; and return
;
	end
