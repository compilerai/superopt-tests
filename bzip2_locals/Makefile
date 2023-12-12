include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/bzip2_locals

UNROLL2 := bzip2_locals \

EXPECTED_FAILS_CLANG :=                                    \
                        hbMakeCodeLengths                  \
                        main                               \
                        sendMTFValues                      \
                        getAndMoveToFrontDecode            \
                        getRLEpair                         \
                        qSort3                             \
                        simpleSort                         \
                        sortIt                             \
                        undoReversibleTransformation_small \

UNROLL2_CLANG = $(UNROLL2)

EXTRA_FLAGS := --smt-query-timeout 180 --global-timeout 28800 --max-address-space-size-gb 32 --disable-removal-of-stack-from-stack-nonstack-ml-in-dst --enable-query-decomposition

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(GCC_EQCHECKER_NOUNROLL_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

test_i386: clangv_O1- eqtest_i386_O1 eqtest_i386_O2 
	cat $^ > $@

clangv_Od: clangv_O1-
	cat $^ > $@
