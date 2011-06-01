	.file	"crtn.S"
	.text
	
	.section .init
	.hidden  _init
	.align 1
	.global	_init
	.type	_init, @function
	mov.l	[r0+],r6
	rts
	
	.section .fini
	.hidden  _fini
	.align 1
	.global	_fini
	.type	_fini, @function
	mov.l	[r0+],r6
	rts
