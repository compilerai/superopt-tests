void test1(){
    const char *x = "hi";
}
void test2(){
    char* x = "hello"; // would raise !!
}
void test3(){
    char *message1 = "Hello, World!";    // would raise.
    char *m2 = message1; // wont.
}
void test4(){
    char xy[] = "Hi";
    char *z = xy;
}

int main () {
    test1();
    test2();
    return 0;
}