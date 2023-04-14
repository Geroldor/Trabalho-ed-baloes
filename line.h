#ifndef LINE_H
#define LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void *linha;

/// @brief cria uma linha
/// @param id id da linha
/// @param x1 coordenada x do início da linha
/// @param y1 coordenada y do início da linha
/// @param x2 coordenada x do fim da linha
/// @param y2 coordenada y do fim da linha
/// @param cor cor da linha
/// @return void* para linha criada
linha createLinha(int id, double x1, double y1, double x2, double y2, char *cor);

/// @brief define o id da linha
/// @param li linha
/// @param i nova id da linha
void linhaSeti(linha li, int i);

/// @brief define a coordenada x do início da linha
/// @param li linha
/// @param x1 nova coordenada x do início da linha
void linhaSetx1(linha li, double x1);

/// @brief define a coordenada y do início da linha
/// @param li linha
/// @param y1 nova coordenada y do início da linha
void linhaSety1(linha li, double y1);

/// @brief define a coordenada x do fim da linha
/// @param li linha
/// @param x2 nova coordenada x do fim da linha
void linhaSetx2(linha li, double x2);

/// @brief define a coordenada y do fim da linha
/// @param li linha
/// @param y2 nova coordenada y do fim da linha
void linhaSety2(linha li, double y2);

/// @brief define a cor da linha
/// @param li linha
/// @param cor nova cor da linha
void linhaSetcor(linha li, char *cor);

/// @brief retorna a id da linha
/// @param li linha
/// @return id da linha
int linhaGeti(linha li);

/// @brief retorna a coordenada x do inicio da linha
/// @param li linha
/// @return coordena x do inicio da linha
double linhaGetx1(linha li);

/// @brief retorna a coordenada y do inicio da linha
/// @param li linha
/// @return coordenada y do inicio da linha
double linhaGety1(linha li);

/// @brief retorna a coordenada x do fim da linha
/// @param li linha
/// @return coordenada x do fim da linha
double linhaGetx2(linha li);

/// @brief retorna a coordenada y do fim da linha
/// @param li linha
/// @return coordenada y do fim da linha
double linhaGety2(linha li);

/// @brief retorna a cor da linha
/// @param li linha
/// @return cor da linha
char *linhaGetcor(linha li);

/// @brief define a rotação da linha
/// @param li linha
/// @param rotacao nova rotação da linha
void linhaSetRotacao(linha li, double rotacao);

/// @brief retorna a rotação da linha
/// @param li linha
/// @return rotação da linha
double linhaGetRotacao(linha li);

/// @brief libera a memória alocada para a linha
/// @param li linha
void linhaFree(linha li);

#endif
