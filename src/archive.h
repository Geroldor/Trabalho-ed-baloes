#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "structures.h"

typedef void* Archive;

/// @brief abre um arquivo de nome @param name no caminho @param path com o modo @param mode
/// @param path caminho do arquivo
/// @param name nome do arquivo
/// @param mode modo de abertura do arquivo
/// @return ponteiro para o arquivo aberto
Archive open(char *path, char *name, char* fullpath, char *mode);

/// @brief fecha o arquivo @param archive
/// @param archive arquivo a ser fechado
void close(Archive arq);

/// @brief obtem o arquivo em @param arq
/// @param arq arquivo onde o objeto será escrito
/// @return ponteiro para o arquivo
FILE *getArchive(Archive arq);


#endif