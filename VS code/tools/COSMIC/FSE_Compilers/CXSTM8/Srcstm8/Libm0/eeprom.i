;	DEFINITIONS FOR STM8 PROCESSOR
;	Copyright (c) 2008 by COSMIC Software
;
	xref	_FLASH_IAPSR
	xref	_FLASH_CR2
	xref	_FLASH_NCR2
;
IAPSR:	equ	_FLASH_IAPSR		; control register
EOP:	equ	2			; end bit
DUL:	equ	3			; unlock
;
CR2:	equ	_FLASH_CR2		; control register
ifndef STM8L
NCR2:	equ	_FLASH_NCR2		; negated control register
endif
;
WPRG:	equ	6			; word programming
