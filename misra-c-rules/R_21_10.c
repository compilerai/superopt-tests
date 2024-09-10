#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {

    clock_t start = clock();
    
    time_t current_time = time(NULL);
    printf("Current time: %s", ctime(&current_time));

    time_t later_time = current_time + 3600;
    double diff_seconds = difftime(later_time, current_time);

    struct tm *local_time = localtime(&current_time);
    printf("Local time: %s", asctime(local_time));

    time_t converted_time = mktime(local_time);
    printf("Converted time: %s", ctime(&converted_time));

    char buffer[80];
    strftime(buffer, 80, "Formatted time: %Y-%m-%d %H:%M:%S\n", local_time);


    struct tm *gmt_time = gmtime(&current_time);

    // 9. Use nanosleep to pause execution
    struct timespec req = {1, 500000000}; // 1.5 seconds
    printf("Pausing for 1.5 seconds...\n");
    nanosleep(&req, NULL);
    printf("Resumed execution.\n");

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return 0;
}
