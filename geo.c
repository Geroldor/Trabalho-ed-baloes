#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "structures.h"

void readgeo(char *fullpathgeo, Lista l)
{
    FILE *geo = fopen(fullpathgeo, "r");
    char *command, type;
    char *corb, *corp, *ancora, *conteudo, *cor;
    int id;
    double x1, y1, x2, y2, r, w, h;
    if (geo == NULL)
    {
        exit(1);
    }
    while (!feof(geo))
    {
        fgets(command, 100, geo);
        type = strtok(command, " ");
        switch (type)
        {
        case 'r':
            sscanf(command, "%d %lf %lf %lf %lf %s %s", &id, &x1, &y1, &w, &h, corb, corp);
            insertLst(l, createRectangle(id, x1, y1, w, h, corb, corp));
            break;

        case 'c':
            sscanf(command, "%d %lf %lf %lf %s %s", &id, &x1, &y1, &r, corb, corp);
            insertLst(l, createCircle(id, x1, y1, r, corb, corp));
            break;

        case 't':
            sscanf(command, "%d %lf %lf %s %s %s", &id, &x1, &y1, corb, corp, ancora, conteudo);
            insertLst(l, textoCreate(id, x1, y1, conteudo, ancora, corb, corp));
            break;

        case 'l':
            sscanf(command, "%d %lf %lf %lf %lf %s", &id, &x1, &y1, &x2, &y2, cor);
            insertLst(l, createLinha(id, x1, y1, x2, y2, cor));
            break;
        }
    }
}