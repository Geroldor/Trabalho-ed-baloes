/*funções para usar com applyClosure*/

#include "lista.h"
#include "circle.h"
#include "rect.h"
#include "line.h"
#include "text.h"
#include "structures.h"
#include "clausure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void move(Item item, Clausura c){
	retangulo r;
	circulo ci;
	linha l;
	texto t;
	if(item == r){
		r = (retangulo) item;
		rectangleSetx(r, getDXClausureMove(c));
		rectangleSety(r, getDYClausureMove(c));
	}
	else if(item == ci){
		ci = (circulo) item;
		circleSetCx(ci, getDXClausureMove(c));
		circleSetCy(ci, getDYClausureMove(c));
	}
	else if(item == l){
		l = (linha) item;
		double xd = abs(linhaGetx1(l) + linhaGetx2(l));
		double yd = abs(linhaGety1(l) + linhaGety2(l));
		linhaSetx1(l, getDXClausureMove(c));
		linhaSety1(l, getDYClausureMove(c));
		linhaSetx2(l, xd + getDXClausureMove(c));
		linhaSety2(l, yd + getDYClausureMove(c));

	}
	else if(item == t){
		t = (texto) item;
		textoSetX(t, getDXClausureMove(c));
		textoSetY(t, getDYClausureMove(c));
	}
}

