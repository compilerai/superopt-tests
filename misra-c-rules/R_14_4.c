int correct(int x) {
    if (x > 1) {
        x--;
    } else {
        x++;
    }
    return x;
}
int wrong(int x) {
    if (x) {
        x--;
    } else {
        x++;
    }
    return x;
}
int main(void) {
    return 0;
}