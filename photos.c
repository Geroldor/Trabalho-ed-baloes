#include "photos.h"
#define TAM_FILA 10
#define TAM_VETOR 15
typedef struct elemento{
    FILE *pic;
    FILE *svgpic;
}Elemento;


typedef struct no {
    int id;
    Elemento *vetor[TAM_VETOR];
    char *fullPath;
    char *mode;
    int inicio;
    int fim;
} No;

typedef struct list{
    No *list[TAM_FILA];
    int inicio;
    int fim;

}list;

no *createFilaPic(int id, int inicio, int fim){
    No *n;
    n->id = id;
    n->inicio = inicio;
    n->fim = fim;
    return n;
}

List *createLstPic(){
    list *f = (list*) malloc(sizeof(list));
    f->inicio = 0;
    f->fim = -1;
    return f;
}

void insertList(no *n, List *f){
    list *fi = f;
    No *q = n;
    fi->fim++;
    fi->list[fi->fim] = q;
}

void removeListfim(List *f ){
    list *fi = f;
    free(fi->list[fi->fim]);
    fi->fim--;
}

void insertPicList(FILE *p, List *f, int i){
    list *fi = f;
    fi->list[i]->fim++;
    fi->list[i]->vetor[fi->list[i]->fim]->pic = p;
}

void removePicList(List *f, int i){
    list *fi = f;
    fclose(fi->list[i]->vetor[fi->list[i]->fim]);
    fi->list[i]->vetor[fi->list[i]->fim]->pic = NULL;
    fi->list[i]->fim--;
}

void removePicListInicio(List *f, int i){
    list *fi = f;
    fclose(fi->list[i]->vetor[fi->list[i]->inicio]->pic);
    fi->list[i]->vetor[fi->list[i]->inicio]->pic = NULL;
    fi->list[i]->inicio++;
}

void removeList(List *f){
    list *fi = f;
    for(int i = 0; i < TAM_FILA; i++){
        for(int j = 0; j < TAM_VETOR; j++){
            fclose(fi->list[i]->vetor[j]->pic);
        }
        free(fi->list[i]);
    }
    free(fi);
}

void openPic(List *f, int i, int posic, char* fullPath, char *mode){
    list *fi = f;
    fi->list[posic]->vetor[i]->pic = fopen(fullPath, mode);
    fi->list[posic]->fullPath = fullPath;
    fi->list[posic]->mode = mode;
}

void writePic(List *f, int i, int posic, char *info){
    list *fi = f;
    fprintf(fi->list[posic]->vetor[i]->pic, "%s", info);
}

void closePic(List *f, int i, int posic){
    list *fi = f;
    fclose(fi->list[posic]->vetor[i]->pic);
}

void startpicTosvg(List *f, int i, int posic, char *info, char *svgname){
    list *fi = f;
    FILE *p = fopen(fi->list[posic]->fullPath, "r");
    FILE *svg = fopen(svgname, "a");
    fprintf(svg, "<?xml version=\"1.0\" standalone=\"no\"?>\n");
    fprintf(svg, "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n");
    fprintf(svg, "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
    fprintf(svg, "<svg width=\"100%%\" height=\"100%%\"\n");
    fprintf(svg, "xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
    fi->list[posic]->vetor[i]->svgpic = svg;
}
