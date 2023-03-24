#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <stdio.h>
#include <stdlib.h>


/**archive.h é um cabeçalho que trata de abrir e 
 * fechar arquivos, organizando-os em uma struct 
 * */

typedef void* archive;

archive *open(char *name, char *mode);
/**Cria e aloca um espaço de memoria para uma struct arq, 
 * em seguida abre um arquivo com nome e modo inserido na entrada da função
 * e retorna um void pointer para a struct com o arquivo
 * */

void close(archive *arq);
/** Fecha o arquivo aberto na struct que esta dentro do void pointer arq
 */

void freearq(archive *a);
/**
 * libera o espaço de memoria que a struct contida em 'a' ocupa.
  */

#endif