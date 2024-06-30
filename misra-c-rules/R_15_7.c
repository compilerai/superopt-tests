/*
All if - else if shall terminate with else.
*/
#include<stdio.h>
int main(){
	int a = 1;
    /*
    shall raise the error
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
    shall not raise the warning.
    */
    if (a + 1 == 2) {
        a--;
    }  else if (a == -2)  {
        a++;
    } else {
        a += 10;
    }
	return 0;
}