include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/bzip2_locals

UNROLL2 := bzip2_locals \
           #recvDecodingTables \
           #generateMTFValues \
           #undoReversibleTransformation_fast \
           #undoReversibleTransformation_small \
           #hbMakeCodeLengths \
           #getAndMoveToFrontDecode \
           #sortIt \
           #qSort3 \

EXPECTED_FAILS_CLANG := bzip2_locals \
                        undoReversibleTransformation_small \
                        hbMakeCodeLengths \
                        sortIt \

UNROLL2_CLANG = $(UNROLL2)

EXTRA_FLAGS := --smt-query-timeout 300 --eqcheck-timeout 7200 --global-timeout 64000 --max-address-space-size-gb 32

# compiler flags
GCC_EQCHECKER_FLAGS_EXTRA= $(GCC_EQCHECKER_NOUNROLL_FLAGS)
CLANG_EQCHECKER_FLAGS_EXTRA= $(CLANG_EQCHECKER_NOUNROLL_FLAGS)
ICC_EQCHECKER_FLAGS_EXTRA= $(ICC_EQCHECKER_NOUNROLL_FLAGS)

include $(SRCDIR)/Makefile.template

test_i386: eqtest_i386_O1
	cat $^ > $@

clangv_Od: clangv_O1
	cat $^ > $@
