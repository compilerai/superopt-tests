int func1(int , int );
int func2(int a, int b);
int func3(int a, int b);
int main(void) {
    return 0;
}
// missing parameters name in forward declaration.
int func1(int a, int b) {
    return (a + b);
}
// params name dont match.
int func2(int a, int c) {
    return (a + c);
}
// matches exactly.
int func3(int a, int b) {
    return (a- b);
}

