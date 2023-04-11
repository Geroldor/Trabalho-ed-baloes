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
	char *fullPath = "~/Downloads/t1/00-smpls-caca-disp.geo";
	char *path;
	char *name;
	getFileName(fullPath, name);
	getPath(fullPath, path);
	retangulo r;
	circulo c;
	linha l;
	texto t;
	Lista lst = createLst(-1);
	Archive arq = open(path, name, "r");
	readgeo(path, name, lst);
	Posic p = getFirst(lst);
	Item item;
	while (p != NULL)
	{
		item = getLst(lst, p);
		if (item == r)
		{
			r = (retangulo) item;
			escreveRetanguloSvg(arq, rectangleGetx(r), rectangleGety(r), rectangleGetw(r), rectangleGeth(r), rectangleGetRotacao(r),rectangleGetcorb(r), rectangleGetcorp(r));

		}
		if (item == c)
		{
			c = (circulo) item;
			escreveCirculoSvg(arq, circleGetx(c), circleGety(c), circleGetr(c), circleGetRotacao(c),circleGetcorb(c), circleGetcorp(c));
		}
		if (item == l)
		{
			l = (linha) item;
			escreveLinhaSvg(arq, linhaGetx1(l), linhaGety1(l), linhaGetx2(l), linhaGety2(l), linhaGetRotacao(l), linhaGetcor(l));
		}
		if (item == t)
		{
			t = (texto) item;
			escreveTextoSvg(arq, textoGetx(t), textoGety(t), textoGetRotacao(t), textoGetConteudo(t), textoGetFontType(t), textoGetFontSize(t), textoGetFontWeight(t), textoGetAncora(t), textoGetCorb(t), textoGetCorp(t));
		}
		p = getNextLst(lst, p);
	}
}