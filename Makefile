SHELL := /bin/bash

SUPEROPT_PROJECT_DIR ?= $(realpath $(CURDIR)/..)
SUPEROPT_INSTALL_DIR ?= $(SUPEROPT_PROJECT_DIR)/usr/local

BUILDDIR=$(CURDIR)/build

# add new dirs' targets here
#CODEGEN_TARGETS := compcert-tests
#OOELALA_TARGETS := ooelala-tests
#MALLOC_TARGETS := malloc-tests cpp
#SPEC_TARGETS := spec17
#FP_TARGETS := fp
#SOUNDNESS_TARGETS := #dietlibc # soundness
MICRO_TARGETS := micro #ctests demo
VECTORIZATION_TARGETS := TSVC_prior_work TSVC_new LORE_mem_write LORE_no_mem_write
LOCALS_TARGETS := localmem-tests bzip2_locals
LOCALS_GLOBALS_TARGETS := TSVC_prior_work_locals TSVC_prior_work_globals
#EQCHECK_TARGETS :=  $(LOCALS_TARGETS) $(VECTORIZATION_TARGETS) $(MICRO_TARGETS) $(MALLOC_TARGETS) $(FP_TARGETS) $(SOUNDNESS_TARGETS) #sag
EQCHECK_TARGETS :=  $(LOCALS_TARGETS) $(LOCALS_GLOBALS_TARGETS) $(VECTORIZATION_TARGETS) $(MICRO_TARGETS)
CLANGV_TARGETS :=  $(LOCALS_TARGETS) $(LOCALS_GLOBALS_TARGETS) $(VECTORIZATION_TARGETS) $(MICRO_TARGETS)

EQCHECK_TARGETS_i386 := $(EQCHECK_TARGETS)
EQCHECK_TARGETS_x64 := $(EQCHECK_TARGETS)
#EQCHECK_TARGETS_ll := llvm-tests
EQCHECK_TARGETS_srcdst :=
TARGETS := $(EQCHECK_TARGETS_i386) #$(EQCHECK_TARGETS_ll)

CLANGV_TARGETS_O1 := $(CLANGV_TARGETS)
CLANGV_TARGETS_O2 := $(CLANGV_TARGETS)
CLANGV_TARGETS_O3 := $(CLANGV_TARGETS)
CLANGV_TARGETS_Od := $(CLANGV_TARGETS)
CLANGV_TARGETS_O1- := $(CLANGV_TARGETS)

MAKEFILES := $(addsuffix /Makefile,$(TARGETS))
BUILD_MAKEFILES := $(addprefix $(BUILDDIR)/,$(MAKEFILES))

IDENTIFY_DURABLES_FILES := cpp/linked_list.cpp cpp/binary_search_tree.cpp cpp/binary_search_tree_iter.cpp malloc-tests/linked_list.c malloc-tests/binary_search_tree.c malloc-tests/binary_search_tree_iter.c malloc-tests/mylist.c malloc-tests/rbtree.c malloc-tests/hash.c

export SUPEROPT_PROJECT_DIR
export SUPEROPT_INSTALL_DIR

# rules

all: $(TARGETS)

$(BUILDDIR)/%:
	mkdir -p $@

$(BUILD_MAKEFILES): $(BUILDDIR)/%/Makefile: %/Makefile $(BUILDDIR)/%
	cp $< $@

$(TARGETS) $(SPEC_TARGETS)::
	mkdir -p $(BUILDDIR)/$@
	cp $@/Makefile -t $(BUILDDIR)/$@
	$(MAKE) -C $(BUILDDIR)/$@

ack-progs::
	$(MAKE) -C $(BUILDDIR)/localmem-tests $@

clangv_O1: OPT_LEVEL=O1
clangv_O2: OPT_LEVEL=O2
clangv_O3: OPT_LEVEL=O3
clangv_Od: OPT_LEVEL=Od
clangv_O1-: OPT_LEVEL=O1-
test_i386: ARCH=i386
eqtest_x64: ARCH=x64
eqtest_i386: ARCH=i386
eqtest_ll: ARCH=ll
eqtest_srcdst: ARCH=srcdst

eqtest_x64 eqtest_i386 eqtest_ll eqtest_srcdst test_i386: %: $(BUILD_MAKEFILES)
	$(foreach t,$(EQCHECK_TARGETS_$(ARCH)),$(MAKE) -C $(BUILDDIR)/$(t) $@ || exit;)
	true > $(BUILDDIR)/$@
	$(foreach t,$(EQCHECK_TARGETS_$(ARCH)), [[ -f $(BUILDDIR)/$(t)/$@ ]] && cat $(BUILDDIR)/$(t)/$@ >> $(BUILDDIR)/$@ || exit;)
	parallel --load "33%" < $(BUILDDIR)/$@

clangv_O1 clangv_O2 clangv_O3 clangv_Od clangv_O1-: %: $(BUILD_MAKEFILES)
	$(foreach t,$(CLANGV_TARGETS_$(OPT_LEVEL)),$(MAKE) -C $(BUILDDIR)/$(t) $@ || exit;)
	true > $(BUILDDIR)/$@
	$(foreach t,$(CLANGV_TARGETS_$(OPT_LEVEL)), [[ -f $(BUILDDIR)/$(t)/$@ ]] && cat $(BUILDDIR)/$(t)/$@ >> $(BUILDDIR)/$@ || exit;)
	parallel --load "33%" < $(BUILDDIR)/$@

ack-compiler::
	rm -rf $(BUILDDIR)/ack-compiler
	git clone https://github.com/compilerai/ack-compiler $(BUILDDIR)/ack-compiler
	make -C $(BUILDDIR)/ack-compiler PREFIX=$(BUILDDIR)/ack-compiler-install
	make -C $(BUILDDIR)/ack-compiler install

typecheck_test:
	$(SUPEROPT_PROJECT_DIR)/superopt/build/etfg_i386/typecheck

codegen_test:
	$(foreach t,$(CODEGEN_TARGETS),$(MAKE) -C $(BUILDDIR)/$(t) codegen_test || exit;)

ooelala_test:
	$(foreach t,$(OOELALA_TARGETS),$(MAKE) -C $(BUILDDIR)/$(t) ooelala_test || exit;)

semanticaa_test:
	$(MAKE) -C $(BUILDDIR)/bzip2 semanticaa_test || exit

specmount::
	-sudo mount -t iso9660 -o ro,exec,loop $(HOME)/tars/cpu2017-1_0_5.iso $(SPEC_MOUNT)

specbuild: $(SPEC_TARGETS)

umount::
	sudo umount $(SPEC_MOUNT)

specclean::
	rm -f $(BUILD)/spec17/build_done

identify_durables::
	python $(SUPEROPT_PROJECT_DIR)/superopt/utils/identify_durables.py --max-call-context-depth 4 $(IDENTIFY_DURABLES_FILES)

$(BUILDDIR)/regression_%.helper::
	@$(foreach t,$(RTARGETS), if $(MAKE) -C $(BUILDDIR)/$(t) all test_i386; then :; else echo "ERROR: 'make test_i386' failed for target" $(BUILDDIR)/$(t); exit 1; fi;)
	@true > $@
	@$(foreach t,$(RTARGETS), if [ -f $(BUILDDIR)/$(t)/test_i386 ]; then cat $(BUILDDIR)/$(t)/test_i386 >> $@; else echo "ERROR:" $(BUILDDIR)/$(t)/test_i386 "does not exist for target" $(t); rm $@; exit 1; fi;)

REGRESSION_PAPER_REQS := localmem-tests TSVC_prior_work_locals TSVC_prior_work_globals
regression_paper:: $(REGRESSION_PAPER_REQS)
$(BUILDDIR)/regression_paper.helper:: RTARGETS=$(REGRESSION_PAPER_REQS)

regression_i386:: $(EQCHECK_TARGETS_i386)
$(BUILDDIR)/regression_i386.helper:: RTARGETS=$(EQCHECK_TARGETS_i386)

.PHONY: regression_paper regression_i386
regression_paper regression_i386:: regression_%: $(BUILDDIR)/regression_%.helper
	# cat $^ > $@
	clear
	parallel --load "33%" < $^ | tee $@
	mv $^ $^.finished

.PHONY: clean_outside_build
clean_outside_build:
	find . -name *.bc | xargs rm -f
	find . -name *.cg.ll | xargs rm -f
	find . -name "*.etfg" | xargs rm -f
	find . -name *.tmp | xargs rm -f
	find . -name '*[^.][^s].log' | xargs rm -f
	find . -name cscope.out | xargs rm -f
	# -find . -name core | xargs rm -f

clean: clean_outside_build
	$(foreach t,$(TARGETS),$(MAKE) -C $(BUILDDIR)/$(t) clean;)
	find $(BUILDDIR) -name "clangv.*" | xargs rm -rf
	find $(BUILDDIR) -name "eqcheck.*" | xargs rm -rf

distclean: clean_outside_build
	rm -rf config-host.mak $(BUILDDIR)
	git clean -df

.PHONY: all clean distclean $(TARGETS) ack-compiler specmount specbuild specclean umount
