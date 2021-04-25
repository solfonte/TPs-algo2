#include "hash.h"
#include "hash_iterador.h"
#include "lista.h"
#include "pila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define ERROR -1
#define EXITO 0
#define FACTOR_DE_CARGA_EXCEDENTE 2
#define FACTOR_DE_AGRANDAMIENTO 2
#define POSICION_NO_VALIDA -1

typedef struct dato{
  const char* clave;
  void*valor;
}dato_t;



struct hash{
  hash_destruir_dato_t destructor;
  size_t cantidad_de_valores;
  lista_t**tabla_hash;
  size_t tamanio_tabla;
};

struct hash_iter{
  hash_t*hash;
  lista_iterador_t*corriente;
  size_t posicion_tabla_actual;
};

extern char* strdup(const char*);


/*Pre condiciones: el procedimiento recibe un puntero a un dato inicializado y un puntero a una funcion inicializado
Post condiciones: el procedimiento destruye la memoria reservada por el dato que contiene el par clave-valor*/
void destruir_dato(void* dato, void (*hash_destruir_dato_t)(void*)){
  dato_t*dato_destruir = (dato_t*)dato;
  if(hash_destruir_dato_t != NULL){
    hash_destruir_dato_t(dato_destruir->valor);
  }
  free((char*)(dato_destruir->clave));
  free(dato);
}

/*Pre condiciones: el procedimiento recibe un dos punteros inicializados y dos variables inicializadas
Post condiciones: el procedimiento destruye la memoria reservada por la tabla de hash*/
void destruir_tabla_hash(lista_t**tabla_hash,size_t tamanio_tabla, void(*hash_destruir_dato_t)(void*),bool se_debe_destruir_dato){
  if(tabla_hash == NULL){
    return;
  }
  for(int i = 0; i < tamanio_tabla; i++){
    while(!lista_vacia(tabla_hash[i])){
      if(se_debe_destruir_dato){
        destruir_dato(lista_ultimo(tabla_hash[i]),hash_destruir_dato_t);
      }
      lista_borrar(tabla_hash[i]);
    }
    free(tabla_hash[i]);
  }
  free(tabla_hash);

}

/*Pre condiciones: la funcion recibe un puntero incializado y un tamanio inicializado
Post condiciones: la funcion devuelve la posicion en la tabla hash para la clave recibida por parametro*/
size_t funcion_hash(const char* clave,size_t tamanio_tabla){
  size_t longitud_clave = strlen(clave);
  size_t contador = 0;
  for(int i = 0; i < longitud_clave; i++){
  contador += (size_t)clave[i];
  }
  return contador % tamanio_tabla;
}

/*Pre condiciones: la funcion recibe dos punteros inicializados y una variable inicializada
Post condiciones: la funcion devuelve EXITO si pudo agregar los elementos de la pila a la nueva tabla de hash o ERROR si no pudo*/
int hashear_elementos_pila(pila_t* pila,lista_t** nueva_tabla_hash,size_t tamanio_tabla_nueva){
  int posicion_tabla = POSICION_NO_VALIDA;
  bool fallo = false;
  dato_t* valor_hash;
  while(!pila_vacia(pila) && !fallo){
    valor_hash = (dato_t*)pila_tope(pila);
    if(valor_hash == NULL){
      return ERROR;
    }
    posicion_tabla = (int)funcion_hash(valor_hash->clave,tamanio_tabla_nueva);
    if(nueva_tabla_hash[posicion_tabla] == NULL){
      nueva_tabla_hash[posicion_tabla] = lista_crear();
      if(nueva_tabla_hash[posicion_tabla] == NULL){
        fallo = true;
      }else{
        fallo = (lista_insertar(nueva_tabla_hash[posicion_tabla],pila_tope(pila)) == ERROR?true:false);
        if(!fallo){
          pila_desapilar(pila);
        }
      }
    }else{
      fallo = (lista_insertar(nueva_tabla_hash[posicion_tabla],pila_tope(pila)) == ERROR?true:false);
      if(!fallo){
        pila_desapilar(pila);
      }
    }
  }
  return (fallo?ERROR:EXITO);
}

/*Pre condiciones: la funcion recibe dos punteros inicializados y una variable inicializada
Post condiciones: la funcion devuelve EXITO si pudo apilar los elementos almacenados en el hash o ERROR si no pudo*/
int apilar_elementos_hash(pila_t* pila,lista_t**tabla_hash,size_t tamanio_tabla){
  size_t posicion_actual_tabla = 0, posicion_actual_lista;
  bool fallo = false;
  while(posicion_actual_tabla < tamanio_tabla && !fallo){
    posicion_actual_lista = 0;
    while(posicion_actual_lista < lista_elementos(tabla_hash[posicion_actual_tabla]) && !fallo){
      fallo = (pila_apilar(pila,lista_elemento_en_posicion(tabla_hash[posicion_actual_tabla],posicion_actual_lista)) == ERROR?true:false);
      posicion_actual_lista++;
    }
    posicion_actual_tabla++;
  }
  return (fallo?ERROR:EXITO);
}

/*Pre condiciones: la funcion recibe dos punteros incializados
Post condiciones: la funcion devuelve POSICION_NO_VALIDA si no encontro la clave o devuelve la posicion en la que se encuentra la clave dentro de la lista*/
int buscar_clave_en_lista(lista_t*lista ,const char* clave){
  int posicion_clave = POSICION_NO_VALIDA;
  int i = 0;
  dato_t* dato;
  while(i < lista_elementos(lista) && posicion_clave == POSICION_NO_VALIDA){
    dato = (dato_t*)lista_elemento_en_posicion(lista,(size_t)i);
    if(strcmp(dato->clave,clave) == 0){
      posicion_clave = i;
    }
    i++;
  }
  return posicion_clave;
}

/*Pre condiciones: la funcion recibe un doble puntero inicializado y dos size_t iniciazados
Post condiciones: la funcion devuelve POSICION_NO_VALIDA si no quedan listas en la tabla de hash o la primera posicion en la tabla luego de la posicion inicial recibida por parametro de la proxima lista con elementos*/
int proxima_posicion_lista_valida(lista_t**tabla_hash,size_t posicion_inicial,size_t tamanio_tabla){
  int proxima_posicion_lista = POSICION_NO_VALIDA;
  size_t i = posicion_inicial;
  while(i < tamanio_tabla && proxima_posicion_lista == POSICION_NO_VALIDA){
    if(tabla_hash[i] != NULL){
      proxima_posicion_lista = (int)i;
    }
    i++;
  }
  return proxima_posicion_lista;
}

/*Pre condiciones: la funcion recibe dos punteros inicializados
Post condiciones:la funcion devuelve un puntero inicializado a un dato_t que contiene el par clave-valor del hash recibidos por parametro o NULL si no lo pudo crear*/
dato_t* crear_dato_hash(const char* clave, void* valor){
  dato_t* valor_hash = (dato_t*)calloc(1,sizeof(dato_t));
  if(valor_hash == NULL){
    return NULL;
  }
  valor_hash-> clave = strdup(clave);
  valor_hash-> valor = valor;
  return valor_hash;
}

/*Pre condiciones: la funcion recibe dos punteros inicializados por parametro, una posicion inicializada y un puntero a una funcion inicializado
Post condiciones: la funcion actualiza el elemento del struct del dato recibido por parametro. Devuelve EXITO si pudo y ERROR si no pudo actualizar*/
int actualizar_elemento(void*elemento,lista_t* lista,int posicion_clave,void(*hash_destruir_dato_t)(void*)){
  void* dato = lista_elemento_en_posicion(lista,(size_t)posicion_clave);
  if(dato == NULL){
    return ERROR;
  }
  if(hash_destruir_dato_t != NULL){
    hash_destruir_dato_t(((dato_t*)dato)->valor);
  }
  ((dato_t*)dato)->valor = elemento;
  return EXITO;
}

/*Pre condiciones: la funcion recibe tres punteros inicializados y una posicion valida inicializada
Post condiciones: la funcion inserta un elemento en el hash, devuelve EXITO si pudo insertar o ERROR si no pudo*/
int insertar_elemento(hash_t* hash,const char* clave, void* elemento, size_t posicion_en_hash){
  dato_t* nuevo_dato = crear_dato_hash(clave,elemento);
  if(nuevo_dato == NULL){
    if(lista_elementos(hash->tabla_hash[posicion_en_hash]) == 0){
      lista_destruir(hash->tabla_hash[posicion_en_hash]);
    }
    return ERROR;
  }
  int resultado_insertar = lista_insertar(hash->tabla_hash[posicion_en_hash],(void*)nuevo_dato);
  if(resultado_insertar == ERROR){
    if(lista_elementos(hash->tabla_hash[posicion_en_hash]) == 0){
      lista_destruir(hash->tabla_hash[posicion_en_hash]);
    }
    return ERROR;
  }
  hash->cantidad_de_valores++;
  return EXITO;
}

/*Pre condiciones: la funcion recibe tres punteros inicializados
Post condiciones: la funcion devuelve true si ya existe la clave recibida por parametro en el hash o false si no nunca fue insertada*/
bool clave_ya_existe(const char* clave,lista_t* lista,int* posicion_clave){
  (*posicion_clave) = buscar_clave_en_lista(lista,clave);
  return (*posicion_clave >= 0);
}

/*Pre condiciones: la funcion recibe un numero inicializado por parametro
Post condiciones: la funcion devuelve true si dicho numero es primo o false si no lo es*/
bool es_primo(size_t numero){
  size_t divisores = 0;
  for(size_t i = 2; i<= numero/2;i++){
    if(numero%i == 0){
      divisores ++;
    }
  }
  return(divisores == 0);
}

/*Pre condiciones: la funcion recibe por parametro una capacidad valida inicialiazada
Post condiciones: la funcion devuelve el siguiente numero primo de la capacidad recibida por parametro*/
size_t proximo_numero_primo(size_t capacidad_minima){
  size_t tamanio_tabla_inicial = capacidad_minima+1;
  while(!es_primo(tamanio_tabla_inicial)){
    tamanio_tabla_inicial ++;
  }
  return tamanio_tabla_inicial;
}

/*Pre condiciones: la funcion recibe un puntero iniciaizado
Post condiciones: la funcion devuelve EXITO si pudo redimensionar la tabla hash o ERROR si no pudo*/
int redimensionar_tabla_hash(hash_t*hash){
  size_t nuevo_tamanio_tabla = proximo_numero_primo(FACTOR_DE_AGRANDAMIENTO*hash->tamanio_tabla);
  pila_t* pila = pila_crear();
  if(pila == NULL){
    return ERROR;
  }
  lista_t** nuevo_array_listas = (lista_t**)calloc(1,sizeof(lista_t*)* nuevo_tamanio_tabla);
  if(nuevo_array_listas == NULL){
    pila_destruir(pila);
    return ERROR;
  }
  int resultado = apilar_elementos_hash(pila,hash->tabla_hash,hash->tamanio_tabla);
  if(resultado == ERROR){
    pila_destruir(pila);
    free(nuevo_array_listas);
    return ERROR;
  }
  resultado = hashear_elementos_pila(pila,nuevo_array_listas,nuevo_tamanio_tabla);
  if(resultado == ERROR){
    pila_destruir(pila);
    free(nuevo_array_listas);
    return ERROR;
  }
  pila_destruir(pila);
  destruir_tabla_hash(hash->tabla_hash,hash->tamanio_tabla,hash->destructor,false);
  hash->tabla_hash = nuevo_array_listas;
  hash->tamanio_tabla = nuevo_tamanio_tabla;
  return EXITO;
}

/*Pre condiciones: la funcion recibe dos variables inicializadas
Post condiciones: la funcion devuelve el factor de carga del hash*/
size_t factor_de_carga_hash(size_t cantidad_de_valores,size_t tamanio_tabla){
  return(cantidad_de_valores/tamanio_tabla);
}

hash_t* hash_crear(hash_destruir_dato_t destruir_elemento, size_t capacidad){
  if(capacidad == 0){
    return NULL;
  }
  hash_t*hash = (hash_t*)calloc(1,sizeof(hash_t));
  if(hash == NULL){
    return NULL;
  }
  size_t capacidad_inicial = proximo_numero_primo(capacidad);
  lista_t**tabla_de_hash = (lista_t**)calloc(capacidad_inicial,sizeof(lista_t*));
  if(tabla_de_hash == NULL){
    free(hash);
    return NULL;
  }
  hash->tabla_hash = tabla_de_hash;
  hash->destructor = destruir_elemento;
  hash->tamanio_tabla = capacidad_inicial;
  return hash;
}

int hash_insertar(hash_t* hash, const char* clave, void* elemento){
  if(hash == NULL || clave == NULL){
    return ERROR;
  }
  int resultado = ERROR;
  size_t posicion_en_hash = funcion_hash(clave,hash->tamanio_tabla);
  if(hash->tabla_hash[posicion_en_hash] == NULL){
    hash->tabla_hash[posicion_en_hash] = lista_crear();
    if(hash->tabla_hash[posicion_en_hash] == NULL){
      return ERROR;
    }
  }
    int posicion_clave = POSICION_NO_VALIDA;
    if(clave_ya_existe(clave,hash->tabla_hash[posicion_en_hash],&posicion_clave)){
      resultado = actualizar_elemento(elemento,hash->tabla_hash[posicion_en_hash],posicion_clave,hash->destructor);
    }else{
      resultado = insertar_elemento(hash,clave,elemento,posicion_en_hash);
    }
    if(resultado == ERROR){
      return ERROR;
    }
  if(factor_de_carga_hash(hash->cantidad_de_valores,hash->tamanio_tabla) >= FACTOR_DE_CARGA_EXCEDENTE){
    resultado = redimensionar_tabla_hash(hash);
  }
  return resultado;
}

int hash_quitar(hash_t* hash, const char* clave){
  if(hash == NULL || hash_cantidad(hash) == 0 || clave == NULL){
    return ERROR;
  }
  size_t posicion_en_hash = funcion_hash(clave,hash->tamanio_tabla);
  if(hash->tabla_hash[posicion_en_hash] == NULL){
    return ERROR;
  }
  int posicion_en_lista = buscar_clave_en_lista(hash->tabla_hash[posicion_en_hash],clave);
  if(posicion_en_lista == POSICION_NO_VALIDA){
    return ERROR;
  }
  destruir_dato(lista_elemento_en_posicion(hash->tabla_hash[posicion_en_hash],(size_t)posicion_en_lista),hash->destructor);
  int resultado_borrar = lista_borrar_de_posicion(hash->tabla_hash[posicion_en_hash],(size_t)posicion_en_lista);
  if(resultado_borrar == ERROR){
    return ERROR;
  }
  hash->cantidad_de_valores--;
  return EXITO;
}

size_t hash_cantidad(hash_t* hash){
  return (hash == NULL? 0: hash->cantidad_de_valores);
}

void* hash_obtener(hash_t* hash, const char* clave){
  if(hash == NULL || clave == NULL){
    return NULL;
  }
  size_t posicion_en_hash = funcion_hash(clave,hash->tamanio_tabla);
  if(hash->tabla_hash[posicion_en_hash] == NULL){
    return NULL;
  }
  int posicion_en_lista = buscar_clave_en_lista(hash->tabla_hash[posicion_en_hash],clave);
  if(posicion_en_lista == POSICION_NO_VALIDA){
    return NULL;
  }
  return (((dato_t*)lista_elemento_en_posicion(hash->tabla_hash[posicion_en_hash],(size_t)posicion_en_lista))->valor);
}

bool hash_contiene(hash_t* hash, const char* clave){
  if(hash == NULL || clave == NULL){
    return false;
  }
  size_t posicion_en_hash = funcion_hash(clave,hash->tamanio_tabla);
  if(hash->tabla_hash[posicion_en_hash] == NULL){
    return false;
  }
  int posicion_en_lista = buscar_clave_en_lista(hash->tabla_hash[posicion_en_hash],clave);
  return(posicion_en_lista >=0);
}

void hash_destruir(hash_t* hash){
  if(hash == NULL){
    return;
  }
  destruir_tabla_hash(hash->tabla_hash,hash->tamanio_tabla,hash->destructor,true);
  free(hash);
}

hash_iterador_t* hash_iterador_crear(hash_t* hash){
  if(hash == NULL || hash->tabla_hash == NULL || hash_cantidad(hash) == 0){
    return NULL;
  }
  hash_iterador_t* iterador_hash = (hash_iterador_t*)calloc(1,sizeof(hash_iterador_t));
  if(iterador_hash == NULL){
    return NULL;
  }
  iterador_hash->hash = hash;
  int posicion_primera_lista_a_iterar = proxima_posicion_lista_valida(hash->tabla_hash,0,hash->tamanio_tabla);
  lista_iterador_t*iterador_lista = lista_iterador_crear(hash->tabla_hash[posicion_primera_lista_a_iterar]);
  if(iterador_lista == NULL){
    free(iterador_hash);
    return NULL;
  }
  iterador_hash->corriente = iterador_lista;
  iterador_hash->posicion_tabla_actual = (size_t)posicion_primera_lista_a_iterar;
  return iterador_hash;
}

void* hash_iterador_siguiente(hash_iterador_t* iterador){
  if(iterador == NULL || iterador->corriente == NULL){
    return NULL;
  }
  void* dato = lista_iterador_siguiente(iterador->corriente);
  if(!lista_iterador_tiene_siguiente(iterador->corriente)){
    lista_iterador_t* iterador_lista_destruir = iterador->corriente;
    int posicion_proxima_lista = proxima_posicion_lista_valida(iterador->hash->tabla_hash,iterador->posicion_tabla_actual+1,iterador->hash->tamanio_tabla);
    if(posicion_proxima_lista == POSICION_NO_VALIDA){
      iterador->corriente = NULL;
    }else{
      iterador->corriente = lista_iterador_crear(iterador->hash->tabla_hash[posicion_proxima_lista]);
      iterador->posicion_tabla_actual = (size_t)posicion_proxima_lista;
    }
    free(iterador_lista_destruir);
  }
  return (void*)(((dato_t*)dato)->clave);
}

bool hash_iterador_tiene_siguiente(hash_iterador_t* iterador){
  if(iterador == NULL || iterador->corriente == NULL){
    return false;
  }
  return !(!lista_iterador_tiene_siguiente(iterador->corriente) && proxima_posicion_lista_valida(iterador->hash->tabla_hash,iterador->posicion_tabla_actual,iterador->hash->tamanio_tabla) == POSICION_NO_VALIDA);
}

void hash_iterador_destruir(hash_iterador_t* iterador){
  if(iterador == NULL){
    return;
  }
  lista_iterador_destruir(iterador->corriente);
  free(iterador);
}
