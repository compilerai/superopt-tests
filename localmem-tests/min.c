#include <stdarg.h>

void check(char* p);
void print_char(char p);
void print_int(int p);

/* minprintf: minimal printf with variable argument list */
void min(char *fmt, ...)
{
  va_list ap;
  char *p, *sval;
  int ival;

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    check(p);
    if (*p != '%') {
      print_char(*p);
      continue;
    }
    switch (*++p) {
      case 'd':
        ival = va_arg(ap, int);
        print_int(ival);
        break;
      case 's':
        for (sval = va_arg(ap, char *); *sval; sval++)
          print_char(*sval);
        break;
      default:
        break;
    }
  }
  va_end(ap);
}
