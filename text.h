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

/// @brief Define o tipo de fonte do texto até que seja alterado novamente.
/// @param font_type Tipo da fonte
/// @param font_size Tamanho da fonte
/// @param font_weight decoração da fonte
/// @param a tipo da fonte para ser inserido no buffer
/// @param b decoração da fonte para ser inserido no buffer
/// @param c tamanho da fonte para ser inserido no buffer
void textBuffer(char *font_type, char *font_size, char* font_weight, char *a, char *b, char *c);

/// @brief Cria um texto
/// @param id id do texto
/// @param x coordenada x da ancora
/// @param y coordenada y da ancora
/// @param conteudo conteudo do texto
/// @param ancora ancora do texto
/// @param corb cor da borda do texto
/// @param corp cor de preenchimento do texto
/// @param font_type tipo da fonte
/// @param font_size tamanho da fonte
/// @param font_weight decoração da fonte
/// @return void* do texto criado
texto textoCreate(int id, double x, double y, char *conteudo, char *ancora, char *corb, char *corp, char *font_type, char *font_size, char *font_weight);

/// @brief define uma nova id para o texto
/// @param tex texto
/// @param id nova id do texto
void textoSetId(texto tex, int id);

/// @brief define uma nova ancora para o texto
/// @param tex texto
/// @param ancora nova posição da ancora do texto
void textoSetAncora(texto tex, char *ancora);

/// @brief define uma coordenada x para o texto
/// @param tex texto
/// @param x nova coordenada x da ancora do texto
void textoSetX(texto tex, double x);

/// @brief define uma coordenada y para o texto
/// @param tex texto
/// @param y coordenada y da ancora do texto
void textoSetY(texto tex, double y);

/// @brief define um novo conteudo para o texto
/// @param tex texto
/// @param conteudo novo conteudo do texto 
void textoSetConteudo(texto tex, char *conteudo);

/// @brief define uma nova cor de borda para o texto
/// @param tex texto
/// @param corb nova cor de borda do texto
void textoSetCorb(texto tex, char *corb);

/// @brief define uma nova cor de preenchimento para o texto
/// @param tex texto
/// @param corp nova cor de preenchimento do texto
void textoSetCorp(texto tex, char *corp);

/// @brief define uma nova rotação para o texto
/// @param tex texto
/// @param rotacao nova rotação do texto
void textoSetRotacao(texto tex, double rotacao);

/// @brief pega a ID do texto
/// @param tex texto
/// @return id do texto
int textoGetI(texto tex);

/// @brief retorna a ancora do texto
/// @param tex texto
/// @return ancora do texto
char *textoGetAncora(texto tex);

/// @brief retorna a coordenada x do texto
/// @param tex texto
/// @return coordenada x do texto
double textoGetX(texto tex);

/// @brief retorna a coordenada y do texto
/// @param tex texto
/// @return coordenada y do texto
double textoGetY(texto tex);

/// @brief retorna o conteudo do texto
/// @param tex texto
/// @return conteudo do texto
char *textoGetConteudo(texto tex);

/// @brief retorna a cor de borda do texto
/// @param tex texto
/// @return cor de borda do texto
char *textoGetCorb(texto tex);

/// @brief retorna a cor de preenchimento do texto
/// @param tex texto
/// @return cor de preenchimento do texto
char *textoGetCorp(texto tex);

/// @brief retorna a rotação do texto
/// @param tex texto
/// @return rotação do texto
double textoGetRotacao(texto tex);

/// @brief retorna o tipo da fonte do texto
/// @param tex texto
/// @return tipo da fonte do texto
void textoFree(texto tex);

/// @brief retorna o tipo da fonte do texto
/// @param tex texto
/// @return tipo da fonte do texto
char *textoGetFontType(texto tex);

/// @brief Define o tipo da fonte do texto
/// @param tex texto
/// @param font_type tipo da fonte do texto 
void textoSetFontType(texto tex, char *font_type);

/// @brief Retorna o peso da fonte do TEXTO
/// @param tex texto 
/// @return peso da fonte do TEXTO
char *textoGetFontWeight(texto tex);

/// @brief Define o peso da fonte do TEXTO
/// @param tex texto
/// @param font_weight peso da fonte do TEXTO
void textoSetFontWeight(texto tex, char *font_weight);

/// @brief Retorna o tamanho da fonte do TEXTO
/// @param tex texto
/// @return tamanho da fonte do TEXTO
char* textoGetFontSize(texto tex);

/// @brief Define o tamanho da fonte do TEXTO
/// @param tex texto
/// @param font_size tamanho da fonte do TEXTO	
void textoSetFontSize(texto tex, char *font_size);
#endif