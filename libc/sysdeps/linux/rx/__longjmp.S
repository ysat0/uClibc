#define _ASM
#define _SETJMP_H
#include <features.h>
#include <bits/setjmp.h>

.globl _longjmp
.type  _longjmp,@function

	.text
	.align 4
_longjmp:
	tst	r2,r2
	scz.l	r2
	mov.l	[r1+],r6
	mov.l	[r1+],r7
	mov.l	[r1+],r8
	mov.l	[r1+],r9
	mov.l	[r1+],r10
	mov.l	[r1+],r11
	mov.l	[r1+],r12
	mov.l	[r1+],r13
	mov.l	[r1+],r14
	mov.l	[r1+],r15
	mov.l	4[r1],r3
	mov.l	r2,r1
	add	[r1],r0
	jmp	r3

libc_hidden_def(_longjmp)
	.end
