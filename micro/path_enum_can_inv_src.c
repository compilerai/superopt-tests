// adapted from DOWNHEAP() of bzip2_modified.c

int weight[516];
int heap[260];
int nHeap;

void
path_enum_can_inv(int z)
{
   int zz = z;
   int tmp = heap[zz];
   int yy;
   while (1) {                                    // #1
      yy = zz << 1;
      if (yy > nHeap) break;                      // #2
      if (weight[tmp] < weight[heap[yy]]) break;  // #3
      heap[zz] = heap[yy];
      zz = yy;
   }
}

/*
 Path enumeration chooses loop head '#1' as anchor node

 With this choice, the correlation of exit path requires additional invariant (yy <= nHeap) at the do-while loop head in dst

 * With u = 1, the exit path only includes exits from #2 and #3
 
   In dst, after loop inversion we get a do-while loop where the exit condition
   is next iteration value of #2.
   Thus, we get dst-edge-cond-implies-src-edge-cond failure (because there is no
   corresponding path for do-while's cond fail exit path).

 * With u > 2, the exit path includes direct and 1-unrolled exits from #2 and #3
 
   In absence of (yy <= nHeap) invariant at loop head, the exit from do-while's cond fail (which has a write)
   can potentially be triggered along with direct exit from #2 in src.
   In this case the dst path has a memory write but the src one does not and we get memory equality failure.

 The solution?  Either do better invariant inference or choose better anchor node
*/
