include  macros2.asm 
include  number.asm


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	_8 dd 8.0
	c3 db MAXTEXTSIZE dup (?),'$'
	c2 db MAXTEXTSIZE dup (?),'$'
	c1 db MAXTEXTSIZE dup (?),'$'
	b2 dd ?
	b1 dd ?
	a2 dd ?
	a1 dd ?
	_SUM dd ?
	_MINUS dd ?
	_DIVIDE dd ?
	_MULTIPLY dd ?


.code
	begin: .startup
	mov AX,@DATA
	mov DS,AX
	mov ES,AX
	finit

LABEL_WHILE_0:

	; > 
	FLD a1
	FLD a2
	FCOM
	JLE LABEL_WHILE_OUT_0

	; ASIGNACION 
	FLD _8
	FSTP b2

	; > 
	FLD a1
	FLD a2
	FCOM
	JLE LABEL_IF_1

	; ASIGNACION 
	FLD _8
	FSTP b1
LABEL_IF_1:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	JMP LABEL_WHILE_0

LABEL_WHILE_OUT_0:
