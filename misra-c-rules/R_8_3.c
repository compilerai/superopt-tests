#include <stdio.h>

const int global_variable = 10;
extern int global_variable;

int f(int );
const int g(int );
int h(int );
int func1(const int a);
int func2(int a);

int func(int x) { return x ;}
int g(int x) { return ++x; }
const int h(int x) {return ++x;}
int func1(int a) { return a; }
int func1(const int a) { return a; }

int main(void) {
    return 0;
}