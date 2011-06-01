#define _ERRNO_H
#include <features.h>
#include <bits/errno.h>
#include <sys/syscall.h>

/* int _clone(int (*fn)(void *arg), void *child_stack, int flags, void *arg); */

.type	clone,@function
.globl	clone

	.text
	.align 4
clone:
	mov.l	r8,[-r0]
	mov.l   #-EINVAL, r5
	tst	r1,r1			/* fn NULL check */
	beq	2f
	tst	r2,r2			/* stack NULL check */

	mov.l	8[r0],r5
	mov.l	r5,[-r2]		/* save arg to new stack */
	mov.l	r1,[-r2]		/* save fn to new stack */

	mov.l	r3,r1
	mov.l	12[r0],r3		/* parent_tidptr */
	mov.l	16[r0],r4		/* child_tidptr */
	mov.l   #__NR_clone, r8
	int	#0x08
	
	mov.l	r1,r5
	tst	r1,r1
	bn	2f
	beq	1f
	mov.l	[r0+],r8
	rts

1:	
	mov.l	[r0+],r2
	mov.l	[r0+],r1
	jsr	r2
	mov.l	#_NR_exit,r8
	int	#0x08

2:
	mov.l	[r0+],r8
	mov.l	r5,r1
	bra	__syscall_error

	.end
