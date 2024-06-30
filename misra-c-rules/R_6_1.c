// MISRA C R.6.1 :: Bit-fields shall only be declared with an appropriate type
// i.e. for int, unsigned int.
// Shall raise warnings.
struct IncorrectFlags {
    char is_ready : 1;      // Incorrect: char is not an appropriate type
    short has_error : 1;    // Incorrect: short is not an appropriate type
    long reserved : 6;      // Incorrect: long is not an appropriate type
};

// shall not raise warnings.
struct StatusFlags {
    unsigned int is_ready : 1;
    unsigned int has_error : 1;
    unsigned int reserved : 6;
};

int main() {
    return 0;
}