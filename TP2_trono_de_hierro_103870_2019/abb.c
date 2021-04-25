#include "abb.h"
#include <stdlib.h>
#define EXITO 0
#define ERROR -1
#define PRIMERO_ES_MAYOR 1
#define PRIMERO_ES_MENOR -1

/*Pre condiciones: el procedimiento recibe 3 punteros a variables como parametros inicializados
Post condiciones: el procedimiento llena el array con un elemento*/
void llenar_array(void**array,int*elementos_almacenados,void*elemento){
  if(array == NULL){
    return;
  }
  array[*elementos_almacenados] = elemento;
  (*elementos_almacenados)++;
}

/*Pre condiciones: el procediemiento recibe 3 punteros a variables como parametros inicializados y un puntero a una funcion tambien inicializado distinto de null
Post condiciones:el procedimiento realiza el recorrido inorden del iterador interno del arbol recursivamente */
void recorrido_inorden_iterador_interno(nodo_abb_t* nodo , bool (*funcion)(void*, void*), void* extra,bool*resultado_funcion){
  if(nodo == NULL || *resultado_funcion == true){
    return;
  }
  recorrido_inorden_iterador_interno(nodo->izquierda,funcion,extra,resultado_funcion);
  if(*resultado_funcion == true){
    return;
  }
  *resultado_funcion = funcion(nodo->elemento,extra);
  recorrido_inorden_iterador_interno(nodo->derecha,funcion,extra,resultado_funcion);
}

/*Pre condiciones: el procediemiento recibe 3 punteros a variables como parametros inicializados y un puntero a una funcion tambien inicializado distinto de null
Post condiciones:el procedimiento realiza el recorrido preorden del iterador interno del arbol recursivamente */
void recorrido_preorden_iterador_interno(nodo_abb_t* nodo , bool (*funcion)(void*, void*), void* extra,bool*resultado_funcion){
  if(nodo == NULL || *resultado_funcion == true){
    return;
  }
  *resultado_funcion = funcion(nodo->elemento,extra);
  recorrido_preorden_iterador_interno(nodo->izquierda,funcion,extra,resultado_funcion);
  recorrido_preorden_iterador_interno(nodo->derecha,funcion,extra,resultado_funcion);
}

/*Pre condiciones: el procediemiento recibe 3 punteros a variables como parametros inicializados y un puntero a una funcion tambien inicializado distinto de null
Post condiciones:el procedimiento realiza el recorrido postorden del iterador interno del arbol recursivamente */
void recorrido_postorden_iterador_interno(nodo_abb_t* nodo , bool (*funcion)(void*, void*), void* extra,bool*resultado_funcion){
  if(nodo == NULL || *resultado_funcion == true){
    return;
  }
  recorrido_postorden_iterador_interno(nodo->izquierda,funcion,extra,resultado_funcion);
  recorrido_postorden_iterador_interno(nodo->derecha,funcion,extra,resultado_funcion);
  if(*resultado_funcion == true){
    return;
  }
  *resultado_funcion = funcion(nodo->elemento,extra);
}


/*Pre condiciones: el procediemiento recibe 4 punteros a variables como parametros inicializados
Post condiciones:el procedimiento realiza el recorrido preorden del arbol recursivamente para llenar el array */
void preorden_llenar_array(nodo_abb_t*nodo,void**array,int tamanio_array,int*elementos_almacenados){
  if(nodo == NULL || *elementos_almacenados == tamanio_array){
    return;
  }
  llenar_array(array,elementos_almacenados,nodo->elemento);
  preorden_llenar_array(nodo->izquierda,array,tamanio_array,elementos_almacenados);
  preorden_llenar_array(nodo->derecha,array,tamanio_array,elementos_almacenados);
}

/*Pre condiciones: el procediemiento recibe 4 punteros a variables como parametros inicializados
Post condiciones:el procedimiento realiza el recorrido inorden del arbol recursivamente para llenar el array */
void inorden_llenar_array(nodo_abb_t*nodo,void**array,int tamanio_array,int*elementos_almacenados){
  if(nodo == NULL || *elementos_almacenados == tamanio_array){
    return;
  }
  inorden_llenar_array(nodo->izquierda,array,tamanio_array,elementos_almacenados);
  if(*elementos_almacenados == tamanio_array){
    return;
  }
  llenar_array(array,elementos_almacenados,nodo->elemento);
  inorden_llenar_array(nodo->derecha,array,tamanio_array,elementos_almacenados);
}

/*Pre condiciones: el procediemiento recibe 4 punteros a variables como parametros inicializados
Post condiciones:el procedimiento realiza el recorrido postorden del arbol recursivamente para llenar el array */
void postorden_llenar_array(nodo_abb_t*nodo,void**array,int tamanio_array,int*elementos_almacenados){
  if(nodo == NULL || *elementos_almacenados == tamanio_array){
    return;
  }
  postorden_llenar_array(nodo->izquierda,array,tamanio_array,elementos_almacenados);
  postorden_llenar_array(nodo->derecha,array,tamanio_array,elementos_almacenados);
  if(*elementos_almacenados == tamanio_array){
    return;
  }
  llenar_array(array,elementos_almacenados,nodo->elemento);
}

/*Pre condiciones: la funcion recibe un puntero a un nodo inicializado
Post condiciones: la funcion devuelve un puntero a al nodo padre del menor de los mayores del arbol o null si el menor de los mayores es el nodo recibido por parametro*/
nodo_abb_t*nodo_padre_del_menor_de_los_mayores(nodo_abb_t*nodo){
  if(nodo->izquierda == NULL){
    return NULL;
  }
  if(nodo->izquierda->izquierda == NULL){
    return nodo;
  }
  return nodo_padre_del_menor_de_los_mayores(nodo->izquierda);
}

/*Pre condiciones: el procedimiento recibe un puntero a un nodo inicializado y un puntero a una funcion tambien inicializado distinto de null
Post condiciones: el procedimiento libera el nodo recibido por parametro, liberando la memoria reservada*/
void liberar_elemento(nodo_abb_t*nodo,void (*abb_liberar_elemento)(void*)){
  if(abb_liberar_elemento != NULL){
    abb_liberar_elemento(nodo->elemento);
  }
  free(nodo);
}


/*Pre condiciones: la funcion recibe 2 punteros a variables como parametros inicializados
Post condiciones: la funcion devuelve un puntero al nodo a insertar en el arbol*/
nodo_abb_t* insertar_elemento(void*elemento,bool*inserte){
  nodo_abb_t* nuevo_nodo = (nodo_abb_t*)calloc(1,sizeof(nodo_abb_t));
  if(nuevo_nodo == NULL){
    return NULL;
  }
  nuevo_nodo->elemento = elemento;
  *inserte = true;
  return nuevo_nodo;
}

/*Pre condiciones: la funcion recibe 3 punteros a variables como parametros inicializados y un puntero a una funcion tambien inicializado distinto de null
Post condiciones: la funcion devuelve un puntero al nodo recibido por parametro*/
nodo_abb_t*insertar_nodo(int(*abb_comparador)(void*,void*),nodo_abb_t*nodo,void*elemento,bool*inserte){
  if(nodo == NULL){
    nodo = insertar_elemento(elemento,inserte);
    return nodo;
  }
  if(abb_comparador(nodo->elemento,elemento) == PRIMERO_ES_MAYOR){
    nodo->izquierda = insertar_nodo(abb_comparador,nodo->izquierda,elemento,inserte);
  }else{
    nodo->derecha = insertar_nodo(abb_comparador,nodo->derecha,elemento,inserte);
  }
  return nodo;
}

/*Pre condiciones: la funcion recibe dos punteros a variables como parametros y y un puntero a una funcion tambien inicializado distinto de null
Post condiciones: la funcion devuelve un puntero al nodo buscado*/
void*buscar_elemento(int(*abb_comparador)(void*,void*),nodo_abb_t*nodo,void*elemento){
  if(nodo == NULL){
    return NULL;
  }
  if(abb_comparador(nodo->elemento,elemento) == PRIMERO_ES_MAYOR){
    return buscar_elemento(abb_comparador,nodo->izquierda,elemento);
  }else if(abb_comparador(nodo->elemento,elemento) == PRIMERO_ES_MENOR){
    return buscar_elemento(abb_comparador,nodo->derecha,elemento);
  }
  return nodo->elemento;
}

/*Pre condiciones: la funcion recibe dos punteros a variables inicializados y un puntero a una funcion tambien inicializado distinto de null
Post condiciones: la funcion devuelve un puntero al nuevo nodo apuntado luego de borrar un elemento*/
nodo_abb_t*borrar_elemento(void (*abb_liberar_elemento)(void*),nodo_abb_t*nodo,bool*borre){
  *borre = true;
  if(nodo->izquierda == NULL && nodo->derecha == NULL){
    liberar_elemento(nodo,abb_liberar_elemento);
    return NULL;
  }else if(nodo->izquierda == NULL || nodo->derecha == NULL){
    nodo_abb_t*aux = (nodo->derecha == NULL? nodo->izquierda : nodo->derecha);
    liberar_elemento(nodo,abb_liberar_elemento);
    return aux;
  }else{
    nodo_abb_t*padre_del_menor_de_los_mayores = nodo_padre_del_menor_de_los_mayores(nodo->derecha);
    if(padre_del_menor_de_los_mayores == NULL){
      nodo_abb_t*nodo_aux = nodo->derecha;
      nodo->derecha->izquierda = nodo->izquierda;
      liberar_elemento(nodo,abb_liberar_elemento);
      return nodo_aux;
    }else{
      nodo_abb_t*menor_de_los_mayores = padre_del_menor_de_los_mayores->izquierda;
      padre_del_menor_de_los_mayores->izquierda = menor_de_los_mayores->derecha;
      menor_de_los_mayores->izquierda = nodo->izquierda;
      menor_de_los_mayores->derecha = nodo->derecha;
      liberar_elemento(nodo,abb_liberar_elemento);
      return menor_de_los_mayores;
    }
  }
}

/*Pre condiciones: la funcion recibe tres punteros a variables como parametros inicializados y dos punteros a funciones tambien inicializados distintos de null
Post condiciones: la funcion devuelve un puntero al nodo recibido por parametro, o en caso de encontrar el elemento devuelve un puntero al nuevo nodo del arbol apuntado o null si no lo encuentra */
nodo_abb_t*borrar_nodo(int(*abb_comparador)(void*,void*),void (*abb_liberar_elemento)(void*),nodo_abb_t*nodo,void*elemento,bool*borre){
  if(nodo == NULL){
    return nodo;
  }
  if(abb_comparador(nodo->elemento,elemento) == PRIMERO_ES_MAYOR){
    nodo->izquierda = borrar_nodo(abb_comparador,abb_liberar_elemento,nodo->izquierda,elemento,borre);
    return nodo;
  }else if(abb_comparador(nodo->elemento,elemento) == PRIMERO_ES_MENOR){
    nodo->derecha = borrar_nodo(abb_comparador,abb_liberar_elemento,nodo->derecha,elemento,borre);
    return nodo;
  }else{
    return borrar_elemento(abb_liberar_elemento,nodo,borre);
  }
}

int arbol_insertar(abb_t* arbol, void* elemento){
  bool inserte = false;
  if(arbol == NULL){
    return ERROR;
  }
  arbol->nodo_raiz = insertar_nodo(arbol->comparador,arbol->nodo_raiz,elemento,&inserte);
  if(inserte){
    return EXITO;
  }
  return ERROR;
}

abb_t* arbol_crear(abb_comparador comparador, abb_liberar_elemento destructor){
  if(comparador == NULL){
    return NULL;
  }
  abb_t*arbol = (abb_t*)calloc(1,sizeof(abb_t));
  if(arbol == NULL){
    return NULL;
  }
  arbol->comparador = comparador;
  arbol->destructor = destructor;
  return arbol;
}

int arbol_borrar(abb_t* arbol, void* elemento){
  bool borre = false;
  if(arbol_vacio(arbol)){
    return ERROR;
  }
  arbol->nodo_raiz = borrar_nodo(arbol->comparador,arbol->destructor,arbol->nodo_raiz,elemento,&borre);
  if(borre){
    return EXITO;
  }
  return ERROR;
}

void* arbol_buscar(abb_t* arbol, void* elemento){
  if(arbol == NULL){
    return NULL;
  }
  return buscar_elemento(arbol->comparador,arbol->nodo_raiz,elemento);
}

void* arbol_raiz(abb_t* arbol){
  if(arbol == NULL || arbol->nodo_raiz == NULL){
    return NULL;
  }
  return arbol->nodo_raiz->elemento;
}

bool arbol_vacio(abb_t* arbol){
  return(arbol == NULL || arbol->nodo_raiz == NULL);
}

int arbol_recorrido_preorden(abb_t* arbol, void** array, int tamanio_array){
  if(arbol_vacio(arbol) || array == NULL || tamanio_array == 0){
    return 0;
  }
  int elementos_almacenados = 0;
  preorden_llenar_array(arbol->nodo_raiz,array,tamanio_array,&elementos_almacenados);
  return elementos_almacenados;
}

int arbol_recorrido_inorden(abb_t* arbol, void** array, int tamanio_array){
  if(arbol_vacio(arbol) || array == NULL || tamanio_array == 0){
    return 0;
  }
  int elementos_almacenados = 0;
  inorden_llenar_array(arbol->nodo_raiz,array,tamanio_array,&elementos_almacenados);
  return elementos_almacenados;
}

int arbol_recorrido_postorden(abb_t* arbol, void** array, int tamanio_array){
  if(arbol_vacio(arbol) || array == NULL || tamanio_array == 0){
    return 0;
  }
  int elementos_almacenados = 0;
  postorden_llenar_array(arbol->nodo_raiz,array,tamanio_array,&elementos_almacenados);
  return elementos_almacenados;
}

void abb_con_cada_elemento(abb_t* arbol, int recorrido, bool (*funcion)(void*, void*), void* extra){
  if(arbol_vacio(arbol) || funcion == NULL){
    return;
  }
  bool resultado_funcion = false;
  switch(recorrido){
    case ABB_RECORRER_INORDEN:
      recorrido_inorden_iterador_interno(arbol->nodo_raiz,funcion,extra,&resultado_funcion);
      break;
    case ABB_RECORRER_PREORDEN:
      recorrido_preorden_iterador_interno(arbol->nodo_raiz,funcion,extra,&resultado_funcion);
      break;
    case ABB_RECORRER_POSTORDEN:
      recorrido_postorden_iterador_interno(arbol->nodo_raiz,funcion,extra,&resultado_funcion);
      break;
  }
}

void arbol_destruir(abb_t* arbol){
  while(!arbol_vacio(arbol)){
    arbol_borrar(arbol,arbol_raiz(arbol));
  }
  free(arbol);
}
