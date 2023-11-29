superopt-tests
==============

Collection of test suites for superopt.

## Building

```sh
# first time configuration
./configure

# for building all test suites
make

# Or, for a particular test suite
make <dirname>

# For example, for building bzip2 the following command would be used
make bzip2
```

## Running tests

```sh
# run regression tests
make regression_i386

# Or, for a particular test suite
make -C build/<dirname> test_i386 && parallel --load='33%' < build/<dirname>/test_i386

# For example, for running localmem-tests
make -C build/localmem-tests test_i386 && parallel --load='33%' < build/localmem-tests/test_i386
```

## Cleaning-up

For restoring the pristine state use:
```sh
make distclean
```

For deleting only the compiled files, use:
```sh
make clean
```

## Editing paths

All paths are set in `Make.conf`.

In addition, some environment variables are used for some paths.  The exhaustive list of environment variables used are:

1. `SUPEROPT_PROJECT_DIR`: Directory where `superopt-project` is cloned.

2. `ICC_INSTALL_DIR`: Directory where ICC is installed.  `icc` is then located to `${ICC_INSTALL_DIR}/bin/icc`.

3. `COMPCERT_INSTALL_BIN`: Directory where CompCert is installed.  `ccomp` is then located to `${COMPCERT_INSTALL_BIN}/ccomp`

4. `COMPCERT_INSTALL_LIB`: Search path for CompCert libs.

5. `ICX_INSTALL_DIR`: Directory where ICX (intel's LLVM based compiler, AKA oneAPI compiler) is installed.  `icx` is then located to `${ICX_INSTALL_DIR}/compiler/latest/linux/bin/icc`.

## Adding a new eqcheck test suite

1. Create a new top-level directory: the name of directory will be your testsuite name
2. Add your C/C++ sources to the newly created directory
3. Copy `misc/Makefile.sample` as `Makefile` into your testsuite directory and edit per your requirements
4. Append the suite name to `EQCHECK_TARGETS` in top-level `Makefile`
