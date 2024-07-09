static void foo(int x);  //in header.h
static void foo(int x)   //in source.cpp
{
}
static void foo(int x);  //in header.h
void foo(int x)          //in source.cpp
{
}
static short y;       //in header.h
static short y = 10;  //in source.c
int main (){
    return 0;
}