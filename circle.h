#ifndef CIRCLE_H
#define CIRCLE_H

typedef void* circulo;

/// @brief Cria um circulo
/// @param id id do circulo
/// @param x coordenada x do circulo
/// @param y coordenada y do circulo
/// @param r raio do circulo
/// @param corp cor de preenchimento do circulo
/// @param corb cor de borda do circulo
/// @return void* para um circulo
circulo *createCircle(int id, double x, double y, double r, char *corp,  char *corb);

/// @brief altera a id do circulo
/// @param ci circulo
/// @param id nova id do circulo
void circleSetId(circulo ci, int id);

/// @brief altera a coordenada x do circulo
/// @param ci circulo
/// @param x nova coordenada x do circulo
void circleSetCx(circulo ci, double x);

/// @brief altera a coordenada y do circulo
/// @param ci circulo
/// @param y nova coordenada y do circulo
void circleSetCy(circulo ci, double y);

/// @brief altera o raio do circulo
/// @param ci circulo
/// @param r novo raio do circulo
void circleSetR(circulo ci, double r);

/// @brief remove o circulo da memoria
/// @param ci circulo
void circleFree(circulo ci);

/// @brief retorna a id do circulo
/// @param ci circulo
/// @return id do circulo
int circleGetId(circulo ci);

/// @brief retorna a coordenada x do circulo
/// @param ci circulo
/// @return coordenada x do circulo
double circleGetCx(circulo ci);

/// @brief retorna a coordenada y do circulo
/// @param ci circulo
/// @return coordenada y do circulo
double circleGetCy(circulo ci);

/// @brief retorna o raio do circulo
/// @param ci circulo
/// @return raio do circulo
double circleGetR(circulo ci);

/// @brief retorna a cor de preenchimento do circulo
/// @param ci circulo
/// @return cor de preenchimento do circulo
char* circleGetCorp(circulo ci);

/// @brief retorna a cor de borda do circulo
/// @param ci circulo
/// @return cor de borda do circulo
char* circleGetCorb(circulo ci);

/// @brief retorna a rotacao do circulo
/// @param ci circulo
/// @return rotacao do circulo
void circleSetCorb(circulo ci, char *corb);

/// @brief define a cor de preenchimento do circulo
/// @param ci circulo
/// @param corp nova cor de preenchimento do circulo
void circleSetCorp(circulo ci, char *corp);

/// @brief define a rotacao do circulo
/// @param ci circulo
/// @param rotacao nova rotacao do circulo
void circleSetRotacao(circulo ci, double rotacao);

/// @brief retorna a rotacao do circulo
/// @param ci circulo
/// @return rotacao do circulo
double circleGetRotacao(circulo ci);
#endif