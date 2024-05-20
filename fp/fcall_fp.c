double pow(double, double);

int fcall_fp(int blockSize)
{
  return (int)pow(2, blockSize+1)-1;
}
