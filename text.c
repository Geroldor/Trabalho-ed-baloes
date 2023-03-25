#include "texto.h"

struct text
{
    char *type;
    int id;
    double x;
    double y;
    char *conteudo;
    char *ancora;
    char *corb;
    char *corp;
    char *fonte;
    double rotacao;
};

texto textoCreate(int id, double x, double y, char *conteudo, char *ancora, char *corb, char *corp, char *fonte, double rotacao, char *type)
{
    struct text *text = (struct text *)malloc(sizeof(struct text));
    text->type = type;
    text->id = id;
    text->x = x;
    text->y = y;
    text->conteudo = conteudo;
    text->ancora = ancora;
    text->corb = corb;
    text->corp = corp;
    text->fonte = fonte;
    text->rotacao = rotacao;
    return text;
}

void textoSetType(texto text, char *type){
    struct text *t = text;
    t->type = type;
}

void textoSetId(texto text, int id)
{
    struct text *t = (struct text *)text;
    t->id = id;
}

void textoSetAncora(texto text, char *ancora)
{
    struct text *t = (struct text *)text;
    t->ancora = ancora;
}

void textoSetX(texto text, double x)
{
    struct text *t = (struct text *)text;
    t->x = x;
}

void textoSetY(texto text, double y)
{
    struct text *t = (struct text *)text;
    t->y = y;
}

void textoSetConteudo(texto text, char *conteudo)
{
    struct text *t = (struct text *)text;
    t->conteudo = conteudo;
}

void textoSetCorb(texto text, char *corb)
{
    struct text *t = (struct text *)text;
    t->corb = corb;
}

void textoSetCorp(texto text, char *corp)
{
    struct text *t = (struct text *)text;
    t->corp = corp;
}

void textoSetFont(texto text, char *fonte)
{
    struct text *t = (struct text *)text;
    t->fonte = fonte;
}   

void textoSetRotacao(texto text, double rotacao)
{
    struct text *t = (struct text *)text;
    t->rotacao = rotacao;
}

char *textoGetType(texto texto){
    struct text *t = texto;
    return t->type;
}

int textoGetI(texto text)
{
    struct text *t = (struct text *)text;
    return t->id;
}

char *textoGetAncora(texto text)
{
    struct text *t = (struct text *)text;
    return t->ancora;
}

double textoGetX(texto text)
{
    struct text *t = (struct text *)text;
    return t->x;
}

double textoGetY(texto text)
{
    struct text *t = (struct text *)text;
    return t->y;
}

char *textoGetConteudo(texto text)
{
    struct text *t = (struct text *)text;
    return t->conteudo;
}

char *textoGetCorb(texto text)
{
    struct text *t = (struct text *)text;
    return t->corb;
}

char *textoGetCorp(texto text)
{
    struct text *t = (struct text *)text;
    return t->corp;
}

char *textoGetFont(texto text)
{
    struct text *t = (struct text *)text;
    return t->fonte;
}

double textoGetRotacao(texto text)
{
    struct text *t = (struct text *)text;
    return t->rotacao;
}

void textoFree(texto text)
{
    struct text *t = (struct text *)text;
    free(t);
}