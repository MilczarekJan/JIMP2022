#ifndef DIJKSTRA_H
#define DOJKSTRA_H

#include "opener.h"

void get_edges(pair *node);

void iteracja(pair *node, int *niesprawdzone, double *odleglosci, int fromvert);

void dijkstra(graph *graf, int fromvert, int tovert);

#endif