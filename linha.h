#ifndef Linha_H
#define Linha_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
linha é um polígono que possui dois pontos de origem (âncora definida por x e y) e cor.
*/
typedef void *linha;

/** createLinha retorna uma linha; */
linha createLinha(int id, double x1, double y1, double x2, double y2, char *cor);

/** linhaSeti recebe uma linha e um inteiro e seta o id da linha */
void linhaSeti(linha li, int i);

/** linhaSetx1 recebe uma linha e um double e seta o x do início da linha */
void linhaSetx1(linha li, double x1);

/** linhaSety1 recebe uma linha e um double e seta o y do início da linha */
void linhaSety1(linha li, double y1);

/** linhaSetx2 recebe uma linha e um double e seta o x do fim da linha */
void linhaSetx2(linha li, double x2);

/** linhaSety2 recebe uma linha e um double e seta o y do fim da linha */
void linhaSety2(linha li, double y2);

/** linhaSetcor recebe uma linha e uma string e seta a cor da linha */
void linhaSetcor(linha li, char *cor);

/** linhaGeti recebe uma linha e retorna o id da linha */
int linhaGeti(linha li);

/** linhaGetx1 recebe uma linha e retorna o x do início da linha */
double linhaGetx1(linha li);

/** linhaGety1 recebe uma linha e retorna o y do início da linha */
double linhaGety1(linha li);

/** linhaGetx2 recebe uma linha e retorna o x do fim da linha */
double linhaGetx2(linha li);

/** linhaGety2 recebe uma linha e retorna o y do fim da linha */
double linhaGety2(linha li);

/** linhaGetcor recebe uma linha e retorna a cor da linha */
char *linhaGetcor(linha li);

/** linhaSetRotacao recebe uma linha e um double e seta o angulo de rotação da linha */
void linhaSetRotacao(linha li, double rotacao);

/** linhaGetRotacao recebe uma linha e retorna o angulo de rotação da linha */
double linhaGetRotacao(linha li);

/** linhaFree recebe uma linha e libera a memória alocada para ela */
void linhaFree(linha li);

#endif
