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

/** create_retangulo cria um retangulo com os dados passados como parâmetro*/
retangulo createRetangulo(int id, double x, double y, double w, double h, char *corb, char *corp);

/** retanguloSeti define o id do retângulo*/
void retanguloSeti(retangulo ret, int id);

/** retanguloSetx define a coordenada x do retângulo*/
void retanguloSetx(retangulo ret, double x);

/** retanguloSety define a coordenada y do retângulo*/
void retanguloSety(retangulo ret, double y);

/** retanguloSetw define a largura do retângulo*/
void retanguloSetw(retangulo ret, double w);

/** retanguloSeth define a altura do retângulo*/
void retanguloSeth(retangulo ret, double h);

/** retanguloSetcorb define a cor de borda do retângulo*/
void retanguloSetcorb(retangulo ret, char *corb);

/** retanguloSetcorp define a cor de preenchimento do retângulo*/
void retanguloSetcorp(retangulo ret, char *corp);

/** retanguloSetrotacao define a rotação do retângulo*/
void retanguloSetrotacao(retangulo ret, double rotacao);

/** retanguloGeti retorna o id do retângulo*/
int retanguloGeti(retangulo ret);

/** retanguloGetx retorna a coordenada x do retângulo*/
double retanguloGetx(retangulo ret);

/** retanguloGety retorna a coordenada y do retângulo*/
double retanguloGety(retangulo ret);

/** retanguloGetw retorna a largura do retângulo*/
double retanguloGetw(retangulo ret);

/** retanguloGeth retorna a altura do retângulo*/
double retanguloGeth(retangulo ret);

/** retanguloGetcorb retorna a cor de borda do retângulo*/
char *retanguloGetcorb(retangulo ret);

/** retanguloGetcorp retorna a cor de preenchimento do retângulo*/
char *retanguloGetcorp(retangulo ret);

/** retanguloGetarea retorna a area do retângulo*/
double retanguloGetarea(retangulo ret);

/** retanguloGetRotacao retorna a rotação do retângulo*/
double retanguloGetRotacao(retangulo ret);

/** retanguloFree libera a memória alocada para o retângulo*/
void retanguloFree(retangulo ret);

#endif
