/*
    The lowercase character 'l' shall not be used in a literal suffix
*/

#include <stdio.h>

int main(){
    // use of L should not raise a warning
    long x = 1L; // this is a literal suffix
    return 0;
}