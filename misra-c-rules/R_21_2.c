#include <stdio.h>

static void test1(void) {
    int validIdentifier = 0;
    printf("Valid identifier: %d\n", validIdentifier);
}

void test2() {
    int _InvalidIdentifier = 1;
    printf("Invalid identifier: %d\n", _InvalidIdentifier);
}

void test3() {
    int __invalidIdentifier = 2;
    printf("Invalid identifier: %d\n", __invalidIdentifier);
}

void test4() {
    #define _InvalidMacro 1 
    #define __invalidMacroName 2
    printf("Invalid macro: %d   %d\n", _InvalidMacro, __invalidMacroName);
    #undef _InvalidMacro
}

void test5() {
    int stdio = 3;
    printf("Invalid standard library identifier: %d\n", stdio);
}

int main() {
    test1();  // Should pass
    test2();  // Should fail due to reserved identifier
    test3();  // Should fail due to reserved identifier
    test4();  // Should fail due to reserved macro name
    test5();  // Should fail due to standard library identifier
    return 0;
}