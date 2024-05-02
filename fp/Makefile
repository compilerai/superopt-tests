include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/fp

PROGS := fp1 fp1_d fp1_l fp2 fp2_d fp3 fp4 fpconst fpconst_d fpedge fpedge_d soundness \
         cast

#PROGS_EQCHECKER_COMPILER := 
#PROGS_EQCHECKER_SRCDST :=

EXTRA_FLAGS :=

UNROLL8_GCC := $(PROGS)
UNROLL16_CLANG := $(PROGS)

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS) -msse2 -mfpmath=sse
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O3
	cat $^ > $@
