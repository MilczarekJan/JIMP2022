#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int opt;

    while((opt = getopt(argc, argv, "a:b:c:")) != -1)
    {
        switch (opt)
        {
            case 'a':
            break;
        }
    }

    return 0;
}
