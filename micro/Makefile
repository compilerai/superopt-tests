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
EXPECTED_FAILS_GCC := non_linear_invariant_casting  \
                      ftmap_1                       \
                      ftmap_2                       \
                      ftmap_3                       \
                      ftmap_4                       \
                      fcalls_merge                  \
                      nested_loops                  \
										 	sum_positive
                      # non_linear_invariant_casting [requires: pointer arithmetic overflow UB modelling and non-linear invariant]
                      # ftmap_1 [eqgen fails because of incorrect disassembly]
                      # ftmap_2 [harvest output does not include function main]
                      # ftmap_3 [harvest output does not include function main]
                      # ftmap_4 [harvest output does not include function main]
                      # fcalls_merge [calls to bar() are sinked and merged]
                      # nested_loops [requires invariant (m > 0) in due to unswitching of inner loop condition]
											# sum_positive [requires: pointer arithmetic overflow UB modelling]
											# sum2d [requires: pointer arithmetic overflow UB modelling]

UNROLL16_CLANG := $(PROGS) \
                  load_store_elim_conditional
EXPECTED_FAILS_CLANG := ftmap_3                     \
                        ftmap_4                     \
										 	  sum_positive # [requires: pointer arithmetic overflow UB modelling]
                        # ftmap_3 [harvest output does not include function main]
                        # ftmap_4 [harvest output does not include function main]

UNROLL1_SRCDST := inequiv_1 \
	                inequiv_2 \
	                nestedLoop \
	                ifswitch

UNROLL4_SRCDST := nested_loop_peeling \
	                nested_loop_unrolling \
	                strlen \
	                bitflip \
	                loopSplitting \
	                # epsilon_corr

UNROLL8_SRCDST := strlen \

EXPECTED_FAILS_SRCDST := inequiv_1 inequiv_2

# compiler flags
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

test_i386: eqtest_i386_O3 eqtest_srcdst
	cat $^ > $@

clangv_Od: clangv_O1
	cat $^ > $@
