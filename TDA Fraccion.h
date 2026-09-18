#ifndef FRACCION_H
#define FRACCION_H

//TDA de fracciones

typedef struct fraccion_ fraccion;


fraccion* fraction_new (int num, int den);

void fraction_destroy (fraccion* f);

void fraction_print (fraccion* f);

int fraction_get_num (fraccion* f);

int fraction_get_den (fraccion* f);

void fraction_simplify (fraccion* f);

fraccion* fraction_add (fraccion* f1, fraccion* f2);

fraccion* fraction_sub (fraccion* f1, fraccion* f2);

fraccion* fraction_mul (fraccion* f1, fraccion* f2);

fraccion* fraction_div (fraccion* f1, fraccion* f2);

int fraction_cmp (fraccion* f1, fraccion* f2);

#endif