#include <string.h>
#include <stdio.h>

void test_cases1() {
    char src[10] = "hello";
    char dest[10];

    // VALID: Copy within bounds
    strcpy(dest, src);

    // VALID: Copy with size explicitly limited
    strncpy(dest, src, 5);

    // INVVALID: because Concatenate outof bounds bounds
    strcat(dest, "world");

    // VALID: Concatenate with size explicitly limited
    strncat(dest, "!", 1);

    // VALID: Compare memory regions within bounds
    char buffer1[10] = "buffer";
    char buffer2[10] = "buffer";
    memcmp(buffer1, buffer2, 6);  // Compare first 6 bytes

    // VALID: Copy memory regions within bounds
    memcpy(buffer1, buffer2, 6);

    // VALID: Set memory within bounds
    memset(buffer1, 'A', 6);
}

void test_cases2() {
    char src[5] = "hello";  // Buffer is too small for null terminator
    char dest[5];

    // INVALID: Source string exceeds destination buffer size
    strcpy(dest, src);  // Buffer overflow
}

void test_cases3(){
    char src[5] = "hello";  // Buffer is too small for null terminator
    char dest[5];

    // INVALID: Copy more bytes than source buffer contains
    strncpy(dest, src, 10);  // Out-of-bounds read from src
}

void test_Case4(){
    // INVALID: Compare memory regions out of bounds
    char buffer1[5] = "buff";
    char buffer2[5] = "buff";
    memcmp(buffer1 + 3, buffer2 + 3, 5);  // Out-of-bounds access
}

