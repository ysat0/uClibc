#define _ASM
#define _SETJMP_H
#include <bits/setjmp.h>

.globl _setjmp
.type  _setjmp,@function

	.text
	.align 4
_setjmp:
	mov.l	r6,[r1+]
	mov.l	r7,[r1+]
	mov.l	r8,[r1+]
	mov.l	r9,[r1+]
	mov.l	r10,[r1+]
	mov.l	r11,[r1+]
	mov.l	r12,[r1+]
	mov.l	r13,[r1+]
	mov.l	r14,[r1+]
	mov.l	r15,[r1+]
	mov.l	r0,[r1+]
	mov.l	[r0],[r1]
	mov.l	#0,4[r1]	/* signal mask not saved */
	rts

	.end
