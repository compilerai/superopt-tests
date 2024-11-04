#include<stdio.h>
//Test Case 1
int t1;
extern int t1;
extern int T1;
extern int t1;  //should raise warning
//Test Case 2
extern int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa;
extern int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab;// shuold raise warning
// Test Case 3
extern int func1();
extern int func1(); // should raise warning
extern int Func1(); // should not raise warning
int main(){
    {
        extern int t1; //should raise warning
        extern int func1(); //should raise warning
    }
    return 0;
}
