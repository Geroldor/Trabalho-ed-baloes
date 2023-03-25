#include "qry.h"

void readqry(archive q){
    FILE *qry = (FILE *) q;
    char *command = NULL;
    char *type;
    int i;
    float r, p, h;
    fgets(command, 100, qry);
    sscanf(command, "%c %d %f %f %f", &type, &i, &r, &p, &h);
}