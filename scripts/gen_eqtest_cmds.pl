#!/usr/bin/perl -w

use strict;
use warnings;
use Cwd;
use File::Basename;

sub read_file {
  my $filename = $_[0];
  open my $fh, '<', $filename or return "";
  my $data = do { local $/; <$fh> };
  $data =~ tr{\n}{ };
  return $data;
}

#constants
my $filename = $ARGV[0];
my $SUPEROPT_PROJECT_DIR = $ARGV[1];
my $VPATH = $ARGV[2];
my $dst_arch = $ARGV[3];
my $compiler = convert_PP_to_plusplus($ARGV[4]);
my $compiler_suffix = convert_PP_to_plusplus($ARGV[5]);
my $benchmark = basename($VPATH);
#my $srcdst_default_compiler_suffix = "gcc.eqchecker.O0.$dst_arch.s";
#my $srcdst_default_isa = "x64";
#my $srcdst_default_isa = "i386";

#print "VPATH = $VPATH\n";
#print "dst_arch = $dst_arch\n";
#print "compiler_suffix = $compiler_suffix\n";

my $PWD = getcwd;

my $extraflagsarg = $ARGV[6];
my @extraflags = split('@', $extraflagsarg);
shift(@extraflags);
my $extraflagsstr = join('',@extraflags);

my $expectedfailsarg = $ARGV[7];
#print "expectedfailsarg = $expectedfailsarg\n";
my @expectedfails_tmp = split('@', $expectedfailsarg);
shift(@expectedfails_tmp);
my %expectedfails = ();
if (scalar @expectedfails_tmp gt 0) {
  if (scalar @expectedfails_tmp gt 1) { die "expectedfails formatted illegally"; }
  my @expectedfails_ls = split(' ',$expectedfails_tmp[0]);
  for (@expectedfails_ls) { $expectedfails{$_} = 1 }
}

my %unroll;

my $cur;
foreach(my $i = 8; $i <= $#ARGV; $i++) {
  my $arg = $ARGV[$i];
  #print "arg = $arg\n";
  if ($arg eq "unroll1") {
    $cur = 1;
  } elsif ($arg eq "unroll2") {
    $cur = 2;
  } elsif ($arg eq "unroll4") {
    $cur = 4;
  } elsif ($arg eq "unroll8") {
    $cur = 8;
  } elsif ($arg eq "unroll16") {
    $cur = 16;
  } elsif ($arg eq "unroll32") {
    $cur = 32;
  } elsif ($arg eq "unroll64") {
    $cur = 64;
  } elsif (defined $cur) {
    $unroll{$arg} = $cur;
  } else {
    $unroll{$arg} = 1;
  }
}

open(OUT, '>', $filename) or die $!;
foreach my $prog (keys %unroll) {
  my $tmpdir = "$PWD/eqcheck.$prog";
  my $u = $unroll{$prog};
  my $prog_extraflagsstr = $extraflagsstr;
  if (-f "$VPATH/$prog.$compiler.pclsprels") {
    $prog_extraflagsstr = $prog_extraflagsstr . " --pc-local-sprel-assumes $VPATH/$prog.$compiler.pclsprels";
  }
  if (-f "$VPATH/$prog.$compiler.correl_hints") {
    $prog_extraflagsstr = $prog_extraflagsstr . " --correl-hints $VPATH/$prog.$compiler.correl_hints";
  }
  if (-f "$VPATH/$prog.$compiler.eqflags") {
    $prog_extraflagsstr = $prog_extraflagsstr . " " . read_file("$VPATH/$prog.$compiler.eqflags");
  }
  my $prog_expectfailstr = '';
  if ($expectedfails{$prog}) {
    $prog_expectfailstr = "-expect-fail";
  }
  if ($compiler eq "srcdst") {
    my $src_pathname = identify_filetype_extension("$VPATH/$prog\_src");
    my $dst_pathname = identify_filetype_extension("$VPATH/$prog\_dst");
    print OUT "python3 $SUPEROPT_PROJECT_DIR/superopt/utils/eqbin.py -isa $dst_arch -logdir 'logs_$benchmark' -extra_flags='$prog_extraflagsstr' $prog_expectfailstr -tmpdir $tmpdir $src_pathname $dst_pathname.UNROLL$u\n";
  } else {
    my $compile_log_str = "";
    if ($compiler =~ /^clang/) {
      $compile_log_str = "-compile_log $PWD/$prog.$compiler$compiler_suffix.log"
    }
    my $src_pathname = identify_filetype_extension("$VPATH/$prog");
    if ($compiler ne "ack" || -f "$PWD/$prog.$compiler$compiler_suffix") { # skip missing binaries for 'ack' which does not support VLA/alloca()
      print OUT "python3 $SUPEROPT_PROJECT_DIR/superopt/utils/eqbin.py -isa $dst_arch -logdir 'logs_$benchmark' -extra_flags='$prog_extraflagsstr' $prog_expectfailstr  -tmpdir $tmpdir $src_pathname $PWD/$prog.$compiler$compiler_suffix.UNROLL$u $compile_log_str\n";
    } else {
    }
  }
}
close(OUT);

sub identify_filetype_extension
{
  my $path = shift;
  my $cpath = "$path.c";
  my $llpath = "$path.ll";
  if (-e $cpath) {
    return $cpath;
  }
  if (-e $llpath) {
    return $llpath;
  }
  unlink($filename);
  die "Neither C file ($cpath) nor LLVM file ($llpath) exists\n";
}

sub convert_PP_to_plusplus
{
  my $in = shift;
  $in =~ s/PP/++/g;
  return $in;
}
