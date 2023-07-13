include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/localmem-tests

EXTRA_FLAGS := --smt-query-timeout 120                                         \
               --global-timeout 7200                                           \
               --enable-query-decomposition                                    \
               --disable-removal-of-stack-from-stack-nonstack-ml-in-dst        \

UNROLL1_PROGS :=                                                               \
                 addr_taken_simple                                             \
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
                 local_used_in_unreachable_loop                                \
                 local_used_on_unreachable_branch                              \
                                                                               \
                 # fib                [u2]                                     \
                 # alloca_linked_list [u2]                                     \
                 #                                                             \
                 # vla_3_single_loop  [timeout?]                               \
                 # vla_4_single_loop  [timeout?]                               \
                 # vla_4_in_loop      [timeout?]                               \

UNROLL1_GCC := fib                                                             \
               $(UNROLL1_PROGS)                                                \

UNROLL2_GCC := alloca_linked_list

EXPECTED_FAILS_GCC := vla_3_single_loop                                        \
                      vla_4_single_loop                                        \
                      vla_2_single_loop                                        \
                      vla_single_loop                                          \
                      vla_conditional_use                                      \
                      minprintf                                                \
                      alloca_malloc_switch                                     \
                      # vla_3_single_loop [timeout]
                      # vla_4_single_loop [timeout]
                      # vla_2_single_loop [missing non-linear invariant relating sp decrement offset value 'eax' with n]
                      # vla_single_loop   [dealloc path correlation failing: sinking (code merging) of sp restore (dealloc) to common path instead of alloc dominating path, no coresponding path in src]
                      # vla_conditional_use [BV timeouts on dealloc edge -- getting spurious live registers and slots]
                      # minprintf requires select(local.addr) which is missing from bv-eqclass exprs
                      #  alloca_malloc_switch [requires RPO DFA]

UNROLL1_CLANG := alloca_linked_list                                            \
                 $(UNROLL1_PROGS)                                              \

UNROLL2_CLANG := fib

EXPECTED_FAILS_CLANG := vla_3_single_loop                                      \
                        vla_4_single_loop                                      \
                        vla_2_single_loop                                      \
                        alloca_malloc_switch                                   \
                        # vla_3_single_loop [timeout]
                        # vla_4_single_loop [timeout]
                        # vla_2_single_loop [missing non-linear invariant relating sp decrement offset value 'eax' with n]
                        #  alloca_malloc_switch [requires RPO DFA]

# ack does not support VLA and alloca()
UNROLL2_ACK = addr_taken_simple                                                \
              addr_taken_array                                                 \
              addr_taken_array_in_loop                                         \
              addr_taken_conditional                                           \
              variadic_acyclic                                                 \
              # variadic_with_loop  requires select(local.addr) which is missing from bv-eqclass exprs
              # minprintf -- harvested assembly is incorrect; looks like switch is implemented using jump table
EXTRA_FLAGS_ACK := --disable-fcall-wfconds

UNROLL1_ICC = $(UNROLL1_PROGS)                                                 \
              # fib [requires non-linear invariants]

UNROLL2_ICC = alloca_linked_list

EXPECTED_FAILS_ICC := vla_3_in_loop                                            \
                      alloca_conditional_simple                                \
                      vla_simple                                               \
                      vla_single_loop                                          \
                      rodata                                                   \
                      vla_conditional_use                                      \
                      vla_in_loop_conditional_continue                         \
                      alloca_malloc_switch                                     \
                      # vla_3_in_loop [timeout]
                      # alloca_conditional_simple [requires RPO DFA]
                      # vla_simple [requires non-linear invariants]
                      # vla_simple_loop [requires non-linear invariants]
                      # rodata [requires non-linear invariants]
                      # vla_conditional_use [requires non-linear invariants]
                      # vla_in_loop_conditional_{continue,exit} [requires non-linear invariants]
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
