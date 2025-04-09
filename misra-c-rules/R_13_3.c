#include <stdio.h>

void non_compliant_cases() {
    int x = 1;
    int y = 2;

    // Non-compliant: ++x is in same full expression as assignment (side effect)
    y = ++x;

    // Non-compliant: x++ used in printf (side effect: function call + increment)
    printf("Value: %d\n", x++);

    // Non-compliant: x-- in a function argument
    printf("Sum: %d\n", x-- + y);

    // Non-compliant: multiple increments in one expression
    x = ++x + x++;
}

void compliant_cases() {
    int x = 1;
    int y = 2;

    // Compliant: ++x is the only side effect in the full expression
    ++x;

    // Compliant: increment and then use in a separate expression
    x++;
    y = x;

    // Compliant: function call without side effects with increment
    x--;
    printf("Value: %d\n", x);

    // Compliant: multiple statements with individual side effects
    ++x;
    y = x + 1;
}

int main() {
    non_compliant_cases();
    compliant_cases();
    return 0;
}
