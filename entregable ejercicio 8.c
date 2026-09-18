#include <stdio.h>
#include <stdlib.h>
#include "TDA Fraccion.h"
#include "TDA Vector.h"


                                                //Calcula el elemento máximo de un vector de fracciones
                                                //Función principal que manda el parametro del contador
fraccion* max_elemento(vector* v){
    if (v == NULL || vector_size(v) == 0) return NULL;
    
    fraccion* primer_elemento = vector_get(v, 0);

    return max_elemento_tail(v, 1, primer_elemento);
}

                                                //Función secundaria que utiliza el contador
fraccion* max_elemento_tail(vector* v, int cnt, fraccion* max_actual){

    if (vector_size(v) != cnt){                 //Obtiene el elemento actual y lo compara con el anterior para devolver el mayor
        
        fraccion* actual = vector_get(v, cnt);
    
        if(fraction_cmp(actual, max_actual) == 1){
        
            max_actual = max_elemento_tail(v, cnt + 1, actual);

        }else{

            max_actual = max_elemento_tail(v, cnt + 1, max_actual);
        }
    }
    return max_actual;
}



                                                //Calcula el elemento mínimo de un vector de fracciones
                                                //Función principal que manda el parametro del contador

fraccion* min_elemento(vector* v){
    if (v == NULL || vector_size(v) == 0) return NULL;

    fraccion* primer_elemento = vector_get(v, 0);

    return min_elemento_tail(v, 1, primer_elemento);
}

                                                //Función secundaria que utiliza el contador
fraccion* min_elemento_tail(vector* v, int cnt, fraccion* min_actual){

    if (vector_size(v) != cnt){                 //Obtiene el elemento actual y lo compara con el anterior para devolver el menor
        
        fraccion* actual = vector_get(v, cnt);

        if(fraction_cmp(actual, min_actual) == -1){
        
            min_actual = min_elemento_tail(v, cnt + 1, actual);

        }else{

            min_actual = min_elemento_tail(v, cnt + 1, min_actual);
        }
    }
    return min_actual;
}





                                                    //Suma todos los elementos del vector de fracciones
fraccion* suma_elementos(vector* v){
    if (v == NULL || vector_size(v) == 0) return NULL;

    fraccion* primer_elemento = vector_get(v, 0);
                                                    //Se crea una copia para poder destruirla y actualizarla después
    fraccion* suma_inicial = fraction_new(fraction_get_num(primer_elemento), fraction_get_den(primer_elemento));

    return suma_elementos_tail(v, 1, suma_inicial);
}

                                                    //Función secundaria que utiliza el contador
fraccion* suma_elementos_tail(vector* v, int cnt, fraccion* suma_actual){

    if (vector_size(v) != cnt){
        
        fraccion* actual = vector_get(v, cnt);

        fraccion* nueva_suma = fraction_add(suma_actual, actual);
                                                //Destruye la suma vieja para que no haya fuga de memoria
        fraction_destroy(suma_actual);              

        suma_actual = suma_elementos_tail(v, cnt + 1, nueva_suma);
    }

    return suma_actual;
}






                                                    //Calcula el promedio de todos los elementos del vector de fracciones
fraccion* promedio(vector* v){
    if (v == NULL || vector_size(v) == 0) return NULL;

    fraccion* primer_elemento = vector_get(v, 0);

    fraccion* suma_inicial = fraction_new(fraction_get_num(primer_elemento), fraction_get_den(primer_elemento));

    return promedio_tail(v, 1, suma_inicial);
}

                                                    //Función secundaria que utiliza el contador
fraccion* promedio_tail(vector* v, int cnt, fraccion* suma_actual){

    fraccion* resultado = NULL;
                                                    //Calcula la suma recursivamente
    if (vector_size(v) != cnt){
        
        fraccion* actual = vector_get(v, cnt);

        fraccion* nueva_suma = fraction_add(suma_actual, actual);

        fraction_destroy(suma_actual);

        resultado = promedio_tail(v, cnt + 1, nueva_suma);

    }else{
                                                    //Calcula el promedio
        fraccion* divisor = fraction_new(vector_size(v), 1);

        resultado = fraction_div(suma_actual, divisor);

        fraction_destroy(suma_actual);
        fraction_destroy(divisor);
    }

    return resultado;
}




                                                //Muestra todos los elementos del vector de fracciones del primero al último
void mostrar(vector* v){
    if (v != NULL){
        mostrar_tail(v, 0);
    }
}
                                                    //Función secundaria que utiliza el contador
void mostrar_tail(vector* v, int cnt){
    if (vector_size(v) != cnt){

        fraccion* actual = vector_get(v, cnt);
        printf("%i/%i  ", fraction_get_num(actual), fraction_get_den(actual));
        mostrar_tail(v, cnt + 1);
    }
}




                                                //Muestra todos los elementos del vector de fracciones del último al primero
void mostrar_inversa(vector* v){
    if (v != NULL){
        mostrar_inversa_tail(v, 0);
    }
}
                                                    //Función secundaria que utiliza el contador
void mostrar_inversa_tail(vector* v, int cnt){
    if (vector_size(v) != cnt){

        fraccion* actual = vector_get(v, cnt);
                                                    //Primero la recursividad para que llegue hasta el final del vector y luego muestre
        mostrar_inversa_tail(v, cnt + 1);
        printf("%i/%i  ", fraction_get_num(actual), fraction_get_den(actual));
    }
}