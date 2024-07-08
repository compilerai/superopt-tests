#include <stdio.h>
typedef struct
{
  size_t len;
  int data[]; // flexible array, should raise warning
} S;
typedef struct
{
  size_t len;
  int data[1]; // flexible array, should raise warning
} S1;
typedef struct
{
  size_t len;
  int data[5]; // not flexible array
} S2;
int main(){
    // R_18_7();
    int arr[1];
    printf("Flexible array members shall not be declared");
}