#define REP1(M) M(1)
#define REP2(M) REP1(M), M(2)
#define REP3(M) REP2(M), M(3)
#define REP4(M) REP3(M), M(4)

#define VLi(I) v##I
#define VL(N) REP##N(VLi)

#define VDLi(I)  v##I[4*i]
#define VDL(N) int REP##N(VDLi)

#define VILN(N) \
  int foo ## N(); \
  int vla_in_loop_ ## N(unsigned n) \
  { \
    int r = 0; \
    for (unsigned i = 1; i < n; ++i) { \
      VDL(N); \
      r += foo ## N(VL(N), i); \
    } \
    return r; \
  } \

VILN(1)
VILN(2)
VILN(3)
VILN(4)
