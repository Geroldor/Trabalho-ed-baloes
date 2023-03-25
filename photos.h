#ifndef PHOTOS_H
#define PHOTOS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "archive.h"

typedef void* no;
typedef void* Fila;
no *createNo(int id);

Fila *createfila();

void insertFila(no *n, Fila *f);

#endif