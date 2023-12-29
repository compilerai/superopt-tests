include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/localmem-tests

EXTRA_FLAGS := --smt-query-timeout 120                                         \
               --global-timeout 7200                                           \
               --enable-query-decomposition                                    \
               --disable-removal-of-stack-from-stack-nonstack-ml-in-dst        \

UNROLL1_PROGS :=                                                               \
                 ata                                                           \
                 atc                                                           \
                 ats                                                           \
                 atail                                                         \
                                                                               \
                 vwl                                                           \
                                                                               \
                 vcu                                                           \
                 vsl                                                           \
                 vil                                                           \
                 vilcc                                                         \
                 vilce                                                         \
                 v2il                                                          \
                 vilN                                                          \
                                                                               \
                 as                                                            \
                 ac                                                            \
                                                                               \
                 min                                                           \
                 rod                                                           \

UNROLL1_GCC := fib                                                             \
               $(UNROLL1_PROGS)                                                \

UNROLL2_GCC := all                

UNROLL1_CLANG := all                                                           \
                 $(UNROLL1_PROGS)                                              \

UNROLL2_CLANG := fib                                                           \

UNROLL1_ICC = fib                                                              \
              $(UNROLL1_PROGS)                                                 \

UNROLL2_ICC = all

# flags
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

C_STD = gnu11
include $(SRCDIR)/Makefile.template

cmds_normal_run: eqtest_i386_O3
	cat $^ > $@

cmds_slow_run: eqtest_slow_i386_O3
	cat $^ > $@

cmds: cmds_normal_run cmds_slow_run
	cat $^ > $@

.PHONY: collect_csv
collect_csv: csv_eqcheck_normal_gcc_O3 csv_eqcheck_normal_clang_O3 csv_eqcheck_normal_icc_O3 csv_eqcheck_slow_gcc_O3 csv_eqcheck_slow_clang_O3 csv_eqcheck_slow_icc_O3
	mv csv_eqcheck_normal_gcc_O3.csv lt_gcc.csv
	mv csv_eqcheck_normal_clang_O3.csv lt_clang.csv
	mv csv_eqcheck_normal_icc_O3.csv lt_icc.csv

	mv csv_eqcheck_slow_gcc_O3.csv lt_gcc_s.csv
	mv csv_eqcheck_slow_clang_O3.csv lt_clang_s.csv
	mv csv_eqcheck_slow_icc_O3.csv lt_icc_s.csv
