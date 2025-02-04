#include <ctype.h>
#include <stdio.h>
 
typedef unsigned char uint8_t;
typedef _Bool bool_t;
// typedef int int32_t;
 
void use_bool ( bool_t use_bool_param ){
  return;
}
 
static bool_t f_13 ( uint8_t a )
{
  int arr[5] = { 10, 20, 30, 40, 50 };
  // unsigned char a = 9;
  // bool_t x = islower ( t ) !=0;
  return (
              ( isdigit ( (int) a ) != 0 )  /* Compliant     */
           && ( isalpha ((uint8_t) 'b' ) != 0 )  /* Compliant     */
            && ( islower ( EOF ) != 0 )  /* Compliant     */
           && ( isalpha ( 256  ) != 0 )  /* Non-compliant */
         );
}
 
void R_21_13 ( void )
{
  bool_t bl;
  bl = f_13( 3U );
  use_bool( bl );
}
 
int main(){
  R_21_13();
  return 0;
}