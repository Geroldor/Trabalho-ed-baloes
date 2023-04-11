#include "text.h"
#include <stdlib.h>

typedef struct text{
    int id;
    double x;
    double y;
    char *conteudo;
    char *ancora;
    char *corb;
    char *corp;
    char *font_type;
    char *font_size;
    double rotacao;
} text;

void textBuffer(char *font_type, char *font_size){
    font_type = (char *)malloc(strlen(font_type) + 10);
    font_size = (char *)malloc(strlen(font_size) + 1);
}

texto textoCreate(int id, double x, double y, char *conteudo, char *ancora, char *corb, char *corp, char *font_type, char *font_size)
{
    text *tex = (text *)malloc(sizeof(text));
    tex->id = id;
    tex->x = x;
    tex->y = y;
    tex->conteudo = conteudo;
    tex->ancora = ancora;
    tex->corb = corb;
    tex->corp = corp;
    tex->font_type = font_type;
    tex->font_size = font_size;
    return tex;
}

void textoSetId(texto tex, int id)
{
    text *t = (text *)tex;
    t->id = id;
}

void textoSetAncora(texto tex, char *ancora)
{
    text *t = (text *)tex;
    t->ancora = ancora;
}

void textoSetX(texto tex, double x)
{
    text *t = (text *)tex;
    t->x = x;
}

void textoSetY(texto tex, double y)
{
    text *t = (text *)tex;
    t->y = y;
}

void textoSetConteudo(texto tex, char *conteudo)
{
    text *t = (text *)tex;
    t->conteudo = conteudo;
}

void textoSetCorb(texto tex, char *corb)
{
    text *t = (text *)tex;
    t->corb = corb;
}

void textoSetCorp(texto tex, char *corp)
{
    text *t = (text *)tex;
    t->corp = corp;
}

void textoSetFont(texto tex, char *fonte)
{
    text *t = (text *)tex;
    t->font_type = fonte;
}   

void textoSetRotacao(texto tex, double rotacao)
{
    text *t = (text *)tex;
    t->rotacao = rotacao;
}

int textoGetI(texto tex)
{
    text *t = (text *)tex;
    return t->id;
}

char *textoGetAncora(texto tex)
{
    text *t = (text *)tex;
    return t->ancora;
}

double textoGetX(texto tex)
{
    text *t = (text *)tex;
    return t->x;
}

double textoGetY(texto tex)
{
    text *t = (text *)tex;
    return t->y;
}

char *textoGetConteudo(texto tex)
{
    text *t = (text *)tex;
    return t->conteudo;
}

char *textoGetCorb(texto tex)
{
    text *t = (text *)tex;
    return t->corb;
}

char *textoGetCorp(texto tex)
{
    text *t = (text *)tex;
    return t->corp;
}

char *textoGetFont(texto tex)
{
    text *t = (text *)tex;
    return t->font_type;
}

double textoGetRotacao(texto tex)
{
    text *t = (text *)tex;
    return t->rotacao;
}

void textoFree(texto tex){
    text *t = (text *)tex;
    free(t);
}

char* textoGetFontType(texto tex){
    text *t = (text *)tex;
    return t->font_type;
}

char* textoGetFontSize(texto tex){
    text *t = (text *)tex;
    return t->font_size;
}

void textoSetFontSize(texto tex, char *font_size){
    text *t = (text *)tex;
    t->font_size = font_size;
}

void textoSetFontType(texto tex, char *font_type){
    text *t = (text *)tex;
    t->font_type = font_type;
}
