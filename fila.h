#ifndef FILA_H
#define FILA_H

typedef void* item;
typedef void* fila;


fila createFila(int capacidade);
/* cria uma fila circular estatica com a capacidade informada */

void insertFila(fila *f, item conteudo);
/* insere o conteudo na ultima posição disponivel na fila f */

void removeFila(fila *f);
/* remove o primeiro item da fila f */

item getFirstFila(fila *f);
/* retorna o primeiro item da fila f */

item getLastFila(fila *f);
/* retorna o ultimo item da fila f */

int getSizeFila(fila *f);
/* retorna a quantidade de elementos na fila f */

int getCapacityFila(fila *f);
/* retorna a capacidade maxima de elementos que a fila pode armazenar */

void killFila(fila *f);
/* apaga a fila e seus elementos e libera seus espaços de memoria */
#endif