#include "circulo.h"

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

void circleSeti(circulo ci, int i)
{
    struct Circulo *pointer = ci;
    pointer->id = i;
}

void circleSetx(circulo ci, double x)
{
    struct Circulo *pointer = ci;
    pointer->x = x;
}

void circleSety(circulo ci, double y)
{
    struct Circulo *pointer = ci;
    pointer->y = y;
}

void circleSetr(circulo ci, double r)
{
    struct Circulo *pointer = ci;
    pointer->r = r;
}

void circleSetcorb(circulo ci, char *corb)
{
    struct Circulo *pointer = ci;
    char *corbstring = malloc(sizeof(char) * strlen(corb));
    strcpy(corbstring, corb);
    pointer->corb = corbstring;
}

void circleSetcorp(circulo ci, char *corp)
{
    struct Circulo *pointer = ci;
    char *corpstring = malloc(sizeof(char) * strlen(corp));
    strcpy(corpstring, corp);
    pointer->corp = corpstring;
}

void circleSetrotacao(circulo ci, double rotacao)
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


