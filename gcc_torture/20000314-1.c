#include"eqchecker_helper.h"
int main ()
{
  long winds = 0;

  while (winds != 0)
    {
      if (*(char *) winds)
	break;
    }

  if (winds == 0 || winds != 0 || *(char *) winds)
    exit (0);

  Mymyabort ();
}


