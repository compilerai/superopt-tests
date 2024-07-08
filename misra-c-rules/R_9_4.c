#include<string.h>
#include<stdio.h>
struct st{
    int x;
    int y;
};
void R_9_4_tests() {
    int a[2]={ [0]=4,[1]=4}; 
    int b[3]={[0]=1, [0]=3, [1]=1000};//should raise warning
    struct st c={.x=4,.y=7};
    struct st d={.x=4,.x=5,.y=7};// should raise warning
}
int main(){
    R_9_4_tests();
    printf("An element of an object shall not be initialised more than once");
}
