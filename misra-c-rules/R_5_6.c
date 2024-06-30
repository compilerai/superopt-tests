/*
MISRA_C R.5.6 :: A typedef name shall be a unique identifier
*/
#include<stdio.h>
/*
incorrect
*/
typedef int MyType;
typedef float MyType;
/*
correct
*/
typedef int IntType;
typedef float FloatType;
int  main () {
    return 0;
}
// This was already handled in Clang.