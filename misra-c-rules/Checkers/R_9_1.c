// #include <stdio.h>
// void sw(int y,int x){
//     x++;
// }
// // Main function to run all test cases
// int main() {
//     int x;
//     // int y=x;
//     // sw(5,x);
//     if(0){
//         int  z=5;
//         printf("de");
//     }
//     // printf("%d",y);
//     return 0;
// }
#include <stdio.h>

/* Test Case 1: Reading an uninitialized local variable */
void test_case_1() {
    int x;  // Local variable with automatic storage duration
    printf("Value of x: %d\n", x);  // Uninitialized read
}

/* Test Case 2: Reading an uninitialized local variable in a conditional block */
void test_case_2(int flag) {
    int y;  // Local variable with automatic storage duration
    if (flag) {
        y = 10;
    }
    printf("Value of y: %d\n", y);  // Uninitialized read if flag is 0
}

/* Test Case 3: Uninitialized variable used in arithmetic operation */
void test_case_3() {
    int a;  // Local variable with automatic storage duration
    int b = a + 5;  // Uninitialized read
    printf("Value of b: %d\n", b);
}

/* Test Case 4: Uninitialized variable in a loop */
void test_case_4() {
    int count;  // Local variable with automatic storage duration
    for (int i = 0; i < 5; ++i) {
        printf("Count: %d\n", count);  // Uninitialized read
    }
}

/* Test Case 5: Function with nested scope */
void test_case_5() {
    int z;  // Local variable with automatic storage duration
    {
        int inner = z;  // Uninitialized read
        printf("Inner value: %d\n", inner);
    }
    printf("Value of z: %d\n", z);  // Uninitialized read
}

/* Test Case 6: Function with local variable shadowing */
void test_case_6() {
    int a = 5;
    {
        int a;  // Local variable shadows outer 'a'
        printf("Shadowed a: %d\n", a);  // Uninitialized read
    }
    printf("Outer a: %d\n", a);
}

/* Test Case 7: Conditional initialization */
void test_case_7(int flag) {
    int value;  // Local variable with automatic storage duration
    if (flag) {
        value = 42;
    }
    printf("Value: %d\n", value);  // Uninitialized read if flag is 0
}
/* Test Case 8: Variable List Size initialization*/
void test_case_8() {
  int x;
  int vla1[x]; // warn: garbage as size
}
/* Test Case 9: Array Subscript*/
void test_case_9() {
  int i, a[10];
  int x = a[i]; // warn: array subscript is undefined
}
/* Test Case 10: Branch Variable */
void test_case_10() {
  int x;
  if (x) // warn
    return;
}
/* Test Case 11: Undefined Return */
int test_case_11() {
  int x;
  return x; // warn
}