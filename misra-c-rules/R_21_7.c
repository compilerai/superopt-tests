#include <stdio.h>
#include <stdlib.h>

int main() {
    
    const char *floatStr = "123.456";
    double floatVal = atof(floatStr);
    printf("String: \"%s\" -> atof: %f\n", floatStr, floatVal);

    
    const char *intStr = "123";
    int intVal = atoi(intStr);
    printf("String: \"%s\" -> atoi: %d\n", intStr, intVal);

    const char *longStr = "1234567890";
    long longVal = atol(longStr);
    printf("String: \"%s\" -> atol: %ld\n", longStr, longVal);

    const char *longLongStr = "123456789012345";
    long long longLongVal = atoll(longLongStr);
    printf("String: \"%s\" -> atoll: %lld\n", longLongStr, longLongVal);

    return 0;
}
