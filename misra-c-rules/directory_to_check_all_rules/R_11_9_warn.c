/*
The macro NULL shall be the only permitted form of integer null pointer constant
*/

// Rule 11.9 -> 0 should not be used as a null pointer constant

#include <stdio.h>

int main(void) {
    void *p = 0; // Non-compliant
    void *r = (void *)0; // Non-compliant
    void *q = NULL; // Compliant
    return 0;
}