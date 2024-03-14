include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/TSVC_new

EXTRA_FLAGS :=                                                                 \
               --global-timeout 7200                                           \
               --eqcheck-timeout 3600                                          \
               --max-address-space-size-gb 16                                  \
               #--disable-dst-to-src-submap # dst-to-src-submap incurs overhead

UNROLL8_GCC := s111 s1111 s113 s119 s124 s125 s128 s131 s132 s1421 s174 s2233 s311 s3111 s319 s421 s423 s441 s443 s471 va vbor
               # cannot pass: s1119 non-bisimilar, s2275 loop interchange, s231 loop interchange, s235 loop interchange, s317 non-linear invariant required, s331 non-linear invariant required
EXPECTED_FAILS_GCC :=             \
                      s174        \
                      vbor        \
                      # s174 [non-linear invariant required?]
                      # s441 [sometime query-timeouts]
                      # vbor [query-timeout]

UNROLL64_CLANG := s1119 s116 s119 s124 s125 s1279 s131 s132 s1421 s171 s174 s252 s254 s271 s2711 s2712 s273 s311 s3111 s319 s352 s421 s423 s471 va vbor vif
                  # cannot pass: s1115 non-bisimilar, s2233 loop interchange, s317 non-linear invariant required
EXPECTED_FAILS_CLANG :=           \
                        s124      \
                        s171      \
                        s174      \
                        s2711     \
                        s3111     \
                        s423      \
                        vbor      \
                        vif       \
                        # s124 [timeout]
                        # s171 [???]
                        # s174 [???]
                        # s2711 [query-timeout]
                        # s311 [sometimes query-timeout]
                        # s3111 [assert-fail in simplification; exceeds max iter count of 1024]
                        # s423 [???]
                        # vbor [query-timeout]
                        # vif [timeout]

UNROLL64_ICC := s1111 s1115 s113 s114 s1161 s119 s1213 s124 s125 s1279 s128 s131 s132 s1421 s174 s253 s254 s271 s2710 s2711 s2712 s272 s273 s274 s276 s293 s311 s3111 s319 s4115 s421 s423 s441 s442 s443 va vbor vif
EXPECTED_FAILS_ICC :=               \
                      s1111         \
                      s1115         \
                      s114          \
                      s1161         \
                      s1213         \
                      s1279         \
                      s1421         \
                      s174          \
                      s273          \
                      s276          \
                      s3111         \
                      s4115         \
                      s441          \
                      s442          \
                      s443          \
                      vbor          \
                      # s1111 [query-timeout]
                      # s1115 [timeout]
                      # s114 [timeout]
                      # s1161 [exceeds mem limit]
                      # s1213 [query-timeout]
                      # s1279 [query-timeout]
                      # s174 [timeout]
                      # s273 [query-timeout]
                      # s274 [sometimes query-timeout]
                      # s276 [query-timeout]
                      # s3111 [query-timeout]
                      # s4115 [timeout]
                      # s441 [query-timeout]
                      # s442 [timeout]
                      # s443 [query-timeout]
                      # vbor [query-timeout: due to path exprs?]

ICC_COMPILER_DEFINE := -Dicc_compiler

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O3
	cat $^ > $@

clangv_Od: clangv_O3
	cat $^ > $@
