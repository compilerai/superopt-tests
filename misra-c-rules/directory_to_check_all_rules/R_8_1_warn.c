/*
Types shall be explicitly specified
*/
#include <stdio.h>
int main(){
    // this should not raise a warning
    int x = 1237; // this is an integer constant
    auto y  = 23; // as auto cannot be used as a type specifier, this should raise an Error
    /*
        can be tested on these two also C auto implements these
        extern z;
        void foo(a, b) {
            return a + b;
        }
    */
    return 0;
}
    