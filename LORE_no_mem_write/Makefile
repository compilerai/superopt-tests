include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/LORE_no_mem_write

EXTRA_FLAGS :=                                                                 \
               --eqcheck-timeout 1800                                          \
               --global-timeout 3600                                           \
               --max-address-space-size-gb 16                                  \
               --disable-d2s # dst-to-src-submap incurs overhead

UNROLL4_GCC := ex1 ex2 ex3 ex4 ex5 ex6 ex8 ex9 ex10 ex11 ex12 ex13
UNROLL8_GCC := ex2u ex3u ex4u ex5u ex6u ex13u
EXPECTED_FAILS_GCC :=                                      \
                      # ex13u [sometimes query-timeout]

UNROLL16_CLANG := ex1 ex7 ex8 ex9 ex10 ex11 ex12
EXPECTED_FAILS_CLANG := ex1                                \
                        ex7                                \
                        ex8                                \
                        ex10                                \
                        # ex1 [???]
                        # ex7 [timeout]
                        # ex8 [timeout]
                        # ex9 [timeout]
                        # ex10 [sometimes global timeout]
                        # ex11 [sometimes timeout]

UNROLL8_ICC := ex7
EXPECTED_FAILS_ICC :=                                      \
                      ex7                                  \
                      # ex7 [assert-fail in simplification; max simplification iter counter reached]

UNROLL4_SRCDST := ex14 ex15 ex16 ex17
UNROLL8_SRCDST := ex15_8
EXPECTED_FAILS_SRCDST := ex15                              \
                         ex17                              \
                         # ex15 [???]
                         # ex17 [loop fusion????]

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O3 eqtest_srcdst
	cat $^ > $@

clangv_Od: clangv_O3
	cat $^ > $@
