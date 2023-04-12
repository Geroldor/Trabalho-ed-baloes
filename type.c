#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

enum getType(void* item){
	if (item->tipo == RECTANGLE)
	{
		return RECTANGLE;
	}
	if (item->tipo == CIRCLE)
	{
		return CIRCLE;
	}
	if (item->tipo == LINE)
	{
		return LINE;
	}
	if (item->tipo == TEXT)
	{
		return TEXT;
	}
}