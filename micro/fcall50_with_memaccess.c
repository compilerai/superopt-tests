int a[100];
int foo(int a);

void fcall50_with_memaccess(int i)
{
  a[0] = 0;
  foo(a[i]); //1
  a[1] = 1;
  foo(a[i]); //2
  a[2] = 1;
  foo(a[i]); //3
  a[3] = 1;
  foo(a[i]); //4
  a[4] = 1;
  foo(a[i]); //5
  a[5] = 1;
  foo(a[i]); //6
  a[6] = 1;
  foo(a[i]); //7
  a[7] = 1;
  foo(a[i]); //8
  a[8] = 1;
  foo(a[i]); //9
  a[9] = 1;
  foo(a[i]); //10
  a[10] = 1;

  foo(a[i]); //1
  a[11] = 1;
  foo(a[i]); //2
  a[12] = 1;
  foo(a[i]); //3
  a[13] = 1;
  foo(a[i]); //4
  a[14] = 1;
  foo(a[i]); //5
  a[15] = 1;
  foo(a[i]); //6
  a[16] = 1;
  foo(a[i]); //7
  a[17] = 1;
  foo(a[i]); //8
  a[18] = 1;
  foo(a[i]); //9
  a[19] = 1;
  foo(a[i]); //10
  a[20] = 1;

  foo(a[i]); //1
  a[21] = 1;
  foo(a[i]); //2
  a[22] = 1;
  foo(a[i]); //3
  a[23] = 1;
  foo(a[i]); //4
  a[24] = 1;
  foo(a[i]); //5
  a[25] = 1;
  foo(a[i]); //6
  a[26] = 1;
  foo(a[i]); //7
  a[27] = 1;
  foo(a[i]); //8
  a[28] = 1;
  foo(a[i]); //9
  a[29] = 1;
  foo(a[i]); //10
  a[30] = 1;

  foo(a[i]); //1
  a[31] = 1;
  foo(a[i]); //2
  a[32] = 1;
  foo(a[i]); //3
  a[33] = 1;
  foo(a[i]); //4
  a[34] = 1;
  foo(a[i]); //5
  a[35] = 1;
  foo(a[i]); //6
  a[36] = 1;
  foo(a[i]); //7
  a[37] = 1;
  foo(a[i]); //8
  a[38] = 1;
  foo(a[i]); //9
  a[39] = 1;
  foo(a[i]); //10
  a[40] = 1;

  foo(a[i]); //1
  a[41] = 1;
  foo(a[i]); //2
  a[42] = 1;
  foo(a[i]); //3
  a[43] = 1;
  foo(a[i]); //4
  a[44] = 1;
  foo(a[i]); //5
  a[45] = 1;
  foo(a[i]); //6
  a[46] = 1;
  foo(a[i]); //7
  a[47] = 1;
  foo(a[i]); //8
  a[48] = 1;
  foo(a[i]); //9
  a[49] = 1;
  foo(a[i]); //10
  a[50] = 1;
}
