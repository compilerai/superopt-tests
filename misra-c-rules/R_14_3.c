#include<stdio.h>
void test1(int x) {
  while(x>0){
    x++;
  }
}
void test2(int x) {
    int y=0;
    while(x){
        y++;
    }
}
void test3(int x){
    while(1){
        x++;
    }
}
void test4(){
    while(0){
        int x=5;
    }
}
void R_14_3_tests(){
  test1(4);
  test2(4);
  test3(5);
}
int main(){
    R_14_3_tests();
    printf("A switch label shall only be used when the most closely-enclosing compound statement is the body of a switch statement");
}
