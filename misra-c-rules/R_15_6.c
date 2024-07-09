// The body of an iteration-statement or a selection-statement shall be a compound statement
// Iteration -> for , while , do . Selection -> Switch , If , else if, else. Make the test cases

void TestFor(){
    for (int i = 0; i < 10; i++) {
        i += i;
    }

    for (int i = 0; i < 20; i++) i += i;
}

void TestWhile(){
    int i = 0;
    while (i < 10) i++;

    while (i < 10) {i++;}
}

void TestDo(){

}

void TestSwitch(){

}

void TestIf(){
    int x = 2;
    if (x == 1) {
        x--;
    } else x++;

    
    if (x == 2) x--;
    else {
        if (x == 3) {
            x *= 2;
        } else x--;
    }
}

int main(){
    return 0;
}