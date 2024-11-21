include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/bzip2

# XXX the following are not used as of now
EXPECTED_FAILS_CLANG_O0 :=                                                                                             \
											     qSort3                                                                                      \
											     sendMTFValues

EXPECTED_FAILS_CLANG_O1 := $(EXPECTED_FAILS_CLANG)

EXPECTED_FAILS_CLANG_O2 :=                                                                                             \
                           generateMTFValues                                                                           \
                           getAndMoveToFrontDecode                                                                     \
                           getRLEpair                                                                                  \
                           hbCreateDecodeTables                                                                        \
                           hbMakeCodeLengths                                                                           \
                           loadAndRLEsource                                                                            \
                           main                                                                                        \
                           qSort3                                                                                      \
                           randomiseBlock                                                                              \
                           recvDecodingTables                                                                          \
                           sendMTFValues                                                                               \
                           simpleSort                                                                                  \
                           sortIt                                                                                      \
                           undoReversibleTransformation_fast                                                           \
                           undoReversibleTransformation_small                                                          \
                           # simpleSort [fails safety check due to query timeout]

EXPECTED_FAILS_CLANG_O3 :=                                                                                             \
                           getAndMoveToFrontDecode                                                                        \
                           getRLEpair                                                                                     \
                           hbMakeCodeLengths                                                                              \
                           main                                                                                           \
                           qSort3                                                                                         \
                           sendMTFValues                                                                                  \
                           simpleSort                                                                                     \
                           sortIt                                                                                         \
                           undoReversibleTransformation_small                                                             \
													 
EXPECTED_FAILS_CLANG := $(EXPECTED_FAILS_CLANG_O0)

EXPECTED_FAILS_CLANGV :=                                                                                               \
                         hbMakeCodeLengths                                                                             \
                         qSort3                                                                                        \
                         sendMTFValues                                                                                 \
                         sortIt                                                                                        \

UNROLL1 := bzip2
UNROLL1_CLANG = $(UNROLL1)
# UNROLL2 := bzip2
# UNROLL2_CLANG = $(UNROLL2)

EXTRA_FLAGS :=        --smt-query-timeout 180 --global-timeout 28800 --max-address-space-size-gb 32                    \
                      --disable-removal-of-stack-from-stack-nonstack-ml-in-dst                                         
                      #--enable-query-decomposition                                                                     \
                      # --disable-dst-to-src-submap

EXTRA_FLAGS_CLANGV := --smt-query-timeout 180 --global-timeout 28800 --max-address-space-size-gb 32                    \
                      --disable-removal-of-stack-from-stack-nonstack-ml-in-dst                                         
                      #--enable-query-decomposition                                                                     \
                      # --disable-dst-to-src-submap

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(GCC_EQCHECKER_NOUNROLL_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

cmds: clangv_O0 # clangv_O1- eqtest_i386_O1 eqtest_i386_O2 
	cat $^ > $@
