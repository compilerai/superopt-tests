#https://godbolt.org/z/377ce8Pv1
        .file   "emi9f.c"
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
        .globl  emi9f_buggy
        .type   emi9f_buggy, @function
emi9f_buggy:
.LFB0:
        .file 1 "emi9f.c"
        .loc 1 7 0
        .cfi_startproc
        subl    $16, %esp
        .cfi_def_cfa_offset 20
.LVL0:
        .loc 1 15 0
        movl    $1, %eax
        movl    $2, b
        addl    $16, %esp
        .cfi_def_cfa_offset 4
.LVL1:
        ret
        .cfi_endproc
.LFE0:
        .size   emi9f_buggy, .-emi9f_buggy
        .section        .text.unlikely
.LCOLDE0:
        .section        .text.startup
.LHOTE0:
        .comm   b,4,4
        .text
.Letext0:
        .section        .text.unlikely
.Letext_cold0:
        .section        .debug_info,"",@progbits
.Ldebug_info0:
        .long   0x9f
        .value  0x4
        .long   .Ldebug_abbrev0
        .byte   0x4
        .uleb128 0x1
        .long   .LASF1
        .byte   0x1
        .long   .LASF2
        .long   .Ldebug_ranges0+0
        .long   0
        .long   .Ldebug_line0
        .uleb128 0x2
        .string "S"
        .byte   0x8
        .byte   0x1
        .byte   0x1
        .long   0x42
        .uleb128 0x3
        .string "f0"
        .byte   0x1
        .byte   0x2
        .long   0x42
        .byte   0
        .uleb128 0x3
        .string "f1"
        .byte   0x1
        .byte   0x3
        .long   0x42
        .byte   0x4
        .byte   0
        .uleb128 0x4
        .byte   0x4
        .byte   0x5
        .string "int"
        .uleb128 0x5
        .long   .LASF3
        .byte   0x1
        .byte   0x6
        .long   0x42
        .long   .LFB0
        .long   .LFE0-.LFB0
        .uleb128 0x1
        .byte   0x9c
        .long   0x7c
        .uleb128 0x6
        .string "a"
        .byte   0x1
        .byte   0x8
        .long   0x7c
        .uleb128 0x2
        .byte   0x91
        .sleb128 -20
        .uleb128 0x7
        .string "d"
        .byte   0x1
        .byte   0x9
        .long   0x21
        .long   .LLST0
        .byte   0
        .uleb128 0x8
        .long   0x21
        .long   0x8c
        .uleb128 0x9
        .long   0x8c
        .byte   0x1
        .byte   0
        .uleb128 0xa
        .byte   0x4
        .byte   0x7
        .long   .LASF0
        .uleb128 0xb
        .string "b"
        .byte   0x1
        .byte   0x5
        .long   0x42
        .uleb128 0x5
        .byte   0x3
        .long   b
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
        .uleb128 0x13
        .byte   0x1
        .uleb128 0x3
        .uleb128 0x8
        .uleb128 0xb
        .uleb128 0xb
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x1
        .uleb128 0x13
        .byte   0
        .byte   0
        .uleb128 0x3
        .uleb128 0xd
        .byte   0
        .uleb128 0x3
        .uleb128 0x8
        .uleb128 0x3a
        .uleb128 0xb
        .uleb128 0x3b
        .uleb128 0xb
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x38
        .uleb128 0xb
        .byte   0
        .byte   0
        .uleb128 0x4
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
        .uleb128 0x5
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
        .uleb128 0x6
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
        .uleb128 0x18
        .byte   0
        .byte   0
        .uleb128 0x7
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
        .uleb128 0x8
        .uleb128 0x1
        .byte   0x1
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x1
        .uleb128 0x13
        .byte   0
        .byte   0
        .uleb128 0x9
        .uleb128 0x21
        .byte   0
        .uleb128 0x49
        .uleb128 0x13
        .uleb128 0x2f
        .uleb128 0xb
        .byte   0
        .byte   0
        .uleb128 0xa
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
        .uleb128 0xb
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
        .long   .LVL0
        .long   .LVL1
        .value  0x8
        .byte   0x74
        .sleb128 0
        .byte   0x93
        .uleb128 0x4
        .byte   0x30
        .byte   0x9f
        .byte   0x93
        .uleb128 0x4
        .long   .LVL1
        .long   .LFE0
        .value  0x8
        .byte   0x74
        .sleb128 -16
        .byte   0x93
        .uleb128 0x4
        .byte   0x30
        .byte   0x9f
        .byte   0x93
        .uleb128 0x4
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
.LASF1:
        .string "GNU C 4.9.2 -m32 -mtune=generic -march=x86-64 -g -O3"
.LASF0:
        .string "sizetype"
.LASF2:
        .string "emi9f.c"
.LASF3:
        .string "main"
        .ident  "GCC: (GCC-Explorer-Build) 4.9.2"
        .section        .note.GNU-stack,"",@progbits
