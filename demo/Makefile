include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/demo

UNROLL1_GCC := sum1d \
               sum_positive \
               sum2d \
               kernel_mvt \
               # s441 -- incomplete CG

UNROLL1_SRCDST := nestedLoop \
                  ifswitch \
                  inequiv_1 \
                  inequiv_2

UNROLL4_SRCDST := bitflip \
                  loopSplitting  # times out

UNROLL8_SRCDST := strlen

EXTRA_FLAGS := --smt-query-timeout 300 --global-timeout 7200

EXPECTED_FAILS_SRCDST := inequiv_1 inequiv_2

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(GCC_EQCHECKER_NOUNROLL_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O3 eqtest_srcdst
	cat $^ > $@

clangv_Od: clangv_O1
	cat $^ > $@
