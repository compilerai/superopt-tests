include ../config.mak                        # paths
include $(SRCDIR)/Make.conf                  # compiler paths and flags
include $(SRCDIR)/Makefile.common            # build rules

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/TSVC_prior_work

PROGS_EQCHECKER := s000 s1112 s112 s121 s122 s1221 s1251 s127 s1281 s1351 s162 s173 s176 s2244 s243 s251 s3251 s351 s452 s453 sum1d vdotr vpv vpvpv vpvtv vtv vtvtv vpvts

# compiler flags
GCC_I386_EQCHECKER_FLAGS= $(GCC_I386_EQCHECKER_FLAGS_COMMON) $(VEC_FLAGS)
CLANG_I386_EQCHECKER_FLAGS= $(CLANG_I386_EQCHECKER_FLAGS_COMMON) $(VEC_FLAGS)
ICC_I386_EQCHECKER_FLAGS= $(ICC_I386_EQCHECKER_FLAGS_COMMON) $(VEC_FLAGS)

# define target variables

BC_O0_SUFFIX := bc.eqchecker.O0
GCC_O3_SUFFIX := gcc.eqchecker.O3.i386.s
CLANG_O3_SUFFIX := clang.eqchecker.O3.i386.s
ICC_O3_SUFFIX := icc.eqchecker.O3.i386.s

# make available to gentest.sh and runtest.sh
export BC_O0_SUFFIX
export GCC_O3_SUFFIX
export CLANG_O3_SUFFIX
export ICC_O3_SUFFIX

EQCHECKER_BC_O0_PROGS = $(addsuffix .$(BC_O0_SUFFIX), $(PROGS_EQCHECKER))
EQCHECKER_BC_O2_PROGS = $(addsuffix .bc.eqchecker.O2, $(PROGS_EQCHECKER))
EQCHECKER_BC_O3_PROGS = $(addsuffix .bc.eqchecker.O3, $(PROGS_EQCHECKER))
EQCHECKER_BC_O3cg_PROGS = $(addsuffix .bc.eqchecker.O3.cg, $(PROGS_EQCHECKER))

EQCHECKER_I386_GCC_O0_PROGS = $(addsuffix .gcc.eqchecker.O0.i386.s, $(PROGS_EQCHECKER))
EQCHECKER_I386_GCC_O2_PROGS = $(addsuffix .gcc.eqchecker.O2.i386.s, $(PROGS_EQCHECKER))
EQCHECKER_I386_GCC_O3_PROGS = $(addsuffix .$(GCC_O3_SUFFIX), $(PROGS_EQCHECKER))

EQCHECKER_I386_CLANG_O0_PROGS = $(addsuffix .clang.eqchecker.O0.i386.s, $(PROGS_EQCHECKER))
EQCHECKER_I386_CLANG_O2_PROGS = $(addsuffix .clang.eqchecker.O2.i386.s, $(PROGS_EQCHECKER))
EQCHECKER_I386_CLANG_O3_PROGS = $(addsuffix .$(CLANG_O3_SUFFIX), $(PROGS_EQCHECKER))

EQCHECKER_I386_ICC_O0_PROGS = $(addsuffix .icc.eqchecker.O0.i386.s, $(PROGS_EQCHECKER))
EQCHECKER_I386_ICC_O2_PROGS = $(addsuffix .icc.eqchecker.O2.i386.s, $(PROGS_EQCHECKER))
EQCHECKER_I386_ICC_O3_PROGS = $(addsuffix .$(ICC_O3_SUFFIX), $(PROGS_EQCHECKER))

EQCHECKER_I386_CCOMP_O2_PROGS = $(addsuffix .ccomp.eqchecker.O2.i386, $(PROGS_EQCHECKER))

EQCHECKER_I386_GCC_O3_XML_FILES = $(addsuffix .gcc.O3.xml, $(PROGS_EQCHECKER))
EQCHECKER_I386_CLANG_O3_XML_FILES = $(addsuffix .clang.O3.xml, $(PROGS_EQCHECKER))
EQCHECKER_I386_ICC_O3_XML_FILES = $(addsuffix .icc.O3.xml, $(PROGS_EQCHECKER))

EQCHECKER_I386_PROGS = \
  $(EQCHECKER_I386_GCC_O0_PROGS) \
  $(EQCHECKER_I386_GCC_O3_PROGS) \
  $(EQCHECKER_I386_CLANG_O0_PROGS) \
  $(EQCHECKER_I386_CLANG_O3_PROGS) \
  #$(EQCHECKER_I386_ICC_O0_PROGS) \
  #$(EQCHECKER_I386_ICC_O3_PROGS)
  #$(EQCHECKER_I386_CCOMP_O2_PROGS) \

LLVM_PROGS     = $(EQCHECKER_BC_O0_PROGS) $(EQCHECKER_BC_O3_PROGS)
LLVM_PROGS_ASM = $(addsuffix .ll, $(LLVM_PROGS))

XML_FILES = \
  $(EQCHECKER_I386_GCC_O3_XML_FILES) \
  $(EQCHECKER_I386_CLANG_O3_XML_FILES)

ALL_PROGS = $(EQCHECKER_I386_PROGS) $(LLVM_PROGS) $(LLVM_PROGS_ASM) $(XML_FILES)

# targets

all: $(ALL_PROGS)

clean:
	# delete all except icc binaries
	rm -f *.o *.tmp $(EQCHECKER_I386_CLANG_O0_PROGS) $(EQCHECKER_I386_CLANG_O3_PROGS) $(EQCHECKER_I386_GCC_O0_PROGS) $(EQCHECKER_I386_GCC_O3_PROGS) $(LLVM_PROGS) $(LLVM_PROGS_ASM) #$(ALL_PROGS)

gentest:
	bash $(VPATH)/gentest.sh

runtest:
	cp $(VPATH)/*tsvc_funcs* -t .
	bash $(VPATH)/runtest.sh

.DEFAULT_GOAL := all

.PHONY: all clean gentest runtest