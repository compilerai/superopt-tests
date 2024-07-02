/*
Emergent language features shall not be used
*/

/*
    This rule bans the following: * stdnoreturn.h, stdatomic.h, thread.h, stdalign.h * Bounds Checking functions in Annex K * _Generic, _Noreturn, _Thread_local, _Alignas and _Alignof keywords
*/


#include <stdio.h>
/*
    Error is raised by 
    #include <stdnoreturn.h>
    #include <threads.h>
    #include <stdatomic.h>
    #include <stdalign.h>


    _Thread_local int myVariable;
    _Alignas int myVariable;
    _Alignof int myVariable;
*/

// use _Generic
#define cbrt(X) _Generic((X), long double: cbrtl, default: cbrt, float: cbrtf)(X)

#define type_selector(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    default: "unknown")

_Noreturn void myFunction();
// _Noreturn int x;
// 
int main(){
    return 0;
}