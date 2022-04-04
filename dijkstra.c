#include "dijkstra.h"
#include "opener.h"

#include <limits.h>

void iteracja(pair *node, int *sprawdzone, double *odleglosci, int fromvert)
{
    pair *curr = node;
    sprawdzone[fromvert] = 1;
    while (curr)
    {
        if(odleglosci[fromvert] + curr->weight < odleglosci[curr->vertex])
            odleglosci[curr->vertex] = odleglosci[fromvert] + curr->weight;
        curr = curr->next;
    }
}

void dijkstra(graph *graf, int fromvert, int tovert)
{
    int sprawdzone[graf->rows * graf->columns];
    double odleglosci[graf->rows * graf->columns];
    int wsz_przeszukane = 0;

    for (int i = 0; i < graf->rows * graf->columns; i++)
    {
        sprawdzone[i] = 0;
        odleglosci[i] = INT_MAX - 1;
    }
    odleglosci[fromvert] = 0;

    double min_odl = 100000;

    iteracja(graf->edges[fromvert], sprawdzone, odleglosci, fromvert); //pierwsza iteracja
    for (int i = 0; i < graf->rows * graf->columns; i++)
    {
        printf("%d: %d, %lf\n", i, sprawdzone[i], odleglosci[i]);
    }

    while(wsz_przeszukane != 1)
    {
        int ind = 0;
        for (int i = 0; i < graf->rows * graf->columns; i++)
        {
            if (sprawdzone[i] != 1 && odleglosci[i] < min_odl)
            {
                ind = i;
                min_odl = odleglosci[i];
            }
        }
        iteracja(graf->edges[ind], sprawdzone, odleglosci, ind);
        printf("\npunkt: %d, odleglosc: %lf\n", ind, min_odl);
        // zamykanie petli

        for (int i = 0; i < graf->rows * graf->columns; i++)
        {
            printf("%d: %d, %lf\n", i, sprawdzone[i], odleglosci[i]);
        }
        wsz_przeszukane = 1;
        for (int i = 0; i < graf->rows * graf->columns; i++)
        {
            if (sprawdzone[i] == 0)
            {
                printf("A\n");
                wsz_przeszukane = 0;
            }
        }
        min_odl = 10000;
        printf("\n");
    }
}