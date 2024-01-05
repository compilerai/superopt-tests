SHELL := /bin/bash

CP := cp -p # preserve timestamps

SUPEROPT_PROJECT_DIR ?= $(realpath $(CURDIR)/..)
SUPEROPT_INSTALL_DIR ?= $(SUPEROPT_PROJECT_DIR)/usr/local

BUILDDIR=$(CURDIR)/build

lt_targets := localmem-tests
tsvc_targets := TSVC_prior_work_locals TSVC_prior_work_globals
bzip2_targets := bzip2_locals
bzip2_modified_targets := bzip2_modified
demo_targets := demo

TARGETS := $(lt_targets) $(tsvc_targets) $(bzip2_targets) $(bzip2_modified_targets) $(demo_targets)

MAKEFILES := $(addsuffix /Makefile,$(TARGETS))
BUILD_MAKEFILES := $(addprefix $(BUILDDIR)/,$(MAKEFILES))

export SUPEROPT_PROJECT_DIR
export SUPEROPT_INSTALL_DIR

# rules

all: $(TARGETS)

$(BUILD_MAKEFILES): $(BUILDDIR)/%/Makefile: %/Makefile $(BUILDDIR)/%
	$(CP) $< $@

$(TARGETS)::
	mkdir -p $(BUILDDIR)/$@
	$(CP) $@/Makefile -t $(BUILDDIR)/$@
	$(MAKE) -C $(BUILDDIR)/$@

$(BUILDDIR)/%_cmds::
	@$(foreach t,$^, if $(MAKE) -C $(BUILDDIR)/$(t) all cmds; then :; else echo "ERROR: 'make cmds' failed for target" $(BUILDDIR)/$(t); exit 1; fi;)
	@true > $@
	@$(foreach t,$^, if [ -f $(BUILDDIR)/$(t)/cmds ]; then cat $(BUILDDIR)/$(t)/cmds >> $@; else echo "ERROR:" $(BUILDDIR)/$(t)/cmds "does not exist for target" $(t); rm $@; exit 1; fi;)

%.finished: $(BUILDDIR)/%_cmds
	@clear
	@echo "Running the eqchecks..."
	@parallel --load "33%" < $^ | tee $@
	@mv $^ $@

.PHONY: lt_csvs tsvc_csvs bzip2_csvs bzip2_modified_csvs demo_csvs
lt_csvs tsvc_csvs bzip2_csvs bzip2_modified_csvs demo_csvs: %_csvs: %.finished
	@echo "Generating CSVs..."
	@$(foreach t,$($(subst _csvs,,$@)_targets), if $(MAKE) -C $(BUILDDIR)/$(t) collect_csv; then :; else echo "ERROR: 'make collect_csv' failed for target" $(BUILDDIR)/$(t); exit 1; fi; mv $(BUILDDIR)/$(t)/*.csv .;)

$(BUILDDIR)/lt_cmds:: $(lt_targets)
$(BUILDDIR)/tsvc_cmds:: $(tsvc_targets)
$(BUILDDIR)/bzip2_cmds:: $(bzip2_targets)
$(BUILDDIR)/bzip2_modified_cmds:: $(bzip2_modified_targets)
$(BUILDDIR)/demo_cmds:: $(demo_targets)

.PHONY: lt_results tsvc_results bzip2_results bzip2_modified_results demo_results
lt_results tsvc_results bzip2_results bzip2_modified_results demo_results: %_results: %_csvs

.PHONY: oopsla24_results
oopsla24_results: lt_results tsvc_results bzip2_results

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
