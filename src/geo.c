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
    char* font_type;
    char *a = malloc(sizeof(char) * 10);
    char* font_size;
    char *b = malloc(sizeof(char) * 10);
    char* font_weight;
    char *c = malloc(sizeof(char) * 10);
    Posic p;
    if (geo == NULL)
    {
        exit(1);
    }
    while (!feof(geo))
    {
        fgets(command, 100, geo);
        
        switch (command[0])
        {
            case 'r':
                sscanf(command, "%s %d %lf %lf %lf %lf %s %s", type, &id, &x1, &y1, &w, &h, corb, corp);
                p = insertLst(l, createRectangle(id, x1, y1, w, h, corb, corp), type);
            break;

            case 'c':
                sscanf(command, "%s %d %lf %lf %lf %s %s", type, &id, &x1, &y1, &r, corb, corp);
                p = insertLst(l, createCircle(id, x1, y1, r, corb, corp), type);
            break;

            case 't':
                if(command[1] == 's'){
                    sscanf(command, "%s %s %s %s", type, a, b, c);
                    textBuffer(font_type, font_size, font_weight, a, b, c);
                    
                }else{
                    sscanf(command, "%s %d %lf %lf %s %s %s %s", type, &id, &x1, &y1, corb, corp, ancora, conteudo);
                    p = insertLst(l, textoCreate(id, x1, y1, conteudo, ancora, corb, corp, font_type, font_size, font_weight), type);
                }
            break;

            case 'l':
                sscanf(command, "%s %d %lf %lf %lf %lf %s", type, &id, &x1, &y1, &x2, &y2, cor);
                p = insertLst(l, createLinha(id, x1, y1, x2, y2, cor), type);
            break;
        }
    }
    close(geon);
}