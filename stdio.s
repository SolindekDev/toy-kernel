	.file	"stdio.c"
	.text
	.globl	exit
	.type	exit, @function
exit:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	.cfi_offset 3, -24
	movl	%edi, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %ebx
#APP
# 4 "clib/stdio.c" 1
	movl %ebx, %eax
# 0 "" 2
#NO_APP
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	exit, .-exit
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
