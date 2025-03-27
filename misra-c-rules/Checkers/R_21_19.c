#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Function demonstrating non-compliant modification of localeconv() return value
void modifyLocaleconv() {
    struct lconv *lc = localeconv();
    lc->decimal_point[0] = '.';  // Non-compliant: Modifying localeconv() result

}

// Function demonstrating non-compliant modification of getenv() return value
void modifyGetenv() {
    char *env_var = getenv("PATH");
    env_var[0] = 'X';  // Non-compliant: Modifying getenv() result
}

// Function demonstrating non-compliant modification of setlocale() return value
void modifySetlocale() {
    char *locale_str = setlocale(LC_ALL, NULL);
    locale_str[0] = 'Y';  // Non-compliant: Modifying setlocale() result
}

// Function demonstrating non-compliant modification of strerror() return value
void modifyStrerror() {
    char *error_str = strerror(1);
    error_str[0] = 'Z';  // Non-compliant: Modifying strerror() result
}