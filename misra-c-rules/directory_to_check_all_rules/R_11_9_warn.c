/*
The macro NULL shall be the only permitted form of integer null pointer constant
*/

// Rule 11.9 -> 0 should not be used as a null pointer constant

#include <stdio.h>

int main(void) {
    void *p = (void *)0; // Non-compliant
    void *t = NULL; // Compliant
    return 0;
}