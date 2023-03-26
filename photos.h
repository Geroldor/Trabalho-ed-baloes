#ifndef PHOTOS_H
#define PHOTOS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void* no;
typedef void* List;

no *createNo(int id);

List *createlist();

void insertList(no *n, List *f);

#endif