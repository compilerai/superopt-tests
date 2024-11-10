	.text
	.globl	mac_check_pass                  # -- Begin function mac_check_pass
	.p2align	4, 0x90
	.type	mac_check_pass,@function
mac_check_pass:                              # @mac_check_pass
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$16, %esp
	movl	32(%esp), %esi
	shll	$10, %esi
	movl	%esi, (%esp)
	calll	MYmymalloc
	testl	%eax, %eax
	je	.LBB0_1
# %bb.2:                                # %for.cond.preheader
	testl	%esi, %esi
	jle	.LBB0_3
# %bb.4:                                # %for.body.preheader
	movl	%eax, %ecx
	xorl	%eax, %eax
	xorl	%edx, %edx
	.p2align	4, 0x90
.LBB0_5:                                # %for.body
                                        # =>This Inner Loop Header: Depth=1
	movl	spec_fd+12, %edi
	movzbl	(%edi,%edx), %ebx
	movb	%bl, (%ecx,%edx)
	incl	%edx
	cmpl	%edx, %esi
	jne	.LBB0_5
	jmp	.LBB0_6
.LBB0_1:
	movl	$-1, %eax
	jmp	.LBB0_6
.LBB0_3:
	xorl	%eax, %eax
.LBB0_6:                                # %cleanup
	addl	$16, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	retl
.Lfunc_end0:
	.size	mac_check_pass, .Lfunc_end0-mac_check_pass
	.globl	mac_check_fail                       # -- Begin function mac_check_fail
	.p2align	4, 0x90
	.type	mac_check_fail,@function
mac_check_fail:                              # @mac_check_fail
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$16, %esp
	movl	32(%esp), %esi
	shll	$10, %esi
	movl	%esi, (%esp)
	calll	MYmymalloc
	testl	%eax, %eax
	je	.LBB1_1
# %bb.2:                                # %for.cond.preheader
	testl	%esi, %esi
	jle	.LBB1_3
# %bb.4:                                # %for.body.preheader
	movl	%eax, %ecx
	xorl	%eax, %eax
	xorl	%edx, %edx
	.p2align	4, 0x90
.LBB1_5:                                # %for.body
                                        # =>This Inner Loop Header: Depth=1
	movl	spec_fd+12, %edi
	movzbl	(%edi,%edx), %ebx
	movb	%bl, (%ecx,%edx)
	incl	%edx
	cmpl	%edx, %esi
	jne	.LBB1_5
	jmp	.LBB1_6
.LBB1_1:
	movl	$-1, %eax
	jmp	.LBB1_6
.LBB1_3:
	xorl	%eax, %eax
.LBB1_6:                                # %cleanup
	# the following two lines are no-op memory accesses that are guaranteed to be safe
	# but won't be accepted by our TV because of (MAC) check
	movl	spec_fd+12, %edi
	movzbl	(%edi), %ebx
	addl	$16, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	retl
.Lfunc_end1:
	.size	mac_check_fail, .Lfunc_end1-mac_check_fail
	.type	spec_fd,@object                 # @spec_fd
	.section	.bss.spec_fd,"aw",@nobits
	.globl	spec_fd
	.p2align	2, 0x0
spec_fd:
	.zero	48
	.size	spec_fd, 48

