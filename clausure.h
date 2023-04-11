#ifndef CLAUSURE_H_
#define CLAUSURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* clausure;

/// @brief Cria uma clausura de movimento
/// @param id id para o objeto
/// @param dx coordenada x
/// @param dy coordenada y
/// @return clausura de movimento
clausure createClausureMove(int id, float dx, float dy);

/// @brief cria uma clausura de rotação para rotacionar um objeto ID em grs°
/// @param id id para o objeto
/// @param grs graus de rotação
/// @return claursura de rotação
clausure createClausureG(int id, float grs);

/// @brief retorna o id contido na clausura de movimento
/// @param c clausura
/// @return id contido na clausura
int getIDClausureMove(clausure c);

/// @brief retorna o dx contido na clausura de movimento
/// @param c clausura
/// @return dx contido na clausura
double getDXClausureMove(clausure c);

/// @brief retorna o dy contido na clausura de movimento
/// @param c clausura
/// @return dy contido na clausura
double getDYClausureMove(clausure c);

/// @brief retorna o id contido na clausura de rotação
/// @param c clausura
/// @return id contido na clausura
int getIDClausureG(clausure c);

/// @brief retorna o grs contido na clausura de rotação
/// @param c clausura
/// @return grs contido na clausura
double getGRSClausureG(clausure c);

#endif