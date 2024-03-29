SHELL := /bin/bash

CP := cp -p # preserve timestamps

SUPEROPT_PROJECT_DIR ?= $(realpath $(CURDIR)/..)
SUPEROPT_INSTALL_DIR ?= $(SUPEROPT_PROJECT_DIR)/usr/local

BUILDDIR=$(CURDIR)/build

export SUPEROPT_PROJECT_DIR
export SUPEROPT_INSTALL_DIR

include misc/Makefile.head

# add suites -- this provides the `run_tests_<name>` target which can be used for invoking the `cmds` generated by `make cmds` of the listed benchmarks
$(call add_suite,all,           c2c bzip2_locals micro localmem-tests TSVC_prior_work TSVC_new LORE_mem_write LORE_no_mem_write TSVC_prior_work_locals TSVC_prior_work_globals statistical)
$(call add_suite,locals,        localmem-tests TSVC_prior_work_locals TSVC_prior_work_globals)
$(call add_suite,bzip2,         bzip2_locals)
$(call add_suite,bzip2m,        bzip2_locals bzip2_modified)
$(call add_suite,statistical,   statistical)
$(call add_suite,sorting,       sorting)
$(call add_suite,micro,         micro)
$(call add_suite,vectorization, TSVC_prior_work TSVC_new LORE_mem_write LORE_no_mem_write)
$(call add_suite,soundness,     soundness)

# add new dirs' targets here
#CODEGEN_TARGETS := compcert-tests
#OOELALA_TARGETS := ooelala-tests
#MALLOC_TARGETS := malloc-tests cpp
#SPEC_TARGETS := spec17
#FP_TARGETS := fp

# CLANGV_TARGETS :=  $(locals_targets) $(vectorization_targets) $(micro_targets)
# 
# CLANGV_TARGETS_O1 := $(CLANGV_TARGETS)
# CLANGV_TARGETS_O2 := $(CLANGV_TARGETS)
# CLANGV_TARGETS_O3 := $(CLANGV_TARGETS)
# CLANGV_TARGETS_Od := $(CLANGV_TARGETS)
# CLANGV_TARGETS_O1- := $(CLANGV_TARGETS)
# 
#IDENTIFY_DURABLES_FILES := cpp/linked_list.cpp cpp/binary_search_tree.cpp cpp/binary_search_tree_iter.cpp malloc-tests/linked_list.c malloc-tests/binary_search_tree.c malloc-tests/binary_search_tree_iter.c malloc-tests/mylist.c malloc-tests/rbtree.c malloc-tests/hash.c

# clangv_O1: OPT_LEVEL=O1
# clangv_O2: OPT_LEVEL=O2
# clangv_O3: OPT_LEVEL=O3
# clangv_Od: OPT_LEVEL=Od
# clangv_O1-: OPT_LEVEL=O1-
# test_i386: ARCH=i386
# 
# clangv_O1 clangv_O2 clangv_O3 clangv_Od clangv_O1-: %: $(BUILD_MAKEFILES)
# 	$(foreach t,$(CLANGV_TARGETS_$(OPT_LEVEL)),$(MAKE) -C $(BUILDDIR)/$(t) $@ || exit;)
# 	true > $(BUILDDIR)/$@
# 	$(foreach t,$(CLANGV_TARGETS_$(OPT_LEVEL)), [[ -f $(BUILDDIR)/$(t)/$@ ]] && cat $(BUILDDIR)/$(t)/$@ >> $(BUILDDIR)/$@ || exit;)
# 	parallel --load "33%" < $(BUILDDIR)/$@

ack-compiler::
	rm -rf $(BUILDDIR)/ack-compiler
	git clone https://github.com/compilerai/ack-compiler $(BUILDDIR)/ack-compiler
	make -C $(BUILDDIR)/ack-compiler PREFIX=$(BUILDDIR)/ack-compiler-install
	make -C $(BUILDDIR)/ack-compiler install

ack-progs::
	$(MAKE) -C $(BUILDDIR)/localmem-tests $@

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

$(SPEC_TARGETS)::
	mkdir -p $(BUILDDIR)/$@
	$(CP) $@/Makefile -t $(BUILDDIR)/$@
	$(MAKE) -C $(BUILDDIR)/$@

specbuild: $(SPEC_TARGETS)

umount::
	sudo umount $(SPEC_MOUNT)

specclean::
	rm -f $(BUILD)/spec17/build_done

identify_durables::
	python $(SUPEROPT_PROJECT_DIR)/superopt/utils/identify_durables.py --max-call-context-depth 4 $(IDENTIFY_DURABLES_FILES)

.PHONY: ack-compiler specmount specbuild specclean umount

include misc/Makefile.tail
