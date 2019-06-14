include  macros2.asm 
include  number.asm


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	_20 dd 20.0
	_5 dd 5.0
	_4 dd 4.0
	_3 dd 3.0
	_2 dd 2.0
	_1 dd 1.0
	_9 dd 9.0
	_8 dd 8.0
	b3 dd ?
	b4 dd ?
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

	; ASIGNACION 
	FLD _8
	FSTP b1

	; ASIGNACION 
	FLD _9
	FSTP b2

	; SUMA 
	FLD _1
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


	; SUMA 
	FLD _SUM
	FLD _3
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


	; SUMA 
	FLD _SUM
	FLD _4
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

	; RESTA 
	FLD _8
	FLD _3
	FSUB
	FSTP _MINUS

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; SUMA 
	FLD _MINUS
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


	; RESTA 
	FLD _SUM
	FLD _1
	FSUB
	FSTP _MINUS

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
	FLD _MINUS
	FSTP b1

	; MULTIPLICA 
	FLD _8
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


	; SUMA 
	FLD _MULTIPLY
	FLD _3
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


	; RESTA 
	FLD _SUM
	FLD _2
	FSUB
	FSTP _MINUS

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; MULTIPLICA 
	FLD _1
	FLD _5
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


	; SUMA 
	FLD _MINUS
	FLD _MULTIPLY
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
	FSTP b4

	; DIVIDE 
	FLD _8
	FLD _3
	FDIV
	FSTP _DIVIDE

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; MULTIPLICA 
	FLD _DIVIDE
	FLD _2
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


	; RESTA 
	FLD _MULTIPLY
	FLD _1
	FSUB
	FSTP _MINUS

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; SUMA 
	FLD _MINUS
	FLD _5
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


	; SUMA 
	FLD _SUM
	FLD _4
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


	; SUMA 
	FLD _SUM
	FLD _20
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
	FSTP b3
