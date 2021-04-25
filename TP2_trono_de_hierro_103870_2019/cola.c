#include "cola.h"
#include <stdbool.h>
#include <stdlib.h>
#define VACIA 0
#define EXITO 0
#define ERROR -1
/*pre condiciones = la funcion no recibe ningun parametro
post condiciones = la funcion devuelve un puntero a un nodo_t*/
nodo_t* crear_nodo_cola(){
  nodo_t*nodo = (nodo_t*)malloc(sizeof(nodo_t));
  if(nodo == NULL){
    return NULL;
  }
  nodo->elemento = NULL;
  nodo->siguiente = NULL;
  return nodo;
}

cola_t* cola_crear(){
  cola_t*cola = (cola_t*)malloc(sizeof(cola_t));
  if(cola == NULL){
    return NULL;
  }
  cola->nodo_inicio = NULL;
  cola->nodo_fin = NULL;
  cola->cantidad = VACIA;
  return cola;
}

int cola_cantidad(cola_t* cola){
  if(cola == NULL){
    return VACIA;
  }
  return cola->cantidad;
}

int cola_encolar(cola_t* cola, void* elemento){
  if(cola == NULL){
    return ERROR;
  }
  nodo_t*nuevo_nodo = crear_nodo_cola();
  if(nuevo_nodo == NULL){
    return ERROR;
  }
  if(cola->nodo_inicio == NULL){
    cola->nodo_inicio = nuevo_nodo;
  }else{
    cola->nodo_fin->siguiente = nuevo_nodo;
  }
  cola->nodo_fin = nuevo_nodo;
  nuevo_nodo->siguiente = NULL;
  nuevo_nodo->elemento = elemento;
  cola->cantidad++;
  return EXITO;
}

bool cola_vacia(cola_t* cola){
  return (cola == NULL || cola_cantidad(cola) == 0);
}

int cola_desencolar(cola_t* cola){
  if(cola == NULL || cola_vacia(cola)){
    return ERROR;
  }
  nodo_t*nodo_eliminar = cola->nodo_inicio;
  cola->nodo_inicio = cola->nodo_inicio->siguiente;
  free(nodo_eliminar);
  cola->cantidad--;
  return EXITO;
}

void* cola_primero(cola_t* cola){
  if(cola == NULL || cola->nodo_inicio == NULL){
    return NULL;
  }
  return cola->nodo_inicio->elemento;
}

void cola_destruir(cola_t*cola){
  while(!cola_vacia(cola)){
    cola_desencolar(cola);
  }
  free(cola);
}
