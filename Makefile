SHELL := /bin/bash

CP := cp -p # preserve timestamps

SUPEROPT_PROJECT_DIR ?= $(realpath $(CURDIR)/..)
SUPEROPT_INSTALL_DIR ?= $(SUPEROPT_PROJECT_DIR)/usr/local

BUILDDIR=$(CURDIR)/build

OOPSLA24_TARGETS := localmem-tests TSVC_prior_work_locals TSVC_prior_work_globals bzip2_locals bzip2_modified

TARGETS := $(OOPSLA24_TARGETS)

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

$(TARGETS)::
	mkdir -p $(BUILDDIR)/$@
	$(CP) $@/Makefile -t $(BUILDDIR)/$@
	$(MAKE) -C $(BUILDDIR)/$@

$(BUILDDIR)/oopsla24_cmds:: $(OOPSLA24_TARGETS)
	@$(foreach t,$^, if $(MAKE) -C $(BUILDDIR)/$(t) all cmds; then :; else echo "ERROR: 'make cmds' failed for target" $(BUILDDIR)/$(t); exit 1; fi;)
	@true > $@
	@$(foreach t,$^, if [ -f $(BUILDDIR)/$(t)/cmds ]; then cat $(BUILDDIR)/$(t)/cmds >> $@; else echo "ERROR:" $(BUILDDIR)/$(t)/cmds "does not exist for target" $(t); rm $@; exit 1; fi;)

oopsla24_cmds.finished: $(BUILDDIR)/oopsla24_cmds
	clear
	parallel --load "33%" < $^ | tee $@
	mv $^ $@

.PHONY: collect_oopsla24_csvs
collect_oopsla24_csvs: oopsla24_cmds.finished
	@$(foreach t,$(OOPSLA24_TARGETS), if $(MAKE) -C $(BUILDDIR)/$(t) collect_csv; then :; else echo "ERROR: 'make collect_csv' failed for target" $(BUILDDIR)/$(t); exit 1; fi; mv $(BUILDDIR)/$(t)/*.csv .;)

.PHONY: oopsla24_results
oopsla24_results: collect_oopsla24_csvs
	$(MAKE) run_oopsla24_cmds
	$(MAKE) collect_oopsla24_csvs

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
