#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "circle.h"
#include "rect.h"
#include "text.h"
#include "lista.h"


void readgeo(char* fullpathgeo, Lista l){
    FILE *geo = fopen(fullpathgeo, "r");
    char command[100], type;
    char corb[20], corp[20], ancora[20],  conteudo[50], cor[20];
    int id;
    float x1, y1, x2, y2, r, w, h;
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
                
                sscanf(command, "%c %d %f %f %f %f %s %s", &type, &id, &x1, &y1, &w, &h, corb, corp);
                insertLst(l, createRetangulo(id, x1, y1, w, h, corb, corp));
            break;

            case 'c':
               
                sscanf(command, "%c %d %lf %lf %lf %s %s", &type, &id, &x1, &y1, &r, corb, corp);
                insertLst(l, createCirculo(id, x1, y1, r, corb, corp));
            break;

            case 't': 
                sscanf(command, "%c %d %f %f %s %s %s", &type, &id, &x1, &y1, corb, corp, conteudo);
                insertLst(l, textoCreate(id, x1, y1, conteudo, ancora, corb, corp));
                printf("ID TEXTO: %d \nX: %f \nY: %f \nConteudo: %s \nCorb: %s \nCorP: %s \nAncora: %s", id, x1, y1, conteudo, corb, corp, ancora);
            break;

            case 'l':
                sscanf(command, "%c %d %f %f %f %f %s", &type, &id, &x1, &y1, &x2, &y2, cor);
                insertLst(l, createLinha(id, x1, y1, x2, y2, cor));
            break;
        }
    }
    
}

int main(){
    Lista l = createLst(-1);
    char fullpathgeo[100] = "~/Downloads/t1/00-smpls-caca-disp.geo";
    readgeo(fullpathgeo, l);
    killLst(l);
    return 0;
}