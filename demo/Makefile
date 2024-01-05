include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/demo

EXTRA_FLAGS := --smt-query-timeout 60 --global-timeout 7200 --max-address-space-size-gb 32 --disable-dst-to-src-submap

PROGS := sample

UNROLL4_GCC := $(PROGS)

UNROLL4_CLANG := $(PROGS)

# UNROLL4_ICC = $(PROGS)

# compiler flags
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

cmds_normal_run: eqtest_i386_O3
	cat $^ > $@

cmds_slow_run: eqtest_slow_i386_O3
	cat $^ > $@

cmds: cmds_normal_run # cmds_slow_run
	cat $^ > $@

.PHONY: collect_csv
collect_csv: csv_eqcheck_normal_gcc_O3 csv_eqcheck_normal_clang_O3 # csv_eqcheck_normal_icc_O3 csv_eqcheck_slow_gcc_O3 csv_eqcheck_slow_clang_O3 csv_eqcheck_slow_icc_O3
	mv csv_eqcheck_normal_gcc_O3.csv demo_gcc.csv
	mv csv_eqcheck_normal_clang_O3.csv demo_clang.csv
	# mv csv_eqcheck_normal_icc_O3.csv demo_icc.csv

	# mv csv_eqcheck_slow_gcc_O3.csv demo_gcc_s.csv
	# mv csv_eqcheck_slow_clang_O3.csv demo_clang_s.csv
	# mv csv_eqcheck_slow_icc_O3.csv demo_icc_s.csv
