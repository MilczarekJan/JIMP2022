#include "bfs.h"
#include "opener.h"

void sasiedzi(pair *node, int *odwiedzone, int *kolejka, int *pockon, int i)
{
    pair *curr = node;
    while (curr)
    {
        if(odwiedzone[curr->vertex] == 0)
        {
            odwiedzone[curr->vertex] = 1;
            printf("%d: %d\n", i, curr->vertex);
        }
        curr = curr->next;

    }
}

void bfs(graph *graf)
{
    int odwiedzone[graf->rows * graf->columns];
    int kolejka[graf->rows * graf->columns];
    int pockon[2] = {0, 1};

    for (int i = 0; i < graf->rows * graf->columns; i++)
    {
        kolejka[i] = -1;
        odwiedzone[i] = 0;
    }
    kolejka[0] = 0;
    for (int i = 0; i < graf->rows * graf->columns; i++)
    {
        sasiedzi(graf->edges[i], odwiedzone, kolejka, pockon, i);
        //printf("%d\n", kolejka[i]);
    }
    for (int i = 0; i < graf->rows * graf->columns; i++)
    {
        printf("%d\n", odwiedzone[i]);
    }
}