#include <stdarg.h>

void MYmyDBG(char* p);
void print_char(char p);
void print_int(int p);

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
  va_list ap; /* points to each unnamed arg in turn */
  char *p, *sval;
  int ival;

  va_start(ap, fmt);
  /* make ap point to 1st unnamed arg */
  for (p = fmt; *p; p++) {
    MYmyDBG(p); // required
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
  va_end(ap); /* clean up when done */
}
