/* Startup code for RX
   Copyright (C) 1999 Free Software Foundation, Inc.
   Copyright (C) 2010 Yoshinori Sato

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU Library General Public License as published by the Free
 Software Foundation; either version 2 of the License, or (at your option) any
 later version.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE. See the GNU Library General Public License for more
 details.

 You should have received a copy of the GNU Library General Public License
 along with this program; if not, write to the Free Software Foundation, Inc.,
 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <features.h>

	.global	_start
	.global __exit
	.global atexit
	.global main

	.weak	_init
	.weak	_fini
	
	.text

/*	
void __uClibc_main(int (*main)(int, char **, char **), int argc,
	                    char **argv, void (*app_init)(void), void (*app_fini)(void)
	,
	                    void (*rtld_fini)(void), void *stack_end attribute_unused)
*/
_start:
	mov.l	[r0],r2
	add	#4,r0,r3
	mov.l	r0,[-r0]
	mov.l	#0,r1
	mov.l	r1,[-r0]
	mov.l	#_fini,r1
	mov.l	r1,[-r0]
	mov.l	#main, r1
	mov.l	#_init,r4
	bsr	__uClibc_main

	/* If that didn't kill us, ... */
__exit:
	mov.l	#1,r15	/* NR_exit */
	int	#0x08

/*
 *	this was needed for gcc/g++-builds,  atexit was not getting included
 *	for some stupid reason,  this gets us a compiler
 */
empty_func:
	rts
	.weak atexit
	atexit = empty_func


/* Define a symbol for the first piece of initialized data.  */
	.data
	.globl __data_start
__data_start:
	.long 0
	.weak data_start
	data_start = __data_start
