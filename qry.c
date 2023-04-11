#include "qry.h"
#include <stdlib.h>

void readqry(char *fullpath)
{
    int i;
    FILE *qry = fopen(fullpath, "r");
    while (!feof(qry))
    {
        char *command = NULL;
        char *type;
        float dx;
        float dy;
        float grs;
        float r;
        float p;
        float h;
        fgets(command, 100, qry);
        type = strtok(command, " ");
        if(strcmp(type, "mv") == 0){
            sscanf(command, "%d %f %f", &i, &dx, &dy);
            

        }

        if(strcmp(type, "g") == 0){
            sscanf(command, "%d %f", &i, &grs);
            printf("%s %d %f", type, i, grs);
        }

        if(strcmp(type, "ff") == 0){
            sscanf(command, "%d %f %f %f", &i, &r, &p, &h);
            printf("%s %d %f %f %f", type, i, r, p, h);
        }

        if(strcmp(type, "tf") == 0)
        {
            sscanf(command, "%d %f %f %f", &i, &r, &p, &h);
            printf("%s %d %f %f %f", type, i, r, p, h);
        
        }
    }
}