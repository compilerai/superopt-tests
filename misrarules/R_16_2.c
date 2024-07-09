#include<stdio.h>
void test1(int x) {
    if (x == 1) {
        case 1: break;// Error: case label used outside of switch statement
            // Do something
    }
}
void R_16_2_tests(){
  test1(4);
}
int main(){
    R_16_2_tests();
    printf("A switch label shall only be used when the most closely-enclosing compound statement is the body of a switch statement");
}
