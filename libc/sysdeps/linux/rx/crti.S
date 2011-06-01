	.file	"crti.S"
	.text
	
	.section .init
	.hidden  _init
	.align 1
	.global	_init
	.type	_init, @function
_init:
	mov.l	r6,[-r0]
	mov.l	r0,r6
	bra	1f
	.align	1
1:	
	.section .fini
	.hidden  _fini
	.align 1
	.global	_fini
	.type	_fini, @function
_fini:
	mov.l	r6,[-r0]
	mov.l	r0,r6
	bra	1f
	.align	1
1:	
