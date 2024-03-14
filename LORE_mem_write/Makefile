include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/LORE_mem_write

EXTRA_FLAGS :=                                                                 \
               --eqcheck-timeout 1200                                          \
               --global-timeout 3600                                           \
               --max-address-space-size-gb 16                                  \
               --disable-dst-to-src-submap # dst-to-src-submap incurs overhead

UNROLL4_GCC := ex101 ex102 ex103 ex104 ex105 ex106 ex107 ex108
UNROLL8_GCC := ex106u ex107u
EXPECTED_FAILS_GCC := \
                      # ex107 [sometimes query-timeout]
                      # ex107u [sometimes query-timeout]

UNROLL16_CLANG := ex101 ex102 ex103 ex104 ex105 ex108
                  # not tested: ex106 ex107
EXPECTED_FAILS_CLANG :=                                    \
												ex105                              \
                        ex108                              \
                        # ex105 [timeout]
                        # ex108 [sometimes timeout]

UNROLL8_SRCDST := ex109 ex109_8 ex1010 ex1011

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(VEC_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: eqtest_i386_O3 eqtest_srcdst
	cat $^ > $@

clangv_Od: clangv_O3
	cat $^ > $@
