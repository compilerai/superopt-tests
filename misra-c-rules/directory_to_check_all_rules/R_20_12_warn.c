// this may be wrong not worked on it enough

#include <stdio.h>

#define GLUE(x, y) (x) ## (y)
#define STRINGIFY(x) #x

#define MACRO_A 100
#define MACRO_B 200

#define EXAMPLE_GLUE(a, b) GLUE((a), (b))
#define EXAMPLE_STRINGIFY(a) STRINGIFY(a)

#define VIOLATION_MACRO(a, b) STRINGIFY(a ## b)

int main() {
    int MACRO_A_VALUE = MACRO_A;
    int MACRO_B_VALUE = MACRO_B;

    printf("MACRO_A: %d\n", MACRO_A_VALUE);
    printf("MACRO_B: %d\n", MACRO_B_VALUE);

    // This violates MISRA Rule 20.12
    printf("Concatenated and Stringified: %s\n", VIOLATION_MACRO(MACRO_, A));

    return 0;
}
