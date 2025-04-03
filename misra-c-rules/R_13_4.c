// test_assignment_result_usage.c
#include <stdio.h>

// Function with assignment inside another expression (violates the rule)
static int test1() {
  int a = 5;
  int b;
  b=6;
  b = (a = 10);  // ❌ Violation: Assignment result used
  int x = 0;
  if (x = 1) {  // ❌ Violation: Assignment result used in if condition
    return 1;
  }
  int y = 0;
  while (y = 5) {  // ❌ Violation: Assignment result used in while condition
    y--;
  }
  return (b = a + 1);  // ❌ Violation
}
int main() {
  return 0;
}
