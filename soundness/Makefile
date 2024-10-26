include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/soundness

UNROLL4_SRCDST :=                                          \
                  emi1_buggy                               \
                  emi1_fixed                               \
                  emi9f_buggy                              \
                  emi9f_fixed                              \

EXPECTED_FAILS_SRCDST :=                                   \
                         emi1_fixed                        \
                         emi1_buggy                        \
                         emi9f_buggy                       \
                         # emi1_fixed [fails because the path enumeration algo does not enumerate the required path]

include $(SRCDIR)/Makefile.template

cmds: eqtest_srcdst
	cat $^ > $@
