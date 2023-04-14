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

void insertFila(fila *fi, item conteudo)
{
    Fila *F = (Fila *)fi;
   if (F->quantidade < F->capacidade)
    {
        F->fim++;
        F->elementos[F->fim].conteudo = conteudo;
        F->quantidade++;
    }
}

void removeFila(fila *fi)
{
    Fila *F = (Fila *)fi;
    F->elementos[F->inicio].conteudo = 0;
    F->inicio++;
    F->quantidade--;
}

item getFirstFila(fila *fi)
{
    Fila *F = (Fila *)fi;
    return F->elementos[F->inicio].conteudo;
}

item getLastFila(fila *fi)
{
    Fila *F = (Fila *)fi;
    return F->elementos[F->fim].conteudo;
}

int getSizeFila(fila *fi)
{
    Fila *F = (Fila *)fi;
    return F->quantidade;
}

int getCapacityFila(fila *fi)
{
    Fila *F = (Fila *)fi;
    return F->capacidade;
}

void killFila(fila *fi)
{
    Fila *F = (Fila *)fi;
    free(F->elementos);
    free(F);
}