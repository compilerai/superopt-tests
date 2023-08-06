include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/micro

EXTRA_FLAGS := --global-timeout 1200 --max-address-space-size-gb 16 --disable-dst-to-src-submap

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
         nested_loops_simple \
         non_linear_invariant_casting \
         non_linear_invariant_shl \
         sum_positive \
         # nested_loops \
         # sum1d \
         # sum2d \
         # path_enum_2 \
         # load_store_elim_cmove # needs "anticipated-cmove expressions"
         #ddec arg_passing fpadd  fcall100 fcall100_with_memaccess \
         #fpext : TOO SLOW

UNROLL8_GCC := $(PROGS) \
               # load_store_elim_conditional not passing in GCC!
EXPECTED_FAILS_GCC :=                               \
                      fptoui                        \
                      fptouid                       \
                      fptouil                       \
                      non_linear_invariant_casting  \
                      ftmap_1_main                  \
                      ftmap_2_main                  \
                      ftmap_3_main                  \
                      ftmap_4_main                  \
                      fcalls_sink_merge             \
                      # fptoui [???]
                      # fptouid [???]
                      # fptouil [???]
                      # non_linear_invariant_casting [requires: pointer arithmetic overflow UB modelling and non-linear invariant]
                      # ftmap_1_main [sp is not aligned by 16 at callsite; the callee is in same translation unit]
                      # ftmap_2_main [pclsprels missing]
                      # ftmap_3_main [nop fcall inlined]
                      # ftmap_4_main [sp is not aligned by 16 at callsite; the callee is in same translation unit]
                      # fcalls_sink_merge [calls to bar() are sinked and merged]
                      # nested_loops [requires invariant (m > 0) in due to unswitching of inner loop condition]
											# sum2d [requires: pointer arithmetic overflow UB modelling]

UNROLL16_CLANG := $(PROGS) \
                  load_store_elim_conditional
EXPECTED_FAILS_CLANG :=                             \
                        fptouil                     \
                        ftmap_3_main                \
                        ftmap_4_main                \
                        # fptouil [???]
                        # ftmap_3 [nop fcall inlined]
                        # ftmap_4 [get_global_sym call inlined]

UNROLL1_SRCDST := inequiv_1                                \
                  inequiv_2                                \
                  nestedLoop                               \
                  ifswitch                                 \
                  ptr_arith_ub                             \
                  path_enum_loop_body                      \

UNROLL4_SRCDST := nested_loop_peeling                      \
                  nested_loop_unrolling                    \
                  strlen                                   \
                  bitflip                                  \
                  loopSplitting                            \
                  # epsilon_corr

UNROLL8_SRCDST := strlen \

EXPECTED_FAILS_SRCDST := inequiv_1                         \
                         inequiv_2                         \
                         ptr_arith_ub                      \
                         # ptr_arith_ub [requires: pointer arithmetic overflow UB modeling]

# compiler flags
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

test_i386: eqtest_i386_O3 eqtest_srcdst
	cat $^ > $@

clangv_Od: clangv_O1
	cat $^ > $@
