include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/TSVC_prior_work

EXTRA_FLAGS := --global-timeout 3600 --max-address-space-size-gb 16 --disable-dst-to-src-submap # dst-to-src-submap incurs overhead

UNROLL8_GCC := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s173 s2244 s243 s251 s3251 s351 s452 s453 sum1d vdotr vpv vpvpv vpvts vpvtv vtv vtvtv
               # cannot pass: s176 (non-bisimilar -- outer loop and inner loop collapse twice), s162 (non-linear invariant required: ecx == ((LEN-k)/4)*16)

UNROLL64_CLANG := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s162 s173 s176 s2244 s243 s251 s3251 s351 s452 s453 sum1d vdotr vpv vpvpv vpvts vpvtv vtv vtvtv # should pass: s176 (high-mem), s162 (query-timeout)
EXPECTED_FAILS_CLANG := s162     \
                        # s162 [???]

UNROLL16_ICC := s000 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s173 s176 s2244 s251 s3251 s452 s453 sum1d vdotr vpv vpvpv vpvts vpvtv vtv vtvtv # should pass: s1251 (query-timeout), s176 (???), s3251 (query timeout), vtvtv (query-timeout), vtv (query-timeout)
                # cannot pass: s1112 (loop reversal with mem write), s243 (loop splitting -- can do similar function without mem write), s162 (non-linear invariant required: edi == (LEN-k)&(~15))
EXPECTED_FAILS_ICC := vtvtv     \
                      s1251     \
                      s3251     \
                      vtv       \
                      s176      \
                      # vtvtv [query timeout]
                      # s1251 [query timeout]
                      # s3251 [query timeout]
                      # vtv [query timeout]
                      # s176 [???]

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

include $(SRCDIR)/Makefile.template

test: eqtest_i386_O3
	cat $^ > $@
