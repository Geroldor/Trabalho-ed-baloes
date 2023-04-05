#include "circle.h"
#include <stdlib.h>
#include <string.h>

struct Circulo
{
    int id;
    double x;
    double y;
    double r;
    char *corb;
    char *corp;
    double rotacao;
};

circulo *createCircle(int id, double x, double y, double r, char *corb, char *corp)
{
    struct Circulo *ci = malloc(sizeof(struct Circulo));
    circleSeti(ci, id);
    circleSetx(ci, x);
    circleSety(ci, y);
    circleSetr(ci, r);
    circleSetcorb(ci, corb);
    circleSetcorp(ci, corp);
    return ci;
}

void circleSetI(circulo ci, int i)
{
    struct Circulo *pointer = ci;
    pointer->id = i;
}

void circleSetX(circulo ci, double x)
{
    struct Circulo *pointer = ci;
    pointer->x = x;
}

void circleSetY(circulo ci, double y)
{
    struct Circulo *pointer = ci;
    pointer->y = y;
}

void circleSetR(circulo ci, double r)
{
    struct Circulo *pointer = ci;
    pointer->r = r;
}

void circleSetCorb(circulo ci, char *corb)
{
    struct Circulo *pointer = ci;
    char *corbstring = malloc(sizeof(char) * strlen(corb));
    strcpy(corbstring, corb);
    pointer->corb = corbstring;
}

void circleSetCorp(circulo ci, char *corp)
{
    struct Circulo *pointer = ci;
    char *corpstring = malloc(sizeof(char) * strlen(corp));
    strcpy(corpstring, corp);
    pointer->corp = corpstring;
}

void circleSetRotacao(circulo ci, double rotacao)
{
    struct Circulo *pointer = ci;
    pointer->rotacao = rotacao;
}

int circleGeti(circulo ci)
{
    struct Circulo *pointer = ci;
    return pointer->id;
}

double circleGetx(circulo ci)
{
    struct Circulo *pointer = ci;
    return pointer->x;
}

double circleGety(circulo ci)
{
    struct Circulo *pointer = ci;
    return pointer->y;
}

double circleGetr(circulo ci)
{
    struct Circulo *pointer = ci;
    return pointer->r;
}

char *circleGetcorb(circulo ci)
{
    struct Circulo *pointer = ci;
    return pointer->corb;
}

char *circleGetcorp(circulo ci)
{
    struct Circulo *pointer = ci;
    return pointer->corp;
}

double circleGetrotacao(circulo ci)
{
    struct Circulo *pointer = ci;
    return pointer->rotacao;
}

void circleFree(circulo ci)
{
    struct Circulo *pointer = ci;
    free(pointer->corb);
    free(pointer->corp);
    free(pointer);
}


