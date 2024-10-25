include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/TSVC_prior_work

EXTRA_FLAGS :=                                                                 \
               --global-timeout 7200                                           \
               --eqcheck-timeout 3600                                          \
               --max-address-space-size-gb 16
               #--disable-d2s # dst-to-src-submap incurs overhead

UNROLL8_GCC := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s173 s2244 s243 s251 s3251 s351 s452 s453 sum1d vdotr vpv vpvpv vpvts vpvtv vtv vtvtv
               # cannot pass: s176 (non-bisimilar -- outer loop and inner loop collapse twice), s162 (non-linear invariant required: ecx == ((LEN-k)/4)*16)

EXPECTED_FAILS_GCC :=          \
	                    s122     \
	                    s122     \
	                    # s122 [???]

UNROLL64_CLANG := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s162 s173 s176 s2244 s243 s251 s3251 s351 s452 s453 sum1d vdotr vpv vpvpv vpvts vpvtv vtv vtvtv
EXPECTED_FAILS_CLANG :=          \
                        s162     \
                        s176     \
                        sum1d    \
                        # s162 [???]
                        # s176 [query timeout]
                        # sum1d [fails safety check -- needs debugging]
                        # vdotr [sometimes query timeouts]
                        # vpvts [sometimes query timeouts]
                        # vtv [sometimes query timeouts]

UNROLL16_ICC := s000 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s173 s176 s2244 s251 s3251 s452 s453 sum1d vdotr vpv vpvpv vpvts vpvtv vtv vtvtv # should pass: s1251 (query-timeout), s176 (???), s3251 (query timeout), vtvtv (query-timeout), vtv (query-timeout)
                # cannot pass: s1112 (loop reversal with mem write), s243 (loop splitting -- can do similar function without mem write), s162 (non-linear invariant required: edi == (LEN-k)&(~15))
EXPECTED_FAILS_ICC :=           \
                      s1251     \
                      s127      \
                      s176      \
                      s2244     \
                      s251      \
                      s3251     \
                      vdotr     \
                      vpvtv     \
                      vtvtv     \
                      # s1251 [query timeout]
                      # s127 [query-timeout?]
                      # s1281 [query-timeout?]
                      # s176 [???]
                      # s2244 [timeout?]
                      # s251  [query timeout]
                      # s3251 [query timeout]
                      # s452 [query timeout???]
                      # vdotr [query timeout]
                      # vpvts [query timeout???]
                      # vpvtv [timeout?]
                      # vtv [sometimes query timeout?]
                      # vtvtv [query timeout]

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O3
	cat $^ > $@

clangv_Od: clangv_O3
	cat $^ > $@
