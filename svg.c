#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "svg.h"

typedef struct _ArqSvg
{
    FILE *f;
    char *fn;
} arqsvg;

ArqSvg abreEscritaSvg(char *fn)
{
    struct _ArqSvg *arq = (ArqSvg)malloc(sizeof(struct _ArqSvg));
    if (arq == NULL)
    {
        return NULL;
    }

    arq->fn = strdup(fn);
    if (arq->fn == NULL)
    {
        free(arq);
        return NULL;
    }

    arq->f = fopen(fn, "w");
    if (arq->f == NULL)
    {
        free(arq->fn);
        free(arq);
        return NULL;
    }

    fprintf(arq->f, "<?xml version=\"1.0\" standalone=\"no\"?>\n");
    fprintf(arq->f, "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n");
    fprintf(arq->f, "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
    fprintf(arq->f, "<svg width=\"100%%\" height=\"100%%\"\n");
    fprintf(arq->f, "xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");

    return arq;
}

void preparaDecoracao(ArqSvg fsvg, char *deco, int decoLen,
                      char *corBorda, char *corPreenchimento,
                      char *larguraBorda, double transparencia,
                      double transparenciaPreenchimento, double transparenciaBorda)
{
    snprintf(deco, decoLen, "stroke:%s;fill-opacity:%lf;stroke-opacity:%lf;stroke-width:%s;fill:%s;stroke-linejoin:round",
             corBorda, transparenciaPreenchimento, transparenciaBorda, larguraBorda, corPreenchimento);
}

void escreveCirculoSvg(ArqSvg fsvg, double xc, double yc, double r, char *deco)
{
    struct _ArqSvg *arq = (struct _ArqSvg *)fsvg;
    fprintf(arq->f, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" style=\"%s\" />\n", xc, yc, r, deco);
}

void escreveRetanguloSvg(ArqSvg fsvg, double x, double y, double larg, double alt, char *deco)
{
    struct _ArqSvg *arq = (struct _ArqSvg *)fsvg;
    fprintf(arq->f, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" style=\"%s\" />\n", x, y, larg, alt, deco);
}

void escreveLinhaSvg(ArqSvg fsvg, double x1, double y1, double x2, double y2, char *deco)
{
    struct _ArqSvg *arq = (struct _ArqSvg *)fsvg;
    fprintf(arq->f, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"%s\" />\n", x1, y1, x2, y2, deco);
}

void preparaDecoracaoTexto(ArqSvg fsvg, char *deco, int decoLen,
                           char *fontFamily, char *fontStyle,
                           char *fontWeight, char *fontSize,
                           char *fontColor, char *textAnchor,
                           char *strokeColor)
{
    snprintf(deco, decoLen, "font-family:%s;font-style:%s;font-weight:%s;font-size:%spx;fill:%s;text-anchor:%s;stroke:%s;stroke-width:1px",
             fontFamily, fontStyle, fontWeight, fontSize, fontColor, textAnchor, strokeColor);
}

void escreveTextoSvg(ArqSvg fsvg, double x, double y, char *deco, char *texto)
{
    struct _ArqSvg *arq = (struct _ArqSvg *)fsvg;
    fprintf(arq->f, "<text x=\"%lf\" y=\"%lf\" style=\"%s\">%s</text>\n", x, y, deco, texto);
}

void fechaSvg(ArqSvg fsvg)
{
    struct _ArqSvg *arq = (struct _ArqSvg *)fsvg;
    fprintf(arq->f, "</svg>\n");
    fclose(arq->f);
    free(arq->fn);
    free(arq);
}

int main(){
    ArqSvg *x = abreEscritaSvg("teste.svg");
    escreveCirculoSvg(x, 4, 5, 2, "blue blue");
    fechaSvg(x);
}