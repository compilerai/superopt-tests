#include <stdio.h>

void *memcpy(void *dest, const void *src, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        ((char*)dest)[i] = ((char*)src)[i];
    }
}

void copier(char *x){
    printf("%p\n", (void*)x);
    printf("%p\n", (void*)(x-2));
    memcpy(x-2,x,10*sizeof(char));
}
int main(){ 
    char str1[] = "abcdefghijkl";
    copier(str1);
}
