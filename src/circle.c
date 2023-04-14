#include "circle.h"
#include <stdlib.h>
#include <string.h>

typedef struct Circle
{
    int id;
    double x;
    double y;
    double r;
    char *corb;
    char *corp;
    double rotacao;
} Circle;

void circleSetI(circulo ci, int i)
{
    Circle *pointer = ci;
    pointer->id = i;
}

void circleSetX(circulo ci, double x)
{
    Circle *pointer = ci;
    pointer->x = x;
}

void circleSetY(circulo ci, double y)
{
    Circle *pointer = ci;
    pointer->y = y;
}

void circleSetR(circulo ci, double r)
{
    Circle *pointer = ci;
    pointer->r = r;
}

void circleSetCorb(circulo ci, char *corb)
{
    Circle *pointer = ci;
    char *corbstring = malloc(sizeof(char) * strlen(corb));
    strcpy(corbstring, corb);
    pointer->corb = corbstring;
}

void circleSetCorp(circulo ci, char *corp)
{
    Circle *pointer = ci;
    char *corpstring = malloc(sizeof(char) * strlen(corp));
    strcpy(corpstring, corp);
    pointer->corp = corpstring;
}

void circleSetRotacao(circulo ci, double rotacao)
{
    Circle *pointer = ci;
    pointer->rotacao = rotacao;
}

circulo *createCircle(int id, double x, double y, double r, char *corb, char *corp)
{
    Circle *ci = malloc(sizeof(Circle));
    circleSetI(ci, id);
    circleSetX(ci, x);
    circleSetY(ci, y);
    circleSetRotacao(ci, r);
    circleSetCorb(ci, corb);
    circleSetCorp(ci, corp);

    return (circulo)ci;
}

int circleGetI(circulo ci)
{
    Circle *pointer = ci;
    return pointer->id;
}

double circleGetCx(circulo ci)
{
    Circle *pointer = ci;
    return pointer->x;
}

double circleGetCy(circulo ci)
{
    Circle *pointer = ci;
    return pointer->y;
}

double circleGetR(circulo ci)
{
    Circle *pointer = ci;
    return pointer->r;
}

char *circleGetCorb(circulo ci)
{
    Circle *pointer = ci;
    return pointer->corb;
}

char *circleGetCorp(circulo ci)
{
    Circle *pointer = ci;
    return pointer->corp;
}

double circleGetRotacao(circulo ci)
{
    Circle *pointer = ci;
    return pointer->rotacao;
}

void circleFree(circulo ci)
{
    Circle *pointer = ci;
    free(pointer->corb);
    free(pointer->corp);
    free(pointer);
}
