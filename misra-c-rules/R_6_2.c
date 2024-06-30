// MISRA C R.6.2 :: Single-bit named bit fields shall not be of a signed type
// i.e. bit fields of unit length can only be unsigned .
struct StatusFlags {
    unsigned int is_ready : 1;    // Correct: single-bit field is unsigned
    unsigned int has_error : 1;   // Correct: single-bit field is unsigned
    unsigned int reserved : 6;    // 6-bit field can be unsigned
};

struct IncorrectFlags {
    signed int is_ready : 1;    // Incorrect: single-bit field is signed
    signed int has_error : 1;   // Incorrect: single-bit field is signed
    unsigned int reserved : 6;  // This is fine, as it is multi-bit and unsigned
};

struct AnotherIncorrectExample {
    int control_signal : 1; // Incorrect: single-bit field is signed by default
};

int main () {
    return 0;
}