include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/fp

EXTRA_FLAGS :=

PROGS := fptrunc fpbinary fptoui fbinary flbinary                              \
         fp1 fp1_d fp1_l fp2 fp2_d fp3 fp4                                     \
         fpconst fpconst_d fpedge fpedge_d                                     \
         soundness                                                             \
         cast fcall_fp                                                         \

EXPECTED_FAILS_GCC :=                                                          \
                      abs1_ld                                                  \
                      abs_max_ld                                               \
                      comp1                                                    \
                      max_ld                                                   \
                      # abs1_ld [some ce-eval issue --- needs debugging]
                      # abs_max_ld [some ce-eval issue --- needs debugging]
                      # comp1 [query timeout]
                      # max_ld [some ce-eval issue --- needs debugging]

EXPECTED_FAILS_CLANG :=                                                        \
                      abs1_ld                                                  \
                      abs_max_ld                                               \
                      comp1                                                    \
                      same_ld                                                  \
                      # abs1_ld [some ce-eval issue --- needs debugging]
                      # abs_max_ld [some ce-eval issue --- needs debugging]
                      # comp1 [query timeout]
                      # same_ld [some ce-eval issue --- needs debugging]

#PROGS_EQCHECKER_COMPILER := 
#PROGS_EQCHECKER_SRCDST :=

UNROLL8_GCC := $(PROGS)
UNROLL16_CLANG := $(PROGS)

EXPECTED_FAILS_ICC :=                                                          \
                      flcmp                                                    \
                      # flcmp [???]

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS) -msse2 -mfpmath=sse
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O0 # eqtest_i386_O3
	cat $^ > $@
