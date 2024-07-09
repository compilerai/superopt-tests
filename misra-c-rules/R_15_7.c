/*
All if - else if shall terminate with else.
*/
#include<stdio.h>
int main(){
	int a = 1;
    /*
    shall not raise the warning. it is a single if.
    */
	if (a == 0) {
		printf("II->GetName()");
	};
    if (a == 10) {
        printf("II->GetName()");
    } else {
        printf("II->GetMain()");
    }
    /*
    shall raise the warning.
    */
    if (a + 1 == 2) {
        a--;
    }  else if (a == -2)  {
        a++;
    }
    /*
        shall raise the warning.
    */
   if (a == 1) {
        if (a > 0) {

        } else if (a == 1) {

        }
   } else {
        a++;
   }
	return 0;
}