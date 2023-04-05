#include "line.h"
#include <stdlib.h>

struct Line
{
    int id;
    double x1, y1, x2, y2;
    char *cor;
    double rotacao;
};

linha createLinha(int id, double x1, double y1, double x2, double y2, char *cor)
{
    struct Line *li = malloc(sizeof(struct Line));
    linhaSeti(li, id);
    linhaSetx1(li, x1);
    linhaSety1(li, y1);
    linhaSetx2(li, x2);
    linhaSety2(li, y2);
    linhaSetcor(li, cor);
    return li;
}

void linhaSeti(linha li, int i)
{
    struct Line *pointer = li;
    pointer->id = i;
}

void linhaSetx1(linha li, double x1)
{
    struct Line *pointer = li;
    pointer->x1 = x1;
}

void linhaSety1(linha li, double y1)
{
    struct Line *pointer = li;
    pointer->y1 = y1;
}

void linhaSetx2(linha li, double x2)
{
    struct Line *pointer = li;
    pointer->x2 = x2;
}

void linhaSety2(linha li, double y2)
{
    struct Line *pointer = li;
    pointer->y2 = y2;
}

void linhaSetcor(linha li, char *cor)
{
    struct Line *pointer = li;
    char *corstring = malloc(sizeof(char) * strlen(cor));
    strcpy(corstring, cor);
    pointer->cor = corstring;
}

int linhaGeti(linha li)
{
    struct Line *pointer = li;
    return pointer->id;
}

double linhaGetx1(linha li)
{
    struct Line *pointer = li;
    return pointer->x1;
}

double linhaGety1(linha li)
{
    struct Line *pointer = li;
    return pointer->y1;
}

double linhaGetx2(linha li)
{
    struct Line *pointer = li;
    return pointer->x2;
}

double linhaGety2(linha li)
{
    struct Line *pointer = li;
    return pointer->y2;
}

char *linhaGetcor(linha li)
{
    struct Line *pointer = li;
    return pointer->cor;
}

void linhaSetRotacao(linha li, double rotacao)
{
    struct Line *pointer = li;
    pointer->rotacao = rotacao;
}

double linhaGetRotacao(linha li)
{
    struct Line *pointer = li;
    return pointer->rotacao;
}


void linhaFree(linha li)
{
    struct Line *pointer = li;
    free(pointer->cor);
    free(li);
}