#include "line.h"
#include <stdlib.h>

typedef struct Line
{
    int id;
    double x1, y1, x2, y2;
    char *cor;
    double rotacao;
} Line;

linha createLinha(int id, double x1, double y1, double x2, double y2, char *cor)
{
    Line *li = malloc(sizeof(Line));
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
    Line *pointer = li;
    pointer->id = i;
}

void linhaSetx1(linha li, double x1)
{
    Line *pointer = li;
    pointer->x1 = x1;
}

void linhaSety1(linha li, double y1)
{
    Line *pointer = li;
    pointer->y1 = y1;
}

void linhaSetx2(linha li, double x2)
{
    Line *pointer = li;
    pointer->x2 = x2;
}

void linhaSety2(linha li, double y2)
{
    Line *pointer = li;
    pointer->y2 = y2;
}

void linhaSetcor(linha li, char *cor)
{
    Line *pointer = li;
    char *corstring = malloc(sizeof(char) * strlen(cor));
    strcpy(corstring, cor);
    pointer->cor = corstring;
}

int linhaGeti(linha li)
{
    Line *pointer = li;
    return pointer->id;
}

double linhaGetx1(linha li)
{
    Line *pointer = li;
    return pointer->x1;
}

double linhaGety1(linha li)
{
    Line *pointer = li;
    return pointer->y1;
}

double linhaGetx2(linha li)
{
    Line *pointer = li;
    return pointer->x2;
}

double linhaGety2(linha li)
{
    Line *pointer = li;
    return pointer->y2;
}

char *linhaGetcor(linha li)
{
    Line *pointer = li;
    return pointer->cor;
}

void linhaSetRotacao(linha li, double rotacao)
{
    Line *pointer = li;
    pointer->rotacao = rotacao;
}

double linhaGetRotacao(linha li)
{
    Line *pointer = li;
    return pointer->rotacao;
}

void linhaFree(linha li)
{
    Line *pointer = li;
    free(pointer->cor);
    free(li);
}