/*
    Octal and hexadecimal escape sequences shall be terminated
*/

#include <stdio.h>

int main(){
    printf("Hello\x0AWorld");
    // this should raise a warning
    return 0;
}