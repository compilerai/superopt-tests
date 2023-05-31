include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/micro

EXTRA_FLAGS := --global-timeout 600 --max-address-space-size-gb 16

PROGS := fptrunc fpbinary fptoui fbinary flbinary \
         fcall10 fcall10_with_memaccess \
         fcall_taking_locals \
         fcalls_merge \
         ftmap_1 \
         ftmap_2 \
         ftmap_3 \
         ftmap_4 \
         rodata_simple \
         load_store_elim_simple \
         loop_hoisting \
         nested_loops \
         non_linear_invariant_casting \
         non_linear_invariant_shl \
         # load_store_elim_cmove # needs "anticipated-cmove expressions"
         #ddec arg_passing fpadd  fcall100 fcall100_with_memaccess \
         #fpext : TOO SLOW

EXTRA_FLAGS :=

UNROLL8_GCC := $(PROGS) \
               # load_store_elim_conditional not passing in GCC!
EXPECTED_FAILS_GCC := non_linear_invariant_casting  \
                      ftmap_1                       \
                      ftmap_2                       \
                      ftmap_3                       \
                      ftmap_4                       \
                      non_linear_invariant_shl      \
                      fcalls_merge                  \
                      # non_linear_invariant_casting [requires: pointer arithmetic overflow UB modelling]
                      # ftmap_1 [eqgen fails because of incorrect disassembly]
                      # ftmap_2 [harvest output does not include function main]
                      # ftmap_3 [harvest output does not include function main]
                      # ftmap_4 [harvest output does not include function main]
                      # fcalls_merge [calls to bar() are sinked and merged]

UNROLL16_CLANG := $(PROGS) \
                  load_store_elim_conditional
EXPECTED_FAILS_CLANG := ftmap_3                     \
                        ftmap_4                     \
                        non_linear_invariant_shl    \
                        # ftmap_3 [harvest output does not include function main]
                        # ftmap_4 [harvest output does not include function main]

UNROLL4_SRCDST := nested_loop_peeling nested_loop_unrolling

# compiler flags
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

test_i386: eqtest_i386_O3 eqtest_srcdst
	cat $^ > $@
