#ifndef SVG_H
#define SVG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"	
#include "structures.h"

/// @brief inicia a escrita do svg
/// @param svg arquivo svg
void startSvg(FILE *svg);

/// @brief encerra a escrita do svg
/// @param svg arquivo svg
void endSvg(FILE *svg);

/// @brief escreve um circulo no svg
/// @param svg arquivo svg
/// @param c circulo
void circleSvg(FILE *svg, circulo c);

/// @brief escreve um retangulo no svg
/// @param svg arquivo svg
/// @param r retangulo
void rectSvg(FILE *svg, retangulo r);

/// @brief escreve um texto no svg
/// @param svg arquivo svg
/// @param t texto
void textSvg(FILE *svg, texto t);

/// @brief escreve uma linha no svg
/// @param svg arquivo svg
/// @param l linha
void lineSvg(FILE *svg, linha l);


#endif