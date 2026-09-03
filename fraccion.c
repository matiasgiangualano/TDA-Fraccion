#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

typedef struct fraccion_ {
    int numerador;
    int denominador;
} fraccion;

// crear una fracción
fraccion* fraction_new (int num, int den){

    if(den == 0){
        return NULL;
    }

    fraccion* nueva_fraccion;
    nueva_fraccion = (fraccion*)malloc(sizeof(fraccion));
    nueva_fraccion->numerador = num;
    nueva_fraccion->denominador = den;

    return nueva_fraccion;
}

//destruir una fracción
void fraction_destroy (fraccion* f){
    free(f);
}

//imprimir una fracción
void fraction_print (fraccion* f){
    printf("%i/%i", f->numerador, f->denominador);
}

//obtener numerador
int fraction_get_num (fraccion* f){
    return f->numerador;
}

//obtener denominador
int fraction_get_den (fraccion* f){
    return f->denominador;
}

//simplificar una fracción
void fraction_simplify (fraccion* f){

    int resto;
    int num = f->numerador;
    int den = f->denominador;
   
    while (den != 0) {
        resto = num % den; 
        num = den;
        den = resto;
    }

    f->numerador = f->numerador / num;
    f->denominador = f->denominador / num;
}

//sumar 2 fracciones
fraccion* fraction_add (fraccion* f1, fraccion* f2){
    int num_res = (f1->numerador * f2->denominador) + (f2->numerador * f1->denominador);
    int den_res = f1->denominador * f2->denominador;
    fraccion* f_sumada = fraction_new(num_res, den_res);

    fraction_simplify (f_sumada);

    return f_sumada;
}

//restar 2 fracciones
fraccion* fraction_sub (fraccion* f1, fraccion* f2){
    int num_res = (f1->numerador * f2->denominador) - (f2->numerador * f1->denominador);
    int den_res = f1->denominador * f2->denominador;
    fraccion* f_restada = fraction_new(num_res, den_res);

    fraction_simplify (f_restada);

    return f_restada;
}

//multiplicar 2 fracciones
fraccion* fraction_mul (fraccion* f1, fraccion* f2){
    int num_res = f1->numerador * f2->numerador;
    int den_res = f1->denominador * f2->denominador;
    fraccion* f_multiplicada = fraction_new(num_res, den_res);

    fraction_simplify (f_multiplicada);

    return f_multiplicada;
}

//dividir 2 fracciones
fraccion* fraction_div (fraccion* f1, fraccion* f2){
    int num_res = f1->numerador * f2->denominador;
    int den_res = f1->denominador * f2->numerador;
    fraccion* f_dividida = fraction_new(num_res, den_res);

    fraction_simplify (f_dividida);

    return f_dividida;
}

//comparar 2 fracciones
int fraction_cmp (fraccion* f1, fraccion* f2){
    int cmp = 0;

    if ((f1->numerador * f2->denominador) > (f2->numerador * f1->denominador)){
        cmp = 1;

    }else if ((f1->numerador * f2->denominador) < (f2->numerador * f1->denominador)){
        cmp = -1;
    }

    return cmp;
}