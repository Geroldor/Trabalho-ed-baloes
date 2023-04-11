#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"	
#include "structures.h"

void startSvg(FILE *svg){
	fprintf(svg, "<svg>\n");
}

void endSvg(FILE *svg){
	fprintf(svg, "</svg>\n");
}

void circleSvg(FILE *svg, circulo c){
	double cx = circleGetCx(c);
	double cy = circleGetCy(c);
	double r = circleGetR(c);
	char* corb = circleGetCorb(c);
	char* corp = circleGetCorp(c);
	fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", cx, cy, r, corb, corp);
}

void rectangleSvg(FILE *svg, retangulo r){
	fprintf(svg, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", rectangleGetx(r), rectangleGety(r), rectangleGetw(r), rectangleGeth(r), rectangleGetcorb(r), rectangleGetcorp(r));
}

void textSvg(FILE *svg, texto t){
	fprintf(svg, "<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" font-size=\"%s\" font-family=\"%s\">%s</text>\n", textoGetX(t), textoGetY(t), textoGetCorb(t), textoGetCorp(t), textoGetFontSize(t), textoGetFontType(t), textoGetConteudo(t));
}

void lineSvg(FILE *svg, linha l){
	fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"1\"/>\n", linhaGetx1(l), linhaGety1(l), linhaGetx2(l), linhaGety2(l), linhaGetcor(l));
}