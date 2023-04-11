#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "structures.h"
#include "archive.h"

typedef struct archive
{
	FILE *file;
	char *name;
	char *path;
	char *fullpath;
} archive;

Archive open(char *path, char *name, char *mode)
{
	archive *arq = (archive *)malloc(sizeof(archive));
	arq->name = name;
	arq->path = path;
	arq->fullpath = (char *)malloc(strlen(path) + strlen(name) + 1);
	strcpy(arq->fullpath, path);
	strcat(arq->fullpath, name);
	arq->file = fopen(arq->fullpath, mode);
	//Archive q = (Archive *)arq;
	return arq;
}

void close(Archive arq)
{
	archive *q = (archive *)arq;
	fclose(q->file);
	free(q->fullpath);
	free(q);
}

FILE *getArchive(Archive arq)
{
	archive *q = (archive *)arq;
	return q->file;
}