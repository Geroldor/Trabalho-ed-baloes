#ifndef _TEXTO_H
#define _TEXTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
TEXTO é um polígono que possui um ponto de origem no início, meio ou fim (âncora definida por x e y),
conteúdo, cor de borda, cor de preenchimento, fonte, tamanho, preso e rotação.
*/
typedef void *texto;

/**TEXTO_BUFFER recebe um char* e um char* e aloca espaço para eles*/
void textBuffer(char *font_type, char *font_size, char* font_weight, char *a, char *b, char *c);

/**CREATE_TEXTO retorna um TEXTO;*/
texto textoCreate(int id, double x, double y, char *conteudo, char *ancora, char *corb, char *corp, char *font_type, char *font_size, char *font_weight);

/**TEXTO_SET_I recebe um TEXTO e um inteiro e seta o ID do TEXTO*/
void textoSetId(texto tex, int id);

/**TEXTO_SET_ANCOR recebe um TEXTO e um char e seta a posição da ancora do TEXTO*/
void textoSetAncora(texto tex, char *ancora);

/**TEXTO_SET_X recebe um TEXTO e um double e seta o x da ancora do TEXTO*/
void textoSetX(texto tex, double x);

/**TEXTO_SET_Y recebe um TEXTO e um double e seta o y da ancora do TEXTO*/
void textoSetY(texto tex, double y);

/**TEXTO_SET_CONTEUDO recebe um TEXTO e uma char* e seta o conteúdo do TEXTO*/
void textoSetConteudo(texto tex, char *conteudo);

/**TEXTO_SET_CORB recebe um TEXTO e uma char* e seta a cor de borda do TEXTO*/
void textoSetCorb(texto tex, char *corb);

/**TEXTO_SET_CORP recebe um TEXTO e uma char* e seta a cor de preenchimento do TEXTO*/
void textoSetCorp(texto tex, char *corp);

/**TEXTO_SET_ROTACAO recebe um TEXTO e um double e seta a rotação do TEXTO*/
void textoSetRotacao(texto tex, double rotacao);

/**TEXTO_GET_I recebe um TEXTO e retorna o ID do TEXTO*/
int textoGetI(texto tex);

/**TEXTO_GET_ANCOR recebe um TEXTO e retorna a posição da ancora do TEXTO*/
char *textoGetAncora(texto tex);

/**TEXTO_GET_X recebe um TEXTO e retorna o x da ancora do TEXTO*/
double textoGetX(texto tex);

/**TEXTO_GET_Y recebe um TEXTO e retorna o y da ancora do TEXTO*/
double textoGetY(texto tex);

/**TEXTO_GET_CONTEUDO recebe um TEXTO e retorna o conteúdo do TEXTO*/
char *textoGetConteudo(texto tex);

/**TEXTO_GET_CORB recebe um TEXTO e retorna a cor de borda do TEXTO*/
char *textoGetCorb(texto tex);

/**TEXTO_GET_CORP recebe um TEXTO e retorna a cor de preenchimento do TEXTO*/
char *textoGetCorp(texto tex);

/**TEXTO_GET_ROTACAO recebe um TEXTO e retorna a rotação do TEXTO*/
double textoGetRotacao(texto tex);

/**TEXTO_FREE recebe um TEXTO e libera a memória alocada para o TEXTO*/
void textoFree(texto tex);

/**TEXTO_GET_FONT_TYPE recebe um TEXTO e retorna a fonte do TEXTO*/
char *textoGetFontType(texto tex);

/**TEXTO_SET_FONT_TYPE recebe um TEXTO e uma char* e seta a fonte do TEXTO*/
void textoSetFontType(texto tex, char *font_type);

/**TEXTO_GET_FONT_WEIGHT recebe um TEXTO e retorna o peso da fonte do TEXTO*/
char *textoGetFontWeight(texto tex);

/**TEXTO_SET_FONT_WEIGHT recebe um TEXTO e uma char* e seta o peso da fonte do TEXTO*/
void textoSetFontWeight(texto tex, char *font_weight);

/**TEXTO_GET_FONT_SIZE recebe um TEXTO e retorna o tamanho da fonte do TEXTO*/
char* textoGetFontSize(texto tex);

/**TEXTO_SET_FONT_SIZE recebe um TEXTO e uma char* e seta o tamanho da fonte do TEXTO*/
void textoSetFontSize(texto tex, char *font_size);
#endif