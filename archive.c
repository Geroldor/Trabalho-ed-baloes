#include <stdio.h>
#include <stdlib.h>
#include "archive.h"

typedef struct arq{
    FILE *a;
    char *name;
    char *mode;
    char *fullpath;
} arq;

archive *open(char *name, char *mode, char *fullpath){
    arq *a = malloc(sizeof(arq));
    a->name = name;
    a->mode = mode;
    a->fullpath = fullpath;
    a->a = fopen(fullpath, mode);
    archive arch = a;
    return arch;
}

void close(archive *a){
    arq *x = a;
    fclose(x->a);
}

void freearq(archive *a){
    arq *x = a;
    free(x);
}

char* read(archive *a){
    arq *x = a;
    char *str = malloc(sizeof(char));
    fgets(str, 100, x);
    return str;
}

char* splitc(char *c){
    char *str = strtok();
}