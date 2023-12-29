#define BUFSZ 4096

void foo(int, char*, int);
void bar(int, char*, int);

void atail(int n, int fd_in, int fd_out)
{
  int i;
  for (i = 0; i < n; ++i) {
    char buf[BUFSZ];
    foo(fd_in, buf, BUFSZ);
    bar(fd_out, buf, BUFSZ);
  }
}
