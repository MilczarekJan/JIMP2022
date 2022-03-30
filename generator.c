#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

double randomdouble(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
void creategraph(FILE* new_file, int ilosckolumn, int iloscwierszy, double dolnagranica, double gornagranica)
//void creategraph(char* nazwa, int iloscwierszy, int ilosckolumn, double dolnagranica, double gornagranica)
{
  char tresc[50];
  int wezeltymczasowy;
  double krawedztymczasowa;
  sprintf(tresc, "%d ", ilosckolumn);
  fputs(tresc, new_file);
  sprintf(tresc, "%d\n\t", iloscwierszy);
  fputs(tresc, new_file);
  for (int i = 0; i < iloscwierszy*ilosckolumn; i++)
  {
    if (i==0) //lewy górny narożnik
    {

      sprintf(tresc, " %d :", i+1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f \n\t", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
    }
    else if (i==ilosckolumn-1) //prawy górny narożnik
    {
      sprintf(tresc, " %d :", i-1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f \n\t", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
    }
    else if (i==ilosckolumn*iloscwierszy-1) //prawy dolny narożnik
    {
      sprintf(tresc, " %d :", i-1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i-ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f \n\t", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
    }
    else if (i==(iloscwierszy-1)*ilosckolumn) //lewy dolny narożnik
    {
      sprintf(tresc, " %d :", i+1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i-ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f \n\t", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
    }
    else if(i>0 && i<ilosckolumn-1)//górny środek grafu
    {
      sprintf(tresc, " %d :", i-1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f \n\t", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
    }
    else if(i>(iloscwierszy-1)*ilosckolumn && i<ilosckolumn*iloscwierszy-1) //dolny środek grafu
    {
      sprintf(tresc, " %d :", i-1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i-ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f \n\t", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
    }
    else if(i%ilosckolumn == 0 && i!=0) //lewy środek grafu
    {
      sprintf(tresc, " %d :", i-ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f \n\t", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
    }
    else if((i+1)%ilosckolumn == 0) //prawy środek grafu
    {
      sprintf(tresc, " %d :", i-ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i-1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f \n\t", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
    }
    else //węzły w środku grafu
    {
      sprintf(tresc, " %d :", i-ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+ilosckolumn);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i-1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f ", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
      sprintf(tresc, " %d :", i+1);
      fputs(tresc, new_file);
      sprintf(tresc, "%f \n\t", randomdouble(dolnagranica,gornagranica));
      fputs(tresc, new_file);
    }
    }
    //if ((i==0 && (j==0 || j==iloscwierszy-1))||(i==ilosckolumn-1 && (j==0 || j==iloscwierszy-1)))
    fclose(new_file);
  }
