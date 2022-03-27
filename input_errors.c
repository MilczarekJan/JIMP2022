#include "input_errors.h"

#include <stdlib.h>
#include <stdio.h>

char *help =
    "Usage: %s -m mode -f number -t number -n/-r filename [-y precise number] [-z precise number] [-h]\n"
    "m - mode (read/write)\n"
    "f - from which vertex the dijkstra algorithm starts (number)\n"
    "t - to which vertex the dijkstra algorithm finds way (number)\n"
    "r - name of the file program is supposed to read from (name)\n"
    "n - name of the file program is supposed to save (name)\n"
    "y - bottom limit of generated paths weight (default: 0) (number)\n"
    "z - top limit of generated paths weight (default: 1) (number)\n"
    "h - display help request (this message)\n";

void input_errors_management(int opt, char *mode, int fromvert, int tovert, char *filename, double fromrange, double torange, char *progname)
{
    printf("mode:|%s|\n", mode);

    if(torange > fromrange) //if fromrange and torange confused, swap them
    {
        double buf = torange;
        torange = fromrange;
        fromrange = buf;
    }

    if(filename == NULL && mode != "read" && mode != "write" && fromvert == -1 && tovert == -1)
    {
        printf(help, progname);
        exit(EXIT_FAILURE);
    }

    if(filename == NULL) // If file not given, exit program
    {
        printf("File name not given! Ending program...\n");
        exit(EXIT_FAILURE);
    }

    if(mode == NULL) // If mod invalid, exit program
    {
        printf("Program mode (read/write) not given! Ending program...\n");
        exit(EXIT_FAILURE);
    }

    if(fromvert == -1 || tovert == -1)
    {
        printf("Dijkstra vertexes not given! Ending program...\n");
        exit(EXIT_FAILURE);
    }
}