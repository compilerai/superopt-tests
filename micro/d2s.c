#define REP1(M) M(1)
#define REP2(M) REP1(M); M(2)
#define REP3(M) REP2(M); M(3)
#define REP4(M) REP3(M); M(4)
#define REP5(M) REP4(M); M(5)
#define REP6(M) REP5(M); M(6)
#define REP7(M) REP6(M); M(7)
#define REP8(M) REP7(M); M(8)

#define STEP do {            \
    *x = (*a)&(*b);          \
    *y = ~(*a)&(*c);         \
    *z = (*x)^(*y);          \
    *c = (*x)/(*y);          \
    *d = (*z)*(*c);          \
    *a = (*c)/2;             \
    *b = (*d)/2;             \
  } while (0)

#define STEP_N(i) STEP
#define STEPS(N) REP##N(STEP_N)

#define F_N_STEPS(N) \
  int non_linear_comp_## N ##_steps(int* a, int* b, int* c, int* d, int* x, int* y, int* z) \
  {                                                                                        \
    STEPS(N);                                                                              \
    return *x**y**z**c**d;                                                                 \
  }

F_N_STEPS(1)
F_N_STEPS(2)
// anything more than 2 steps chokes our preprocessing stage (pointsto and other analyses)
// F_N_STEPS(3)
// F_N_STEPS(5)
