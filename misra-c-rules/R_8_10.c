/*
MISRA_C R.8.10 :: An inline function shall be declared with the static storage class
*/
#include <stdio.h>
/*
shall not raise warnings
*/
static inline int add(int a, int b) {
    return a + b;
}
/*
shall raise warnings
*/
inline int sub(int a, int b) {
    return a - b;
}
int main() {
    int x = 5, y = 3;
    int result = add(x, y);
    printf("Result: %d\n", result);
    return 0;
}