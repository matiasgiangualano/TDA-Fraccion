#ifndef _VECTOR
#define _VECTOR

#include "TDA Fraccion.h"

#define VECTOR_ELEMENT fraccion*

typedef struct _vector vector;
vector* vector_new(int ini_size);
void vector_free(vector* v);
int vector_size(vector* v);
int vector_isfull(vector* v);
int vector_isempty(vector* v);
VECTOR_ELEMENT vector_get(vector* v, int index);
VECTOR_ELEMENT vector_set(vector* v, int index, VECTOR_ELEMENT value);
int vector_add(vector* v, VECTOR_ELEMENT value);
int vector_insert(vector* v, int index, VECTOR_ELEMENT value);
VECTOR_ELEMENT vector_remove(vector* v, int index);

#endif