include  macros2.asm 
include  number.asm


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	_11 dd 11.0
	_10 dd 10.0
	_44 dd 44.0
	_3 dd 3.0
	_9 dd 9.0
	_93 dd 93.0
	_2 dd 2.0
	b6 dd ?
	b5 dd ?
	b4 dd ?
	b3 dd ?
	b2 dd ?
	b1 dd ?
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

	; => 
	FLD b3
	FLD b4
	FCOM
	JL LABEL_IF_0

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; => 
	FLD b1
	FLD _2
	FCOM
	JL LABEL_IF_0

	; ASIGNACION 
	FLD _93
	FSTP b4
LABEL_IF_0:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; => 
	FLD b5
	FLD _9
	FCOM
	JGE LABEL_IF_1

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; => 
	FLD b6
	FLD _3
	FCOM
	JL LABEL_IF_2
LABEL_IF_1:

	; ASIGNACION 
	FLD _44
	FSTP b4
LABEL_IF_2:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; => 
	FLD b5
	FLD _10
	FCOM
	JL LABEL_IF_4

	; ASIGNACION 
	FLD _44
	FSTP b4
LABEL_IF_4:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; => 
	FLD b5
	FLD _11
	FCOM
	JL LABEL_IF_6

	; ASIGNACION 
	FLD _44
	FSTP b4
LABEL_IF_6:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)

