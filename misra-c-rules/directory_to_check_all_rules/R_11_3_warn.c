// A cast shall not be performed between a 
// pointer to object type and a pointer to a different object type


#include <stdio.h>

int main(){
    int x = 2;
    int* p = &x;
    char* r = (char*) p;
    return 0;
}
