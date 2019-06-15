include  macros2.asm 
include  number.asm


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	_9 dd 9.0
	_2 dd 2.0
	_15 dd 15.0
	_4 dd 4.0
	_11 dd 11.0
	_10 dd 10.0
	_3 dd 3.0
	_5 dd 5.0
	_1 dd 1.0
	c3 db MAXTEXTSIZE dup (?),'$'
	c2 db MAXTEXTSIZE dup (?),'$'
	c1 db MAXTEXTSIZE dup (?),'$'
	b3 dd ?
	b2 dd ?
	b1 dd ?
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

	; ASIGNACION 
	FLD _1
	FSTP b1
LABEL_FOR_0:

	; TO 
	FLD b1
	FLD _5
	FCOM
	JG LABEL_FOR_OUT_0:

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
	FLD _3
	FSTP a2

	; ASIGNACION 
	FLD _10
	FSTP b2
LABEL_FOR_1:

	; TO 
	FLD b2
	FLD _11
	FCOM
	JG LABEL_FOR_OUT_1:

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
	FLD _4
	FSTP a1

	; NEXT 
	ADD b2, _1
	JMP LABEL_FOR_1
LABEL_FOR_OUT_1:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; NEXT 
	ADD b1, _1
	JMP LABEL_FOR_0
LABEL_FOR_OUT_0:

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
	FLD _15
	FSTP b3
LABEL_FOR_2:

	; TO 
	FLD b3
	FLD _15
	FCOM
	JG LABEL_FOR_OUT_2:

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
	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	JL LABEL_IF_1

	; ASIGNACION 
	FLD _9
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


	; NEXT 
	ADD b3, _1
	JMP LABEL_FOR_2
LABEL_FOR_OUT_2:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)

