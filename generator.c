#include "generator.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomdouble(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void creategraph(FILE *filename, int columns, int rows, double fromrange, double torange, int cohesive)
{
    char tresc[50];
    int temp_node;
    double temp_edge;
    sprintf(tresc, "%d ", columns);
    fputs(tresc, filename);
    sprintf(tresc, "%d\n\t", rows);
    fputs(tresc, filename);
    if (cohesive == 1)
    {
      for (int i = 0; i < rows * columns; i++)
      {
        if ((i + 1) % columns != 0)
        {
          sprintf(tresc, " %d :", i + 1);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        if(i % columns != 0)
        {
          sprintf(tresc, " %d :", i - 1);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        if(i >= columns)
        {
          sprintf(tresc, " %d :", i - columns);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        if(i <= (rows - 1) * columns)
        {
          sprintf(tresc, " %d :", i + columns);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        fputs("\n\t", filename);
      }
    }
    else
    {
      for (int i = 0; i < rows * columns; i++)
      {
        if ((i + 1) % columns != 0)
        {
          sprintf(tresc, " %d :", i + 1);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        if(i % columns != 0)
        {
          sprintf(tresc, " %d :", i - 1);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        if(i >= columns)
        {
          /*
          sprintf(tresc, " %d :", i - columns);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
          */
          //Powstaje de facto kilka niepołączonych ze sobą grafów ("wierszy")
        }
        if(i <= (rows - 1) * columns)
        {
          sprintf(tresc, " %d :", i + columns);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        fputs("\n\t", filename);
    }
  }
}
