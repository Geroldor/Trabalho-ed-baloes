#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "circle.h"
#include "rect.h"
#include "text.h"

void readgeo(char* fullpathgeo){
    FILE *geo = fopen(fullpathgeo, "r");
    char command[100], type;
    int id;
    if(geo == NULL){
        exit(1);
    }
    while (fgets(command, 100, geo))
    {
        type = command[0];
        if(feof(geo)){
            break;
        }
        switch(type){
            case 'r':
                float x, y, w, h;
                char corb[20], corp[20];
                sscanf(command, "%c %d %f %f %f %f %s %s", &type, &id, &x, &y, &w, &h, corb, corp);
                retangulo *rect = createRetangulo(id, x, y, w, h, corb, corp);
                printf("ID RETANGULO: %d \nX: %f \nY: %f \nwidth: %f \nheight: %f \nCorb: %s \nCorP: %s", id, x, y, w, h, corb, corp);
            break;

            case 'c':
                double x, y, r;
                char corb[20],corp[20];
                sscanf(command, "%c %d %lf %lf %lf %s %s", &type, &id, &x, &y, &r, corb, corp);
                circulo *c = createCirculo(id, x, y, r, corb, corp);
                printf("ID CIRCULO: %d \nX: %f \nY: %f \nR: %f \nCorb: %s \nCorP: %s", id, x, y, r, corb, corp);
            break;

            case 't': 
                double x, y; 
                char ancora[20], corb[20], corp[20], conteudo[50];
                sscanf(command, "%c %d %f %f %s %s %s", &type, &id, &x, &y, corb, corp, conteudo);
                texto *t = textoCreate(id, x, y, conteudo, ancora, corb, corp);
                printf("ID TEXTO: %d \nX: %f \nY: %f \nConteudo: %s \nCorb: %s \nCorP: %s \nAncora: %s", id, x, y, conteudo, corb, corp, ancora);
            break;

            case 'l':
                double x1, y1, x2, y2;
                char cor[20];
                sscanf(command, "%c %d %lf %lf %lf %lf %s", &type, &id, &x1, &y1, &x2, &y2, cor);
                linha *l = createLinha(id, x1, y1, x2, y2, cor);
                printf("ID LINHA: %d \nX1: %f \nY1: %f \nX2: %f \nY2: %f \nCor: %s", id, x, y, r, corb);
            break;
        }
    }
    
}

int main(){
    char fullpathgeo[] = "~/Downloads/t1/00-smpls-caca-disp.geo";
    readgeo(fullpathgeo);
}