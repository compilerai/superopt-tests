/*
    The lowercase character 'l' shall not be used in a literal suffix
*/

#include <stdio.h>

int main(){
    // use of l should raise a warning
    long x = 1237l; // this is a literal suffix
    return 0;
}