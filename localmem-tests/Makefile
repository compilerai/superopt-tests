include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/localmem-tests

EXTRA_FLAGS := --smt-query-timeout 120                                         \
               --global-timeout 7200                                           \
               --enable-query-decomposition                                    \
               --disable-removal-of-stack-from-stack-nonstack-ml-in-dst        \
               --encode-avail-exprs-in-smt-queries

UNROLL1_PROGS :=                                                               \
                 addr_taken_simple                                             \
                 addr_taken_conditional                                        \
                 addr_taken_array                                              \
                 addr_taken_array_3                                            \
                 addr_taken_array_in_loop                                      \
                                                                               \
                 variadic_acyclic                                              \
                 variadic_with_loop                                            \
                                                                               \
                 vla_simple                                                    \
                 vla_conditional_use                                           \
                 vla_midway_decl                                               \
                 vla_single_loop                                               \
                 vla_2_single_loop                                             \
                 vla_2_nested_loops                                            \
                 vla_in_loop                                                   \
                 vla_in_loop_conditional_continue                              \
                 vla_in_loop_conditional_exit                                  \
                 vla_2_in_loop                                                 \
                 vla_3_in_loop                                                 \
                 vla_2d                                                        \
                 vla_3_single_loop                                             \
                 vla_4_single_loop                                             \
                 vla_4_in_loop                                                 \
                                                                               \
                 alloca_simple                                                 \
                 alloca_conditional                                            \
                 alloca_conditional_simple                                     \
                 alloca_malloc_switch                                          \
                 alloca_unreal                                                 \
                                                                               \
                 minprintf                                                     \
                 minscanf                                                      \
                 rodata                                                        \
                                                                               \
                 # fib                [u2]                                     \
                 # alloca_linked_list [u2]                                     \
                 #                                                             \
                 # vla_3_single_loop  [timeout?]                               \
                 # vla_4_single_loop  [timeout?]                               \

UNROLL1_GCC := fib                                                             \
               fib_paper                                                       \
               $(UNROLL1_PROGS)                                                \

UNROLL2_GCC := alloca_linked_list

EXPECTED_FAILS_GCC := vla_3_single_loop                                        \
                      vla_2_in_loop                                            \
                      vla_3_in_loop                                            \
                      vla_4_in_loop                                            \
                      vla_4_single_loop                                        \
                      vla_2_single_loop                                        \
                      vla_single_loop                                          \
                      vla_2_nested_loops                                       \
                      vla_2d                                                   \
                      minprintf                                                \
                      minscanf                                                 \
                      alloca_malloc_switch                                     \
                      alloca_conditional                                       \
                      vla_conditional_use                                      \
                      # vla_3_single_loop [timeout]
                      # vla_2_in_loop [requires invariant (i < n) on loop body PCs / suffixpath]
                      # vla_3_in_loop [requires invariant (i < n) on loop body PCs / suffixpath]
                      # vla_4_in_loop [requires invariant (i < n) on loop body PCs / suffixpath]
                      # vla_4_single_loop [timeout]
                      # vla_2_single_loop [missing non-affine invariant relating sp decrement offset value 'eax' with n]
                      # vla_single_loop   [dealloc path correlation failing: sinking (code merging) of sp restore (dealloc) to common path instead of alloc dominating path, no coresponding path in src]
                      # vla_2_nested_loops [some bitwise computation is happening -- local-mem-eq is failing]
                      # vla_2d [mem-eq query timeout]
                      # minprintf,minscanf [requires select(local.addr) which is missing from bv-eqclass exprs]
                      # alloca_malloc_switch [fails stack-dealloc wfcond -- requires RPO DFA for more precise spvr]
                      # alloca_conditional [requires invariant (i < n) on loop body PCs / suffixpath]
                      # vla_conditional_use [times-out somtimes because the invariant inference DFA does not proceed in RPO i.e. it tries relaxing an edge before relaxing all its predecessors]

UNROLL1_CLANG := alloca_linked_list                                            \
                 $(UNROLL1_PROGS)                                              \

UNROLL2_CLANG := fib                                                           \
                 fib_paper

EXPECTED_FAILS_CLANG := vla_3_single_loop                                      \
                        vla_4_single_loop                                      \
                        vla_2_single_loop                                      \
                        vla_2_in_loop                                          \
                        vla_4_in_loop                                          \
                        vla_2d                                                 \
                        vla_2_nested_loops                                     \
                        variadic_acyclic                                       \
                        alloca_malloc_switch                                   \
                        alloca_conditional_simple                              \
                        # vla_3_single_loop [timeout]
                        # vla_4_single_loop [timeout]
                        # vla_2_single_loop [missing non-affine invariant relating sp decrement offset value 'eax' with n]
                        # vla_2_in_loop [requires invariant (i < n) on loop body PCs / suffixpath]
                        # vla_4_in_loop [query timeout => timeout]
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
                      vla_single_loop                                          \
                      vla_midway_decl                                          \
                      vla_2_single_loop                                        \
                      vla_3_single_loop                                        \
                      vla_4_single_loop                                        \
                      vla_3_in_loop                                            \
                      vla_conditional_use                                      \
                      vla_in_loop                                              \
                      vla_in_loop_conditional_continue                         \
                      vla_in_loop_conditional_exit                             \
                      vla_4_in_loop                                            \
                      vla_2d                                                   \
                      vla_2_nested_loops                                       \
                      rodata                                                   \
                      alloca_conditional_simple                                \
                      alloca_malloc_switch                                     \
                      # vla_simple{,_nested_1,_nested_2} [requires non-affine invariants]
                      # vla{,_2,}_single_loop [requires non-affine invariants]
                      # vla_midway_decl [multiple allocs]
                      # vla{_3,_4}_single_loop [timeout]
                      # vla_3_in_loop [sometimes timeout]
                      # rodata [requires non-affine invariants]
                      # vla_conditional_use [requires non-affine invariants]
                      # vla_in_loop [requires non-affine invariants?]
                      # vla_in_loop_conditional_{continue,exit} [requires non-affine invariants]
                      # vla_4_in_loop [query timeout => timeout]
                      # vla_2d [non-affine invariant required for 2D VLA strided traversal: reg == 4*i*(n+1)]
                      # vla_2_nested_loops [loop peeling leading to multiple stack allocations for inner VLA alloc]
                      # alloca_conditional_simple [fails stack-dealloc wfcond -- requires RPO DFA for more precise spvr]
                      # alloca_malloc_switch [requires more powerful inequality inference and RPO DFA]

#UNROLL1_ICX = alloca_linked_list $(UNROLL1_PROGS)
#UNROLL2_ICX = fib

# flags
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

C_STD = gnu11
include $(SRCDIR)/Makefile.template

test_i386: eqtest_i386_O3
	cat $^ > $@

clangv_Od: clangv_O1-
	cat $^ > $@
