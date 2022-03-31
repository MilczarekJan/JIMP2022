#include "opener.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void readnumber(char* textline, int i)
{
    //index od i do dwokropka
}

void file_open(FILE *inf)
{
    char textline[128];
    while (fgets(textline, sizeof(textline), inf) != NULL)
    {
         printf("%s", textline);
        // pierwszy zrad es
        int i = 0;
        while (textline[i] != '\n')
        {
            if (isspace(i) == 1)
            {
                i++;
                continue;
            }
        }
    }
}