#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
//fila circular estatica



typedef struct No{
    item conteudo;
}no;

typedef struct queue{
    no* elementos;
    int inicio;
    int fim;
    int capacidade;
    int quantidade;
}Fila;

fila createFila(int capacidade){
    Fila* F = malloc(sizeof(Fila));
    F->capacidade = capacidade;
    F->elementos = malloc(sizeof(no)*capacidade);
    F->inicio = 0;
    F->fim = -1;
    F->quantidade = 0;
    return F;
}

void insertFila(Fila* f, item conteudo){
    if(f->quantidade<f->capacidade){
        f->fim++;
        f->elementos[f->fim].conteudo = conteudo;
        f->quantidade++;
        printf("%d\n", f->elementos[f->fim].conteudo);
    }
}

void removeFila(Fila *f){
    f->elementos[f->inicio].conteudo = 0;
    f->inicio++;
    f->quantidade--;
}

item getFirstFila(Fila *f){
    printf("%d\n", f->elementos[f->inicio].conteudo);
    return f->elementos[f->inicio].conteudo;
}

item getLastFila(Fila *f){
    printf("%d\n", f->elementos[f->fim].conteudo);
    return f->elementos[f->fim].conteudo;
}

int getSizeFila(Fila *f){
    return f->quantidade;
}

int getCapacityFila(Fila *f){
    return f->capacidade;
}

void killFila(Fila *f){
    free(f->elementos);
    free(f);
}