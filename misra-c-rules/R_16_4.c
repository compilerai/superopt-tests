// MISRA C R 16.4 :: Every switch statement shall have a default label
#include <stdio.h>
void test1(int x) {
    switch (x) {
        case 1:
            printf("Case 1\n");
            break;
        case 2:
            printf("Case 2\n");
            break;
        default:
            printf("Default case\n");
            break;
    }
}
void test2(int x) {
    switch (x) {
        case 1:
            printf("Case 1\n");
            break;
        case 2:
            printf("Case 2\n");
            break;
    }
}
int main(void) {
    test1(1); test1(2);
    test2(3);
    return 0;
}