const int cts[] = { 0x66, 0x65, 0x67, 0x60 };

void MYmyprintf(char const* fmt, ...);
void MYmyscanf(char const* fmt, ...);

int rod(int n)
{
  char zz[] = "0123456789";
  MYmyprintf("Scanning %d chars", n);
  char t[n];
  MYmyscanf("%s",t);
  int ret = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    MYmyprintf("Round #...\n", i);
    zz[j] ^= t[i];
    if (++j >= sizeof zz) j = 0;
  }
  ret += zz[0] + cts[n%((sizeof cts)/sizeof(cts[0]))];
  MYmyprintf("Returning %d", ret);
  return ret;
}
