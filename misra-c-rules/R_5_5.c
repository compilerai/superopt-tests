#define AREA(l,b) (l*b)
#define ALPHA 5 

#define x m
#define yz x + 4
#define beta gamma

struct testing{
    int x;  // (1) used macro here
    int y;
    int alpha;
    int pp;
};

int main(){
    // printf("value of alpha is %d\n", ALPHA);
    int AREA  = AREA(3,4); // (2)  name of identidier same as macro name
    int x = yz;  // (3) user macro here
    int alpha  = 5; 
    struct testing myStruct;
}


