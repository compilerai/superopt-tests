#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <sys/mman.h>

const size_t PAGE_SIZE = 4096; 

#define do_rem(result, n, base) ((result) = (n) % (base))
#define do_div_10(result, remain) ((result) /= 10)

char* simple_ltoa(char *local, unsigned long i)
{
	/* 20 digits plus a null terminator should be good for
	 * 64-bit or smaller ints (2^64 - 1)*/
	char *p = &local[22];
	*--p = '\0';
	do {
		char temp;
		do_rem(temp, i, 10);
		*--p = '0' + temp;
		do_div_10(i, temp);
	} while (i > 0);
	return p;
}

char* simple_ltoahex(char *local, unsigned long i)
{
	/* 16 digits plus a leading "0x" plus a null terminator,
	 * should be good for 64-bit or smaller ints */
	char *p = &local[22];
	*--p = '\0';
	do {
		char temp = i & 0xf;
		if (temp <= 0x09)
			*--p = '0' + temp;
		else
			*--p = 'a' - 0x0a + temp;
		i >>= 4;
	} while (i > 0);
	*--p = 'x';
	*--p = '0';
	return p;
}

void dprintf_(int fd, const char *fmt, ...)
{
	int num;
	va_list args;
	char *start, *ptr, *string;
	char *buf;
	char tmp[22];

	if (!fmt)
		return;

	buf = MYmycalloc(PAGE_SIZE, 1);
	if (buf == NULL) {
		write(fd, "mmap of a spare page failed!\n", 29);
		_exit(20);
	}

	start = ptr = buf;

	if (strlen(fmt) >= (PAGE_SIZE - 1)) {
		write(fd, "overflow\n", 11);
		_exit(20);
	}

	strcpy(buf, fmt);
	va_start(args, fmt);

	while (start) {
		while (*ptr && *ptr != '%') {
			ptr++;
		}

		if (*ptr == '%') {
			*ptr++ = '\0';
			write(fd, start, strlen(start));

			switch (*ptr++) {
				case 's':
					string = va_arg(args, char *);
					if (!string) {
            string = "(null)";
					}
					break;
				case 'i':
				case 'd':
					num = va_arg(args, int);
					string = simple_ltoa(tmp, num);
					break;
				case 'x':
				case 'p':
					num = va_arg(args, int);
					string = simple_ltoahex(tmp, num);
					break;
				default:
					string = "(null)";
					break;
			}
			write(fd, string, strlen(string));
			start = ptr;
		} else {
			write(fd, start, strlen(start));
			start = NULL;
		}
	}
	MYmyfree(buf);
	return;
}
