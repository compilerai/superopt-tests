include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/TSVC_prior_work_globals
EXTRA_FLAGS :=                                                           \
                --smt-query-timeout 30                                   \
                --global-timeout 14400                                   \
                --eqcheck-timeout 7200                                   \
                --enable-query-decomposition                             \
                --qd-smt-query-timeout 5                                 \
                --disable-removal-of-stack-from-stack-nonstack-ml-in-dst \
                --no-strengthen-mae
                #--disable-dst-to-src-submap                              \

UNROLL64_GCC := # s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s162 s173 s2244 s243 s251 s3251 s351 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vtvtv vpvts
UNROLL64_CLANG := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s162 s173 s2244 s243 s251 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vtvtv vpvts
UNROLL64_ICC := # s000 s112 s122 s1251 s127 s1281 s1351 s173 s2244 s251 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vpvts

EXPECTED_FAILS_CLANG :=                                                  \
                        s1211                                            \
                        s1251                                            \
                        s1351                                            \
                        s173                                             \
                        s2244                                            \
                        sum1d                                            \
                        vpv                                              \
                        vpvts                                            \
                        vtv                                              \
                        # s1251 [timeout]
                        # s173 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # s2244 [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # sum1d [timeout]
                        # vpv [eqcheck timeout -- CE based pruning is apparently being ineffective?]
                        # vpvts [query-timeout -> QD invoked -> timeout]
                        # vtv [query-timeout -> QD invoked -> timeout]

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

C_STD = gnu11
include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O3
	cat $^ > $@

clangv_Od: clangv_O3
	cat $^ > $@
