#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
// fila circular estatica

typedef struct No
{
    item conteudo;
} no;

typedef struct queue
{
    no *elementos;
    int inicio;
    int fim;
    int capacidade;
    int quantidade;
} Fila;

fila createFila(int capacidade)
{
    Fila *F = malloc(sizeof(Fila));
    F->capacidade = capacidade;
    F->elementos = malloc(sizeof(no) * capacidade);
    F->inicio = 0;
    F->fim = -1;
    F->quantidade = 0;
    fila fil = F;
    return fil;
}

void insertFila(Fila *fi, item conteudo)
{
    no *c.conteudo = conteudo;
    if (fi->quantidade < fi->capacidade)
    {
        fi->fim++;
        fi->elementos[fi->fim].conteudo = c.conteudo;
        fi->quantidade++;
        printf("%d\n", fi->elementos[fi->fim].conteudo);
    }
}

void removeFila(Fila *fi)
{
    fi->elementos[fi->inicio].conteudo = 0;
    fi->inicio++;
    fi->quantidade--;
}

item getFirstFila(Fila *fi)
{
    return fi->elementos[fi->inicio].conteudo;
}

item getLastFila(Fila *fi)
{
    return fi->elementos[fi->fim].conteudo;
}

int getSizeFila(Fila *fi)
{
    return fi->quantidade;
}

int getCapacityFila(Fila *fi)
{
    return fi->capacidade;
}

void killFila(Fila *fi)
{
    free(fi->elementos);
    free(fi);
}