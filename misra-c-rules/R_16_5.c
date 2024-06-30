/*
RULE_16.5 :  A default label shall appear as either the first or the last switch label of a switch statement
*/
#include<stdio.h>
/*Default occurs at the end*/
void case1() {
    printf("Testing case1\n");
    int x = 1;
    switch(x) {
        case 1:
            printf("1\n");
        case 2:
            printf("2\n");
        default:
            printf("default\n");
    }
    printf("case1 Tested...\n\n");
}

/*Default occurs at the beginning*/
void case2() {
    printf("Testing case2\n");
    int x = 2;
    switch(x) {
        default:
            printf("default\n");
        case 1:
            printf("1\n");
        case 0:
            printf("2\n");
    }
    printf("case2 Tested...\n\n");
}

/*
Default occurs at both the ends : This is an error , multiple defaults can't appear.
*/
void case3() {
    printf("Testing case3\n");
    int x = 3;
    switch(x) {
        default:
            printf("default-1\n");
        case 1:
            printf("1\n");
        case 0:
            printf("2\n");
        default:
            printf("default-2\n");
    }   
    printf("case3 Tested...\n\n"); 
}

/*Default don't occurs at the extremes.*/
void case4() {
    printf("Testing case4\n");
    int x = 3;
    switch(x) {
        case 1:
            printf("1\n");
        default:
            printf("default\n");
        case 0:
            printf("2\n");
    }    
    printf("case4 Tested...\n\n");
}

/*
only default label appears --> A different warning for this will be raised , i.e. 16.6 , each switch shall have atleast 2 labels.
*/
void case5(){    
    printf("Testing case5\n");
    int x = 3;
    switch(x) {
        default:
            printf("default\n");
    }    
    printf("case5 Tested...\n\n");
}

/*
default label doesn't appears : A default label shall always appear : 16.4 , this rule was already in clang , it was ignored earlier.
*/
void case6(){
    printf("Testing case6\n");
    int x = 3;
    switch(x) {
        case 1:
            printf("1\n");
        case 3 : 
            printf("3\n");   
    }    
    printf("case6 Tested...\n\n");
}

int main(){
    case1();
    case2();
    case3();
    case4();
    case5();
    case6();
    return 0;
}