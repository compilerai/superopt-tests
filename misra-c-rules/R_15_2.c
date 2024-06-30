/*
 RULE_15.2 :  The goto statement shall jump to a label declared later in the same function
*/
#include<stdio.h>
/*
goto Location appears after goto :: Shall not raise any warnings..
*/
void case1(){
    int a = 55;
    if (a & 1) {
        goto odd;
    } else { 
        goto even;
    }
    even:
        printf("%d is even", a);
        return;
    odd:
        printf("%d is odd", a);
        return;
}

/*
goto Location appears before goto :: shall raise warnings...
*/
void case2(){
    int cnt = 2;
    even:
        if (cnt == 1) {
            printf("is even");
            return;
        }
        else {
            printf("..\n");
        }
    int a = 7;
    if (a & 1) {
        goto odd;
    } else { 
        cnt--;
        goto even;
    }
    odd:
        printf("%d is odd", a);
        return;
}

int main(){
    case1();
    case2();
    return 0;
}