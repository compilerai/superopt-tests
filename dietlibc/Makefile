include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/dietlibc

UNROLL1 := memccpy   \
           memchr    \
           memrchr   \
           memrchr2

UNROLL1_SRCDST := $(UNROLL1)
EXPECTED_FAILS_SRCDST := $(UNROLL1) # all are supposed to fail

include $(SRCDIR)/Makefile.template

test: eqtest_srcdst
