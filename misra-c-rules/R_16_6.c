// This needs a change.
// Ignoring default label , there shall be atleast 2 clauses. Currently , we have included default as well.
// MISRA C R 16.6 :: Every switch statement shall have atleast two clauses.
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
// Doesnt raise warnings now , but changes will be made.
void test2(int x) {
    switch (x) {
        case 1:
            printf("Case 1\n");
            break;
        default:
            printf("Default case\n");
            break;
    }
}
// Does raise warnings now ....
void test2(int x) {
    switch (x) {
        default:
            printf("Default case\n");
            break;
    }
}

int main() {
    test1(2); test1(3);
    test2(1); test2(0);
    return 0;
}