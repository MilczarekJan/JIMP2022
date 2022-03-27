#include "input_errors.h"

#include <stdlib.h>
#include <stdio.h>

void input_errors_management(int opt, char *name, char *mod, int fromvert, int tovert, char *filename, double fromrange, double torange)
{
    if(torange > fromrange) //if fromrange and torange confused, swap them
    {
        double buf = torange;
        torange = fromrange;
        fromrange = buf;
    }

    if(filename == NULL) // If file not given, exit program
    {
        printf("File name not given! Ending program...");
        exit(EXIT_FAILURE);
    }

    if(mod == NULL) // If mod not given, exit program
    {
        printf("Program mode (save/write) not given! Ending program...");
        exit(EXIT_FAILURE);
    }

    if(fromvert == -1 || tovert == -1)
    {
        printf("Dijkstra vertexes not given! Ending program...");
        exit(EXIT_FAILURE);
    }
}