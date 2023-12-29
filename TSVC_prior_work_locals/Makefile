include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/TSVC_prior_work_locals
EXTRA_FLAGS :=                                                                 \
               --smt-query-timeout 60                                          \
               --global-timeout 7200                                           \
               --enable-query-decomposition                                    \
               --qd-smt-query-timeout 15                                       \
               --disable-dst-to-src-submap                                     \
               --disable-removal-of-stack-from-stack-nonstack-ml-in-dst        \

UNROLL64_CLANG := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s173 s2244 s243 s251 s452 s453 vdotr vpv vpvpv vpvtv vtv vtvtv vpvts

EXPECTED_FAILS_CLANG :=                                    \
                        # s1221 [sometimes query-timeout?]
# compiler flags
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

C_STD = gnu11
include $(SRCDIR)/Makefile.template

cmds_normal_run: eqtest_i386_O3
	cat $^ > $@

cmds_slow_run: eqtest_slow_i386_O3
	cat $^ > $@

cmds: cmds_normal_run cmds_slow_run
	cat $^ > $@

.PHONY: collect_csv
collect_csv: csv_eqcheck_normal_clang_O3 csv_eqcheck_slow_clang_O3
	mv csv_eqcheck_normal_clang_O3.csv tsvc_l.csv
	mv csv_eqcheck_slow_clang_O3.csv tsvc_l_s.csv
