#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>

enum type {RECTANGLE, CIRCLE, LINE, TEXT};

enum type getType(void* item);

#endif