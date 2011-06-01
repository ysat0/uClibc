/* Macros to swap the order of bytes in integer values.  m68k version.
   Copyright (C) 1997, 2002 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef _ASM_BITS_BYTESWAP_H
#define _ASM_BITS_BYTESWAP_H 1

# define __bswap_non_constant_32(x) \
  __extension__							\
  ({ unsigned int __bswap_32_v;					\
	  __asm__ __volatile__ ("revl %1,%0"			\
			   : "=r" (__bswap_32_v)		\
			   : "r" ((unsigned int) (x)));		\
     __bswap_32_v; })

# define __bswap_non_constant_16(x) \
  __extension__							\
  ({ unsigned short __bswap_16_v;				\
	  __asm__ __volatile__ ("revw %1,%0"			\
			   : "=r" (__bswap_16_v)		\
			   : "r" ((unsigned short) (x)));	\
     __bswap_16_v; })
#endif

#include <bits/byteswap-common.h>
