# List of source files
SOURCES =\
	R_21_19\
	R_22_7\
	R_21_14\
	R_22_3.c\
	R_19_1.c\
	R_21_18.c\
	R_21_17.c\
	R_21_13.c\
    R_21_16.c\
    R_21_15.c\
	R_18_6.c\
	R_18_3.c\
	R_18_2.c\
	R_18_1.c\
	R_21_20.c\
	R_22_6.c\
	R_22_4.c\
	R_9_1.c\
	R_22_2.c\
	R_22_1.c\

# Corresponding binary names
BINS = $(SOURCES:.c=)

# Compiler
CC = clang --analyze  

# Individual flags for each program (order corresponds to the SOURCES list)
CHECKER_R_21_19=-Xclang -analyzer-checker=alpha.unix.ConstPointerLocalChecker
CHECKER_R_22_7=-Xclang -analyzer-checker=alpha.unix.EOFChecker
CHECKER_R_21_14=-Xclang -analyzer-checker=alpha.unix.MemcmpChecker
CHECKER_R_22_3=-Xclang -analyzer-checker=alpha.unix.Stream
CHECKER_R_19_1=-Xclang -analyzer-checker=alpha.unix.cstring.BufferOverlap
CHECKER_R_21_18=-Xclang -analyzer-checker=alpha.unix.cstring
CHECKER_R_21_17=-Xclang -analyzer-checker=alpha.unix.cstring
CHECKER_R_21_13=-Xclang -analyzer-checker=alpha.unix.CTypeFunctionsChecker
CHECKER_R_21_16=-Xclang -analyzer-checker=alpha.unix.PointerArgumentChecker
CHECKER_R_21_15=-Xclang -analyzer-checker=alpha.unix.PointerArgumentChecker
CHECKER_R_18_6= -Xclang -analyzer-checker=core.StackAddressEscape
CHECKER_R_18_3= -Xclang -analyzer-checker=alpha.unix.ArrayPointerArithmetic
CHECKER_R_18_2= -Xclang -analyzer-checker=alpha.unix.ArrayPointerArithmetic
CHECKER_R_18_1= -Xclang -analyzer-checker=alpha.unix.ArrayPointerArithmetic
CHECKER_R_21_20= -Xclang -analyzer-checker=alpha.unix.StdLibOldReturnValueUseChecker
CHECKER_R_22_6= -Xclang -analyzer-checker=alpha.unix.Stream
CHECKER_R_22_4 = -Xclang -analyzer-checker=alpha.unix.ReadOnlyStreamChecker
CHECKER_R_9_1= -Xclang -analyzer-checker=core
CHECKER_R_22_2= -Xclang -analyzer-checker=unix.Malloc
CHECKER_R_22_1= -Xclang -analyzer-checker=unix.Malloc

# Default target to build all programs
all: $(BINS)

# Rule to build each binary
$(BINS): % : %.c
	$(CC) $(CHECKER_$*) -o $@ $<

# Clean up generated files
clean:
	rm -f $(BINS)

