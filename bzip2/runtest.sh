#!/bin/bash

set -eu # fail on error

###########################

declare -A g_eqflags
g_eqflags["qSort3"]="--smt-query-timeout 600" # timeouts otherwise

###########################

<<<<<<< HEAD
    echo "python ${SUPEROPT_PROJECT_DIR}/superopt/utils/chaperon.py --logfile \"${EQLOGS}/${binary}.${func}.${compiler}.O3.eqlog\" \"${SUPEROPT_PROJECT_DIR}/superopt/build/etfg_i386/eq -f ${func} ${eq_opts} ${binary}.bc.eqchecker.O0.ll.ALL.etfg ${binary}.${compiler}.eqchecker.O3.i386.ALL.tfg\""
  done < ${infile}
}

mkdir -p ${EQLOGS}
=======
source ${SUPEROPT_PROJECT_DIR}/superopt-tests/scripts/eqchecker_runtest_from_file.sh
>>>>>>> origin/ipa

binary=bzip2
compiler=clang
> chaperon_commands

gen_commands eq_funcs_spec2k_bzip2_ext_nv ""                   >> chaperon_commands
gen_commands eq_funcs_spec2k_bzip2_ext_v2 "--unroll-factor 4"  >> chaperon_commands
gen_commands eq_funcs_spec2k_bzip2_ext_v8 "--unroll-factor 16" >> chaperon_commands

parallel --load "${PARALLEL_LOAD_PERCENT:-100}%" < chaperon_commands
