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
/* At loop head, in order to prove `(dst-edgecond => src-edgecond)` for the loop exit edge, we require that `src+4*i = src+4*n` implies `i >= n` but this cannot be proven
   because `4*n` can potentially overflow:

   (1)  The inductive invariants at loop head include `i <= n`, `i >= 0` and `n >= 0`, making top-bit of `i` and `n` identically 0.
   (2)  The collected assumes assert non-overflow of `4*i` (through `src[i]`) but not of `4*n` because it does not show in src program.
   (3)  Thus, `4*n` can overflow with `4*i = 4*n` not implying `i >= n` (the counterexample being `i` and `n` differing by second to top bit)

 * The missing invariant is no-overflow assumption for `src+4*n` computation.  This assumption is valid because:

   (1) The src program is computing `src+4*i` with `i` ranging from `0` to `n-1`.
   (2) C standard says that 1-element past the last element is still a valid address and has the usual guarantee of no-overflow (6.5.6.8).
   (3) Therefore, `src+4*n` can be computed with no-overflow guarantee.

 * Note that merely adding and collecting the 1-past last element assume will not make the proof go through in this case:

   (1) The collected assume will be that `src+4*(i+1)` will not overflow.
   (2) This does not imply that `src+4*n` will not overflow.
   (3) The no-overflow assume `src+4*n` will be collected in the last iteration of the loop, thus we essentially need an unbounded lookahead on collection of assumes.
   (4) IOW, we need the assume: ForAll(j, (j in [0,n)) => NoOverflow(src+4*(j+1))) at the loop head.
   (5) We do not have any mechanism for inferring such assumes at the moment.
*/
