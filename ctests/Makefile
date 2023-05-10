include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/ctests

NOUNROLL_PROGS := nsieve \
                  qsort  \
                  lists  \
                  #nsievebits \ # ext_rotate_left expr is generated which is not supported by solvers

UNROLL_PROGS := chomp        \
                fannkuch     \
                knucleotide  \
                sha1

UNROLL1_GCC := $(NOUNROLL_PROGS)
UNROLL4_GCC := $(UNROLL_PROGS)

UNROLL1_CLANG := $(NOUNROLL_PROGS)
UNROLL8_CLANG := $(UNROLL_PROGS)

EXTRA_FLAGS := --global-timeout 7200

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(GCC_EQCHECKER_NOUNROLL_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

test: eqtest_i386_O3
