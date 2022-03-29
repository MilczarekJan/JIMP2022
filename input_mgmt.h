#ifndef INPUT_MGMT_H
#define INPUT_MGMT_H

#include <stdio.h>
#include <string.h>

void view_help(char *progname);

void input_errors_management(char *mode, int fromvert, int tovert, char *filename, double fromrange, double torange, char *progname, int rows, int columns);

#endif