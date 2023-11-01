// adapted from DOWNHEAP() of bzip2_modified.c

int weight[516];
int heap[260];
int nHeap;

void
path_enum_can_inv(int z)
{
   int zz = z;
   int tmp = heap[zz];
   int yy = zz << 1;
   // loop inversion of while(1)
   if (yy <= nHeap) {
     do{
       if (weight[tmp] < weight[heap[yy]]) break;
       heap[zz] = heap[yy];
       zz = yy;
       yy = zz << 1;
     } while (yy <= nHeap);
   }
}

