#ifndef FILA_H
#define FILA_H

typedef void* item;
typedef void* fila;

/// @brief cria uma fila
/// @param capacidade define o tamanho maximo da fila
/// @return ponteiro para a fila criada
fila createFila(int capacidade);

/// @brief insere o item inserido no @param conteudo no final da fila @param f
/// @param f fila onde o item sera inserido
/// @param conteudo conteudo do item a ser inserido
void insertFila(fila *f, item conteudo);


/// @brief remove o primeiro item da fila @param f
/// @param f fila onde o item sera removido
void removeFila(fila *f);

/// @brief recebe a fila @param f e retorna o primeiro item da fila
/// @param f fila onde o item sera retornado
/// @return primeiro item da fila @param f
item getFirstFila(fila *f);

/// @brief recebe a fila @param f e retorna o ultimo item da fila
/// @param f fila onde o item sera retornado 
/// @return ultimo item da fila @param f
item getLastFila(fila *f);

/// @brief retorna o tamanho da fila @param f
/// @param f fila onde o tamanho sera retornado
/// @return o tamanho da fila @param f
int getSizeFila(fila *f);


/// @brief retorna o tamanho maximo da fila @param f
/// @param f fila onde o tamanho maximo sera retornado
/// @return tamanho maximo da fila @param f
int getCapacityFila(fila *f);


/// @brief apaga a fila @param f e seus elementos e libera seus espaços de memoria
/// @param f fila a ser apagada
void killFila(fila *f);

#endif