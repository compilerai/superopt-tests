/*
MISRA C R.5.7 :: A tag name shall be a unique identifier
*/

/*
Warning wont be raised here.
*/
struct Employee {
    int id;
    char name[50];
};

struct Department {
    int dept_id;
    char dept_name[50];
};

enum Color {
    RED,
    GREEN,
    BLUE
};

/*
Warning will be raised here
*/
struct Data {
    int id;
    char value[50];
};

struct Data {  // Error: Duplicate tag name
    float id;
    double value;
};

enum Data {  // Error: Duplicate tag name
    VALUE1,
    VALUE2,
    VALUE3
};

/*
Warning will be raised here.
*/
struct Data2 {
    int id;
    char value[50];
};

union Data2 {  // Error: Duplicate tag name
    float floatValue;
    double doubleValue;
};

enum Data3 {  // Error: Duplicate tag name
    RR,
    BB
};

int main() {
    return 0;
}