#ifndef BFS_H
#define BFS_H

#include "opener.h"



#include <stdio.h>
#include <stdlib.h>

void sasiedzi(pair *node, int *odwiedzone, int *kolejka, int *wskazniki);

void bfs(graph *graf);

#endif