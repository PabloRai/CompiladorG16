include  macros2.asm 
include  number.asm


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 40

.DATA
	_sarasa db sarasa,'$', 6 dup (?)
	_93 dd 93.0
	_0xABF dd 2751.0
	_0b110 dd 6.0
	_9 dd 9.0
	_HOLA db HOLA,'$', 4 dup (?)
	_8 dd 8.0
	_2 dd 2.0
	_3 dd 3.0
	_5 dd 5.0
	_1 dd 1.0
	_9.2 dd 9.2
	c3 db MAXTEXTSIZE dup (?),'$'
	c2 db MAXTEXTSIZE dup (?),'$'
	c1 db MAXTEXTSIZE dup (?),'$'
	b4 dd ?
	b3 dd ?
	b2 dd ?
	b1 dd ?
	a2 dd ?
	a1 dd ?


.code
	begin: .startup
	mov AX,@DATA
	mov DS,AX
	mov ES,AX
	finit
