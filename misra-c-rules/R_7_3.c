
long helper(){
    return 0l; // non-compliant
}

int main(){
    long num1 = 145l; // non-compliant
    long long num3 = 23249824ll; // non-compliant
    unsigned long long  num5 = 9324850ull; // non-compliant

    int x = 13l; // non-compliant

    char* l;

    long num2 = 223L;
    long long num4 = 234432LL;
    unsigned long long num6 = 3849ULL;
    
    return 0;

}