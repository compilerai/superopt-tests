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
                      cast3sf                                                  \
                      cast3uf                                                  \
                      fcall_fp2a                                               \
                      # cast3sf Failing due to timeout in region_agrees_with_memlabel (The addr calculation has float_to_ieee_bv in it)
                      # cast3uf Failing due to timeout in region_agrees_with_memlabel (The addr calculation has float_to_ieee_bv in it)
                      # fcall_fp2a nondet termination due to old_preds != new_preds

EXPECTED_FAILS_CLANG :=                                                        \

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
