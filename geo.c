#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "structures.h"
#include "lista.h"
#include "geo.h"


void readgeo(char *path, char* name, char* fullpath, Lista l)
{
    //Archive geon = open(path, name, fullpath, "r");
    //FILE *geo = getArchive(geon);
    FILE *geo = fopen(fullpath, "r");
    char *command, *type;
    char *corb, *corp, *ancora, *conteudo, *cor;
    int id;
    double x1, y1, x2, y2, r, w, h;
    char* font_type;
    char* font_size;
    char* aux;
    if (geo == NULL)
    {
        exit(1);
    }
    while (!feof(geo))
    {
        fgets(command, 100, geo);
        type = strtok(command, " ");
        
        if (strcmp(type, "r") == 0)
        {
        
            sscanf(command, "%d %lf %lf %lf %lf %s %s", &id, &x1, &y1, &w, &h, corb, corp);
            insertLst(l, createRectangle(id, x1, y1, w, h, corb, corp));
        }

        if(strcmp(type, "c") == 0)
        {
            sscanf(command, "%d %lf %lf %lf %s %s", &id, &x1, &y1, &r, corb, corp);
            insertLst(l, createCircle(id, x1, y1, r, corb, corp));
        }
        
        if(strcmp(type, "tl") == 0)
        {
            textBuffer(font_type, font_size, aux);
            sscanf(command, "%s %s %s", font_type, aux, font_size);
        }

        if(strcmp(type, "t") == 0)
        {
            sscanf(command, "%d %lf %lf %s %s %s %s", &id, &x1, &y1, corb, corp, ancora, conteudo);
            insertLst(l, textoCreate(id, x1, y1, conteudo, ancora, corb, corp, font_type, font_size, aux));
        }

        if(strcmp(type, "l") == 0)
        {
            sscanf(command, "%d %lf %lf %lf %lf %s", &id, &x1, &y1, &x2, &y2, cor);
            insertLst(l, createLinha(id, x1, y1, x2, y2, cor));
            break;
        }
    }
}