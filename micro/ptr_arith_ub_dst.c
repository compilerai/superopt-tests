void
ptr_arith_ub(int* src, int n, int* dst)
{
  if (n < 0)
    return;
  int* src_end = src+n;
  while (src != src_end) {
    *dst = *src + 42;
    dst++;
    src++;
  }
}
/* At loop head, in order to prove `(dst-edgecond => src-edgecond)`, `src < src_end` is required but we cannot prove it
   on the entry edge to the loop because `src < src+n` need not be true i.e.  `(src+n)` can overflow.

 * On the src side, we are guaranteed that `src+n-1` will not overflow because there is a memory access in the loop body for it and it is UB if the address computation
   overflow.

 * C standard says that 1-address past the block is still a valid address and has the usual guarantee of no-overflow (6.5.6.8).

 * But in our case, we need more than this, we need the assume information upfront while proving well-formedness condition (the assume is associated with memory access, not address computation).
*/
