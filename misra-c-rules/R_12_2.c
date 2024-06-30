// MISRA C R 12.2 :: The right hand operand of a shift operator shall lie in the range zero to one less than the width 
// in bits of the essential type of the left hand operand
int main () {
    int x = 55;
    /*
        currently this gets caught.
    */
    int y1 = x >> (-1);
    int a = -3;
    /*
        currently this doesn't gets caught.
    */
    int y2 = x >> (a);
    return 0;
}