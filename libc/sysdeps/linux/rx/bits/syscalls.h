#ifndef _BITS_SYSCALLS_H
#define _BITS_SYSCALLS_H
#ifndef _SYSCALL_H
# error "Never use <bits/syscalls.h> directly; include <sys/syscall.h> instead."
#endif

#undef __NR_iopl
#undef __NR_vm86

#ifndef __ASSEMBLER__

#define ASM_ARGS_0
#define ARGS_0(name, dummy)				\
  register unsigned long r1 __asm__("r1");		\
  register unsigned long r15 __asm__("r15") = name
  
#define ASM_ARGS_1	, "0"(r1)
#define ARGS_1(name, a1)				\
  unsigned long __arg1 = (unsigned long)a1;		\
  register unsigned long r1 __asm__("r1") = __arg1;	\
  register unsigned long r15 __asm__("r15") = name

#define ASM_ARGS_2	, "0"(r1), "r"(r2)
#define ARGS_2(name, a1, a2)				\
  unsigned long __arg1 = (unsigned long)a1;		\
  unsigned long __arg2 = (unsigned long)a2;		\
  register unsigned long r1 __asm__("r1") = __arg1;	\
  register unsigned long r2 __asm__("r2") = __arg2;	\
  register unsigned long r15 __asm__("r15") = name

#define ASM_ARGS_3	, "0"(r1), "r"(r2), "r"(r3)
#define ARGS_3(name, a1, a2, a3)			\
  unsigned long __arg1 = (unsigned long)a1;		\
  unsigned long __arg2 = (unsigned long)a2;		\
  unsigned long __arg3 = (unsigned long)a3;		\
  register unsigned long r1 __asm__("r1") = __arg1;	\
  register unsigned long r2 __asm__("r2") = __arg2;	\
  register unsigned long r3 __asm__("r3") = __arg3;	\
  register unsigned long r15 __asm__("r15") = name

#define ASM_ARGS_4	, "0"(r1), "r"(r2), "r"(r3), "r"(r4)
#define ARGS_4(name, a1, a2, a3, a4)			\
  unsigned long __arg1 = (unsigned long)a1;		\
  unsigned long __arg2 = (unsigned long)a2;		\
  unsigned long __arg3 = (unsigned long)a3;		\
  unsigned long __arg4 = (unsigned long)a4;		\
  register unsigned long r1 __asm__("r1") = __arg1;	\
  register unsigned long r2 __asm__("r2") = __arg2;	\
  register unsigned long r3 __asm__("r3") = __arg3;	\
  register unsigned long r4 __asm__("r4") = __arg4;	\
  register unsigned long r15 __asm__("r15") = name

#define ASM_ARGS_5	, "0"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5)
#define ARGS_5(name, a1, a2, a3, a4, a5)		\
  unsigned long __arg1 = (unsigned long)a1;		\
  unsigned long __arg2 = (unsigned long)a2;		\
  unsigned long __arg3 = (unsigned long)a3;		\
  unsigned long __arg4 = (unsigned long)a4;		\
  unsigned long __arg5 = (unsigned long)a5;		\
  register unsigned long r1 __asm__("r1") = __arg1;	\
  register unsigned long r2 __asm__("r2") = __arg2;	\
  register unsigned long r3 __asm__("r3") = __arg3;	\
  register unsigned long r4 __asm__("r4") = __arg4;	\
  register unsigned long r5 __asm__("r5") = __arg5;	\
  register unsigned long r15 __asm__("r15") = name

#define ASM_ARGS_6	, "0"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5), "r"(r7)
#define ARGS_6(name, a1, a2, a3, a4, a5, a6)		\
  unsigned long __arg1 = (unsigned long)a1;		\
  unsigned long __arg2 = (unsigned long)a2;		\
  unsigned long __arg3 = (unsigned long)a3;		\
  unsigned long __arg4 = (unsigned long)a4;		\
  unsigned long __arg5 = (unsigned long)a5;		\
  unsigned long __arg6 = (unsigned long)a6;		\
  register unsigned long r1 __asm__("r1") = __arg1;	\
  register unsigned long r2 __asm__("r2") = __arg2;	\
  register unsigned long r3 __asm__("r3") = __arg3;	\
  register unsigned long r4 __asm__("r4") = __arg4;	\
  register unsigned long r5 __asm__("r5") = __arg5;	\
  register unsigned long r7 __asm__("r7") = __arg6;	\
  register unsigned long r15 __asm__("r15") = name

#define INTERNAL_SYSCALL_NCS(name, err, nr, args...)	\
  ({ ARGS_##nr (name, args);				\
     __asm__ __volatile__ ("int #0x08\n\t"		\
			   : "=r"(r1)			\
			   : "r"(r15) ASM_ARGS_##nr	\
			   : "memory");			\
     (int)r1; })

#endif /* __ASSEMBLER__ */
#endif /* _BITS_SYSCALLS_H */
