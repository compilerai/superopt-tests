#include <stdio.h>

// Non-compliant: Defining a reserved identifier (starts with _ or __)
#define _MY_RESERVED_MACRO 100   // Non-compliant
#define __MY_RESERVED_MACRO 200  // Non-compliant

// Non-compliant: Undefining a standard macro
#undef __STDC__  // Non-compliant: __STDC__ is a reserved macro
#define _MY_HEADER_H     // ❌ Error: Starts with '_'
#undef __cplusplus       // ❌ Error: Starts with '__'
#define memcpy 123       // ❌ Error: Reserved 'mem' prefix
#define wcslen_impl      // ❌ Error: Reserved 'wcs' prefix
#define int              // ❌ Error: Keyword
#define __private_macro  // ❌ Error: Double underscore


// Compliant: Defining a user-defined macro without using reserved identifiers
#define MY_MACRO 300  // Compliant

int main() {
    return 0;
}
