// correct.
void test1(){
    const char *x = "hi";
}
// incorrect.
void test2(){
    char* x = "hello"; // would raise !!
}
// both .
void test3(){
    char *message1 = "Hello, World!";    // would raise.
    char *m2 = message1; // wont.
}
// array.
void test4(){
    char xy[] = "Hi";
    char *z = xy;
}
//
int main () {
    test1();
    test2();
    test3();
    test4();
    return 0;
}