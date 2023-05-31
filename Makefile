SHELL := /bin/bash

include config-host.mak      # BUILDDIR
include $(SRCDIR)/Make.conf                  # compiler paths and flags

# add new dirs' targets here
#CODEGEN_TARGETS := compcert-tests
#OOELALA_TARGETS := ooelala-tests
#MALLOC_TARGETS := malloc-tests cpp
#SPEC_TARGETS := spec17
#FP_TARGETS := fp
#SOUNDNESS_TARGETS := #dietlibc # soundness
MICRO_TARGETS := micro #ctests demo
VECTORIZATION_TARGETS := TSVC_prior_work TSVC_new LORE_mem_write LORE_no_mem_write
LOCALS_TARGETS := localmem-tests bzip2_locals #TSVC_prior_work_locals TSVC_prior_work_globals
#EQCHECK_TARGETS :=  $(LOCALS_TARGETS) $(VECTORIZATION_TARGETS) $(MICRO_TARGETS) $(MALLOC_TARGETS) $(FP_TARGETS) $(SOUNDNESS_TARGETS) #sag
EQCHECK_TARGETS :=  $(LOCALS_TARGETS) $(VECTORIZATION_TARGETS) $(MICRO_TARGETS)

EQCHECK_TARGETS_i386 := $(EQCHECK_TARGETS)
EQCHECK_TARGETS_x64 := $(EQCHECK_TARGETS)
#EQCHECK_TARGETS_ll := llvm-tests
EQCHECK_TARGETS_srcdst :=
#TARGETS := $(EQCHECK_TARGETS_i386) $(EQCHECK_TARGETS_x64) $(EQCHECK_TARGETS_ll) #$(OOELALA_TARGETS) # $(CODEGEN_TARGETS)
TARGETS := $(EQCHECK_TARGETS_i386) #$(EQCHECK_TARGETS_ll)

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

clean:
	$(foreach t,$(TARGETS),$(MAKE) -C $(BUILDDIR)/$(t) clean;)
	find . -name *.bc | xargs rm -f
	find . -name *.cg.ll | xargs rm -f
	find . -name "*.etfg" | xargs rm -f
	find . -name *.tmp | xargs rm -f
	find . -name *.log | xargs rm -f
	find . -name cscope.out | xargs rm -f
	find . -name core | xargs rm -f

distclean: clean
	rm -rf config-host.mak $(BUILDDIR)

.PHONY: all clean distclean $(TARGETS) ack-compiler specmount specbuild specclean umount
