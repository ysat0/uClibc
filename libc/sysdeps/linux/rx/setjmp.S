#define _ASM
#define _SETJMP_H
#include <bits/setjmp.h>

.globl setjmp
.type  setjmp,@function
.globl __sigsetjmp
.type  __sigsetjmp,@function

	.text
	.align 4
setjmp:
	mov.l	#1,r2		/* Always save sigmask */
__sigsetjmp:
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
	mov.l	r2,4[r1]	/* set mask_was_saved */
	mov.l	#0,r1
	bra	__sigjmp_save

	.end
