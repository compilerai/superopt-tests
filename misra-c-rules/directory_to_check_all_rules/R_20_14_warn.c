/*
All #else, #elif and #endif preprocessor directives shall reside in the same file as the #if, #ifdef or #ifndef directive to which they are related
*/

#include <stdio.h>

#define Check_A 10

#ifdef Check_A        // <=
#if Check_A > 5
static int a = 5;
#elif Check_A > 2
static int a = 2;
#else
static int a = 0;
#endif                // <=

int main(void)
{
  return a;
}


