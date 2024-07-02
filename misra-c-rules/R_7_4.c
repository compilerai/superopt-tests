// MISRA C R 7.4 :: A string literal shall not be assigned to an object unless the object's type is "pointer to const-qualified char"
// void test1(){
//     const char *greeting = "Good morning!"; 
//     char editableGreeting[] = "Good morning!"; 
//     editableGreeting[5] = 'a';
// }
// int main () {
//     const char *message1 = "Hello, World!";  // Correct: pointer to const-qualified char
//     char *message2 = "Hello, World!";  // Incorrect: pointer to non-const char
//     return 0;
// }
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
    return 0;
}