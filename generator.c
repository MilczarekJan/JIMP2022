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
        else if(i % columns != 0)
        {
          sprintf(tresc, " %d :", i - 1);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        else if(i >= columns)
        {
          sprintf(tresc, " %d :", i - columns);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        else if(i <= (rows - 1) * columns)
        {
          sprintf(tresc, " %d :", i + columns);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        /*
        sprintf(tresc, " %d :", i + 1);
        fputs(tresc, filename);
        sprintf(tresc, "%f ", randomdouble(fromrange, torange));
        fputs(tresc, filename);
        sprintf(tresc, " %d :", i - 1);
        fputs(tresc, filename);
        sprintf(tresc, "%f ", randomdouble(fromrange, torange));
        fputs(tresc, filename);
        sprintf(tresc, " %d :", i + columns);
        fputs(tresc, filename);
        sprintf(tresc, "%f ", randomdouble(fromrange, torange));
        fputs(tresc, filename);
        sprintf(tresc, " %d :", i - columns);
        fputs(tresc, filename);
        sprintf(tresc, "%f ", randomdouble(fromrange, torange));
        fputs(tresc, filename);
        */
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
        else if(i % columns != 0)
        {
          sprintf(tresc, " %d :", i - 1);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
        else if(i >= columns)
        {
          /*
          sprintf(tresc, " %d :", i - columns);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
          */
          //Powstaje de facto kilka niepołączonych ze sobą grafów ("wierszy")
        }
        else if(i <= (rows - 1) * columns)
        {
          sprintf(tresc, " %d :", i + columns);
          fputs(tresc, filename);
          sprintf(tresc, "%f ", randomdouble(fromrange, torange));
          fputs(tresc, filename);
        }
    }
  }
    /*
    if (cohesive==1)
    {
      for (int i = 0; i < rows * columns; i++)
      {
          if (i == 0) // lewy górny narożnik
          {

              sprintf(tresc, " %d :", i + 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f \n\t", randomdouble(fromrange, torange));
              fputs(tresc, filename);
          }
          else if (i == columns - 1) // prawy górny narożnik
          {
              sprintf(tresc, " %d :", i - 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f \n\t", randomdouble(fromrange, torange));
              fputs(tresc, filename);
          }
          else if (i == columns * rows - 1) // prawy dolny narożnik
          {
              sprintf(tresc, " %d :", i - 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i - columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f \n\t", randomdouble(fromrange, torange));
              fputs(tresc, filename);
          }
          else if (i == (rows - 1) * columns) // lewy dolny narożnik
          {
              sprintf(tresc, " %d :", i + 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i - columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f \n\t", randomdouble(fromrange, torange));
              fputs(tresc, filename);
          }
          else if (i > 0 && i < columns - 1) // górny środek grafu
          {
              sprintf(tresc, " %d :", i - 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f \n\t", randomdouble(fromrange, torange));
              fputs(tresc, filename);
          }
          else if (i > (rows - 1) * columns && i < columns * rows - 1) // dolny środek grafu
          {
              sprintf(tresc, " %d :", i - 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i - columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f \n\t", randomdouble(fromrange, torange));
              fputs(tresc, filename);
          }
          else if (i % columns == 0 && i != 0) // lewy środek grafu
          {
              sprintf(tresc, " %d :", i - columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f \n\t", randomdouble(fromrange, torange));
              fputs(tresc, filename);
          }
          else if ((i + 1) % columns == 0) // prawy środek grafu
          {
              sprintf(tresc, " %d :", i - columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i - 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f \n\t", randomdouble(fromrange, torange));
              fputs(tresc, filename);
          }
          else // węzły w środku grafu
          {
              sprintf(tresc, " %d :", i - columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + columns);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i - 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f ", randomdouble(fromrange, torange));
              fputs(tresc, filename);
              sprintf(tresc, " %d :", i + 1);
              fputs(tresc, filename);
              sprintf(tresc, "%f \n\t", randomdouble(fromrange, torange));
              fputs(tresc, filename);
          }
      }
    }
*/
    fclose(filename);
}
