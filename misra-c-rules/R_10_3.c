// MISRA _ C R.10.3 Test
#include <stdio.h>

/*Long <--> Int*/
void Test1() {
    long long y1 = 922337207LL;
    int x1 = y1;

    int x2 = 55;
    long long y2 = x2;
}

/*float <--> Int*/
void Test2() {
    int y1 = 200;
    float f1 = y1;    

    float f2 = 10.1f;
    int y2 = f2;
}

/*double <--> Int*/
void Test3(){
    int y1 = 200;
    double f1 = y1;    

    double f2 = 10.1;
    int y2 = f2;
}

/*float <--> double*/
void Test4() {
    float y1 = 3.14f;
    double x1 = y1;

    double x2 = 3.22;
    float y2 = x2;
}

/*UInt <--> Int*/
void Test5() {
    int y = -1;
    unsigned int x = y;
}

/*Char <--> Int*/
void Test6() {
    int y1 = 65;
    char x1 = y1;
    
    y1 = 1000;
    x1 = y1;

    char x2 = 'A';
    int y2 = x2;
}

/*Long <--> Short*/
void Test7() {
    long long y1 = 32767L;
    short x1 = y1; 

    short x2 = 10;
    long long y2 = x2;
}

int main() {
    return 0;
}