#include "rect.h"
#include <stdlib.h>

typedef struct Rectangle
{
    int id;
    double x;
    double y;
    double w;
    double h;
    char *cor;
    char *corb;
    double rotacao;
} Rectangle;

void rectangleSeti(retangulo ret, int i)
{
    Rectangle *pointer = ret;
    pointer->id = i;
}

void rectangleSetx(retangulo ret, double x)
{
    Rectangle *pointer = ret;
    pointer->x = x;
}

void rectangleSety(retangulo ret, double y)
{
    Rectangle *pointer = ret;
    pointer->y = y;
}

void rectangleSetw(retangulo ret, double w)
{
    Rectangle *pointer = ret;
    pointer->w = w;
}

void rectangleSeth(retangulo ret, double h)
{
    Rectangle *pointer = ret;
    pointer->h = h;
}

void rectangleSetcorb(retangulo ret, char *corb)
{
    Rectangle *pointer = ret;
    char *corborda = malloc(sizeof(char) * strlen(corb));
    strcpy(corborda, corb);
    pointer->corb = corborda;
}

void rectangleSetcorp(retangulo ret, char *corp)
{
    Rectangle *pointer = ret;
    char *corpreenchimento = malloc(sizeof(char) * strlen(corp));
    strcpy(corpreenchimento, corp);
    pointer->cor = corpreenchimento;
}

rectangle createRectangle(int id, double x, double y, double w, double h, char *corb, char *corp)
{
    Rectangle *ret = (Rectangle *)malloc(sizeof(Rectangle));
    rectangleSeti(ret, id);
    rectangleSetx(ret, x);
    rectangleSety(ret, y);
    rectangleSetw(ret, w);
    rectangleSeth(ret, h);
    rectangleSetcorb(ret, corb);
    rectangleSetcorp(ret, corp);
    return ret;
}

int rectangleGeti(retangulo ret)
{
    Rectangle *pointer = ret;
    return pointer->id;
}

double rectangleGetx(retangulo ret)
{
    Rectangle *pointer = ret;
    return pointer->x;
}

double rectangleGety(retangulo ret)
{
    Rectangle *pointer = ret;
    return pointer->y;
}

double rectangleGetw(retangulo ret)
{
    Rectangle *pointer = ret;
    return pointer->w;
}

double rectangleGeth(retangulo ret)
{
    Rectangle *pointer = ret;
    return pointer->h;
}

char *rectangleGetcorb(retangulo ret)
{
    Rectangle *pointer = ret;
    return pointer->corb;
}

char *rectangleGetcorp(retangulo ret)
{
    Rectangle *pointer = ret;
    return pointer->cor;
}

double rectangleGetarea(retangulo ret)
{
    Rectangle *pointer = ret;
    return pointer->h * pointer->w;
}

double rectangleGetRotacao(retangulo ret)
{
    Rectangle *pointer = ret;
    return pointer->rotacao;
}

void rectangleSetrotacao(retangulo ret, double rotacao)
{
    Rectangle *pointer = ret;
    pointer->rotacao = rotacao;
}

void rectangleFree(retangulo ret)
{
    Rectangle *pointer = ret;
    free(pointer->corb);
    free(pointer->cor);
    free(ret);
}