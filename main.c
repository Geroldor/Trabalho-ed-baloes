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

int main(){
	char *fullPath = "/home/geraldo/Downloads/t1/03-cenario-grande.geo";
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
	FILE *arq = abreEscritaSvg(fullPath);
	while (p != NULL)
	{
		if (strcmp(getType(p), "r") == 0)
		{
			r = (retangulo) getLst(p);
			escreveRetanguloSvg(arq, rectangleGetx(r), rectangleGety(r), rectangleGetw(r), rectangleGeth(r), rectangleGetRotacao(r),rectangleGetcorb(r), rectangleGetcorp(r));
		}
		if (strcmp(getType(p), "c") == 0)
		{
			c = getLst(p);
			escreveCirculoSvg(arq, circleGetCx(c), circleGetCy(c), circleGetR(c), circleGetRotacao(c),circleGetCorb(c), circleGetCorp(c));
		}
		if (strcmp(getType(p), "l") == 0)
		{
			l = (linha) getLst(p);
			escreveLinhaSvg(arq, linhaGetx1(l), linhaGety1(l), linhaGetx2(l), linhaGety2(l), linhaGetRotacao(l), linhaGetcor(l));
		}
		if (strcmp(getType(p), "t") == 0)
		{
			t = (texto) getLst(p);
			escreveTextoSvg(arq, textoGetX(t), textoGetY(t), textoGetRotacao(t), textoGetConteudo(t), textoGetFontType(t), textoGetFontSize(t), textoGetFontWeight(t), textoGetAncora(t), textoGetCorb(t), textoGetCorp(t));
		}
		p = getNextLst(p);
	}
}