#define REPC1(M) M(1)
#define REPC2(M) REPC1(M) , M(2)
#define REPC3(M) REPC2(M) , M(3)
#define REPC4(M) REPC3(M) , M(4)

#define REPSC1(M) M(1)
#define REPSC2(M) REPSC1(M) ; M(2)
#define REPSC3(M) REPSC2(M) ; M(3)
#define REPSC4(M) REPSC3(M) ; M(4)

#define VLi(I) v##I
#define VL(N) REPC##N(VLi)

#define VDLi(I)  v##I[n]
#define VDL(N) int REPC##N(VDLi)

#define OP1 +
#define OP2 -
#define OP3 &
#define OP4 ^

#define VALi(I)  v##I[i] = a[i] OP##I a[i]
#define VAL(N) REPSC##N(VALi)

#define VSLN(N) \
  int foo ## N(); \
  int vla_single_loop_ ## N(int *a, int n) \
  { \
    if (n <= 0) \
      return 0; \
    VDL(N); \
    _Pragma("clang loop vectorize(disable) unroll(disable)") \
    for (int i = 0; i < n; ++i) { \
      VAL(N); \
    } \
    return foo ## N(VL(N)); \
  } \

VSLN(1)
VSLN(2)
VSLN(3)
VSLN(4)
