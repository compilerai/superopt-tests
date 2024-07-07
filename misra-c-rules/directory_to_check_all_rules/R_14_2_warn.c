// Rule 14.2 forbids any modification of the loop counter inside the loop body
// for loop should be well formed

#include <stdio.h>

int main(void) {
    int i;
    for (i = 0; i < 10; i++) {
        i++; // Non-compliant
        // Raise error on Any assignment or modification of loop counter
    }
    
    int flag = 0;

    for (i = 0; ( i < 5 ) && !flag; i++ )
    {
        if ( i == 3 )
        {
            flag = 1; /* Compliant - allows early termination of loop */
        }
        else{
            flag = 0;
        } // remove else and can also check for 15.7 rule

        i = i + 3;     /* Non-compliant - altering the loop counter */
    }

    return 0;
}