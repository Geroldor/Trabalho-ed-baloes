#ifndef FILA_H
#define FILA_H

typedef void* item;
typedef void* fila;


fila createFila(int capacidade);
/* cria uma fila circular estatica com a capacidade informada */

void insertFila(Fila *f, item conteudo);
/* insere o conteudo na ultima posição disponivel na fila f */

void removeFila(Fila *f);
/* remove o primeiro item da fila f */

item getFirstFila(Fila *f);
/* retorna o primeiro item da fila f */

item getLastFila(Fila *f);
/* retorna o ultimo item da fila f */

int getSizeFila(Fila *f);
/* retorna a quantidade de elementos na fila f */

int getCapacityFila(Fila *f);
/* retorna a capacidade maxima de elementos que a fila pode armazenar */

void killFila(Fila *f);
/* apaga a fila e seus elementos e libera seus espaços de memoria */
#endif