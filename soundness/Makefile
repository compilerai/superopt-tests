include ../config.mak                        # paths

# set VPATH path for targets and src files
VPATH = $(SRCDIR)/soundness

include $(SRCDIR)/Makefile.template

test_i386: $(VPATH)/Makefile
	echo '# equivalence fail' > $@
	echo "python3 $(SUPEROPT_PROJECT_DIR)/superopt/utils/eqbin.py -isa i386 -j 10 -extra_flags='--check-safety --disable-innermost-only-loop-unrolling-heuristic' -expect-fail 'main' -tmpdir $(BUILDDIR)/soundness/eqcheck.emi1.s $(VPATH)/emi1.c -assembly $(VPATH)/emi1.s.UNROLL3" >> $@
	echo "python3 $(SUPEROPT_PROJECT_DIR)/superopt/utils/eqbin.py -isa i386 -j 10 -extra_flags='--disable-innermost-only-loop-unrolling-heuristic' -expect-fail 'main' -tmpdir $(BUILDDIR)/soundness/eqcheck.emi9f.s $(VPATH)/emi9f.c -assembly $(VPATH)/emi9f.s.UNROLL3" >> $@
	echo '# eqcheck pass' >> $@
	echo "python3 $(SUPEROPT_PROJECT_DIR)/superopt/utils/eqbin.py -isa i386 -j 10 -extra_flags='--check-safety --disable-innermost-only-loop-unrolling-heuristic' -expect-fail 'main' -tmpdir $(BUILDDIR)/soundness/eqcheck.emi1.fixed.s $(VPATH)/emi1.c -assembly $(VPATH)/emi1.fixed.s.UNROLL3" >> $@
	echo "python3 $(SUPEROPT_PROJECT_DIR)/superopt/utils/eqbin.py -isa i386 -j 10 -extra_flags='--disable-innermost-only-loop-unrolling-heuristic' -expect-fail 'main' -tmpdir $(BUILDDIR)/soundness/eqcheck.emi9f.fixed.s $(VPATH)/emi9f.c -assembly $(VPATH)/emi9f.fixed.s.UNROLL3" >> $@
