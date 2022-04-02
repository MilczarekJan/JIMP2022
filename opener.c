#include "opener.h"
#include "generator.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void readnumber(char* textline, int i)
{
    //index od i do dwokropka
}

void file_open(FILE *inf)
{
    char textline[128];
    char *ch_columns = NULL;
    char *ch_rows = NULL;
    int columns = 0;
    int rows = 1;

    fscanf(inf, "%d %d", &columns, &rows);

    printf("%d %d\n", columns, rows);

    char c;
    int i = 0;

    while (fgets(textline, sizeof(textline), inf) != NULL)
    {
        printf("%s", textline);
    }

    /*while ((c = fgetc(inf)) != EOF) // nie usuwac!
    {
        fputc(c, inf);

        if(c != '\n')
        {
            printf("%c", c);
        }
        else
        {
            printf("%c %d",  c, i);
            i++;
        }
    }*/
    printf("\n");
}