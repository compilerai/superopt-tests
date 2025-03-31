// adapted from bzip2.sortIt
int *ftab;
#define BIGFREQ(b) (ftab[((b)+1) << 8] - ftab[(b) << 8])
void consume(int*);
void d2s_local_nested_loops(int h)
{
  int i, j, vv;
  int runningOrder[256];

  for (i = 0; i <= 255; i++) runningOrder[i] = i;
  for (i = h; i <= 255; i++) {
    vv = runningOrder[i];
    j = i;
    while (BIGFREQ(runningOrder[j-h]) > BIGFREQ(vv) ) {
      runningOrder[j] = runningOrder[j-h];
      j = j - h;
      if (j <= (h - 1)) goto zero;
    }
zero:
    runningOrder[j] = vv;
  }
  consume(runningOrder);
}
