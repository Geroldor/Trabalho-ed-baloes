#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archive.h"
#include "path.h"
#include "svg.h"


Archive abreEscritaSvg(char *fullPath)
{
    char* fileName;
    getFileName(fullPath, fileName);
    char* path;
    getPath(fullPath, path);
    Archive arq = open(path, fileName, fullPath, "a");
    FILE *svg = getArchive(arq);
    fprintf(svg, "<svg width=\"100%%\" height=\"100%%\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
    return arq;
}

void escreveCirculoSvg(Archive arq, double xc, double yc, double r, double rotation, char *corb, char *corp)
{
    FILE *svg = getArchive(arq);   
    fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" transform=\"rotate(%f, %f, %f)\" color=\"%s\" stroke-width=\"1\" stroke=\"%s\" />\n", xc, yc, r, rotation, xc, yc, corp, corb);
}

void escreveRetanguloSvg(Archive arq, double x, double y, double larg, double alt, double rotation, char *corb, char *corp)
{
    FILE *svg = getArchive(arq);
    fprintf(svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" transform=\"rotate(%f, %f, %f)\" color=\"%s\" stroke-width=\"1\" stroke=\"%s\" anchor=\"middle\"/>\n", x, y, larg, alt, rotation, x, y, corp, corb);
}

void escreveLinhaSvg(Archive arq, double x1, double y1, double x2, double y2, double rotation, char *deco)
{
    FILE *svg = getArchive(arq);
    fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" transform=\"rotate(%f, %f, %f)\" style=\"%s\" />\n", x1, y1, x2, y2, rotation, ((x1+x2)/2), ((y1+y2)/2), deco);
}

void escreveTextoSvg(Archive arq, double x, double y, double rotation, char *texto, char *fontType, char *fontSize, char* fontweight, char *anchor, char *corb, char *corp)
{
    FILE *svg = getArchive(arq);
    if(strcmp(anchor, "m") == 0)
    {
        fprintf(svg, "<text x=\"%lf\" y=\"%lf\" transform=\"rotate(%f, %f, %f)\" font-family=\"%s\" font-size=\"%s\" text-anchor=\"middle\"  font-weight=\"%s\">%s</text>\n", x, y, rotation, x, y, fontType, fontSize, fontweight, texto);
    }
    else if(strcmp(anchor, "i") == 0)
    {
        fprintf(svg, "<text x=\"%lf\" y=\"%lf\" fill=\"\" font-family=\"%s\" font-size=\"%s\" text-anchor=\"start\" font-weight=\"%s\">%s</text>\n", x, y, fontType, fontSize, fontweight, texto);
    }
    else if(strcmp(anchor, "f") == 0)
    {
        fprintf(svg, "<text x=\"%lf\" y=\"%lf\" fill=\"\" font-family=\"%s\" font-size=\"%s\" text-anchor=\"end\" font-weight=\"%s\">%s</text>\n", x, y, fontType, fontSize, fontweight, texto);
    }
}

void fechaSvg(Archive arq)
{
    FILE *svg = getArchive(arq);
    fprintf(svg, "</svg>\n");
    close(arq);
}