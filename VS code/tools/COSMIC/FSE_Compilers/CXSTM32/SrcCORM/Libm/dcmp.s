;	DOUBLE COMPARE
;	Copyright (c) 2011 by COSMIC Software
;	- r0:r1 <> r2:r3
;
	xdef c_dcmp
;
c_dcmp:
	tst	r0,r2		; both negative
	bpl	noneg		; no, normal compare
rev:
	cmp	r2,r0		; reverse compare MSW
	bne	ok		; ok, exit
	cmp	r3,r1		; reverse compare LSW
	beq	ok		; ok, exit
	b	uns		; convert flags
noneg:
	teq	r0,r2		; different sign
	bmi	sdif		; yes, skip
	cmp	r0,r2		; compare MSW
	bne	ok		; ok, exit
	cmp	r1,r3		; compare LSW
	beq	ok		; ok, exit
uns:
	movs	r2,#$fe		; not zero
	rrxs	r2		; carry to
	negs	r2		; sign
	mov	r2,r0		; restore register
	bx	lr		; and return
sdif:
	cmp	r0,r2		; compare
ok:
	bx	lr		; and return
;
	end
