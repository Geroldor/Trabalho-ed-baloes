#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archive.h"
#include "path.h"
#include "svg.h"


FILE *abreEscritaSvg(char *fullPath)
{
    char* fileName = (char *) malloc (sizeof(char) * 100);
    getFileName(fullPath, fileName);
    FILE *svg = fopen(strcat(fileName, ".svg"), "w");
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
    return svg;
}

void escreveCirculoSvg(FILE *svg, double xc, double yc, double r, double rotation, char *corb, char *corp)
{
      
    fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" transform=\"rotate(%f, %f, %f)\" color=\"%s\" stroke-width=\"1\" stroke=\"%s\" />\n", xc, yc, r, rotation, xc, yc, corp, corb);
}

void escreveRetanguloSvg(FILE *svg, double x, double y, double larg, double alt, double rotation, char *corb, char *corp)
{
    fprintf(svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" transform=\"rotate(%f, %f, %f)\" color=\"%s\" stroke-width=\"1\" stroke=\"%s\" anchor=\"middle\"/>\n", x, y, larg, alt, rotation, x, y, corp, corb);
}

void escreveLinhaSvg(FILE *svg, double x1, double y1, double x2, double y2, double rotation, char *deco)
{
    
    fprintf(svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" transform=\"rotate(%f, %f, %f)\" style=\"%s\" />\n", x1, y1, x2, y2, rotation, ((x1+x2)/2), ((y1+y2)/2), deco);
}

void escreveTextoSvg(FILE *svg, double x, double y, double rotation, char *texto, char *fontType, char *fontSize, char* fontweight, char *anchor, char *corb, char *corp)
{
    
    if(strcmp(anchor, "m") == 0)
    {
        
        fprintf(svg, "<text x=\"%lf\" y=\"%lf\" transform=\"rotate(%f, %f, %f)\" text-anchor=\"middle\" fill=\"%s\" stroke\"%s\" ", x, y, rotation, x, y, corb, corp);
        if ((fontSize != NULL) && (fontType != NULL) && (fontweight != NULL))
        {
            fprintf(svg, "font-family=\"%s\" font-size=\"%s\" font-weight=\"%s\">%s</text>\n", fontType, fontSize, fontweight, texto);
        }else{
            fprintf(svg, ">%s</text>\n", texto);
        }
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

void fechaSvg(FILE *svg)
{
    fprintf(svg, "</svg>\n");
    fclose(svg);
}