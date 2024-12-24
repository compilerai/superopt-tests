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
my $type = $ARGV[0];
my $out_filename = $ARGV[1];
my $SUPEROPT_PROJECT_DIR = $ARGV[2];
my $VPATH = $ARGV[3];
my $benchmark = basename($VPATH);
my $PWD = getcwd;
my $num_processes_per_file = 2;
  
my ($dst_arch, $compiler, $extraflagsarg, $expectedfailsarg, $ccoptsarg, $record_filename_arg);
my ($opt_level);
my ($tmpdir_prefix);
my $cur_index;

if ($type eq "eqcheck") {
  $dst_arch = $ARGV[4];
  $compiler = convert_PP_to_plusplus($ARGV[5]);
  $opt_level = convert_PP_to_plusplus($ARGV[6]);
  $extraflagsarg = $ARGV[7];
  $expectedfailsarg = $ARGV[8];
  $ccoptsarg = $ARGV[9];
  $record_filename_arg = $ARGV[10];
  $tmpdir_prefix = $ARGV[11];
  #print "expectedfailsarg = $expectedfailsarg\n";
  $cur_index = 12;
} elsif ($type eq "clangv") {
  $dst_arch = "i386";
  $opt_level = $ARGV[4];
  $extraflagsarg = $ARGV[5];
  $expectedfailsarg = $ARGV[6];
  $ccoptsarg = $ARGV[7];
  $record_filename_arg = $ARGV[8];
  $tmpdir_prefix = $ARGV[9];
  $cur_index = 10;
} else {
  die "incorrect type";
}

my @extraflags = split('@', $extraflagsarg);
shift(@extraflags);
my $extraflagsstr = join('',@extraflags);

my $expectedfails = get_string_arg($expectedfailsarg);
my $ccopts = get_string_arg($ccoptsarg);
my $record_filename = get_string_arg($record_filename_arg);

my %unroll;

my $cur;
foreach(my $i = $cur_index; $i <= $#ARGV; $i++) {
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

open(OUT, '>', $out_filename) or die $!;
foreach my $prog (keys %unroll) {
  my $u = $unroll{$prog};
  my $prog_extraflagsstr = $extraflagsstr;

  if ($type eq "eqcheck") {
    if (-f "$VPATH/$prog.$compiler.pclsprels") {
      $prog_extraflagsstr = $prog_extraflagsstr . " --pc-local-addr-guesses $VPATH/$prog.$compiler.pclsprels";
    }
    if (-f "$VPATH/$prog.$compiler.correl_hints") {
      $prog_extraflagsstr = $prog_extraflagsstr . " --correl-hints $VPATH/$prog.$compiler.correl_hints";
    }
    if (-f "$VPATH/$prog.$compiler.eqflags") {
      $prog_extraflagsstr = $prog_extraflagsstr . " " . read_file("$VPATH/$prog.$compiler.eqflags");
    }

    if ($compiler eq "srcdst") {
      my $tmpdir = "$PWD/$tmpdir_prefix.$prog.$compiler";
      my $src_pathname = identify_filetype_extension("$VPATH/$prog\_src");
      my $dst_pathname = identify_filetype_extension("$VPATH/$prog\_dst");
      print OUT "python3 $SUPEROPT_PROJECT_DIR/superopt/utils/eqbin.py -isa $dst_arch -j $num_processes_per_file -extra_flags='$prog_extraflagsstr' -compiler='$compiler' -expect-fails='$expectedfails' -cc-opts '$ccopts' -record='$record_filename' -tmpdir $tmpdir $src_pathname -assembly $dst_pathname.UNROLL$u\n";
    } else {
      my $compiler_suffix = ".eqchecker.$opt_level.$dst_arch.s";
      my $tmpdir = "$PWD/$tmpdir_prefix.$prog.$compiler$compiler_suffix";
      my $compile_log_str = "";
      if ($compiler =~ /^clang/) {
        $compile_log_str = "-compile_log $PWD/$prog.$compiler$compiler_suffix.log"
      }
      my $src_pathname = identify_filetype_extension("$VPATH/$prog");
      if ($compiler ne "ack" || -f "$PWD/$prog.$compiler$compiler_suffix") { # skip missing binaries for 'ack' which does not support VLA/alloca()
        print OUT "python3 $SUPEROPT_PROJECT_DIR/superopt/utils/eqbin.py -isa $dst_arch -j $num_processes_per_file -extra_flags='$prog_extraflagsstr' -compiler='$compiler' -opt_level $opt_level -expect-fails='$expectedfails' -cc-opts '$ccopts' -record '$record_filename' -tmpdir $tmpdir $src_pathname -assembly $PWD/$prog.$compiler$compiler_suffix.UNROLL$u $compile_log_str\n";
      } else {
      }
    }
  } elsif ($type eq "clangv") {
    my $src_pathname = identify_filetype_extension("$VPATH/$prog");
    my $tmpdir = "$PWD/clangv.$prog.$opt_level";
    print OUT "python3 $SUPEROPT_PROJECT_DIR/superopt/utils/eqbin.py -isa $dst_arch -j $num_processes_per_file -extra_flags='$prog_extraflagsstr' -compiler='clangv' -expect-fails='$expectedfails' -cc-opts '$ccopts' -record '$record_filename' -tmpdir $tmpdir -unroll $u -opt_level $opt_level $src_pathname\n";
  } else {
    die "not-reached";
  }
}
close(OUT);

sub identify_filetype_extension
{
  my $path = shift;
  my $cpath = "$path.c";
  my $llpath = "$path.ll";
  my $spath = "$path.s";
  if (-e $cpath) {
    return $cpath;
  }
  if (-e $llpath) {
    return $llpath;
  }
  if (-e $spath) {
    return $spath;
  }
  unlink($out_filename);
  die "Neither of C file ($cpath) or LLVM file ($llpath) or S file ($spath) exists\n";
}

sub convert_PP_to_plusplus
{
  my $in = shift;
  $in =~ s/PP/++/g;
  return $in;
}

sub get_string_arg
{
  my $expectedfailsarg = shift;
  my @expectedfails_tmp = split('@', $expectedfailsarg);
  shift(@expectedfails_tmp);
  my $expectedfails = "";
  if (scalar @expectedfails_tmp gt 0) {
    if (scalar @expectedfails_tmp gt 1) { die "expectedfails/ccopts/record-filename formatted illegally"; }
    $expectedfails = $expectedfails_tmp[0];
  }
  return $expectedfails;
}
