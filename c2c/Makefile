include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/c2c

UNROLL1_SRCDST := nestedLoop                               \
                  ifswitch                                 \
                  inequiv_1                                \
                  inequiv_2                                \

UNROLL4_SRCDST := bitflip                                  \
                  loopSplitting                            \
                  strlen_dietlibc                          \
                  strlen_glibc_fixed                       \
                  strlen_glibc

EXPECTED_FAILS_SRCDST := inequiv_1                         \
                         inequiv_2                         \
                         strlen_dietlibc                   \

EXTRA_FLAGS := --smt-query-timeout 300 --global-timeout 7200 #--highmem-reserved-pages 1

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(GCC_EQCHECKER_NOUNROLL_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: eqtest_srcdst
	cat $^ > $@
