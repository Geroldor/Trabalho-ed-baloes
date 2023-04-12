#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archive.h"
#include "path.h"
#include "svg.h"
#include "structures.h"
#include "objects.h"
#include "qry.h"
#include "geo.h"
#include "text.h"
#include "line.h"
#include "rect.h"
#include "circle.h"
#include "text.h"

enum type {RECTANGLE, CIRCLE, LINE, TEXT};

int main(){
	char *fullPath = "/home/geraldo/Downloads/t1/01-caca-fotos.geo";
	char *path = malloc(sizeof(char) * 100);
	char *name = malloc(sizeof(char) * 100);
	getFileName(fullPath, name);
	getPath(fullPath, path);
	retangulo r;
	circulo c;
	linha l;
	texto t;
	Lista lst = createLst(-1);
	readgeo(path, name, fullPath, lst);
	Posic p = getFirstLst(lst);
	Item item;
	Archive arq = abreEscritaSvg(fullPath);
	enum type type;
	while (p != NULL)
	{
		item = getLst(lst, p);
		if (type == RECTANGLE)
		{
			r = (retangulo) item;
			escreveRetanguloSvg(arq, rectangleGetx(r), rectangleGety(r), rectangleGetw(r), rectangleGeth(r), rectangleGetRotacao(r),rectangleGetcorb(r), rectangleGetcorp(r));

		}
		if (type == CIRCLE)
		{
			c = (circulo) item;
			escreveCirculoSvg(arq, circleGetCx(c), circleGetCy(c), circleGetR(c), circleGetRotacao(c),circleGetCorb(c), circleGetCorp(c));
		}
		if (type == LINE)
		{
			l = (linha) item;
			escreveLinhaSvg(arq, linhaGetx1(l), linhaGety1(l), linhaGetx2(l), linhaGety2(l), linhaGetRotacao(l), linhaGetcor(l));
		}
		if (type == TEXT)
		{
			t = (texto) item;
			escreveTextoSvg(arq, textoGetX(t), textoGetY(t), textoGetRotacao(t), textoGetConteudo(t), textoGetFontType(t), textoGetFontSize(t), textoGetFontWeight(t), textoGetAncora(t), textoGetCorb(t), textoGetCorp(t));
		}
		p = getNextLst(lst, p);
	}
	fechaSvg(arq);
	free(path);
	free(name);
	killLst(lst);
	close(arq);
}