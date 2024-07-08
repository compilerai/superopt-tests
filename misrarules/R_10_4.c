// Boolean for Boolean values true/false: '_Bool';
// signed for signed integers or unnamed enums: 'signed char', 'signed short', 'signed int', 'signed long', 'signed long long', 'enum { .... };';
// unsigned for unsigned integers: 'unsigned char', 'unsigned short', 'unsigned int', 'unsigned long', 'unsigned long long';
// floating for floating-point values: 'float', 'double', 'long double';
// character for characters only: 'char';
// named enum for a named set of user-defined values: 'enum name { .... };'.
//Exception: the essential types of the left and right operands of the operators '+', '-', '+=', and '-=' can be 'character' and 'signed' / 'unsigned' respectively.
#include<string.h>
#include<stdio.h>
enum {A,D};
enum namedenum{B,C};
void R_10_4_tests(){
  int x=4;
  int y=6;
  float fx=0.9f;
  char a='c';
  unsigned int ux=6;
  _Bool bx=1;
  int c=x+y;
  c=x+A;
  c=x+B;
  c=x+ux;   //should raise warning
  c=x+a;    //should raise warning
  c=x+fx;   //should raise warning
  c=x+bx;   //should raise warning
  c=a+4;
  c=a+ux;
  c=a+4.0;    //should raise warning
}
int main(){
    R_10_4_tests();
    printf("Both operands of an operator in which the usual arithmetic conversions are performed shall have the same essential type category.");
}
