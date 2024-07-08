#include<stdio.h>
void test1(int x) {
    for(int i=1;i<4;i++){
        switch(i){
          case 1: printf("1");
                  break;
        }
        default: printf("other element");
    }
}
void test2(int x) {
    if (x == 1) {
        case 1: break;// Error: case label used outside of switch statement
            // Do something
    }
}
void R_16_2_tests(){
  test1(4);
  test2(4);
}
int main(){
    R_16_2_tests();
    printf("A switch label shall only be used when the most closely-enclosing compound statement is the body of a switch statement");
}
