	.text
	.file	"src_ub.c"
	.globl	src_always_ub                   # -- Begin function src_always_ub
	.p2align	4, 0x90
	.type	src_always_ub,@function
src_always_ub:                          # @src_always_ub
	retl
	.globl	src_cond_ub                     # -- Begin function src_cond_ub
	.p2align	4, 0x90
	.type	src_cond_ub,@function
src_cond_ub:                            # @src_cond_ub
	xorl	%eax, %eax
	retl
