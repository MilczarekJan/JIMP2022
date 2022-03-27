#include "input_errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int     opt;
    char    *name = NULL;
    char    *mod = NULL;
    int     fromvert = -1;
    int     tovert = -1;
    char    *filename = NULL;
    double  fromrange = 0;
    double  torange = 1;
    /*
    m - mod(read/write)
    f - z ktorego wierzcholka szukanie
    t - do ktorego wierzcholka szukanie (sciezki)
    */

    while((opt = getopt(argc, argv, "m:f:t:s:n:r:y:z:")) != -1)
    {
        switch (opt)
        {
            case 'm':
                mod = optarg;
                break;
            case 'f':
                fromvert = atoi(optarg);
                break;
            case 't':
                tovert = atoi(optarg);
                break;
            case 'n':
            case 'r':
                filename = optarg;
                break;
            case 'y':
                fromrange = atof(optarg);
                break;
            case 'z':
                torange = atof(optarg);
                break;
        }
    }

    input_errors_management(opt, name, mod, fromvert, tovert, filename, fromrange, torange);

    return 0;
}