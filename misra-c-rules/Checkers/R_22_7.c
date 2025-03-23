#include <stdio.h>

void compliant_fgetc_check(FILE *file) {
    int ch = fgetc(file);
    if (ch == EOF) {  // ✅ Correct: Direct comparison with unmodified return value
        printf("End of file reached or error occurred.\n");
    }
}

void non_compliant_fgetc_check(FILE *file) {
    int ch = fgetc(file);
    if ((ch & 0xFF) == EOF) {  // ❌ Incorrect: Modification before comparison
        printf("End of file reached or error occurred.\n");
    }
}

void compliant_fputc_check(FILE *file) {
    if (fputc('A', file) == EOF) {  // ✅ Correct: Direct comparison with unmodified return value
        printf("Error writing to file.\n");
    }
}

void non_compliant_fputc_check(FILE *file) {
    int result = fputc('A', file);
    if ((result + 1) == EOF) {  // ❌ Incorrect: Modification before comparison
        printf("Error writing to file.\n");
    }
}

void compliant_fclose_check(FILE *file) {
    if (fclose(file) == EOF) {  // ✅ Correct: Direct comparison with unmodified return value
        printf("Error closing file.\n");
    }
}

void non_compliant_fclose_check(FILE *file) {
    int result = fclose(file);
    if ((result * -1) == EOF) {  // ❌ Incorrect: Modification before comparison
        printf("Error closing file.\n");
    }
}
