double pow(double, double);

int fcall_fp(int blockSize)
{
  return (int)pow(2, blockSize+1)-1;
}

int fcall_fp2(int blockSize)
{
  int i1 = (int)pow(2, blockSize+1)-1;

  return (int)pow(2, blockSize+1)-i1;
}

int fcall_fp2a(int blockSize)
{
  int i1 = (int)pow(2, blockSize+1)-1;

  return (int)pow(i1, blockSize+1)-1;
}
