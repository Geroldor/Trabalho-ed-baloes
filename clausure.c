#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clausure.h"

typedef struct clausureMove{
	// struct para mover um objeto
	int id;
	float dx;
	float dy;
} clausureMove;

typedef struct clausureG{
	// struct para girar um objeto
	int id;
	float grs;
} clausureG;

clausure createClausureMove(int id, float dx, float dy){
	clausureMove *c = malloc(sizeof(clausureMove));
	c->id = id;
	c->dx = dx;
	c->dy = dy;
	return c;
}

clausure createClausureG(int id, float grs){
	clausureG *c = malloc(sizeof(clausureG));
	c->id = id;
	c->grs = grs;
	return c;
}

int getIDClausureMove(clausure c){
	clausureMove *cj = c;
	return cj->id;
}

double getDXClausureMove(clausure c){
	clausureMove *cj = c;
	return cj->dx;
}

double getDYClausureMove(clausure c){
	clausureMove *cj = c;
	return cj->dy;
}

int getIDClausureG(clausure c){
	clausureG *cj = c;
	return cj->id;
}

double getGRSClausureG(clausure c){
	clausureG *cj = c;
	return cj->grs;
}

void freeClausureMove(clausure c){
	clausureMove *cj = c;
	free(cj);
}

void freeClausureG(clausure c){
	clausureG *cj = c;
	free(cj);
}