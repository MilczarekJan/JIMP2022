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
    printf("\nGraph file created succesefully. You can find it in the containing folder.\n\n");
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
        if(i < (rows - 1) * columns)
        {
          sprintf(tresc, " %d :", i + columns);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        if (i != rows * columns - 1)
        {
          fputs("\n\t", filename);
        } else fputs("\n", filename);
      }
    }
    else
    {
      for (int i = 0; i < rows * columns; i++)
      {

        if ((i + 1) % columns != 0)
        {
          if (i + 1 == rows * columns - 1)
          {
            //Nie tworzyć ścieżki do ostatniego punktu
          }
          else
          {
            sprintf(tresc, " %d :", i + 1);
            fputs(tresc, filename);
            sprintf(tresc, "%f ", randomdouble(fromrange, torange));
            fputs(tresc, filename);
          }
        }
        if(i % columns != 0)
        {
            sprintf(tresc, " %d :", i - 1);
            fputs(tresc, filename);
            sprintf(tresc, "%f ", randomdouble(fromrange, torange));
            fputs(tresc, filename);
            //Tutaj warunek nie jest tworzony ponieważ sytuacja w której  i - 1 == rows * columns -1 jest niemożliwa
        }
        if(i >= columns)
        {
            sprintf(tresc, " %d :", i - columns);
            fputs(tresc, filename);
            sprintf(tresc, "%f ", randomdouble(fromrange, torange));
            fputs(tresc, filename);
            //Tutaj warunek nie jest tworzony ponieważ sytuacja w której  i - columns == rows * columns -1 jest niemożliwa
        }
        if(i <= (rows - 1) * columns)
        {
          if (i + columns == rows * columns - 1)
          {
            //Nie tworzyć ścieżki do ostatniego punktu
          }
          else
          {
            sprintf(tresc, " %d :", i + columns);
            fputs(tresc, filename);
            sprintf(tresc, "%f ", randomdouble(fromrange, torange));
            fputs(tresc, filename);
          }
        }
        if (i != rows * columns - 1)
        {
          fputs("\n\t", filename);
        }
        else fputs("\n", filename);
      }
    }
}
