#include <stdio.h>
#include <stdlib.h>

int main() {
    int status;

    printf("Executing 'ls' command to list directory contents:\n");
    status = system("ls");
    if (status == -1) {
        perror("Error executing 'ls' command");
        return 1;
    }

    return 0;
}
