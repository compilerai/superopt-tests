include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/micro

EXTRA_FLAGS := --global-timeout 6000                                           \
               --max-address-space-size-gb 16                                  \
               # --disable-dst-to-src-submap                                     \
               # --disable-removal-of-stack-from-stack-nonstack-ml-in-dst        \

PROGS :=                                                                       \
         fcall10 fcall10_with_memaccess                                        \
         fcall25 fcall25_with_memaccess                                        \
         fcall50 fcall50_with_memaccess                                        \
         fcall100 fcall100_with_memaccess                                      \
         fcall200                                                              \
         fcall_taking_locals                                                   \
         fcalls_merge                                                          \
         ftmap_1                                                               \
         ftmap_2                                                               \
         ftmap_3                                                               \
         ftmap_4                                                               \
         ftmap_5                                                               \
         rodata_simple                                                         \
         load_store_elim_simple                                                \
         loop_hoisting                                                         \
         nested_loops_simple                                                   \
         non_linear_invariant_casting                                          \
         non_linear_invariant_shl                                              \
         sum_positive                                                          \
         idiv                                                                  \
         simple_struct                                                         \
         ret_long_long                                                         \
                                                                               \
         local_used_in_unreachable_loop                                        \
         local_used_on_unreachable_branch                                      \
         dead_and_alive_alloc                                                  \
         # nested_loops                                                        \
         # sum1d                                                               \
         # sum2d                                                               \
         # path_enum_2                                                         \
         # load_store_elim_cmove # needs "anticipated-cmove expressions"       \
         #ddec arg_passing fcall100 fcall100_with_memaccess                    \
         # src_ub : gcc harvest fails due to ud2                               \

UNROLL2_GCC := $(PROGS) \
               # load_store_elim_conditional not passing in GCC!
EXPECTED_FAILS_GCC :=                                                          \
                      alive_alloca                                             \
                      call_ret_struct                                          \
                      call_ret_struct_indir                                    \
                      dead_alloca                                              \
                      fcalls_sink_merge                                        \
                      ftmap_1_main                                             \
                      ftmap_2_main                                             \
                      ftmap_3_main                                             \
                      ftmap_4_main                                             \
                      ftmap_5_main                                             \
                      non_linear_comp_2_steps                                  \
                      non_linear_comp_5_steps                                  \
                      non_linear_invariant_casting                             \
                      ret_long_long                                            \
                      src_always_ub                                            \
                      # alive_alloca [correlation of alloc fails failure -- the unreachable path in src cannot be correlated but the syntactic lockstep alloc-dealloc pairing insists on matching it]
                      # call_ret_struct [fails as fcall happens while esp is not 16 aligned]
                      # dead_alloca [dealloc of unreachable alloca not correlated -- can probably be fixed by enabling enumeration of dealloc even if there is no corresponding alloc]
                      # fcalls_sink_merge [calls to bar() are sunk and merged]
                      # ftmap_1_main [sp is not aligned by 16 at callsite; the callee is in same translation unit]
                      # ftmap_2_main [pclsprels missing]
                      # ftmap_3_main [nop fcall inlined]
                      # ftmap_4_main [sp is not aligned by 16 at callsite; the callee is in same translation unit]
                      # ftmap_5_main [needs more precise points-to analysis -- see ftmap_5.c]
                      # sum2d [requires: pointer arithmetic overflow UB modelling]
                      # nested_loops [requires invariant (m > 0) in due to unswitching of inner loop condition]
                      # nested_loops_depth_5 [sometimes timeout]
                      # non_linear_comp_2_steps [query timeout on mem-eq query: perhaps d2s is weaker than expected]
                      # non_linear_comp_5_steps [timeout]
                      # non_linear_invariant_casting [requires: pointer arithmetic overflow UB modelling and non-linear invariant]
                      # ret_long_long [incompletness: need to include edx in return-reg expr]
                      # src_always_ub [eqgen fails due to ud2]

UNROLL2_CLANG := $(PROGS)                                                      \
                 d2s                                                           \
                 unreachable_alloc_in_src_pathset                              \
                 load_store_elim_conditional                                   \

EXPECTED_FAILS_CLANG :=                                                        \
                        alive_alloca                                           \
                        dead_alloca                                            \
                        fcalls_hoist_merge                                     \
                        fcalls_sink_merge                                      \
                        ftmap_3_main                                           \
                        ftmap_4_main                                           \
                        ftmap_5_main                                           \
                        load_load_elim                                         \
                        load_store_elim                                        \
                        loop_hoisting                                          \
                        non_linear_comp_2_steps                                \
                        non_linear_comp_5_steps                                \
                        ret_long_long                                          \
                        store_store_elim                                       \
                        # alive_alloca [correlation of alloc fails -- the unreachable path in src cannot be correlated but the syntactic lockstep alloc-dealloc pairing insists on matching it]
                        # dead_alloca [dealloc of unreachable alloca not correlated -- can probably be fixed by enabling enumeration of dealloc even if there is no corresponding alloc]
                        # fcalls_hoist_merge [calls to printf are folded into one by conditionally setting args]
                        # fcalls_sink_merge [calls to bar() are sunk and merged]
                        # ftmap_3 [nop fcall inlined]
                        # ftmap_4_main [get_global_sym call inlined]
                        # ftmap_5_main [needs more precise points-to analysis -- see ftmap_5.c]
                        # load_load_elim [safety check failed due to sinking of a heap load]
                        # load_store_elim [safety check failed due to sinking of a heap load]
                        # loop_hoisting [requires non-affine invariant: ecx = (n-1)&4]
                        # non_linear_comp_2_steps [query timeout on mem-eq query: perhaps d2s is weaker than expected]
                        # non_linear_comp_5_steps [timeout]
                        # ret_long_long [incompletness: need to include edx in return-reg expr]
                        # store_store_elim [store sinking -- heaps diverge]

UNROLL1_SRCDST :=                                          \
                  ptr_arith_ub                             \
                  path_enum_loop_body                      \
                  diff_speed                               \
                  src_ub                                   \

UNROLL4_SRCDST := nested_loop_peeling                      \
                  nested_loop_unrolling                    \
                  path_enum_can_inv                        \
                  mac_check                                \
                  # safety_check                             \

EXPECTED_FAILS_SRCDST := inequiv_1                         \
                         inequiv_2                         \
                         ptr_arith_ub                      \
                         path_enum_can_inv                 \
                         diff_speed                        \
                         mac_check_fail                    \
                         # ptr_arith_ub [requires: pointer arithmetic overflow UB modeling]
                         # path_enum_can_inv [requires: better path enumeration or better invariant inference; see path_enum_can_inv_src.c]

UNROLL1_ICC = $(PROGS)

EXPECTED_FAILS_ICC :=                                                          \
                      alive_alloca                                             \
                      dead_alloca                                              \
                      fcall_taking_locals                                      \
                      fcalls_sink_merge                                        \
                      ftmap_2_main                                             \
                      ftmap_3_main                                             \
                      non_linear_comp_2_steps                                  \
                      non_linear_comp_5_steps                                  \
                      ret_long_long                                            \
                      store_store_elim                                         \
                      # alive_alloca [correlation of alloc fails -- the unreachable path in src cannot be correlated but the syntactic lockstep alloc-dealloc pairing insists on matching it]
                      # dead_alloca [dealloc of unreachable alloca not correlated -- can probably be fixed by enabling enumeration of dealloc even if there is no corresponding alloc]
                      # fcall_taking_locals [need manual addr mappings]
                      # fcalls_sink_merge [calls to bar() are sunk and merged]
                      # ftmap_2_main [need manual addr mappings]
                      # ftmap_3_main [need manual addr mappings]
                      # non_linear_comp_2_steps [query timeout on mem-eq query: perhaps d2s is weaker than expected]
                      # non_linear_comp_5_steps [timeout]
                      # ret_long_long [incompletness: need to include edx in return-reg expr]
                      # store_store_elim [???]

# compiler flags
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O3 eqtest_srcdst
	cat $^ > $@

clangv_Od: clangv_O1
	cat $^ > $@
