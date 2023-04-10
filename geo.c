#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "structures.h"

void readgeo(char *path, char* name, Lista l)
{
    Archive geon = open(path, name, "r");
    FILE *geo = getArchive(geon);
    char *command, *type;
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
        switch ((char)type)
        {
        case 'r':
            sscanf(command, "%d %lf %lf %lf %lf %s %s", &id, &x1, &y1, &w, &h, corb, corp);
            insertLst(l, createRectangle(id, x1, y1, w, h, corb, corp));
            break;

        case 'c':
            sscanf(command, "%d %lf %lf %lf %s %s", &id, &x1, &y1, &r, corb, corp);
            insertLst(l, createCircle(id, x1, y1, r, corb, corp));
            break;
        
        case 'tl':
            char* font_type;
            char* font_size;
            char* aux;
            textBuffer(font_type, font_size);
            sscanf(command, "%s %s %s", font_type, aux, font_size);
            strcat(font_type, aux); 
            break;

        case 't':
            sscanf(command, "%d %lf %lf %s %s %s %s", &id, &x1, &y1, corb, corp, ancora, conteudo);
            insertLst(l, textoCreate(id, x1, y1, conteudo, ancora, corb, corp));
            break;

        case 'l':
            sscanf(command, "%d %lf %lf %lf %lf %s", &id, &x1, &y1, &x2, &y2, cor);
            insertLst(l, createLinha(id, x1, y1, x2, y2, cor));
            break;
        }
    }
}