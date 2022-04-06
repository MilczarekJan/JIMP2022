#include "opener.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void insert_edge(pair **head, int vertex, double weight)
{
    pair *edge = malloc(sizeof(pair));
    pair temppair;
    temppair.vertex = vertex;
    temppair.weight = weight;
    temppair.next = (*head);
    *edge = temppair;
    *head = edge;
}

graph *file_open(char *filename)
{
    FILE *inf = fopen(filename, "r");
    if(inf == NULL)
    {
        printf("Could not open file \"%s\".\n", filename);
        exit(EXIT_FAILURE);
    }

    int columns;
    int rows;

    fscanf(inf, "%d %d", &columns, &rows);

    pair** edges;
    edges = malloc(rows * columns * sizeof(pair));

    int c;
    int d;
    int line_no = 0;

    int vertex;
    double weight;

    while(fscanf(inf, "%d :%lf", &vertex, &weight) != -1)
    {
        c = fgetc(inf);
        d = fgetc(inf);
        insert_edge(&edges[line_no], vertex, weight);
        if(d == 10)
            line_no++;
        fputc(c, inf);
        fputc(d, inf);
    }

    graph *graf = malloc(sizeof(graph));
    graph tempgraf;
    tempgraf.edges = edges;
    tempgraf.rows = rows;
    tempgraf.columns = columns;
    *graf = tempgraf;

    //printf("%d\n", graf->edges[2]->vertex);

    fclose(inf);

    return graf;
}

