#include <stdio.h>
void* MYmymalloc(size_t);

#define KB (1024)

struct spec_fd_t {
    int limit;
    int len;
    int pos;
    unsigned char *buf;
} spec_fd[3];

int
mac_check_pass(int input_size)
{
  int i;
  unsigned char *validate_array = (unsigned char *)MYmymalloc(input_size*KB);
  if (validate_array == NULL) {
	  return -1;
  }
  for (i = 0; i < input_size*KB; i++) {
	  // buf is potentially allocated on heap;
	  // an access to buf in dst must be matched by an access in src
	  validate_array[i] = spec_fd[0].buf[i];
  }
  return 0;
}

int
mac_check_fail(int input_size)
{
  int i;
  unsigned char *validate_array = (unsigned char *)MYmymalloc(input_size*KB);
  if (validate_array == NULL) {
	  return -1;
  }
  for (i = 0; i < input_size*KB; i++) {
	  // buf is potentially allocated on heap;
	  // an access to buf in dst must be matched by an access in src
	  validate_array[i] = spec_fd[0].buf[i];
  }
  return 0;
}
