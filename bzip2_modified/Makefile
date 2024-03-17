include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/bzip2_modified

UNROLL2 := bzip2_modified

UNROLL2_CLANG = $(UNROLL2)

EXTRA_FLAGS        := --smt-query-timeout 300 --eqcheck-timeout 14400 --global-timeout 86400 --max-address-space-size-gb 32
EXTRA_FLAGS_CLANGV := --smt-query-timeout 300 --eqcheck-timeout 14400 --global-timeout 86400 --max-address-space-size-gb 32

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(GCC_EQCHECKER_NOUNROLL_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: clangv_O1-
	cat $^ > $@

clangv_Od: clangv_O1-
	cat $^ > $@
