#ifndef _RETANGULO_H_
#define _RETANGULO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
RETANGULO é um polígono que possui um ponto de origem (âncora definida por x e y), largura, altura,
cor de borda e cor de preenchimento.
*/

typedef void *retangulo;

/** create_rectangle cria um retangulo com os dados passados como parâmetro*/
retangulo createRectangle(int id, double x, double y, double w, double h, char *corb, char *corp);

/** rectangleSeti define o id do retângulo*/
void rectangleSeti(retangulo ret, int id);

/** rectangleSetx define a coordenada x do retângulo*/
void rectangleSetx(retangulo ret, double x);

/** rectangleSety define a coordenada y do retângulo*/
void rectangleSety(retangulo ret, double y);

/** rectangleSetw define a largura do retângulo*/
void rectangleSetw(retangulo ret, double w);

/** rectangleSeth define a altura do retângulo*/
void rectangleSeth(retangulo ret, double h);

/** rectangleSetcorb define a cor de borda do retângulo*/
void rectangleSetcorb(retangulo ret, char *corb);

/** rectangleSetcorp define a cor de preenchimento do retângulo*/
void rectangleSetcorp(retangulo ret, char *corp);

/** rectangleSetrotacao define a rotação do retângulo*/
void rectangleSetrotacao(retangulo ret, double rotacao);

/** rectangleGeti retorna o id do retângulo*/
int rectangleGeti(retangulo ret);

/** rectangleGetx retorna a coordenada x do retângulo*/
double rectangleGetx(retangulo ret);

/** rectangleGety retorna a coordenada y do retângulo*/
double rectangleGety(retangulo ret);

/** rectangleGetw retorna a largura do retângulo*/
double rectangleGetw(retangulo ret);

/** rectangleGeth retorna a altura do retângulo*/
double rectangleGeth(retangulo ret);

/** rectangleGetcorb retorna a cor de borda do retângulo*/
char *rectangleGetcorb(retangulo ret);

/** rectangleGetcorp retorna a cor de preenchimento do retângulo*/
char *rectangleGetcorp(retangulo ret);

/** rectangleGetarea retorna a area do retângulo*/
double rectangleGetarea(retangulo ret);

/** rectangleGetRotacao retorna a rotação do retângulo*/
double rectangleGetRotacao(retangulo ret);

/** rectangleFree libera a memória alocada para o retângulo*/
void rectangleFree(retangulo ret);

#endif
