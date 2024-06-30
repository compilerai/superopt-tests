/*
MISRA_C RULE R_8_12 :: Within an enumerator list, the value of an implicitly-specified enumeration constant shall be unique
*/
#include<stdio.h>
#include<stdbool.h>
/*
implicitly HEARTS gets assigned 4 , hence a warning is raised.
*/
enum Suits 
{ 
  SUITS_SPADES = 1,
  SUITS_CLUBS,
  SUITS_DIAMONDS,  
  SUITS_HEARTS,
  SUITS_UNKNOWN = 4 
};

int main(){
    char ch = 'a';
    char ch2 = 'b';
    unsigned int a = 22;
}