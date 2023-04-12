#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "structures.h"
#include "lista.h"
#include "geo.h"


void readgeo(char *path, char* name, char* fullpath, Lista l)
{
    Archive geon = open(path, name, fullpath, "r");
    //FILE *geo = getArchive(geon);
    FILE *geo = fopen(fullpath, "r");
    char *command = malloc(sizeof(char) * 100);
    char *type = malloc(sizeof(char) * 100);
    char *corb = malloc(sizeof(char) * 100);
    char *corp = malloc(sizeof(char) * 100);
    char *ancora = malloc(sizeof(char) * 100);
    char *conteudo = malloc(sizeof(char) * 100);
    char *cor = malloc(sizeof(char) * 100);
    int id;
    double x1, y1, x2, y2, r, w, h;
    char* font_type = malloc(sizeof(char) * 100);
    char* font_size = malloc(sizeof(char) * 100);
    char* aux;
    if (geo == NULL)
    {
        exit(1);
    }
    while (!feof(geo))
    {
        fgets(command, 100, geo);
        sscanf(command, "%s", type);
        
        if (strcmp(type, "r") == 0)
        {
            sscanf(command, "%s %d %lf %lf %lf %lf %s %s", type, &id, &x1, &y1, &w, &h, corb, corp);
            insertLst(l, createRectangle(id, x1, y1, w, h, corb, corp), type);
        }

        if(strcmp(type, "c") == 0)
        {
            sscanf(command, "%s %d %lf %lf %lf %s %s", type, &id, &x1, &y1, &r, corb, corp);
            insertLst(l, createCircle(id, x1, y1, r, corb, corp), type);
        }
        
        if(strcmp(type, "tl") == 0)
        {
            sscanf(command, "%s %s %s %s", type, font_type, aux, font_size);
            textBuffer(font_type, font_size, aux);   
        }

        if(strcmp(type, "t") == 0)
        {
            sscanf(command, "%s %d %lf %lf %s %s %s %s", type, &id, &x1, &y1, corb, corp, ancora, conteudo);
            insertLst(l, textoCreate(id, x1, y1, conteudo, ancora, corb, corp, font_type, font_size, aux), type);
        }

        if(strcmp(type, "l") == 0)
        {
            sscanf(command, "%s %d %lf %lf %lf %lf %s", type, &id, &x1, &y1, &x2, &y2, cor);
            insertLst(l, createLinha(id, x1, y1, x2, y2, cor), type);
        }
    }
    close(geon);
    free(command);
    free(type);
    free(corb);
    free(corp);
    free(ancora);
    free(conteudo);
    free(cor);
    free(font_type);
    free(font_size);
    free(aux);
}