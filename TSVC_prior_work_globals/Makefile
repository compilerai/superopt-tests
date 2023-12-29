include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/TSVC_prior_work_globals
EXTRA_FLAGS :=                                                           \
                --smt-query-timeout 30                                   \
                --global-timeout 7200                                    \
                --enable-query-decomposition                             \
                --qd-smt-query-timeout 5                                 \
                --disable-removal-of-stack-from-stack-nonstack-ml-in-dst \
                --disable-dst-to-src-submap                              \
                --no-strengthen-mae                                      \

UNROLL64_CLANG := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s173 s2244 s243 s251 s452 s453 vdotr vpv vpvpv vpvtv vtv vtvtv vpvts

# compiler flags
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

C_STD = gnu11
include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O3
	cat $^ > $@
