/*
A cast shall not remove any const or volatile qualification from the type pointed to by a pointer
*/

#include <stdio.h>

int main(){
    const int x = 2;
    const int* p = &x;
    int* r = (int*) p;
    return 0;
}
