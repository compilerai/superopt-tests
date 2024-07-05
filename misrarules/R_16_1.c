#include <stdio.h>

void testFallThrough(int value) {
    switch (value) {
        case 1:
        case 2:{
            printf("Case 2\n");
            break;
            }
        case 3:{
            printf("Case 3\n");// Explicit fall-through
            }
        case 4:
        case 5:
        case 6:{
            printf("Case 4\n");
            break;
        }
        default:
            printf("Default case\n");
            break;
    }
}

int main() {
    printf("All switch statements must be well-formed. In this rule, only checking for fall-through is performed; other well-formed criteria are checked in other MISRA rules.");
    return 0;
}