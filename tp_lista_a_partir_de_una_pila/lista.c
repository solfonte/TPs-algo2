#include "lista.h"
#include "pila.h"
#include <stdlib.h>
#define ERROR -1
#define EXITO 0

struct lista{
  pila_t* pila;
};

struct lista_iterador{
  lista_t* lista;
  pila_t* corriente;
};

lista_t* lista_crear(){
  lista_t* lista = (lista_t*)malloc(sizeof(lista_t));
  if(lista == NULL){
    return NULL;
  }
  pila_t* pila = pila_crear();
  if(pila == NULL){
    free(lista);
    return NULL;
  }
  lista->pila = pila;
  return lista;
}

int lista_insertar(lista_t* lista, void* elemento){
  if(lista == NULL){
    return ERROR;
  }
  return pila_apilar(lista->pila,elemento);
}

/*La funcion inserta el elemento recibido por parametro en la lista en la posicion indicada por el usuario recursivamente.
Devuelve ERROR si no pudo y EXITO si pudo*/
int insertar_en_posicion_rec(pila_t* pila,void* elemento,size_t posicion_actual,size_t posicion_insertar){
  if(posicion_actual == posicion_insertar){
    return pila_apilar(pila,elemento);
  }
  void* elemento_aux = pila_tope(pila);
  int estado_desapilar = pila_desapilar(pila);
  if(estado_desapilar == ERROR){
    return ERROR;
  }
  int estado_insertar = insertar_en_posicion_rec(pila,elemento,posicion_actual - 1,posicion_insertar);
  int estado_apilar = pila_apilar(pila,elemento_aux);
  return (estado_insertar == ERROR || estado_apilar == ERROR? ERROR:EXITO);
}

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){
  if(lista == NULL){
    return ERROR;
  }
  if(posicion > pila_cantidad(lista->pila) - 1 || pila_vacia(lista->pila)){
    return lista_insertar(lista,elemento);
  }
  return insertar_en_posicion_rec(lista->pila,elemento,(size_t)pila_cantidad(lista->pila),posicion);
}

int lista_borrar(lista_t* lista){
  if(lista == NULL){
    return ERROR;
  }
  return pila_desapilar(lista->pila);
}

/*La funcion borra el elemento de la posicion de la lista indicada por el usuario recursivamente.
Devuelve ERROR si no pudo y EXITO si pudo*/
int borrar_de_posicion_rec(pila_t* pila,size_t posicion_actual,size_t posicion_borrar){
  if(posicion_actual == posicion_borrar){
    return pila_desapilar(pila);
  }
  void* elemento_aux = pila_tope(pila);
  int estado_desapilar = pila_desapilar(pila);
  if(estado_desapilar == ERROR){
    return ERROR;
  }
  int estado_borrar = borrar_de_posicion_rec(pila,posicion_actual - 1,posicion_borrar);
  int estado_apilar = pila_apilar(pila,elemento_aux);
  return (estado_borrar == ERROR || estado_apilar == ERROR? ERROR:EXITO);
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
  if(lista == NULL || pila_vacia(lista->pila)){
    return ERROR;
  }
  if(posicion >= pila_cantidad(lista->pila) - 1){
    return lista_borrar(lista);
  }
  return borrar_de_posicion_rec(lista->pila,(size_t)pila_cantidad(lista->pila) - 1,posicion);
}

/*La funcion devuelve el elemento de la posicion de la lista indicada por el usuario recursivamente.
Devuelve NULL si no pudo*/
void* elemento_en_posicion_rec(pila_t* pila,size_t posicion_actual,size_t posicion_elemento){
  if(posicion_actual == posicion_elemento){
    return pila_tope(pila);
  }
  void* elemento_aux = pila_tope(pila);
  int estado_desapilar = pila_desapilar(pila);
  if(estado_desapilar == ERROR){
    return NULL;
  }
  void* elemento_buscado = elemento_en_posicion_rec(pila,posicion_actual - 1,posicion_elemento);
  int estado_apilar = pila_apilar(pila,elemento_aux);
  return (estado_apilar == ERROR || elemento_buscado == NULL? NULL:elemento_buscado);
}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
  if(lista == NULL || pila_vacia(lista->pila) || posicion >= pila_cantidad(lista->pila)){
    return NULL;
  }
  if(posicion == pila_cantidad(lista->pila) - 1){
    return lista_ultimo(lista);
  }
  return elemento_en_posicion_rec(lista->pila,(size_t)pila_cantidad(lista->pila) - 1,posicion);
}

void* lista_ultimo(lista_t* lista){
  if(lista == NULL){
    return NULL;
  }
  return pila_tope(lista->pila);
}

bool lista_vacia(lista_t* lista){
  return (lista == NULL || pila_vacia(lista->pila)? true:false);
}

size_t lista_elementos(lista_t* lista){
  if(lista == NULL){
    return 0;
  }
  return (size_t)pila_cantidad(lista->pila);
}

void lista_destruir(lista_t* lista){
  if(lista == NULL){
    return;
  }
  pila_destruir(lista->pila);
  free(lista);
}

/*La funcion copia los elementos de una pila a la otra recursivamente.
Devuelve ERROR si no pudo y EXITO si pudo*/
int copiar_elementos_pila_rec(pila_t* pila,pila_t* pila_corriente,int posicion_actual,int cantidad_elementos){
  if(posicion_actual == cantidad_elementos){
    return EXITO;
  }
  void* elemento_aux = pila_tope(pila);
  int estado_apilar_pila_nueva = pila_apilar(pila_corriente,elemento_aux);
  int estado_desapilar = pila_desapilar(pila);
  if(estado_desapilar == ERROR || estado_apilar_pila_nueva == ERROR){
    return ERROR;
  }
  int estado_copiar = copiar_elementos_pila_rec(pila,pila_corriente,posicion_actual + 1,cantidad_elementos);
  if(estado_copiar == ERROR){
    return ERROR;
  }
  return pila_apilar(pila,elemento_aux);
}

/*La funcion copia los elementos de una pila a la otra.
Devuelve ERROR si no pudo y EXITO si pudo*/
int copiar_elementos_pila(pila_t* pila,pila_t* pila_corriente){
  return copiar_elementos_pila_rec(pila,pila_corriente,0,pila_cantidad(pila));
}

lista_iterador_t* lista_iterador_crear(lista_t* lista){
  if(lista == NULL){
    return NULL;
  }
  lista_iterador_t* iterador = (lista_iterador_t*)malloc(sizeof(lista_iterador_t));
  if(iterador == NULL){
    return NULL;
  }
  iterador->lista = lista;
  iterador->corriente = pila_crear();
  if(iterador->corriente == NULL){
    free(iterador);
    return NULL;
  }
  int estado_copiar = copiar_elementos_pila(lista->pila,iterador->corriente);
  if(estado_copiar == ERROR){
    pila_destruir(iterador->corriente);
    free(iterador);
    return NULL;
  }
  return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
  if(iterador == NULL){
    return false;
  }
  return !pila_vacia(iterador->corriente);
}

void* lista_iterador_siguiente(lista_iterador_t* iterador){
  if(iterador == NULL){
    return NULL;
  }
  void*elemento = pila_tope(iterador->corriente);
  int resultado_desapilar = pila_desapilar(iterador->corriente);
  return(resultado_desapilar == ERROR? NULL:elemento);
}

void lista_iterador_destruir(lista_iterador_t* iterador){
  if(iterador == NULL){
    return;
  }
  pila_destruir(iterador->corriente);
  free(iterador);
}

void lista_con_cada_elemento(lista_t* lista, void (*funcion)(void*)){
  if(lista == NULL || funcion == NULL){
    return;
  }
  pila_t* pila_aux = pila_crear();
  if(pila_aux == NULL){
    return;
  }
  copiar_elementos_pila(lista->pila,pila_aux);
  int estado_desapilar = EXITO;
  while(!pila_vacia(pila_aux) && estado_desapilar == EXITO){
    funcion(pila_tope(pila_aux));
    estado_desapilar = pila_desapilar(pila_aux);
  }
  pila_destruir(pila_aux);
}
