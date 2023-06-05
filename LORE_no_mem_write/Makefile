include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/LORE_no_mem_write

EXTRA_FLAGS := --global-timeout 1200 --max-address-space-size-gb 16 --disable-dst-to-src-submap # dst-to-src-submap incurs overhead

UNROLL4_GCC := ex1 ex2 ex3 ex4 ex5 ex6 ex8 ex9 ex10 ex11 ex12 ex13
UNROLL8_GCC := ex2u ex3u ex4u ex5u ex6u ex13u # should pass: ex13u (query-timeout)
EXPECTED_FAILS_GCC := ex13u     \
                      # ex13u [query-timeout]

UNROLL16_CLANG := ex1 ex7 ex8 ex9 ex10 ex11 ex12 # should pass: ex1 (???), ex7 (timeout), ex8 (timeout), ex9 (timeout), ex11 (sometimes timeout)
EXPECTED_FAILS_CLANG := ex1     \
                        ex7     \
                        ex8     \
                        # ex1 [???]
                        # ex7 [timeout]
                        # ex8 [timeout]

UNROLL8_ICC := ex7 # should pass: ex7 (assert-fails in simplification; max simplification iter count reached)
EXPECTED_FAILS_ICC := ex7 \
                      # ex7 [assert-fail in simplification; max simplification iter counter reached]

UNROLL4_SRCDST := ex14 ex15 ex16 ex17 # should pass: ex15 (???), ex17 (loop fusion?)
UNROLL8_SRCDST := ex15_8
EXPECTED_FAILS_SRCDST := ex15     \
                         ex17     \
                         # ex15 [???]
                         # ex17 [???]

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

include $(SRCDIR)/Makefile.template

test_i386: eqtest_i386_O3 eqtest_srcdst
	cat $^ > $@

clangv_Od: clangv_O3
	cat $^ > $@
