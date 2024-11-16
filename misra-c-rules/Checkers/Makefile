# List of source files
SOURCES =\
	R_18_6.c\
	R_18_3.c\
	R_18_2.c\
	R_18_1.c\
	R_21_20.c\
	R_22_6.c\
	R_22_4.c\
	R_9_1.c\
	R_22_2.c\

# Corresponding binary names
BINS = $(SOURCES:.c=)

# Compiler
CC = clang --analyze  

# Individual flags for each program (order corresponds to the SOURCES list)
CHECKER_R_18_6= -Xclang -analyzer-checker=core.StackAddressEscape
CHECKER_R_18_3= -Xclang -analyzer-checker=alpha.unix.ArrayPointerArithmetic
CHECKER_R_18_2= -Xclang -analyzer-checker=alpha.unix.ArrayPointerArithmetic
CHECKER_R_18_1= -Xclang -analyzer-checker=alpha.unix.ArrayPointerArithmetic
CHECKER_R_21_20= -Xclang -analyzer-checker=unix.StdLibOldReturnValueUseChecker
CHECKER_R_22_6= -Xclang -analyzer-checker=alpha.unix.Stream
CHECKER_R_22_4 = -Xclang -analyzer-checker=alpha.unix.ReadOnlyStreamChecker
CHECKER_R_9_1= -Xclang -analyzer-checker=core
CHECKER_R_22_2= -Xclang -analyzer-checker=unix.Malloc
# Default target to build all programs
all: $(BINS)

# Rule to build each binary
$(BINS): % : %.c
	$(CC) $(CHECKER_$*) -o $@ $<

# Clean up generated files
clean:
	rm -f $(BINS)

