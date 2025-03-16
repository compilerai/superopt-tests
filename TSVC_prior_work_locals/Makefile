include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/TSVC_prior_work_locals
EXTRA_FLAGS :=                                                                 \
               --smt-query-timeout 60                                          \
               --global-timeout 14400                                          \
               --eqcheck-timeout 7200                                          \
               --enable-query-decomposition                                    \
               --qd-smt-query-timeout 15                                       \
               --disable-removal-of-stack-from-stack-nonstack-ml-in-dst
               #--disable-dst-to-src-submap                                     \

UNROLL64_GCC_O3 := # s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s162 s173 s2244 s243 s251 s3251 s351 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vtvtv vpvts
UNROLL64_CLANG_O3 := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s162 s173 s2244 s243 s251 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vtvtv vpvts
UNROLL64_ICC_O3 := # s000 s112 s122 s1251 s127 s1281 s1351 s173 s2244 s251 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vpvts

EXPECTED_FAILS_CLANG :=                                    \
                        sum1d                              \
                        # s000 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s1112 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s112 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s121 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s1221 [sometimes query-timeout?]
                        # s1251 [query-timeout -> QD invoked -> timeout]
                        # s1281 [sometimes query-timeout?]
                        # s1351 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s162 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s173 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s2244 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s243 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s251   [sometimes query-timeout?]
                        # s452 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s453 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # sum1d [timeout -- d2s_state_update takes >90% of total time]
                        # vdotr [global timeout]
                        # vpv    [query-timeout -> QD invoked -> timeout]
                        # vpvpv  [sometimes query-timeout?]
                        # vpvts  [query-timeout -> QD invoked -> timeout]
                        # vtv    [query-timeout -> QD invoked -> timeout]
# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

C_STD = gnu11
include $(SRCDIR)/Makefile.template

cmds_pa_run:: eqtest_pa_i386_O3
	cat $^ > $@

cmds_normal_run:: eqtest_i386_O3
	cat $^ > $@

cmds: cmds_normal_run # cmds_pa_run
	cat $^ > $@

clangv_Od: clangv_O3
	cat $^ > $@
