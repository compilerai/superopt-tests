SHELL := /bin/bash

CP := cp -p # preserve timestamps

SUPEROPT_PROJECT_DIR ?= $(realpath $(CURDIR)/..)
SUPEROPT_INSTALL_DIR ?= $(SUPEROPT_PROJECT_DIR)/usr/local

BUILDDIR=$(CURDIR)/build

# add new dirs' targets here
SOUNDNESS_TARGETS := soundness #dietlibc
MICRO_TARGETS := micro #ctests demo
VECTORIZATION_TARGETS := TSVC_prior_work TSVC_new LORE_mem_write LORE_no_mem_write
LOCALS_TARGETS := localmem-tests bzip2_locals bzip2_modified
LOCALS_GLOBALS_TARGETS := TSVC_prior_work_locals TSVC_prior_work_globals
EQCHECK_TARGETS :=  $(LOCALS_TARGETS) $(LOCALS_GLOBALS_TARGETS) $(VECTORIZATION_TARGETS) $(MICRO_TARGETS) $(SOUNDNESS_TARGETS)

EQCHECK_TARGETS_i386 := $(EQCHECK_TARGETS)
TARGETS := $(EQCHECK_TARGETS_i386)

MAKEFILES := $(addsuffix /Makefile,$(TARGETS))
BUILD_MAKEFILES := $(addprefix $(BUILDDIR)/,$(MAKEFILES))

export SUPEROPT_PROJECT_DIR
export SUPEROPT_INSTALL_DIR

# rules

all: $(TARGETS)

$(BUILDDIR)/%:
	mkdir -p $@

$(BUILD_MAKEFILES): $(BUILDDIR)/%/Makefile: %/Makefile $(BUILDDIR)/%
	$(CP) $< $@

$(TARGETS) $(SPEC_TARGETS)::
	mkdir -p $(BUILDDIR)/$@
	$(CP) $@/Makefile -t $(BUILDDIR)/$@
	$(MAKE) -C $(BUILDDIR)/$@

$(BUILDDIR)/oopsla24_results.helper:: localmem-tests TSVC_prior_work_locals TSVC_prior_work_globals bzip2_locals bzip2_modified soundness
	@$(foreach t,$^, if $(MAKE) -C $(BUILDDIR)/$(t) all cmds; then :; else echo "ERROR: 'make cmds' failed for target" $(BUILDDIR)/$(t); exit 1; fi;)
	@true > $@
	@$(foreach t,$^, if [ -f $(BUILDDIR)/$(t)/cmds ]; then cat $(BUILDDIR)/$(t)/cmds >> $@; else echo "ERROR:" $(BUILDDIR)/$(t)/cmds "does not exist for target" $(t); rm $@; exit 1; fi;)

.PHONY: oopsla24_results
oopsla24_results: $(BUILDDIR)/oopsla24_results.helper
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

.PHONY: all clean distclean $(TARGETS)
