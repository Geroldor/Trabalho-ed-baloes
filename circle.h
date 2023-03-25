#ifndef CIRCLE_H
#define CIRCLE_H

typedef void* circulo;

/*
Cria um circulo com os parametros passados
*/
circulo *createCircle(int id, double x, double y, double r, char *corp,  char *corb);
/*
Define o id do circulo
*/
void circleSetId(circulo ci, int id);
/*
define a coordenada x do circulo
*/
void circleSetCx(circulo ci, double x);
/*
define a coordenada y do circulo
*/
void circleSetCy(circulo ci, double y);
/*
define o raio do circulo
*/
void circleSetR(circulo ci, double r);
/*
define a cor de preenchimento do circulo
*/
void circleSetFill(circulo ci, char *fill);
/*
Libera a memoria alocada para o circulo
*/
void circleFree(circulo ci);
/*
Retorna o id do circulo
*/
int circleGetId(circulo ci);
/*
Retorna a coordenada x do circulo
*/
double circleGetCx(circulo ci);
/*
Retorna a coordenada y do circulo
*/
double circleGetCy(circulo ci);
/*
Retorna o raio do circulo
*/
double circleGetR(circulo ci);
/*
Retorna a cor de preenchimento do circulo
*/
char cicleGetCorp(circulo ci);

char cicleGetCorb(circulo ci);

void circleSetCorb(circulo ci, char *corb);

void circleSetCorp(circulo ci, char *corp);

#endif