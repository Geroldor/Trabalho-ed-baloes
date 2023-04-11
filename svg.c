#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archive.h"
#include "path.h"
#include "svg.h"


void abreEscritaSvg(char *fullPath)
{
    char* fileName;
    getFileName(fullPath, fileName);
    Archive arq = open(fullPath, fileName , "a");
    FILE *svg = getArchive(arq);
    fprintf(svg, "<?xml version=\"1.0\" standalone=\"no\"?>\n");
    fprintf(svg, "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n");
    fprintf(svg, "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
    fprintf(svg, "<svg width=\"100%%\" height=\"100%%\"\n");
    fprintf(svg, "xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
}

void escreveCirculoSvg(Archive arq, double xc, double yc, double r, char *deco)
{
    FILE *svg = getArchive(arq);   
    fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" style=\"%s\" />\n", xc, yc, r, deco);
}

void escreveRetanguloSvg(Archive arq, double x, double y, double larg, double alt, char *deco)
{
    FILE *svg = getArchive(arq);
    fprintf(svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" style=\"%s\" />\n", x, y, larg, alt, deco);
}

void escreveLinhaSvg(Archive arq, double x1, double y1, double x2, double y2, char *deco)
{
    FILE *svg = getArchive(arq);
    fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"%s\" />\n", x1, y1, x2, y2, deco);
}

void escreveTextoSvg(Archive arq, double x, double y, char *texto, char *fontType, char *fontSize)
{
    FILE *svg = getArchive(arq);
    fprintf(svg, "<text x=\"%lf\" y=\"%lf\" font-family=\"%s\" font-size=\"%s\">%s</text>\n", x, y, fontType, fontSize, texto);
}

void fechaSvg(Archive arq)
{
    FILE *svg = getArchive(arq);
    fprintf(svg, "</svg>\n");
    close(arq);
}