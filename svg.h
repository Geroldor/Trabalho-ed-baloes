#ifndef Archive__
#define Archive__
#include "archive.h"
/*
  Cria o arquivo "fn" para escrita. Substitui o arquivo, caso exista.
  Retorna NULL, caso nao tenha sido possivel criar arquivo.
 */
Archive abreEscritaSvg(char *fullPath);
/*
   Insere uma circunferencia com centro em (xc,yc) de raio r. Atributos de formatacao
(cores, largura de bordas, etc) podem ser informados pela string deco (atribuir NULL,
caso nao queira atribuir decoracao). As formatacoes mais usuais podem preparadas por
meio da operacao preparaDecoracao.
 */
void escreveCirculoSvg(Archive fsvg, double xc, double yc, double r, double rotation, char *corb, char *corp);

/*
   Insere um retangulo com canto inferior esquerdo  em (x,y), de largura larg e altura alt.
Atributos de formatacao (cores, largura de bordas, etc) podem ser informados pela string
deco (atribuir NULL, caso nao queira atribuir decoracao). As formatacoes mais usuais
podem preparadas por meio da operacao preparaDecoracao.
 */
void escreveRetanguloSvg(Archive fsvg, double x, double y, double larg, double alt, double rotation, char *corb, char *corp);

/*
   Insere uma linha com extremidades em (x1,y1) e (x2,y2).
Atributos de formatacao (cores, largura de bordas, etc) podem ser informados pela string
deco (atribuir NULL, caso nao queira atribuir decoracao). As formatacoes mais usuais
podem preparadas por meio da operacao preparaDecoracao.
 */
void escreveLinhaSvg(Archive fsvg, double x1, double y1, double x2, double y2, double rotation, char *deco);

/*
  Insere no arquivo svg o texto txt na coordenada (x,y).
Atributos de formatacao (cores, fonte, etc) podem ser informados pela string
deco (atribuir NULL, caso nao queira atribuir decoracao). As formatacoes mais usuais
podem preparadas por meio da operacao preparaDecoracaoTexto.
 */
void escreveTextoSvg(Archive fsvg, double x, double y, double rotation, char *txt, char *fontType, char *fontSize, char *fontweight, char* anchor, char* corb, char* corp);

/* Fecha o arquivo fsvg. */
void fechaSvg(Archive fsvg);

#endif