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

/// @brief Cria um retângulo
/// @param id id do retângulo
/// @param x coordenada x do retângulo
/// @param y coordenada y do retângulo
/// @param w largura do retangulo
/// @param h altura do retangulo
/// @param corb cor de borda do retângulo
/// @param corp cor de preenchimento do retângulo
/// @return void* do retângulo criado
retangulo createRectangle(int id, double x, double y, double w, double h, char *corb, char *corp);

/// @brief Define uma nova id para o retângulo
/// @param ret retangulo
/// @param id nova id
void rectangleSeti(retangulo ret, int id);

/// @brief define uma nova coordenada x para o retângulo
/// @param ret retangulo
/// @param x nova coordenada x
void rectangleSetx(retangulo ret, double x);

/// @brief define uma nova coordenada y para o retângulo
/// @param ret retangulo
/// @param y nova coordenada y
void rectangleSety(retangulo ret, double y);

/// @brief define uma nova largura para o retângulo
/// @param ret retangulo
/// @param w nova largura
void rectangleSetw(retangulo ret, double w);

/// @brief define uma nova altura para o retângulo
/// @param ret retangulo
/// @param h nova altura
void rectangleSeth(retangulo ret, double h);

/// @brief define uma nova cor de borda para o retângulo
/// @param ret retangulo
/// @param corb cor de borda
void rectangleSetcorb(retangulo ret, char *corb);

/// @brief define uma nova cor de preenchimento para o retângulo
/// @param ret retangulo
/// @param corp cor de preenchimento
void rectangleSetcorp(retangulo ret, char *corp);

/// @brief define uma nova rotação para o retângulo
/// @param ret retangulo
/// @param rotacao nova rotação
void rectangleSetrotacao(retangulo ret, double rotacao);

/// @brief retorna a id do retângulo
/// @param ret retangulo
/// @return id do retângulo
int rectangleGeti(retangulo ret);

/// @brief retorna a coordenada x do retângulo
/// @param ret retangulo
/// @return coordenada x do retângulo
double rectangleGetx(retangulo ret);

/// @brief retorna a coordenada y do retângulo
/// @param ret retangulo
/// @return coordenada y do retângulo
double rectangleGety(retangulo ret);

/// @brief retorna a largura do retângulo
/// @param ret retangulo
/// @return largura do retângulo
double rectangleGetw(retangulo ret);

/// @brief retorna a altura do retângulo
/// @param ret retangulo
/// @return altura do retângulo
double rectangleGeth(retangulo ret);

/// @brief retorna a cor de borda do retângulo
/// @param ret retangulo
/// @return cor de borda do retângulo
char *rectangleGetcorb(retangulo ret);

/// @brief retorna a cor de preenchimento do retângulo
/// @param ret retangulo
/// @return cor de preenchimento do retângulo
char *rectangleGetcorp(retangulo ret);

/// @brief retorna a rotação do retângulo
/// @param ret retangulo
/// @return rotação do retângulo
double rectangleGetRotacao(retangulo ret);

/// @brief remove o retângulo
/// @param ret retangulo
void rectangleFree(retangulo ret);

#endif
