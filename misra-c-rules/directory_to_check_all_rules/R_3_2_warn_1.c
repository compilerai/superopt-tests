/*
 Line splicing should not be used in inline comments
*/

#include <stdio.h>

int main(){
    // this is comment 1\     
    this is continued comment with spaces after backslash and should raise a warning 
    return 0;
}