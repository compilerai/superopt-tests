#include <stdio.h>

#define INVALID_MACRO(x, y) #x##y  // Non-compliant: '#' followed immediately by '##'

#define VALID_MACRO(x, y) #x "_" #y  // Compliant: '#' is not immediately followed by '##'

void non_compliant_usage() {
    printf("%s\n", INVALID_MACRO(Hello, World)); // Non-compliant case
}

void compliant_usage() {
    printf("%s\n", VALID_MACRO(Hello, World)); // Compliant case
}

int main() {
    compliant_usage();
    return 0; 
}
