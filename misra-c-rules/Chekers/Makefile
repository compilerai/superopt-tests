# List of source files
SOURCES =\
	R_22_4.c\

# Corresponding binary names
BINS = $(SOURCES:.c=)

# Compiler
CC = clang --analyze -Xclang 

# Individual flags for each program (order corresponds to the SOURCES list)
CHECKER_R_22_4 = -analyzer-checker=alpha.unix.ReadOnlyStreamChecker
# Default target to build all programs
all: $(BINS)

# Rule to build each binary
$(BINS): % : %.c
	$(CC) $(CHECKER_$*) -o $@ $<

# Clean up generated files
clean:
	rm -f $(BINS)

