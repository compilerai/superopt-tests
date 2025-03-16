include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/sag

UNROLL1_CLANG_O1 := quicksort mergesort

EXPECTED_FAILS_GCC :=
EXPECTED_FAILS_CLANG :=
EXPECTED_FAILS_ICC :=

include $(SRCDIR)/Makefile.template

test: eqtest_i386_O1
	cat $^ > $@
