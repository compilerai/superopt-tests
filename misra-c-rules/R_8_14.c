/*
MISRA_C R.8.14 : The restrict type qualifier shall not be used
*/
#include <stdio.h>
/*
restrict shall not be used.
*/
void use(int* a, int* b, int* restrict c) {
    *a += *c;
    *b += *c;
}
void use2(int* a, int* restrict c) {
    *a += *c;
}

int main(void) {
    int a = 50, b = 60, c = 70;
    use(&a, &b, &c);
    printf("%d %d %d \n", a, b, c); // Output: 120 130 70
    return 0;
}