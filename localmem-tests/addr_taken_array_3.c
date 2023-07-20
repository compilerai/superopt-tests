void foo(int*,unsigned char*);

// 3 local arrays
void addr_taken_array_3(int* a, unsigned char* b)
{
   unsigned char auc[256];
   int ai[256];
   int ai2[256];

#pragma clang loop vectorize(disable) unroll(disable)
   for (int i = 0; i <= 255; i++) {
     ai[i] = i^a[i];
   }
#pragma clang loop vectorize(disable) unroll(disable)
   for (int i = 0; i <= 255; i++) {
     auc[i] = b[i]&(unsigned char)a[i];
   }
#pragma clang loop vectorize(disable) unroll(disable)
   for (int i = 0; i <= 255; i++)
     ai2[i] = ~ai[i];
   foo(ai2, auc);
}
