// this may be wrong not worked on it enough

#include <stdio.h>

#define abc "abc"
#define f(x) abc#x + (x)
#define g(x) abc##(x) + (x)


int main(){
    return 0;
}