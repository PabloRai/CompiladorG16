include  macros2.asm 
include  number.asm


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	_3 dd 3.0
	_2 dd 2.0
	_8 dd 8.0
	c3 db MAXTEXTSIZE dup (?),'$'
	c2 db MAXTEXTSIZE dup (?),'$'
	c1 db MAXTEXTSIZE dup (?),'$'
	b2 dd ?
	b1 dd ?
	a4 dd ?
	a3 dd ?
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

	; SUMA 
	FLD _8
	FLD _2
	FADD
	FSTP _SUM

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FLD _SUM
	FSTP b2

LABEL_WHILE_1:

	; > 
	FLD a3
	FLD a4
	FCOM
	JLE LABEL_WHILE_OUT_1

	; MULTIPLICA 
	FLD b1
	FLD _3
	FMUL
	FSTP _MULTIPLY

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; ASIGNACION 
	FLD _MULTIPLY
	FSTP b2

	JMP LABEL_WHILE_1

LABEL_WHILE_OUT_1:

	JMP LABEL_WHILE_0

LABEL_WHILE_OUT_0:
