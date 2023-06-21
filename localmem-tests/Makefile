include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/localmem-tests

EXTRA_FLAGS := --smt-query-timeout 300 --global-timeout 7200

UNROLL1_PROGS := \
                 addr_taken_array             		 \
                 addr_taken_array_in_loop     		 \
                 addr_taken_conditional       		 \
                 addr_taken_simple            		 \
                 variadic_with_loop           		 \
                 alloca_conditional           		 \
                 alloca_simple                		 \
                 rodata                            \
                 vla_conditional_use          		 \
                 vla_2_inside_loop            		 \
                 vla_simple_loop              		 \
                 vla_2_single_loop                 \
                 #vla_1_inside_loop            		 \
                 #variadic_acyclic                  \
                 #local_used_in_unreachable_loop    \
                 #local_used_on_unreachable_branch  \
                 #vla_3_inside_loop            		 \
                 #vla_4_inside_loop            		 \
                 #vla_3_single_loop                 \
                 #vla_4_single_loop                 \
                 #alloca_linked_list2               \
                 # #vla_midway_decl                   \
                 # #vla_2_nested_loops                \
                 # #vla_2d                            \
                 # #minscanf                     # gcc eqgen fails
                 # #arg_addr_taken               # eqgen fails
								 # # should pass: vla_{3,4}_single_loop.{gcc,clang} (query-timeout), vla_3_inside_loop.icc (query-timeout)

UNROLL1_GCC = fib                               \
              alloca_malloc_switch              \
              vla_in_loop                       \
              vla_in_loop_conditional_continue  \
              vla_in_loop_conditional_exit      \
              $(UNROLL1_PROGS)
							# minprintf requires select(local.addr) which is missing from bv-eqclass exprs
UNROLL2_GCC = alloca_linked_list
EXPECTED_FAILS_GCC := vla_3_single_loop         \
                      vla_4_single_loop         \
                      # vla_3_single_loop [timeout]
                      # vla_4_single_loop [timeout]

UNROLL1_CLANG = minprintf                         \
                alloca_linked_list                \
                alloca_malloc_switch              \
                vla_in_loop                       \
                vla_in_loop_conditional_continue  \
                vla_in_loop_conditional_exit      \
                $(UNROLL1_PROGS)
UNROLL2_CLANG = fib
EXPECTED_FAILS_CLANG := vla_3_single_loop         \
                        vla_4_single_loop         \
                        # vla_3_single_loop [timeout]
                        # vla_4_single_loop [timeout]

# ack does not support VLA and alloca()
UNROLL2_ACK = \
							addr_taken_simple         \
							addr_taken_array          \
							addr_taken_array_in_loop  \
							addr_taken_conditional    \
							variadic_acyclic          \
							# variadic_with_loop  requires select(local.addr) which is missing from bv-eqclass exprs
							# minprintf -- harvested assembly is incorrect; looks like switch is implemented using jump table
EXTRA_FLAGS_ACK := --disable-fcall-wfconds

UNROLL1_ICC = minprintf                \
              fib                     \
              $(UNROLL1_PROGS)
              # vla_in_loop{,conditional_continue,conditional_exit} require non-linear invariants
              # alloca_malloc_switch requires more powerful inequality inference
UNROLL2_ICC = alloca_linked_list
EXPECTED_FAILS_ICC := vla_3_inside_loop         \
                      # vla_3_inside_loop [timeout]

#UNROLL1_ICX = alloca_linked_list $(UNROLL1_PROGS)
#UNROLL2_ICX = fib

# flags
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

C_STD = gnu11
include $(SRCDIR)/Makefile.template

test_i386: eqtest_i386_O3
	cat $^ > $@

clangv_Od: clangv_O1
	cat $^ > $@
