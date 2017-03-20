#include <unistd.h>

#include "puzzle/puzzle.h"
#include "puzzle/printer.h"
#include "puzzle/dfs.h"

int main(int argc, char **argv) {
    int c;
    char *fvalue;

    while ((c = getopt (argc, argv, "f:")) != -1)
        switch (c)
        {
            case 'f':
                fvalue = optarg;
                break;
            case '?':
                if (optopt == 'f')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                             "Unknown option character `\\x%x'.\n",
                             optopt);
                return 1;
            default:
                abort ();
        }
    printf ("fvalue = %s\n", fvalue);

    for (int index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);
    return 0;
    
}