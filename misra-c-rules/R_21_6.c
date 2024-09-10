#include <stdio.h>

void test1(){
    // opening a file and perfornign operations
    FILE *file = fopen("sample_text.txt", "w");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", "sample_text.txt");
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fputs("This is a test file.\n", file);

    fclose(file);
}

void test2(){
    FILE *file = fopen("sample_text.txt", "r");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", "sample_text.txt");
    }
    // Using fscanf to read formatted input from the file
    char str[50];
    fscanf(file, "%s", str);
    printf("First word in the file: %s\n", str);

    // Using fgets to read a line from the file
    fgets(str, sizeof(str), file);
    printf("Rest of the line: %s", str);

    // Using fgetc to read a character from the file
    char ch;
    ch = fgetc(file);
    printf("First character of the next line: %c\n", ch);
    fclose(file);

}

int main(){
    test1();
    test2();
    return 0;

}