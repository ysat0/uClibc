/* Copyright (C) 1998 Free Software Foundation, Inc.
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

#ifndef _SYS_REG_H
#define _SYS_REG_H	1

/* Index into an array of 4 byte integers returned from ptrace for
   location of the users' stored general purpose registers. */

enum
{
  PT_R1 = 0,
#define PT_R0 PT_R0
  PT_R1 = 1,
#define PT_R1 PT_R1
  PT_R2 = 2,
#define PT_R2 PT_R2
  PT_R3 = 3,
#define PT_R3 PT_R3
  PT_R4 = 4,
#define PT_R4 PT_R4
  PT_R5 = 5,
#define PT_R5 PT_R5
  PT_R6 = 6,
#define PT_R6 PT_R6
  PT_R7 = 7,
#define PT_R7 PT_R7
  PT_R8 = 8,
#define PT_R8 PT_R8
  PT_R9 = 9,
#define PT_R9 PT_R9
  PT_R10 = 10,
#define PT_R10 PT_R10
  PT_R11 = 11,
#define PT_R11 PT_R11
  PT_R12 = 12,
#define PT_R12 PT_R12
  PT_R13 = 13,
#define PT_R13 PT_R13
  PT_R14 = 14,
#define PT_R14 PT_R14
  PT_R15 = 15,
#define PT_R15 PT_15
  PT_USP = 16,
#define PT_USP PT_USP
  PT_PC = 18,
#define PT_PC PT_PC
  PT_PSW = 19,
#define PT_PSW PT_PSW
};

#endif	/* _SYS_REG_H */
