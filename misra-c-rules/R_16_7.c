// MISRA C R 16.7 :: A switch-expression shall not have essentially Boolean type
#include <stdio.h>
#include <stdbool.h>

void test1(int value) {
    switch (value) {
        case 0:
            printf("Case 0\n");
            break;
        case 1:
            printf("Case 1\n");
            break;
        default:
            printf("Default case\n");
            break;
    }
}

void test2(bool value) {
    switch (value) {
        case 0:
            printf("False case\n");
            break;
        case 1:
            printf("True case\n");
            break;
        default:
            printf("Default case\n");
            break;
    }
}

int main() {
    test1(false); test1(true);
    test2(false); test2(true);
    return 0;
}