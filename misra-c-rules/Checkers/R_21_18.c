#include <string.h>
#include <stdio.h>
#include <stdint.h>

void test_valid_cases() {
    char src[20] = "Hello, World!";
    char dest[20];

    // VALID: Appropriate size for strncpy
    strncpy(dest, src, sizeof(dest));

    // VALID: Appropriate size for strncat
    strncat(dest, "!", sizeof(dest) - strlen(dest) - 1);

    // VALID: Appropriate size for memcpy
    char buf1[10] = "abcdef";
    char buf2[10];
    memcpy(buf2, buf1, sizeof(buf1));

    // VALID: Appropriate size for memset
    memset(buf2, 0, sizeof(buf2));

    // VALID: Appropriate size for memcmp
    int result = memcmp(buf1, buf2, sizeof(buf1));

    // VALID: Appropriate size for strlen (implicitly uses size_t)
    size_t len = strlen(src);

}

void test_invalid_cases() {
    char src[10] = "abcdef";
    char dest[10];

    // INVALID: Size larger than destination buffer
    strncpy(dest, src, 20);
}

void test_invalid_cases2() {
    char src[10] = "abcdef";
    char dest[10];

    // INVALID: Size larger than remaining space in destination
    strcpy(dest, "Hello");
    strncat(dest, ", World!", 20);

}

