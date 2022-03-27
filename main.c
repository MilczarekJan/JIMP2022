#include "input_errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int     opt;
    char    *mode = NULL;
    int     fromvert = -1;
    int     tovert = -1;
    char    *filename = NULL;
    double  fromrange = 0;
    double  torange = 1;

    char    *progname= argv[0];

    while((opt = getopt(argc, argv, "h:m:f:t:s:n:r:y:z:")) != -1)
    {
        switch (opt)
        {
            case 'h':
                //printf(&help, progname);
                printf("gowno zajebane\n");
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

    input_errors_management(opt, mode, fromvert, tovert, filename, fromrange, torange, progname);

    if(mode == "read") // od tad cos sie pierdoli
    {
        FILE *inf = fopen(filename, "r");
        if(inf == NULL)
        {
            printf("Can not open file %s.", filename);
            exit(EXIT_FAILURE);
        }
    }
    else if(mode == "write")
    {
        FILE *inf = fopen(filename, "w");
    }
    else
    {
        printf("Program mode (read/write) invalid! Ending program...\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}