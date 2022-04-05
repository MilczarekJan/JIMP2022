#include "bfs.h"
#include "opener.h"

#include <stdlib.h>
#include <stdio.h>

void sasiedzi(pair *node, int *odwiedzone, int *kolejka, int *wskazniki)
{
    int i = 0;
    pair *curr = node;
    while (curr)
    {
        if(odwiedzone[curr->vertex] == 0)
        {
            odwiedzone[curr->vertex] = 1;
            if(wskazniki[i] != -1)
                i++;
            if(wskazniki[i] == -1)
                wskazniki[i] = curr->vertex;

            //printf("%d\n", curr->vertex);
        }
        curr = curr->next;

    }
}

void bfs(graph *graf)
{


    int odwiedzone[graf->rows * graf->columns];
    int kolejka[graf->rows * graf->columns];
    int wskazniki[4] = {-1, -1, -1, -1};
    int wsz_sprawdzone = 0;
    int i_kolejki = 1;

    for (int i = 0; i < graf->rows * graf->columns; i++)
    {
        kolejka[i] = -1;
        odwiedzone[i] = 0;
    }
    kolejka[0] = 0;
    odwiedzone[0] = 1;

    for(int i = 0; i < graf->rows * graf->columns; i++)
    {
        if(kolejka[i] == -1)
        {
            printf("graf niespojny\n");
            exit(EXIT_SUCCESS);
        }
        
        sasiedzi(graf->edges[kolejka[i]], odwiedzone, kolejka, wskazniki);


        for (int j = 0; j < 4; j++)
        {
            if(wskazniki[j] != -1)
            {
                kolejka[i_kolejki] = wskazniki[j];
                wskazniki[j] = -1;
                i_kolejki++;
            }
        }

        wsz_sprawdzone = 1;
        for (int j = 0; j < graf->rows * graf->columns; j++)
        {
            if(odwiedzone[j] == 0)
                wsz_sprawdzone = 0;
        }
    }

    //for (int i = 0; i < graf->rows * graf->columns; i++)
    //    printf("%d: %d\n", i, kolejka[i]);

    if(wsz_sprawdzone == 1)
        printf("graf spojny\n");
}