#include <features.h>

#include <asm/unistd.h>

	.text
	.align 4
	.globl	__vfork
	.hidden	__vfork
	.type	__vfork,@function

__vfork:
	mov.l	[r0+],r2
	mov.l	#__NR_vfork,r8
	int	#0x08
	cmp	#-4096,r1
	bc	1f	/* errno < 0 && errno >=4096 */
	jmp	r2
1:	mov.l	r2,[-r0]
	bra	__syscall_error

weak_alias(__vfork,vfork)
libc_hidden_weak(vfork)
	.end
