#ifndef OPENER_H
#define OPENER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct pair
{
    int vertex;
    double weight;
    struct pair *next;
} pair;

typedef struct graph
{
    int rows;
    int columns;
    pair **edges;
} graph;


void insert_edge(pair **head, int vertex, double weight);

graph *file_open(FILE *inf);

#endif