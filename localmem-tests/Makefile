include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/localmem-tests

EXTRA_FLAGS := --smt-query-timeout 120                                         \
               --global-timeout 14400                                          \
               --eqcheck-timeout 7200                                          \
               --enable-query-decomposition                                    \
               --disable-removal-of-stack-from-stack-nonstack-ml-in-dst        \
               --disable-dst-to-src-submap

UNROLL1_PROGS :=                                                               \
                 addr_taken_simple                                             \
                 addr_taken_parameter                                          \
                 addr_taken_conditional                                        \
                 addr_taken_array                                              \
                 addr_taken_array_in_loop                                      \
                                                                               \
                 variadic_acyclic                                              \
                 variadic_with_loop                                            \
                                                                               \
                 vla_simple                                                    \
                 vla_conditional_use                                           \
                 vla_midway_decl                                               \
                 vla_2_nested_loops                                            \
                 vla_single_loop_N                                             \
                 vla_in_loop_N                                                 \
                 vla_in_loop_conditional_continue                              \
                 vla_in_loop_conditional_exit                                  \
                 vla_2d                                                        \
                                                                               \
                 alloca_simple                                                 \
                 alloca_conditional                                            \
                 alloca_malloc_switch                                          \
                                                                               \
                 minprintf                                                     \
                 minscanf                                                      \
                 rodata                                                        \
                                                                               \
                 # fib                [u2]                                     \
                 # alloca_linked_list [u2]                                     \

UNROLL1_GCC := fib                                                             \
               fib_paper                                                       \
               $(UNROLL1_PROGS)                                                \

UNROLL2_GCC := alloca_linked_list

EXPECTED_FAILS_GCC :=                                                          \
                      vla_in_loop_2                                            \
                      vla_in_loop_3                                            \
                      vla_in_loop_4                                            \
                      vla_single_loop_1                                        \
                      vla_single_loop_2                                        \
                      vla_single_loop_3                                        \
                      vla_single_loop_4                                        \
                      vla_2_nested_loops                                       \
                      vla_2d                                                   \
                      minprintf                                                \
                      minscanf                                                 \
                      alloca_malloc_switch                                     \
                      alloca_conditional                                       \
                      alloca_conditional_3                                     \
                      vla_conditional_use                                      \
                      # vla_in_loop_2 [requires invariant (i < n) on loop body PCs / suffixpath]
                      # vla_in_loop_3 [requires invariant (i < n) on loop body PCs / suffixpath]
                      # vla_in_loop_4 [requires invariant (i < n) on loop body PCs / suffixpath]
                      # vla_single_loop_1 [dealloc path correlation failing: sinking (code merging) of sp restore (dealloc) to common path instead of alloc dominating path, no coresponding path in src]
                      # vla_single_loop_2 [missing non-affine invariant relating sp decrement offset value 'eax' with n]
                      # vla_single_loop_3 [timeout]
                      # vla_single_loop_4 [timeout]
                      # vla_2_nested_loops [some bitwise computation is happening -- local-mem-eq is failing]
                      # vla_2d [mem-eq query timeout]
                      # minprintf,minscanf [requires select(local.addr) which is missing from bv-eqclass exprs]
                      # alloca_malloc_switch [fails stack-dealloc wfcond -- requires RPO DFA for more precise spvr]
                      # alloca_conditional [requires invariant (i < n) on loop body PCs / suffixpath]
                      # alloca_conditional_3 [times out -- don't know the exact reason for failure]
                      # vla_conditional_use [times-out somtimes because the invariant inference DFA does not proceed in RPO i.e. it tries relaxing an edge before relaxing all its predecessors]

UNROLL1_CLANG := alloca_linked_list                                            \
                 $(UNROLL1_PROGS)                                              \

UNROLL2_CLANG := fib                                                           \
                 fib_paper

EXPECTED_FAILS_CLANG :=                                                        \
                        vla_single_loop_2                                      \
                        vla_single_loop_3                                      \
                        vla_single_loop_4                                      \
                        vla_in_loop_2                                          \
                        vla_in_loop_3                                          \
                        vla_in_loop_4                                          \
                        vla_2d                                                 \
                        vla_2_nested_loops                                     \
                        variadic_acyclic                                       \
                        alloca_malloc_switch                                   \
                        # vla_single_loop_2 [missing non-affine invariant relating sp decrement offset value 'eax' with n]
                        # vla_single_loop_{3,4} [timeout]
                        # vla_in_loop_2 [requires invariant (i < n) on loop body PCs / suffixpath]
                        # vla_in_loop_3 [query timeout => timeout]
                        # vla_in_loop_4 [query timeout => timeout]
                        # vla_2d [non-affine invariant required for 2D VLA strided traversal: reg == 4*i*(n+1)]
                        # vla_2_nested_loops [timeout]
                        # variadic_acyclic [push insn is used for allocation -- we correlate local before write and thus get different mem on path where the local is not written-to before dealloc]
                        # alloca_malloc_switch [fails stack-dealloc wfcond -- requires RPO DFA for more precise spvr]

# ack does not support VLA and alloca()
UNROLL2_ACK = addr_taken_simple                                                \
              addr_taken_array                                                 \
              addr_taken_array_in_loop                                         \
              addr_taken_conditional                                           \
              variadic_acyclic                                                 \
              # minprintf -- harvested assembly is incorrect; looks like switch is implemented using jump table
EXTRA_FLAGS_ACK := --disable-fcall-wfconds

UNROLL1_ICC = $(UNROLL1_PROGS)                                                 \
              # fib [requires non-affine invariants]

UNROLL2_ICC = alloca_linked_list

EXPECTED_FAILS_ICC := vla_simple                                               \
                      vla_simple_nested_1                                      \
                      vla_simple_nested_2                                      \
                      vla_midway_decl                                          \
                      vla_single_loop_1                                        \
                      vla_single_loop_2                                        \
                      vla_single_loop_3                                        \
                      vla_single_loop_4                                        \
                      vla_in_loop_1                                            \
                      vla_in_loop_3                                            \
                      vla_in_loop_4                                            \
                      vla_conditional_use                                      \
                      vla_in_loop_conditional_continue                         \
                      vla_in_loop_conditional_exit                             \
                      vla_2d                                                   \
                      vla_2_nested_loops                                       \
                      rodata                                                   \
                      alloca_conditional_simple                                \
                      alloca_malloc_switch                                     \
                      # vla_simple{,_nested_1,_nested_2} [requires non-affine invariants]
                      # vla_single_loop_{1,2} [requires non-affine invariants]
                      # vla_single_loop_{3,4} [timeout]
                      # vla_midway_decl [multiple allocs]
                      # vla_in_loop_1 [requires non-affine invariants?]
                      # vla_in_loop_3 [sometimes timeout]
                      # vla_in_loop_4 [query timeout => timeout]
                      # rodata [requires non-affine invariants]
                      # vla_conditional_use [requires non-affine invariants]
                      # vla_in_loop_conditional_{continue,exit} [requires non-affine invariants]
                      # vla_2d [non-affine invariant required for 2D VLA strided traversal: reg == 4*i*(n+1)]
                      # vla_2_nested_loops [loop peeling leading to multiple stack allocations for inner VLA alloc]
                      # alloca_conditional_simple [fails sp-below-isp wfcond after fcall -- requires RPO DFA for more precise spvr]
                      # alloca_malloc_switch [requires more powerful inequality inference and RPO DFA]

#UNROLL1_ICX = alloca_linked_list $(UNROLL1_PROGS)
#UNROLL2_ICX = fib

# flags
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

C_STD = gnu11
include $(SRCDIR)/Makefile.template

cmds_normal_run: eqtest_i386_O3
	cat $^ > $@

cmds_pa_run: eqtest_pa_i386_O3
	cat $^ > $@

cmds_fa_run: eqtest_fa_i386_O3
	cat $^ > $@

cmds: cmds_normal_run cmds_pa_run cmds_fa_run
	cat $^ > $@

.PHONY: collect_csv
collect_csv: csv_eqcheck_normal_gcc_O3 csv_eqcheck_normal_clang_O3 csv_eqcheck_normal_icc_O3 csv_eqcheck_pa_gcc_O3 csv_eqcheck_pa_clang_O3 csv_eqcheck_pa_icc_O3 csv_eqcheck_fa_gcc_O3 csv_eqcheck_fa_clang_O3 csv_eqcheck_fa_icc_O3
	mv csv_eqcheck_normal_gcc_O3.csv lt_gcc.csv
	mv csv_eqcheck_normal_clang_O3.csv lt_clang.csv
	mv csv_eqcheck_normal_icc_O3.csv lt_icc.csv

clangv_Od: clangv_O1-
	cat $^ > $@
