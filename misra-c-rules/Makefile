CLANG=clang

SRCS:=  \
    R_10_2.c \
    R_12_2.c \
    R_15_2.c \
    R_15_7.c \
    R_16_4.c \
    R_16_5.c \
    R_16_6.c \
    R_16_7.c \
    R_5_6.c  \
    R_5_7.c  \
    R_6_1.c  \
    R_6_2.c  \
    R_7_4.c  \
    R_8_10.c \
    R_8_12.c \
    R_8_14.c

BINS:=$(SRCS:.c=.o)
EXECUTABLE=output_executable

all: $(EXECUTABLE)

$(EXECUTABLE): $(BINS)
	$(CLANG) $(BINS) -o $(EXECUTABLE)

%.o: %.c
	$(CLANG) -c $< -o $@

clean:
	rm -f $(BINS) $(EXECUTABLE)

.PHONY: clean all

run: $(EXECUTABLE)
	./$(EXECUTABLE)
