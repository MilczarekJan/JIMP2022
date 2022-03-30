#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

int main(int argc, char const *argv[])
{
  srand (time(NULL));
  FILE* ouf = fopen("plikgrafu.txt","w");  
  creategraph(ouf,7, 4, 4.7, 15.6);
  printf("%d\n",111/10 );
  return 0;
}
