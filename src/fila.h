#ifndef FILA_H
#define FILA_H

typedef void *item;
typedef void *fila;

/// @brief cria uma fila
/// @param capacidade define o tamanho maximo da fila
/// @return ponteiro para a fila criada
fila createFila(int capacidade);

/// @brief insere o item inserido no conteudo no final da fila fi
/// @param fi fila onde o item sera inserido
/// @param conteudo conteudo do item a ser inserido
void insertFila(fila *fi, item conteudo);

/// @brief remove o primeiro item da fila fi
/// @param fi fila onde o item sera removido
void removeFila(fila *fi);

/// @brief recebe a fila fi e retorna o primeiro item da fila
/// @param fi fila onde o item sera retornado
/// @return primeiro item da fila fi
item getFirstFila(fila *fi);

/// @brief recebe a fila fi e retorna o ultimo item da fila
/// @param fi fila onde o item sera retornado
/// @return ultimo item da fila fi
item getLastFila(fila *fi);

/// @brief retorna o tamanho da fila fi
/// @param fi fila onde o tamanho sera retornado
/// @return o tamanho da fila fi
int getSizeFila(fila *fi);

/// @brief retorna o tamanho maximo da fila fi
/// @param fi fila onde o tamanho maximo sera retornado
/// @return tamanho maximo da fila fi
int getCapacityFila(fila *fi);

/// @brief apaga a fila fi e seus elementos e libera seus espaços de memoria
/// @param fi fila a ser apagada
void killFila(fila *fi);

#endif