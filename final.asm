include macros2.asm 


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	_93 dd 93.0
	_0xABF dd 2751.0
	_0b110 dd 6.0
	_9 dd 9.0
	_HOLA db 'HOLA','$', 4 dup (?)
	_8 dd 8.0
	_2 dd 2.0
	_3 dd 3.0
	_5 dd 5.0
	_1 dd 1.0
	c3 db MAXTEXTSIZE dup (?),'$'
	c2 db MAXTEXTSIZE dup (?),'$'
	c1 db MAXTEXTSIZE dup (?),'$'
	b4 dd ?
	b3 dd ?
	b2 dd ?
	b1 dd ?
	a2 dd ?
	a1 dd ?
	_SUM dd ?
	_MINUS dd ?
	_DIVIDE dd ?
	_MULTIPLY dd ?
	_AUXILIAR dd ?


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
	JG LABEL_FOR_OUT_0

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

	; NEXT 
	MOV EAX, b1
	ADD EAX, _1
	MOV b1, EAX
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
	FLD _1
	FSTP b1
LABEL_FOR_1:

	; TO 
	FLD b1
	FLD _5
	FCOM
	JG LABEL_FOR_OUT_1

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

	; NEXT 
	MOV EAX, b1
	ADD EAX, _2
	MOV b1, EAX
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


	; ASIGNACION 
	FLD _8
	FSTP b1

	; MULTIPLICA 
	FLD _3
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


	; SUMA 
	FLD b1
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


	; SUMA 
	FLD _3
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
	FLD _SUM
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
	JLE LABEL_IF_2

	; ASIGNACION 
	LEA SI, _HOLA
	LEA DI,c1
	CALL COPY
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


	JMP LABEL_WHILE_0

LABEL_WHILE_OUT_0:

	; => 
	FLD a1
	FLD _2
	FCOM
	JL LABEL_IF_5

	; ASIGNACION 
	FLD _9
	FSTP a1

	; ASIGNACION 
	FLD _0b110
	FSTP a1

	; ASIGNACION 
	FLD _0xABF
	FSTP a1
LABEL_IF_5:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; > 
	FLD a1
	FLD b2
	FCOM
	JLE LABEL_IF_8

	; ASIGNACION 
	FLD _9
	FSTP a1
LABEL_IF_8:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; > 
	FLD a1
	FLD b2
	FCOM
	JLE LABEL_IF_11

	; ASIGNACION 
	FLD _3
	FSTP b2

	; GET
	getString b1

	; > 
	FLD a1
	FLD b2
	FCOM
	JLE LABEL_IF_13

	; ASIGNACION 
	FLD _9
	FSTP a1
LABEL_IF_13:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)

LABEL_IF_11:

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
	FLD b3
	FLD b4
	FCOM
	JL LABEL_IF_16

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
	JL LABEL_IF_16

	; ASIGNACION 
	FLD _93
	FSTP b4
LABEL_IF_16:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; > 
	FLD a1
	FLD b2
	FCOM
	JLE LABEL_IF_19

	; ASIGNACION 
	FLD _3
	FSTP b2

	; ASIGNACION 
	FLD _5
	FSTP b3

	; > 
	FLD a1
	FLD b2
	FCOM
	JLE LABEL_IF_21

	; ASIGNACION 
	FLD _9
	FSTP a1

LABEL_WHILE_1:

	; > 
	FLD b1
	FLD b2
	FCOM
	JLE LABEL_WHILE_OUT_1

	; ASIGNACION 
	FLD _1
	FSTP b1
LABEL_FOR_2:

	; TO 
	FLD b1
	FLD _5
	FCOM
	JG LABEL_FOR_OUT_2

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

	; NEXT 
	MOV EAX, b1
	ADD EAX, _2
	MOV b1, EAX
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


	; ASIGNACION 
	FLD _9
	FSTP a2

	; => 
	FLD b3
	FLD b4
	FCOM
	JGE LABEL_IF_22

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
	JL LABEL_IF_23
LABEL_IF_22:

	; ASIGNACION 
	FLD _93
	FSTP b4
LABEL_IF_23:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	JMP LABEL_WHILE_1

LABEL_WHILE_OUT_1:
LABEL_IF_21:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)

LABEL_IF_19:

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


LABEL_WHILE_SPECIAL_0:

	; IN 
	MOV EAX, b1
	MOV _AUXILIAR, EAX

	; LIST 
	FLD _AUXILIAR
	FLD _3
	FCOM
	JE LABEL_WHILE_SPECIAL_TRUE_0

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; LIST 
	FLD _AUXILIAR
	FLD b1
	FCOM
	JE LABEL_WHILE_SPECIAL_TRUE_0

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
	FLD b2
	FLD b1
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


	; LIST 
	FLD _AUXILIAR
	FLD _SUM
	FCOM
	JE LABEL_WHILE_SPECIAL_TRUE_0

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	JMP LABEL_WHILE_SPECIAL_OUT_0

LABEL_WHILE_SPECIAL_TRUE_0: 

LABEL_WHILE_SPECIAL_1:

	; IN 
	MOV EAX, b1
	MOV _AUXILIAR, EAX

	; MULTIPLICA 
	FLD _8
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
	FLD _3
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


	; LIST 
	FLD _AUXILIAR
	FLD _MINUS
	FCOM
	JE LABEL_WHILE_SPECIAL_TRUE_1

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	; LIST 
	FLD _AUXILIAR
	FLD b1
	FCOM
	JE LABEL_WHILE_SPECIAL_TRUE_1

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
	FLD b2
	FLD b1
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


	; LIST 
	FLD _AUXILIAR
	FLD _SUM
	FCOM
	JE LABEL_WHILE_SPECIAL_TRUE_1

	; STACK CLENUP
	FFREE st(0)
	FFREE st(1)
	FFREE st(2)
	FFREE st(3)
	FFREE st(4)
	FFREE st(5)
	FFREE st(6)
	FFREE st(7)


	JMP LABEL_WHILE_SPECIAL_OUT_1

LABEL_WHILE_SPECIAL_TRUE_1: 

	; ASIGNACION 
	FLD _8
	FSTP b1

	JMP LABEL_WHILE_SPECIAL_1

LABEL_WHILE_SPECIAL_OUT_1:

	JMP LABEL_WHILE_SPECIAL_0

LABEL_WHILE_SPECIAL_OUT_0:



	; END PROGRAM 

	mov AX, 4C00h
	int 21h


	; ROUTINES
STRLEN PROC
	mov bx,0
STRL01:
	cmp BYTE PTR [SI+BX],'$'
	je STREND
	inc BX
	cmp BX, MAXTEXTSIZE
	jl STRL01
STREND:
	ret
STRLEN ENDP

COPY PROC
	call STRLEN	cmp bx,MAXTEXTSIZE
	jle COPYSIZEOK
	mov bx,MAXTEXTSIZE
COPYSIZEOK:
	mov cx,bx
	cld
	rep movsb
	mov al,'$'
	mov BYTE PTR [DI],al
	ret
COPY ENDP

END begin
