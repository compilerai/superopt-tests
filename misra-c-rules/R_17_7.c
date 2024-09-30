int helper(){
    return 42;
}

void helper2(){
    (void)helper();
}

int helper3(){
    return 44;
}


int helper4(){
    return (int) helper();
}

int main(){
    helper();  // non compliant
    helper2(); 
    int y = helper3();
    helper4(); // non compliant
    return 0;
}