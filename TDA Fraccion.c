#include <stdio.h>
#include <stdlib.h>
#include "TDA Fraccion.h"

typedef struct fraccion_ {
    int numerador;
    int denominador;
} fraccion;

                                                            // Crea una fracción
fraccion* fraction_new (int num, int den){

    if(den == 0){
        return NULL;
    }
                                                            //Normalización de fracción
    if (den < 0) {
        num = -num;
        den = -den;
    }

    fraccion* nueva_fraccion = (fraccion*)malloc(sizeof(fraccion));
    if (nueva_fraccion != NULL)
    {
        nueva_fraccion->numerador = num;
        nueva_fraccion->denominador = den;
    }
    return nueva_fraccion;
}

                                                            //Destruye una fracción
void fraction_destroy (fraccion* f){
    free(f);
}

                                                            //Imprime una fracción
void fraction_print (fraccion* f){
    if(f != NULL){
        printf("%i/%i", f->numerador, f->denominador);
    }
}

                                                            //Obtiene el numerador
int fraction_get_num (fraccion* f){
    int numerador = 0;
    if(f != NULL){
        numerador = f->numerador;
    }
    return numerador;
}

                                                            //Obtiene el denominador
int fraction_get_den (fraccion* f){
    int denominador = 0;
    if(f != NULL){
        denominador = f->denominador;
    }
    return denominador;
}

                                                            //Simplifica una fracción
void fraction_simplify (fraccion* f){

    if (f != NULL) {
                                                            //Se calcula el máximo común múltiplo
        int resto;
        int num = abs(f->numerador);
        int den = abs(f->denominador);
   
        while (den != 0) {
            resto = num % den; 
            num = den;
            den = resto;
        }

        f->numerador = f->numerador / num;
        f->denominador = f->denominador / num;
    }
}

                                                                    //Suma 2 fracciones
fraccion* fraction_add (fraccion* f1, fraccion* f2){
    
    fraccion* sumada = NULL;
    if (f1 != NULL && f2 != NULL)
    {
        int num_res = (f1->numerador * f2->denominador) + (f2->numerador * f1->denominador);
        int den_res = f1->denominador * f2->denominador;
        sumada = fraction_new(num_res, den_res);
        fraction_simplify (sumada);
    }

    return sumada;
}

                                                                    //Resta 2 fracciones
fraccion* fraction_sub (fraccion* f1, fraccion* f2){
    
    fraccion* restada = NULL;
    if (f1 != NULL && f2 != NULL)
    {
        int num_res = (f1->numerador * f2->denominador) - (f2->numerador * f1->denominador);
        int den_res = f1->denominador * f2->denominador;
        restada = fraction_new(num_res, den_res);

        fraction_simplify (restada);
    }
    return restada;
}

                                                                    //Multiplica 2 fracciones
fraccion* fraction_mul (fraccion* f1, fraccion* f2){

    fraccion* multiplicada = NULL;
    if (f1 != NULL && f2 != NULL)
    {
        int num_res = f1->numerador * f2->numerador;
        int den_res = f1->denominador * f2->denominador;
        multiplicada = fraction_new(num_res, den_res);

        fraction_simplify (multiplicada);
    }
    return multiplicada;
}

                                                                    //Divide 2 fracciones
fraccion* fraction_div (fraccion* f1, fraccion* f2){
    
    fraccion* dividida = NULL;
    if (f1 != NULL && f2 != NULL)
    {
        int num_res = f1->numerador * f2->denominador;
        int den_res = f1->denominador * f2->numerador;
        dividida = fraction_new(num_res, den_res);

        fraction_simplify (dividida);
    }
    return dividida;
}

                                                                    //Compara 2 fracciones
int fraction_cmp (fraccion* f1, fraccion* f2){
    int cmp = 0;
    if ((f1->numerador * f2->denominador) > (f2->numerador * f1->denominador)){
        cmp = 1;

    }else if ((f1->numerador * f2->denominador) < (f2->numerador * f1->denominador)){
        cmp = -1;
    }
    return cmp;
}