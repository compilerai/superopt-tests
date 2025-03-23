include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/sorting

UNROLL2 := mergesort \
           quicksort

UNROLL2_CLANGV_O0 = $(UNROLL2)

EXTRA_FLAGS        := --smt-query-timeout 180 --global-timeout 28800 --max-address-space-size-gb 32 --disable-removal-of-stack-from-stack-nonstack-ml-in-dst --enable-query-decomposition

EXPECTED_FAILS_CLANGV :=                                             \
                         main                                        \
                         printArray                                  \
                         # main [harvest fails]
                         # printArray [rodata issue]

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(GCC_EQCHECKER_NOUNROLL_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: clangv_O0 #clangv_O1-
	cat $^ > $@
