#include "rect.h"
#include <stdlib.h>

struct Rectangle
{
    int id;
    double x;
    double y;
    double w;
    double h;
    char *cor;
    char *corb;
    double rotacao;
};

retangulo createRetangulo(int id, double x, double y, double w, double h, char *corb, char *corp)
{
    struct Rectangle *ret = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    retanguloSeti(ret, id);
    retanguloSetx(ret, x);
    retanguloSety(ret, y);
    retanguloSetw(ret, w);
    retanguloSeth(ret, h);
    retanguloSetcorb(ret, corb);
    retanguloSetcorp(ret, corp);
    return ret;
}

void retanguloSeti(retangulo ret, int i)
{
    struct Rectangle *pointer = ret;
    pointer->id = i;
}

void retanguloSetx(retangulo ret, double x)
{
    struct Rectangle *pointer = ret;
    pointer->x = x;
}

void retanguloSety(retangulo ret, double y)
{
    struct Rectangle *pointer = ret;
    pointer->y = y;
}

void retanguloSetw(retangulo ret, double w)
{
    struct Rectangle *pointer = ret;
    pointer->w = w;
}

void retanguloSeth(retangulo ret, double h)
{
    struct Rectangle *pointer = ret;
    pointer->h = h;
}

void retanguloSetcorb(retangulo ret, char *corb)
{
    struct Rectangle *pointer = ret;
    char *corborda = malloc(sizeof(char) * strlen(corb));
    strcpy(corborda, corb);
    pointer->corb = corborda;
}

void retanguloSetcorp(retangulo ret, char *corp)
{
    struct Rectangle *pointer = ret;
    char *corpreenchimento = malloc(sizeof(char) * strlen(corp));
    strcpy(corpreenchimento, corp);
    pointer->cor = corpreenchimento;
}

int retanguloGeti(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->id;
}

double retanguloGetx(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->x;
}

double retanguloGety(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->y;
}

double retanguloGetw(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->w;
}

double retanguloGeth(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->h;
}

char *retanguloGetcorb(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->corb;
}

char *retanguloGetcorp(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->cor;
}

double retanguloGetarea(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->h * pointer->w;
}

double retanguloGetRotacao(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->rotacao;
}

void retanguloSetrotacao(retangulo ret, double rotacao)
{
    struct Rectangle *pointer = ret;
    pointer->rotacao = rotacao;
}

void retanguloFree(retangulo ret)
{
    struct Rectangle *pointer = ret;
    free(pointer->corb);
    free(pointer->cor);
    free(ret);
}