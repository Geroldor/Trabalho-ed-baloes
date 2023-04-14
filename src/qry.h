#ifndef QRY_H
#define QRY_H

#include "lista.h"
#include "objects.h"
#include "path.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// @brief lê o arquivo qry e chama as funções de acordo com o comando
/// @param fullpath caminho para o arquivo qry
void readqry(char *fullpath);


#endif