#include <stdlib.h>
#include <stdio.h>

int dbglvl=4;
#define debug(level,str)           { if (level<dbglvl) printf(str); }
#define debug1(level,str, a)       { if (level<dbglvl) printf(str, a); }
#define debug2(level,str, a, b)    { if (level<dbglvl) printf(str, a,b); }
#define debug3(level,str, a, b, c) { if (level<dbglvl) printf(str,a,b,c); }


void *MYmymemcpy(void *dest, const void *src, size_t n);
void *MYmymemset(void *s, int c, size_t n);
void* MYmymalloc(size_t);
void MYmyexit(int);

void spec_initbufs();
void spec_compress(int in, int out, int level);
void spec_uncompress(int in, int out, int level);
int spec_init ();
int spec_random_load (int fd);
int spec_load (int num, char *filename, int size);
int spec_read (int fd, unsigned char *buf, int size);
int spec_getc (int fd);
int spec_ungetc (unsigned char ch, int fd);
int spec_rewind(int fd);
int spec_reset(int fd);
int spec_write(int fd, unsigned char *buf, int size);
int spec_putc(unsigned char ch, int fd);
int debug_time();


#define MB (1024*1024)
#define FUDGE_BUF (100*1024)
#define VALIDATE_SKIP 1027
#define MAX_SPEC_FD 3
extern long int seedi;
extern struct spec_fd_t {
    int limit;
    int len;
    int pos;
    unsigned char *buf;
} spec_fd[MAX_SPEC_FD];


int main (int argc, char *argv[]) {
    int i, level;
    int input_size=64, compressed_size;
    char *input_name="input.combined";
    unsigned char *validate_array;
    seedi = 10;

    if (argc > 1) input_name=argv[1];
    if (argc > 2) input_size=atoi(argv[2]);
    if (argc > 3) 
	compressed_size=atoi(argv[3]);
    else
	compressed_size=input_size;

    spec_fd[0].limit=input_size*MB;
    spec_fd[1].limit=compressed_size*MB;
    spec_fd[2].limit=input_size*MB;
    spec_init();

    debug_time();
    debug(2, "Loading Input Data\n");
    spec_load(0, input_name, input_size*MB);
    debug1(3, "Input data %d bytes in length\n", spec_fd[0].len);

    validate_array = (unsigned char *)malloc(input_size*MB/1024);
    if (validate_array == NULL) {
	printf ("main: Error mallocing memory!\n");
	//exit (1);
	MYmyexit (1);
    }
    /* Save off one byte every ~1k for validation */
    for (i = 0; i*VALIDATE_SKIP < input_size*MB; i++) {
	validate_array[i] = spec_fd[0].buf[i*VALIDATE_SKIP];
    }


#ifdef DEBUG_DUMP
    int fd = open ("out.uncompressed", O_RDWR|O_CREAT, 0644);
    write(fd, spec_fd[0].buf, spec_fd[0].len);
    close(fd);
#endif

    spec_initbufs();

    for (level=7; level <= 9; level += 2) {
	debug_time();
	debug1(2, "Compressing Input Data, level %d\n", level);

	spec_compress(0,1, level);

	debug_time();
	debug1(3, "Compressed data %d bytes in length\n", spec_fd[1].len);

#ifdef DEBUG_DUMP
	{
	    char buf[256];
	    sprintf(buf, "out.compress.%d", level);
	    fd = open (buf, O_RDWR|O_CREAT, 0644);
	    write(fd, spec_fd[1].buf, spec_fd[1].len);
	    close(fd);
	}
#endif

	spec_reset(0);
	spec_rewind(1);

	debug_time();
	debug(2, "Uncompressing Data\n");
	spec_uncompress(1,0, level);
	debug_time();
	debug1(3, "Uncompressed data %d bytes in length\n", spec_fd[0].len);

#ifdef DEBUG_DUMP
	{
	    char buf[256];
	    sprintf(buf, "out.uncompress.%d", level);
	    fd = open (buf, O_RDWR|O_CREAT, 0644);
	    write(fd, spec_fd[0].buf, spec_fd[0].len);
	    close(fd);
	}
#endif

	for (i = 0; i*VALIDATE_SKIP < input_size*MB; i++) {
	    if (validate_array[i] != spec_fd[0].buf[i*VALIDATE_SKIP]) {
		printf ("Tested %dMB buffer: Miscompared!!\n", input_size);
		//exit (1);
		MYmyexit (1);
	    }
	}
	debug_time();
	debug(3, "Uncompressed data compared correctly\n");
	spec_reset(1);
	spec_rewind(0);
    }
    printf ("Tested %dMB buffer: OK!\n", input_size);

    return 0;
}
