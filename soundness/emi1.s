#https://godbolt.org/z/8dofdnarc
#gcc 4.9.2 -O3 -m32

        .file   "emi1.c"
        .text
.Ltext0:
        .section        .text.unlikely,"ax",@progbits
.LCOLDB0:
        .section        .text.startup,"ax",@progbits
.LHOTB0:
        .p2align 4,,15
        .section        .text.unlikely
.Ltext_cold0:
        .section        .text.startup
        .globl  main
        .type   main, @function
main:
.LFB0:
        .file 1 "emi1.c"
        .loc 1 11 0
        .cfi_startproc
.LVL0:
        leal    4(%esp), %ecx
        .cfi_def_cfa 1, 0
        andl    $-8, %esp
        movl    $3, %eax
        pushl   -4(%ecx)
        pushl   %ebp
        .cfi_escape 0x10,0x5,0x2,0x75,0
        movl    %esp, %ebp
        pushl   %ecx
        .cfi_escape 0xf,0x3,0x75,0x7c,0x6
        subl    $12, %esp
        movl    a, %ecx
.LVL1:
.L2:
        testl   %ecx, %ecx
        movl    262124(%ebp), %edx
        js      .L3
.L5:
.LVL2:
        .loc 1 15 0
        subl    $1, %eax
        jne     .L2
        .loc 1 23 0
        addl    $12, %esp
        xorl    %eax, %eax
        popl    %ecx
        .cfi_remember_state
        .cfi_restore 1
        .cfi_def_cfa 1, 0
        popl    %ebp
        .cfi_restore 5
        leal    -4(%ecx), %esp
        .cfi_def_cfa 4, 4
        ret
.LVL3:
        .p2align 4,,10
        .p2align 3
.L3:
        .cfi_restore_state
        .loc 1 20 0
        testl   %edx, %edx
        je      .L5
        jmp     .L3
        .cfi_endproc
.LFE0:
        .size   main, .-main
        .section        .text.unlikely
.LCOLDE0:
        .section        .text.startup
.LHOTE0:
        .comm   a,4,4
        .text
.Letext0:
        .section        .text.unlikely
.Letext_cold0:
        .section        .debug_info,"",@progbits
.Ldebug_info0:
        .long   0xa3
        .value  0x4
        .long   .Ldebug_abbrev0
        .byte   0x4
        .uleb128 0x1
        .long   .LASF2
        .byte   0x1
        .long   .LASF3
        .long   .Ldebug_ranges0+0
        .long   0
        .long   .Ldebug_line0
        .uleb128 0x2
        .long   .LASF4
        .byte   0x1
        .byte   0xa
        .long   0x72
        .long   .LFB0
        .long   .LFE0-.LFB0
        .uleb128 0x1
        .byte   0x9c
        .long   0x72
        .uleb128 0x3
        .string "b"
        .byte   0x1
        .byte   0xc
        .long   0x72
        .sleb128 -1
        .uleb128 0x4
        .string "d"
        .byte   0x1
        .byte   0xc
        .long   0x72
        .long   .LLST0
        .uleb128 0x4
        .string "e"
        .byte   0x1
        .byte   0xc
        .long   0x72
        .long   .LLST1
        .uleb128 0x5
        .string "f"
        .byte   0x1
        .byte   0xc
        .long   0x79
        .uleb128 0x3
        .string "c"
        .byte   0x1
        .byte   0xd
        .long   0x90
        .sleb128 -1
        .byte   0
        .uleb128 0x6
        .byte   0x4
        .byte   0x5
        .string "int"
        .uleb128 0x7
        .long   0x72
        .long   0x89
        .uleb128 0x8
        .long   0x89
        .byte   0x1
        .byte   0
        .uleb128 0x9
        .byte   0x4
        .byte   0x7
        .long   .LASF0
        .uleb128 0x9
        .byte   0x2
        .byte   0x7
        .long   .LASF1
        .uleb128 0xa
        .string "a"
        .byte   0x1
        .byte   0x8
        .long   0x72
        .uleb128 0x5
        .byte   0x3
        .long   a
        .byte   0
        .section        .debug_abbrev,"",@progbits
.Ldebug_abbrev0:
        .uleb128 0x1
        .uleb128 0x11
        .byte   0x1
        .uleb128 0x25
        .uleb128 0xe
        .uleb128 0x13
        .uleb128 0xb
        .uleb128 0x3
        .uleb128 0xe
        .uleb128 0x55
        .uleb128 0x17
        .uleb128 0x11
        .uleb128 0x1
        .uleb128 0x10
        .uleb128 0x17
        .byte   0
        .byte   0
        .uleb128 0x2
        .uleb128 0x2e
        .byte   0x1
        .uleb128 0x3f
        .uleb128 0x19
        .uleb128 0x3
        .uleb128 0xe
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x11
        .uleb128 0x1
        .uleb128 0x12
        .uleb128 0x6
        .uleb128 0x40
        .uleb128 0x18
        .uleb128 0x2117
        .uleb128 0x19
        .uleb128 0x1
        .uleb128 0x13
        .byte   0
        .byte   0
        .uleb128 0x3
        .uleb128 0x34
        .byte   0
        .uleb128 0x3
        .uleb128 0x8
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x1c
        .uleb128 0xd
        .byte   0
        .byte   0
        .uleb128 0x4
        .uleb128 0x34
        .byte   0
        .uleb128 0x3
        .uleb128 0x8
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x2
        .uleb128 0x17
        .byte   0
        .byte   0
        .uleb128 0x5
        .uleb128 0x34
        .byte   0
        .uleb128 0x3
        .uleb128 0x8
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .byte   0
        .byte   0
        .uleb128 0x6
        .uleb128 0x24
        .byte   0
        .uleb128 0xb
        .uleb128 0xb
        .uleb128 0x3e
        .uleb128 0xb
        .uleb128 0x3
        .uleb128 0x8
        .byte   0
        .byte   0
        .uleb128 0x7
        .uleb128 0x1
        .byte   0x1
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x1
        .uleb128 0x13
        .byte   0
        .byte   0
        .uleb128 0x8
        .uleb128 0x21
        .byte   0
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x2f
        .uleb128 0xb
        .byte   0
        .byte   0
        .uleb128 0x9
        .uleb128 0x24
        .byte   0
        .uleb128 0xb
        .uleb128 0xb
        .uleb128 0x3e
        .uleb128 0xb
        .uleb128 0x3
        .uleb128 0xe
        .byte   0
        .byte   0
        .uleb128 0xa
        .uleb128 0x34
        .byte   0
        .uleb128 0x3
        .uleb128 0x8
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x3f
        .uleb128 0x19
        .uleb128 0x2
        .uleb128 0x18
        .byte   0
        .byte   0
        .byte   0
        .section        .debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
        .long   .LVL1
        .long   .LVL2
        .value  0x2
        .byte   0x30
        .byte   0x9f
        .long   .LVL3
        .long   .LFE0
        .value  0x2
        .byte   0x30
        .byte   0x9f
        .long   0
        .long   0
.LLST1:
        .long   .LVL0
        .long   .LVL1
        .value  0x2
        .byte   0x30
        .byte   0x9f
        .long   0
        .long   0
        .section        .debug_aranges,"",@progbits
        .long   0x1c
        .value  0x2
        .long   .Ldebug_info0
        .byte   0x4
        .byte   0
        .value  0
        .value  0
        .long   .LFB0
        .long   .LFE0-.LFB0
        .long   0
        .long   0
        .section        .debug_ranges,"",@progbits
.Ldebug_ranges0:
        .long   .LFB0
        .long   .LFE0
        .long   0
        .long   0
        .section        .debug_line,"",@progbits
.Ldebug_line0:
        .section        .debug_str,"MS",@progbits,1
.LASF2:
        .string "GNU C 4.9.2 -m32 -mtune=generic -march=x86-64 -g -O3"
.LASF0:
        .string "sizetype"
.LASF3:
        .string "emi1.c"
.LASF1:
        .string "short unsigned int"
.LASF4:
        .string "main"
        .ident  "GCC: (GCC-Explorer-Build) 4.9.2"
        .section        .note.GNU-stack,"",@progbits
