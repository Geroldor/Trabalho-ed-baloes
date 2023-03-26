#include "qry.h"

void readqry(char *fullpath)
{
    FILE *qry = fopen(fullpath, "r");
    while (qry != EOF)
    {
        char *command = NULL;
        char *type;
        fgets(command, 100, qry);
        switch (command[0])
        {
        case 'mv':
            int i;
            float dx, dy;
            sscanf(command, "%s %d %f %f", type, &i, &dx, &dy);
            break;

        case 'g':
            int i;
            float grs;
            sscanf(command, "%s %d %f", type, &i, &grs);
            break;

        case 'ff':
            int i;
            float r, p, h;
            sscanf(command, "%c %d %f %f %f", &type, &i, &r, &p, &h);
            break;

        case 'tf':
            int i, l;
            sscanf(command, "%c %d %f %f %f", &type, &i, &r, &p, &h);
            break;
        }
    }
}