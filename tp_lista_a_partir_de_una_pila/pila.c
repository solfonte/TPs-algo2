#include "pila.h"
#include<stdlib.h>
#define TAMANIO_VECTOR_INICIAL 2
#define TOPE_INICIAL 0
#define ERROR -1
#define VACIA 0
#define EXITO 0
#define AUMENTAR_TAMANIO 2
#define DISMINUIR_TAMANIO 1/2
#define PORCENTAJE_MINIMO_ELEMENTOS 1/4
/*Pre condiciones: la funcion recibe un puntero a una pila inicializada
  post condiciones:la funcion devuelve true si se cumplen las condiciones para disminuir el tamanio del vector*/
bool puedo_disminuir_vector(pila_t*pila){
  return ( (pila->tope <=PORCENTAJE_MINIMO_ELEMENTOS*pila->tamanio) && (pila->tamanio*DISMINUIR_TAMANIO >= TAMANIO_VECTOR_INICIAL));
}
/*Pre condiciones: la funcion recibe un puntero a una pila inicializada y un int inicializado
  post condiciones: la funcion devuelve -1 si no se pudo redimensionar la pila y 0 si pudo*/
int redimensionar_pila(pila_t*pila,int nueva_dimension){
  void*aux;
    aux = realloc(pila->elementos,sizeof(void*)*(long unsigned int)nueva_dimension);
    if(aux == NULL){
      return ERROR;
    }
    pila->elementos = aux;
    pila->tamanio = nueva_dimension;
    return EXITO;
  }
pila_t* pila_crear(){
    pila_t*pila = (pila_t*)malloc(sizeof(pila_t));
    if(pila == NULL){
      return NULL;
    }
    pila->tope = TOPE_INICIAL;
    pila->tamanio = TAMANIO_VECTOR_INICIAL;
    pila->elementos = malloc(TAMANIO_VECTOR_INICIAL*sizeof(void*));
    if(pila->elementos == NULL){
      free(pila);
      return NULL;
    }
    return pila;
  }
int pila_apilar(pila_t* pila, void* elemento){
  if(pila == NULL){
    return ERROR;
  }
  bool apile = false;
  while(!apile){
   if(pila->tope == pila->tamanio){
     int resultado = redimensionar_pila(pila,pila->tamanio*AUMENTAR_TAMANIO);
     if(resultado == ERROR){
       return ERROR;
     }
   }else{
      pila->elementos[pila->tope] = elemento;
      pila->tope++;
      apile = true;
    }
  }
    return EXITO;
}
bool pila_vacia(pila_t* pila){
  if(pila == NULL || pila->tope == 0){
    return true;
  }
  return false;
}
void* pila_tope(pila_t* pila){
  if(pila == NULL || pila_vacia(pila)){
    return NULL;
  }
  return pila->elementos[(pila->tope)-1];
}
int pila_desapilar(pila_t* pila){
  if(pila == NULL || pila_vacia(pila)){
    return ERROR;
  }
  if(!pila_vacia(pila)){
    (pila->tope)--;
  }
  if(puedo_disminuir_vector(pila)){
    redimensionar_pila(pila,pila->tamanio*DISMINUIR_TAMANIO);
  }
  return EXITO;
}
int pila_cantidad(pila_t* pila){
  if(pila == NULL){
    return VACIA;
  }
  return pila->tope;
}
void pila_destruir(pila_t* pila){
  if(pila == NULL){
    return;
  }
  if(pila->elementos == NULL){
    free(pila);
    return;
  }
  free(pila->elementos);
  free(pila);
}
