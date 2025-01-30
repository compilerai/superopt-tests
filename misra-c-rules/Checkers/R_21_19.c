#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
    // localeconv() returns a pointer to struct lconv
    struct lconv *lc = localeconv();
    
    // getenv() returns a pointer to a string (char*)
    char *env_var = getenv("PATH");
    
    // setlocale() returns a pointer to a string (char*)
    char *locale_str = setlocale(LC_ALL, NULL);
    
    // strerror() returns a pointer to a string (char*)
    char *error_str = strerror(1);

    // Compliant Usage: Only reading the values
    printf("Decimal point: %s\n", lc->decimal_point);
    printf("Environment variable: %s\n", env_var);
    printf("Current locale: %s\n", locale_str);
    printf("Error message: %s\n", error_str);

    // Non-compliant Usage: Modifying returned values (violates const requirement)
    // These should not be done as per MISRA-C rules

    // lc->decimal_point[0] = '.';  // Non-compliant: Modifying localeconv() result
    // env_var[0] = 'X';            // Non-compliant: Modifying getenv() result
    // locale_str[0] = 'Y';         // Non-compliant: Modifying setlocale() result
    // error_str[0] = 'Z';          // Non-compliant: Modifying strerror() result

    return 0;
}