#include "photos.h"
#define TAM_FILA 10
#define TAM_VETOR 15
typedef FILE* Elemento;

typedef struct no {
    int id;
    Elemento *vetor[TAM_VETOR];
    int inicio;
    int fim;
} No;

typedef struct fila{
    No *fila[TAM_FILA];
    int inicio;
    int fim;

}fila;

no *createNo(int id){
    No *n = (No*) malloc(sizeof(No));
    n->id = id;
    n->inicio = 0;
    n->fim = -1;
    return n;
}

Fila *createfila(){
    fila *f = (fila*) malloc(sizeof(fila));
    f->inicio = 0;
    f->fim = -1;
    return f;
}

void insertFila(no *n, Fila *f){
    fila *fi = f;
    No *q = n;
    fi->fim++;
    fi->fila[fi->fim] = q;
}

void removeFilafim(fila *f ){
    free(f->fila[f->fim]);
    f->fim--;
}

void insertPicFila(FILE *p, fila *f, int i){
    f->fila[i]->fim++;
    f->fila[i]->vetor[f->fila[i]->fim] = p;
}

void removePicFila(fila *f, int i){
    fclose(f->fila[i]->vetor[f->fila[i]->fim]);
    f->fila[i]->vetor[f->fila[i]->fim] = NULL;
    f->fila[i]->fim--;
}