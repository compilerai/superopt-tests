include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/bzip2_locals

UNROLL1 := bzip2_locals \

UNROLL1_CLANG = $(UNROLL1)

EXTRA_FLAGS        := --smt-query-timeout 180 --global-timeout 28800 --max-address-space-size-gb 32 --disable-removal-of-stack-from-stack-nonstack-ml-in-dst --enable-query-decomposition
EXTRA_FLAGS_CLANGV := --smt-query-timeout 180 --global-timeout 28800 --max-address-space-size-gb 32 --disable-removal-of-stack-from-stack-nonstack-ml-in-dst --enable-query-decomposition

# compiler flags
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: clangv_O1- eqtest_i386_O1 eqtest_i386_O2 
	cat $^ > $@
