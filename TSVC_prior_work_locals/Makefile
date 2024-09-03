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

UNROLL64_GCC := # s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s162 s173 s2244 s243 s251 s3251 s351 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vtvtv vpvts
UNROLL64_CLANG := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s162 s173 s2244 s243 s251 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vtvtv vpvts
UNROLL64_ICC := # s000 s112 s122 s1251 s127 s1281 s1351 s173 s2244 s251 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vpvts

EXPECTED_FAILS_CLANG :=                                    \
                        s1221                              \
                        s1251                              \
                        s1281                              \
                        s251                               \
                        sum1d                              \
                        vdotr                              \
                        vpv                                \
                        vpvpv                              \
                        vpvts                              \
                        vtv                                \
                        # s1221  [query-timeout -> QD invoked -> timeout]
                        # s1221 [sometimes query-timeout?]
                        # s1251 [query-timeout -> QD invoked -> timeout]
                        # s1281 [query-timeout -> QD invoked -> timeout]
                        # s251   [query-timeout -> QD invoked -> timeout]
                        # sum1d [timeout -- d2s_state_update takes >90% of total time]
                        # vdotr [global timeout]
                        # vpv    [query-timeout -> QD invoked -> timeout]
                        # vpvpv  [query-timeout -> QD invoked -> timeout]
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
