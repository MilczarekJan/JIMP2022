#include "input_mgmt.h"
#include "generator.h"
#include "opener.h"
#include "dijkstra.h"
#include "bfs.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void print_edges(pair *node)
{
    pair *curr = node;
    while(curr)
    {
        printf("%d %lf ", curr->vertex, curr->weight);
        curr = curr->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int     opt;
    char    *mode = NULL;
    int     fromvert = 0;
    int     tovert = 4; // do ustawienia -1 wiele rzeczy później
    char    *filename = NULL;
    int     cohesive = 1;
    double  fromrange = 0;
    double  torange = 1;
    int     rows = 4;
    int     columns = 4;

    char    *progname = argv[0];

    graph   *examinedgraph = NULL;

    while((opt = getopt(argc, argv, "h:m:f:t:s:n:r:y:z:c:i:")) != -1)
    {
        switch (opt)
        {
            case 'h':
                view_help(progname);
                break;
            case 'm':
                mode = optarg;
                break;
            case 'f':
                fromvert = atoi(optarg);
                break;
            case 't':
                tovert = atoi(optarg);
                break;
            case 'n':
                filename = optarg;
                break;
            case 'y':
                fromrange = atof(optarg);
                break;
            case 'z':
                torange = atof(optarg);
                break;
            case 'c':
                columns = atof(optarg);
                break;
            case 'r':
                rows = atof(optarg);
                break;
            case 'i':
                if(optarg[0] == 'f' || strcmp(optarg, "false") == 0)
                    cohesive = 0;
                break;
        }
    }

    input_errors_management(mode, fromvert, tovert, filename, fromrange, torange, progname, rows, columns);

    if(strcmp(mode, "read") == 0)
    {
        graph* graf = file_open(filename);

        dijkstra(graf, fromvert, tovert);
        bfs(graf);
    }
    else if(strcmp(mode, "write") == 0)
    {
        FILE *ouf = fopen(filename, "w");
        if(ouf == NULL)
        {
            printf("Could not create file \"%s\".\n", filename);
            exit(EXIT_FAILURE);
        }

        creategraph(ouf, columns, rows, fromrange, torange, cohesive);
    }

    return 0;
}
