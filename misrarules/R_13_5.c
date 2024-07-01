#include <stdio.h>

int sideEffectFunction() {
    int count = 0;
    return ++count;
}

int main() {
    int a = 5;
    int b = 0;

    // Example violating the MISRA C rule
    if (a > 0 || sideEffectFunction() > 0) {
        printf("a > 0 || sideEffectFunction() > 0 is true\n");
    } else {
        printf("a > 0 || sideEffectFunction() > 0 is false\n");
    }
    // Example violating the MISRA C rule
    if (a > 0 ||  a++ ) {
        printf("a > 0 || sideEffectFunction() > 0 is true\n");
    } else {
        printf("a > 0 || sideEffectFunction() > 0 is false\n");
    }
    // Correct usage without side effect in the right-hand operand
    if (a > 0 || b > 0) {
        printf("a > 0 || b > 0 is true\n");
    } else {
        printf("a > 0 || b > 0 is false\n");
    }
    printf("The right hand operand of a logical && or || operator shall not contain persistent side effects");
    return 0;
}
