#include <stdio.h>
#include <stdlib.h>
#include "TDA Vector.h"


typedef struct _vector{
   VECTOR_ELEMENT* a;
   int size;
   int max_size;
} vector;



                                                             //Crea una estructura de vector de tamaño cero
vector* vector_new(int ini_size){

    vector* nuevo_vector = (vector*)malloc(sizeof(vector));
    nuevo_vector->max_size = ini_size;
    nuevo_vector->size = 0;
    nuevo_vector->a = (VECTOR_ELEMENT*)malloc(sizeof(VECTOR_ELEMENT) * ini_size);

    return nuevo_vector;
}


                                                            //Libera un vector
void vector_free(vector* v){
    free(v->a);
    free(v);
}


                                                            //Obtiene el tamaño actual del vector
int vector_size(vector* v){
    return v->size;
}


                                                            // Devuelve 0 si no está lleno y 1 si está lleno
int vector_isfull(vector* v){
    return (v->max_size == v->size);
}


                                                            //Devuelve 0 si no está vacío y 1 si está vacío
int vector_isempty(vector* v){
    return (v->size == 0);
}



                                                            //Obtiene el valor de una posición del vector
VECTOR_ELEMENT vector_get(vector* v, int index){
    return v->a[index];
}



                                                            //Reemplaza el valor de una posición del vector
VECTOR_ELEMENT vector_set(vector* v, int index, VECTOR_ELEMENT value){
    VECTOR_ELEMENT anterior = v->a[index];
    v->a[index] = value;

    return anterior;
}



                                                            //Agrega un elemento al final
int vector_add(vector* v, VECTOR_ELEMENT value){
    int flag = 0;
    if(vector_isfull(v)){
        
        VECTOR_ELEMENT* aux = (VECTOR_ELEMENT*)realloc(v->a, (v->max_size * 2) * sizeof(VECTOR_ELEMENT));
        if(aux != NULL){
            v->a = aux;
            v->max_size = v->max_size * 2;
            v->a[v->size] = value;
            v->size = v->size + 1;
            flag = 1;
        }
    }else{
        v->a[v->size] = value;
        v->size = v->size + 1;
        flag = 1;
    }
    return flag;
}



                                                        //Agrega un elemento en una posición determinada
int vector_insert(vector* v, int index, VECTOR_ELEMENT value){
    int flag = 0;
    if(index > v->size){
        if(index >= v->max_size){
            VECTOR_ELEMENT* aux = (VECTOR_ELEMENT*)realloc(v->a, (index + 1) * sizeof(VECTOR_ELEMENT));
            if(aux != NULL){
                v->a = aux;
                v->max_size = index + 1;
                v->size = index + 1;
                v->a[index] = value;
                flag = 1;
            }
        } else{
            v->a[index] = value;
            v->size = index + 1;
            flag = 1;
        }
    } else{
        int exito = 1;
        if(vector_isfull(v)){
            VECTOR_ELEMENT* aux = (VECTOR_ELEMENT*)realloc(v->a, (v->max_size * 2) * sizeof(VECTOR_ELEMENT));
            if(aux != NULL){
                v->a = aux;
                v->max_size = v->max_size * 2;
            } else{
                exito = 0;
            }
        }
        if(exito == 1){
            for(int i = v->size; i > index; i--){
                v->a[i] = v->a[i - 1];
            }
            v->a[index] = value;
            v->size = v->size + 1;
            flag = 1;
        }
    }
    return flag;
}



                                                        //Elimina un elemento del vector
VECTOR_ELEMENT vector_remove(vector* v, int index){
    VECTOR_ELEMENT removido = v->a[index];
    for(int i = index; i < v->size - 1; i++){
        v->a[i] = v->a[i + 1];
    }
    v->size = v->size - 1;
    return removido;
}
