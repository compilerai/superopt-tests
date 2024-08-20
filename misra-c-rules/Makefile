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
    R_8_14.c \
    D_4_10.c \
    R_13_5.c \
    R_16_1.c \
    R_17_2.c \
    R_17_6.c \
    R_21_4.c \
    R_21_5.c \
    R_5_3.c  \
    R_9_3.c \
    R_9_4.c  \
    R_9_5.c  \
    R_10_1.c \
    R_10_4.c \
    R_13_1.C \
    R_16_2.c \
    R_18_8.c \
    R_17_1.c \
    R_20_6.c  \
    R_18_7.c \
    R_14_3.c \

BINS:=$(SRCS:.c=.o)
all: $(BINS)
	$(CLANG) $(BINS) -o $(EXECUTABLE)

%.o: %.c
	$(CLANG) -c $< -o $@

clean:
	rm -f $(BINS)

