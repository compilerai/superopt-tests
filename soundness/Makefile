include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/soundness
TMPDIR_PATH := $(BUILDDIR)/soundness

EQBIN := python3 $(SUPEROPT_PROJECT_DIR)/superopt/utils/eqbin.py

DEPS := $(VPATH)/Makefile $(VPATH)/emi1.c $(VPATH)/emi9f.c $(VPATH)/emi1.s $(VPATH)/emi9f.s $(VPATH)/emi1.fixed.s $(VPATH)/emi9f.fixed.s

fails: $(DEPS)
	# safety check fail
	echo '$(EQBIN) -isa i386 -j 10 -extra_flags="--disable-innermost-only-loop-unrolling-heuristic" -expect-fail "main" -tmpdir $(TMPDIR_PATH)/eqcheck.emi1.s $(VPATH)/emi1.c -assembly $(VPATH)/emi1.s.UNROLL3' > $@
	# equivalence fail
	echo '$(EQBIN) -isa i386 -j 10 -extra_flags="--disable-innermost-only-loop-unrolling-heuristic" -expect-fail "main" -tmpdir $(TMPDIR_PATH)/eqcheck.emi9f.s $(VPATH)/emi9f.c -assembly $(VPATH)/emi9f.s.UNROLL3' >> $@

passes: $(DEPS)
	echo '$(EQBIN) -isa i386 -j 10 -extra_flags="--disable-innermost-only-loop-unrolling-heuristic" -expect-fail "main" -tmpdir $(TMPDIR_PATH)/eqcheck.emi1.fixed.s $(VPATH)/emi1.c -assembly $(VPATH)/emi1.fixed.s.UNROLL3' > $@
	echo '$(EQBIN) -isa i386 -j 10 -extra_flags="--disable-innermost-only-loop-unrolling-heuristic" -expect-fail "main" -tmpdir $(TMPDIR_PATH)/eqcheck.emi9f.fixed.s $(VPATH)/emi9f.c -assembly $(VPATH)/emi9f.fixed.s.UNROLL3' >> $@

cmds: fails passes
	cat $^ > $@
