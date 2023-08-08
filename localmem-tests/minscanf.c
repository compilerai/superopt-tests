#include <stdio.h>
#include <stdarg.h>

// rudimentary minscanf

int MYmy_isblank(int);
int read_int();
void read_string(char* s);
int match_char(char tc);

//int MYmy_isspace(int);
//int MYmy_isdigit(int);
//int MYmy_getchar(void);
//int MYmy_ungetc(int, FILE*);

//int
//read_int()
//{
//  int ret = 0;
//  char ch;
//  while (MYmy_isdigit(ch = MYmy_getchar())) {
//    ret = ret*10 + (ch-'0');
//  }
//  if (ch == EOF)
//    return ret;
//  MYmy_ungetc(ch, stdin);
//  return ret;
//}
//
//void
//read_string(char* s)
//{
//  char ch;
//  while (!MYmy_isspace(ch = MYmy_getchar())) {
//    *s++ = ch;
//  }
//  // no need to unget space character
//  *s = '\0';
//}
//
//int match_char(char tc)
//{
//	char c;
//	while (MYmy_isblank(c = MYmy_getchar())); // blanks are not considered
//	if (c == EOF || c != tc) {
//		return 0;
//	}
//	return 1;
//}

void DBG();

int minscanf(char* fmt, ...)
{
	va_list ap;
	char *p;
	int ret = 0;

	va_start(ap, fmt);
	for (p = fmt; *p; ++p) {
    DBG();
		if (*p != '%') {
			if (!MYmy_isblank(*p)) { // blanks are ignored
			  if (!match_char(*p))
			    break;
			}
			continue;
		}
		switch (*++p)
		{
			case 'd' :
			  *va_arg(ap, int*) = read_int();
				++ret;
				break;
			case 's' :
				read_string(va_arg(ap, char*));
				++ret;
				break;
			case '%':
			  if (!match_char('%'))
			    goto end;
			  break;
			default :
				goto end; // ERROR!
		}
	}
end:
	va_end(ap);
	return ret;
}
