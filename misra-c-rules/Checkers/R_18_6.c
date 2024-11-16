#include<stdlib.h>
char const *p;

void test() {
  char const str[] = "string";
  p = str; // warn
}

void* test1() {
   return __builtin_alloca(12); // warn
}

void test2() {
  static int *x;
  int y;
  x = &y; // warn
}

int* violation_function() {
    int local_var = 10;  // Automatic storage.
    return &local_var;   // Violates the rule.
}

int* compliant_dynamic_memory_function() {
    int* dynamic_var = (int*)malloc(sizeof(int)); // Persistent storage.
    if (dynamic_var) {
        *dynamic_var = 20;
    }
    return dynamic_var; // Compliant.
}

int* compliant_global_var_function() {
    static int persistent_var; // Persistent storage (static duration).
    persistent_var = 30;
    return &persistent_var; // Compliant.
}
