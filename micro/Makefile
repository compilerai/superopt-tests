include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/micro

EXTRA_FLAGS := --global-timeout 1200                                           \
               --max-address-space-size-gb 16                                  \
               --disable-removal-of-stack-from-stack-nonstack-ml-in-dst        \
               #--disable-dst-to-src-submap

PROGS := fptrunc fpbinary fptoui fbinary flbinary                              \
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
         #ddec arg_passing fpadd  fcall100 fcall100_with_memaccess             \
         #fpext : TOO SLOW                                                     \

UNROLL2_GCC := $(PROGS) \
               # load_store_elim_conditional not passing in GCC!
EXPECTED_FAILS_GCC :=                                                          \
                      alive_alloca                                             \
                      dead_alloca                                              \
                      call_ret_struct                                          \
                      fcall200                                                 \
                      fcalls_sink_merge                                        \
                      fptoui                                                   \
                      fptouid                                                  \
                      fptouil                                                  \
                      ftmap_1_main                                             \
                      ftmap_2_main                                             \
                      ftmap_3_main                                             \
                      ftmap_4_main                                             \
                      ftmap_5_main                                             \
                      nested_loops_depth_5                                     \
                      non_linear_invariant_casting                             \
                      ret_long_long                                            \
											# sum2d [requires: pointer arithmetic overflow UB modelling]
                      # alive_alloca [correlation of alloc fails failure -- the unreachable path in src cannot be correlated but the syntactic lockstep alloc-dealloc pairing insists on matching it]
                      # call_ret_struct [incompleteness: need to update esp to esp+4 for an fcall which returns aggregate (struct/union)]
                      # dead_alloca [dealloc of unreachable alloca not correlated -- can probably be fixed by enabling enumeration of dealloc even if there is no corresponding alloc]
                      # fcall200 [times out -- needs another 20 minutes or so (total 40 minutes)]
                      # fcalls_sink_merge [calls to bar() are sunk and merged]
                      # fptoui [???]
                      # fptouid [???]
                      # fptouil [???]
                      # ftmap_1_main [sp is not aligned by 16 at callsite; the callee is in same translation unit]
                      # ftmap_2_main [pclsprels missing]
                      # ftmap_3_main [nop fcall inlined]
                      # ftmap_4_main [sp is not aligned by 16 at callsite; the callee is in same translation unit]
                      # ftmap_5_main [needs more precise points-to analysis -- see ftmap_5.c]
                      # nested_loops [requires invariant (m > 0) in due to unswitching of inner loop condition]
                      # nested_loops_depth_5 [timeout]
                      # non_linear_invariant_casting [requires: pointer arithmetic overflow UB modelling and non-linear invariant]
                      # ret_long_long [incompletness: need to include edx in return-reg expr]

UNROLL2_CLANG := $(PROGS)                                                      \
                 unreachable_alloc_in_src_pathset                              \
                 load_store_elim_conditional                                   \

EXPECTED_FAILS_CLANG :=                                                        \
                        alive_alloca                                           \
                        call_ret_struct                                        \
                        dead_alloca                                            \
                        fcall200                                               \
                        fptouil                                                \
                        fptouil                                                \
                        ftmap_3_main                                           \
                        ftmap_4_main                                           \
                        ftmap_5_main                                           \
                        nested_loops_depth_4                                   \
                        nested_loops_depth_5                                   \
                        ret_long_long                                          \
                        # alive_alloca [correlation of alloc fails -- the unreachable path in src cannot be correlated but the syntactic lockstep alloc-dealloc pairing insists on matching it]
                        # call_ret_struct [incompleteness: need to update esp to esp+4 for an fcall which returns aggregate (struct/union)]
                        # dead_alloca [dealloc of unreachable alloca not correlated -- can probably be fixed by enabling enumeration of dealloc even if there is no corresponding alloc]
                        # fcall200 [times out -- needs another 20 minutes or so (total 40 minutes)]
                        # fptouil [???]
                        # ftmap_3 [nop fcall inlined]
                        # ftmap_4_main [get_global_sym call inlined]
                        # ftmap_5_main [needs more precise points-to analysis -- see ftmap_5.c]
                        # nested_loops_depth_3 [sometimes timeout]
                        # nested_loops_depth_4 [timeout]
                        # nested_loops_depth_5 [timeout]
                        # ret_long_long [incompletness: need to include edx in return-reg expr]

UNROLL1_SRCDST :=                                          \
                  ptr_arith_ub                             \
                  path_enum_loop_body                      \
                  diff_speed                               \

UNROLL4_SRCDST := nested_loop_peeling                      \
                  nested_loop_unrolling                    \
                  path_enum_can_inv                        \

EXPECTED_FAILS_SRCDST := inequiv_1                         \
                         inequiv_2                         \
                         ptr_arith_ub                      \
                         path_enum_can_inv                 \
                         diff_speed                        \
                         # ptr_arith_ub [requires: pointer arithmetic overflow UB modeling]
                         # path_enum_can_inv [requires: better path enumeration or better invariant inference; see path_enum_can_inv_src.c]

UNROLL1_ICC = $(PROGS)

EXPECTED_FAILS_ICC :=                                                          \
                      alive_alloca                                             \
                      call_ret_struct                                          \
                      dead_alloca                                              \
                      fcall200                                                 \
                      fcall50_with_memaccess                                   \
                      fcall_taking_locals                                      \
                      fcalls_sink_merge                                        \
                      fdiv                                                     \
                      flcmp                                                    \
                      flcmp                                                    \
                      fptouil                                                  \
                      fptouil                                                  \
                      ftmap_2_main                                             \
                      ftmap_3_main                                             \
                      ftmap_4_main                                             \
                      non_linear_invariant_casting                             \
                      ret_long_long                                            \
                      store_store_elim                                         \
                      # alive_alloca [correlation of alloc fails -- the unreachable path in src cannot be correlated but the syntactic lockstep alloc-dealloc pairing insists on matching it]
                      # call_ret_struct [incompleteness: need to update esp to esp+4 for an fcall which returns aggregate (struct/union)]
                      # dead_alloca [dealloc of unreachable alloca not correlated -- can probably be fixed by enabling enumeration of dealloc even if there is no corresponding alloc]
                      # fcall200 [times out -- needs another 20 minutes or so (total 40 minutes)]
                      # fcall50_with_memaccess [times out]
                      # fcall_taking_locals [need manual addr mappings]
                      # fcalls_sink_merge [calls to bar() are sunk and merged]
                      # flcmp [???]
                      # fptouil [???]
                      # ftmap_2_main [need manual addr mappings]
                      # ftmap_3_main [need manual addr mappings]
                      # non_linear_invariant_casting [requires: pointer arithmetic overflow UB modelling and non-linear invariant]
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
