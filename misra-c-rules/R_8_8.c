static void f1(int x);
static void f1(int x)  { }
// 
static void f2(int x);
void f2(int x) { }
// 
void f3(int x);
static void f3(int x) { }
// 
void f4(int x);
void f4(int x) {}
// without forward declarations.
void f5(int x) { }
static void f6(int x) { }
// 
int main (){
    return 0;
}