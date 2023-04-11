#include <string.h>
#include "path.h"

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq)
{
    extArq = strrchr(fullPath, '.');
    char *aux = strrchr(fullPath, '/');
    strncpy(path, fullPath, aux - fullPath + 1);
    path[aux - fullPath + 1] = '\0';
    strncpy(nomeArq, aux + 1, strlen(aux) + 1);
    nomeArq[strlen(aux) - strlen(extArq) - 1] = '\0';
    lenExtArq = strlen(extArq);
    lenNomeArq = strlen(nomeArq);
}
void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath){
    strcat(fullPath, path);
    strcat(fullPath, fileName);
}

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenFullPath){
    joinFilePath(path, fileName, fullPath, lenFullPath);
    if (strrchr(fullPath, '.') == NULL)
    {
        strcat(fullPath, ext);
    }
}
void getFileName(char *fullPath, char *fileName){
    char *aux1 = strrchr(fullPath, '/');
    char *aux2 = strrchr(fullPath, '.');
    strncpy(fileName, aux1 + 1, strlen(aux1) + 1);
    fileName[strlen(aux1) - strlen(aux2) - 1] = '\0';
}
void getPath(char *fullPath, char *path){
    char *aux = strrchr(fullPath, '/');
    strncpy(path, fullPath, aux - fullPath + 1);
    path[aux - fullPath + 1] = '\0';
}

void normalizePath(char *path, char *normPath, int lenNormPath){
    char *aux = strrchr(path, '/');
    if (*aux != '\0' && aux != NULL){
        aux = '\0';
    }
    strncpy(normPath, path, strlen(path) - 1);
}