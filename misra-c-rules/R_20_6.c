#include <stdio.h>

// Define some macros
#define PRINT(arg) printf("%d\n",(arg))           
#define SUM(define, ifndef) ((define) +(ifndef))    //should raise warning
#define SUM1(ifdef,a) ((a)+(ifdef))      //should raise warning
#define SUM2(include, error) ((include)+(error))  //should raise warning
#define SUM3(a, b) ((a) + (b))
#define MESSAGE(message) #message
#define CHECK(cond, msg) if (!(cond)) { printf("%s\n", (msg)); }
void R_20_6() {
    int x=5;
} 
int main(){
    R_20_6();
    printf("Tokens that look like a preprocessing directive shall not occur within a macro argument");
}

// #define: Helps define a macro

// #undef: It undefines a macro

// #include: It lets you include a file in the source code program

// #ifdef: It is used to include a code section if a specific macro is defined by #define

// #ifndef: It includes a code section if a specific macro is not defined by #define

// #endif: It indicates the end of #endif

// #if: It checks for the specified condition

// #else: It executes the alternate code when #if fails

// #error: It stops program compilation

// #warning: It continues the compilation process by displaying warning messages in the console window.

// #region and #endregion: They increase the readability of code sections using the expansion and collapse features.