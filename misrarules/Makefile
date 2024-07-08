CLANG=clang

SRCS:=           \
        D_4_10.c \
        R_13_5.c \
        R_16_1.c \
        R_17_2.c \
        R_17_6.c \
        R_21_4.c \
        R_21_5.c \
        R_5_3.c  \
        R_9_3.c  \
        R_9_4.c  \
        R_9_5.c  \
        R_10_1.c \
        R_10_4.c \
        R_13_1.C \
        R_16_2.c \
        R_18_8.c \
        R_17_1.c \

BINS:= $(SRCS:.c=.o)

run: $(BINS)

%.o: %.c
	$(CLANG) $^ -o $@

cmds: run

# Clean up all compiled binaries
clean:
	rm -f $(BINS) a.out

