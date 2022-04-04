#ifndef OPENER_H
#define OPENER_H

#include "generator.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

graph* file_open(FILE *inf);
void deallocate_graph(graph* redundantgraph);
void showgraph(graph* testedgraph);

#endif
