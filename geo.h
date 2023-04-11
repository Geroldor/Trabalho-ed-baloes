#ifndef GEO_H
#define GEO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "structures.h"
#include "lista.h"
#include "geo.h"

/// @brief lê o arquivo geo e armazena os dados em uma lista encadeada
/// @param path caminho do arquivo geo
/// @param name nome do arquivo geo
/// @param l lista encadeada que armazena os dados do arquivo geo 
void readgeo(char* path, char* name, char* fullpath, Lista l);

#endif