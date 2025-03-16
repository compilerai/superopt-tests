include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/TSVC_new_locals
EXTRA_FLAGS = --smt-query-timeout 30 --global-timeout 7200

UNROLL64_GCC_O3 := s111 s1111 s113 s119 s124 s125 s128 s131 s132 s1421 s174 s2233 s311 s3111 s319 s421 s423 s441 s443 s471 va

UNROLL64_CLANG_O3 := s1119 s116 s119 s124 s125 s1279 s131 s171 s252 s254 s271 s2711 s2712 s273 s311 s319 s352 va
# CLANG PROGS THAT SHOULD PASS AFTER CORREL ALGO UPDATE -- s423, s421 (both s421 and s423 same issue), s1421 (non zero bv rank), s174, s3111, s471
# CLANG PROGS WHERE LOOP IS ELIMINATED -- s132  # increasing LEN2 might help?

UNROLL64_ICC_O3 := # s119 s124 s125 s1279 s128 s132 s253 s254 s271 s2711 s2712 s272 s274 s276 s293 s311 s319 s4115 s441 s443 va vif
# ICC PROGS NOT PASSING AFTER VERSION CHANGE -- vbor (due to path exprs), s2710, s442, s3111 s131, s1111, s423(should pass), s113, s273, s114 (should pass), s1421(should pass), s1161, s174(should pass), s1213, s421 (should pass), s1115 (Query timeout  - Should pass),

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

C_STD = gnu11
include $(SRCDIR)/Makefile.template
