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
	fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", circleGetCx(c), circleGetCy(c), circleGetR(c), circleGetCorb(c), circleGetCorp(c));
}

void rectangleSvg(FILE *svg, retangulo r){
	fprintf(svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\"/>\n", rectangleGetX(r), rectangleGetY(r), rectangleGetW(r), rectangleGetH(r), rectangleGetCorb(r), rectangleGetCorp(r));
}

void textSvg(FILE *svg, texto t){
	fprintf(svg, "<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" font-size=\"20\" font-family=\"Verdana\">%s</text>\n", textGetX(t), textGetY(t), textGetCorb(t), textGetCorp(t), textGetConteudo(t));
}

void lineSvg(FILE *svg, linha l){
	fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"1\"/>\n", lineGetX1(l), lineGetY1(l), lineGetX2(l), lineGetY2(l), lineGetCor(l));
}