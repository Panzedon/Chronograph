;	LONG LONG DIVISION
;	Copyright (c) 2013 by COSMIC Software
;	- r0:r1 /= r2:r3
;
	xdef c_lldiv, c_lludv
	xdef c_llmod, c_llumd
	.dcall  "16,0,c_lldiv"
	.dcall  "16,0,c_lludv"
	.dcall  "16,0,c_llmod"
	.dcall  "16,0,c_llumd"
;
c_llmod:
	cbnz	r0,smok1	; 1st operand LSW not zero, continue
	cmp	r1,#0		; test 1st operand MSW
	beq	fini		; zero, exit
smok1:
	cbnz	r2,smok2	; 2nd operand LSW not zero, continue
	cmp	r3,#0		; test 2nd operand MSW
	beq	fini		; zero, exit
smok2:
	push	{r4-r7}		; save registers
	movs	r7,#1		; modulus
	cmp	r1,#0		; check sign
	bpl	okm		; positive, skip
	movs	r7,#3		; sign flag
	negs	r1		; invert operand
	negs	r0
	sbcs	r1,#0
okm:
	cmp	r3,#0		; check sign
	bpl	cdiv		; positive, skip
	b	invs		; invert and continue
;
c_lldiv:
	cbnz	r0,sdok1	; 1st operand LSW not zero, continue
	cmp	r1,#0		; test 1st operand MSW
	beq	fini		; zero, exit
sdok1:
	cbnz	r2,sdok2	; 2nd operand LSW not zero, continue
	cmp	r3,#0		; test 2nd operand MSW
	beq	fini		; zero, exit
sdok2:
	push	{r4-r7}		; save registers
	movs	r7,#0		; division
	movs	r6,#2		; sign flag
	cmp	r1,#0		; check sign
	bpl	okd		; positive, skip
	eors	r7,r6		; update flag
	negs	r1		; invert operand
	negs	r0
	sbcs	r1,#0
okd:
	cmp	r3,#0		; check sign
	bpl	cdiv		; positive, skip
	eors	r7,r6		; update flag
invs:
	negs	r3		; invert operand
	negs	r2
	sbcs	r3,#0
	b	cdiv		; and continue
;
c_llumd:
	cbnz	r0,umok1	; 1st operand LSW not zero, continue
	cmp	r1,#0		; test 1st operand MSW
	beq	fini		; zero, exit
umok1:
	cbnz	r2,umok2	; 2nd operand LSW not zero, continue
	cmp	r3,#0		; test 2nd operand MSW
	beq	fini		; zero, exit
umok2:
	push	{r4-r7}		; save registers
	movs	r7,#1		; unsigned mod
	b	cdiv		; and continue
;
c_lludv:
	cbnz	r0,udok1	; 1st operand LSW not zero, continue
	cmp	r1,#0		; test 1st operand MSW
	beq	fini		; zero, exit
udok1:
	cbnz	r2,udok2	; 2nd operand LSW not zero, continue
	cmp	r3,#0		; test 2nd operand MSW
	beq	fini		; zero, exit
udok2:
	push	{r4-r7}		; save registers
	movs	r7,#0		; unsigned div
cdiv:
	movs	r4,#0		; clear
	movs	r5,#0		; remainder
	movs	r6,#64		; set counter
	cbz	r1,fast		; check for
	cbnz	r3,fast		; accelerate
	cmp	r1,r2
	bhs	bcl
fast:
	mov	r4,r1		; shift left
	mov	r1,r0
	movs	r0,#0
	subs	r6,#32		; adjust count
bcl:
	lsls	r0,#1		; shift
	adcs	r1,r1		; result
	adcs	r4,r4		; and
	adcs	r5,r5		; remainder
	subs	r4,r2		; subtract
	sbcs	r5,r3		; values
	blo	rest		; smaller, continue
	adds	r0,#1		; set bit
	b	next		; and continue
rest:
	adds	r4,r2		; restore
	adcs	r5,r3		; remainder
next:
	subs	r6,#1		; count down
	bne	bcl		; and loop back
	lsrs	r7,#1		; check result type
	bcc	okq		; quotient, skip
	mov	r0,r4		; copy remainder
	mov	r1,r5		; otherwise
okq:
	beq	oks		; check sign
	negs	r1		; invert
	negs	r0		; if negative
	sbcs	r1,#0
oks:
	pop	{r4-r7}		; restore registers
fini:
	bx	lr		; and return
;
	end
