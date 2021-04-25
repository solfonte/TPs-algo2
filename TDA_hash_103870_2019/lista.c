#include <stdlib.h>
#include "lista.h"
#define ERROR -1
#define EXITO 0

typedef struct nodo{
	void* elemento;
	struct nodo* siguiente;
} nodo_t;

struct lista{
  nodo_t*nodo_inicio;
  nodo_t*nodo_fin;
  size_t cantidad;
};

struct lista_iterador{
  lista_t*lista;
  nodo_t*corriente;
};
/*pre condiciones: el procedimiento recibe un puntero a una lista inicializada
post condiciones: el procedimiento borra un elemento de la lista desde el inicio*/
void borrar_desde_inicio(lista_t*lista){
  if(lista_elementos(lista) == 1){
    free(lista->nodo_inicio);
    lista->cantidad--;
    return;
  }
  nodo_t*nodo_eliminar = lista->nodo_inicio;
  lista->nodo_inicio = lista->nodo_inicio->siguiente;
  free(nodo_eliminar);
  lista->cantidad--;
}

/*pre condiciones: la funcion no recibe ningun parametro
post condiciones: la funcion devuelve un puntero a un nodo inicializado*/
nodo_t*crear_nodo(){
  nodo_t*nodo = (nodo_t*)calloc(1,sizeof(nodo_t));
  return nodo;
}

/*pre condiciones: la funcion recibe la cantidad de elementos en una lista y una posicion
post condiciones: la funcion devuelve true si la posicion de la lista existe o false si no existe*/
bool posicion_existe(size_t cantidad_elementos,size_t posicion){
  return(cantidad_elementos > posicion);//chequear
}

/*pre condiciones: la funcion recibe un puntero a una lista inicializada y una posicion
post condiciones: la funcion devuelve un puntero a un nodo en la posicion anterior ala recibida por parametro*/
nodo_t*nodo_posicion_menos_uno(lista_t*lista,size_t posicion){
  int i = 1;
  nodo_t*aux = lista->nodo_inicio;
  while(i < posicion){
    aux = aux->siguiente;
    i++;
  }
  return aux;
}

lista_t* lista_crear(){
  lista_t*lista = (lista_t*)calloc(1,sizeof(lista_t));
  return lista;
}

int lista_insertar(lista_t* lista, void* elemento){
  if(lista == NULL){
    return ERROR;
  }
  nodo_t*nuevo_nodo = crear_nodo();
  if(nuevo_nodo == NULL){
    return ERROR;
  }
  if(lista_vacia(lista)){
    lista->nodo_inicio = nuevo_nodo;
  }else{
    lista->nodo_fin->siguiente = nuevo_nodo;
  }
  lista->nodo_fin = nuevo_nodo;
  nuevo_nodo->elemento = elemento;
  lista->cantidad ++;
  return EXITO;
}

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){
  if(lista == NULL){
    return ERROR;
  }
  if(!posicion_existe(lista->cantidad,posicion)){
    return lista_insertar(lista,elemento);
  }
  nodo_t*nuevo_nodo = crear_nodo();
  if(nuevo_nodo == NULL){
    return ERROR;
  }
  if(posicion == 0){
    nuevo_nodo->siguiente = lista->nodo_inicio;
    lista->nodo_inicio = nuevo_nodo;
  }else{
    nodo_t*aux = nodo_posicion_menos_uno(lista,posicion);
    nuevo_nodo->siguiente = aux->siguiente;
    aux->siguiente = nuevo_nodo;
  }
  nuevo_nodo->elemento = elemento;
  lista->cantidad++;
  return EXITO;
}

int lista_borrar(lista_t* lista){
  if(lista == NULL || lista_vacia(lista)){
    return ERROR;
  }
  if(lista->nodo_inicio == lista->nodo_fin){
    free(lista->nodo_inicio);
    lista->cantidad--;
    return EXITO;
  }
  nodo_t*aux = nodo_posicion_menos_uno(lista,lista->cantidad-1);
  free(aux->siguiente);
  aux->siguiente = NULL;
  lista->nodo_fin = aux;
  lista->cantidad --;
  return EXITO;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
  if(lista == NULL){
    return ERROR;
  }
	if(!posicion_existe(lista->cantidad,posicion)){
		return lista_borrar(lista);
	}
  if(posicion == 0){
    nodo_t*nodo_borrar = lista->nodo_inicio;
    lista->nodo_inicio = nodo_borrar->siguiente;
    free(nodo_borrar);
  }else{
    nodo_t*aux = nodo_posicion_menos_uno(lista,posicion);
    nodo_t*nodo_borrar = aux->siguiente;
    aux->siguiente = nodo_borrar->siguiente;
		if(posicion == (lista->cantidad - 1)){
			lista->nodo_fin = aux;
		}
    free(nodo_borrar);
  }
  lista->cantidad --;
  return EXITO;
}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
  if(lista == NULL || !posicion_existe(lista->cantidad,posicion)){
    return NULL;
  }
	if(posicion == 0){
		return lista->nodo_inicio->elemento;
	}
	nodo_t*aux = nodo_posicion_menos_uno(lista,posicion);
  return aux->siguiente->elemento;
}

void* lista_ultimo(lista_t* lista){
  if(lista == NULL || lista_vacia(lista)){
    return NULL;
  }
  return lista->nodo_fin->elemento;
}

bool lista_vacia(lista_t* lista){
	return(lista == NULL || lista->cantidad == 0);
}

size_t lista_elementos(lista_t* lista){
	if(lista == NULL){
		return 0;
	}
  return lista->cantidad;
}

void lista_destruir(lista_t* lista){
  while(!lista_vacia(lista)){
    borrar_desde_inicio(lista);
  }
  free(lista);
}

lista_iterador_t* lista_iterador_crear(lista_t* lista){
	if(lista == NULL){
		return NULL;
	}
	lista_iterador_t*iterador = (lista_iterador_t*)malloc(sizeof(lista_iterador_t));
	if(iterador == NULL){
		return NULL;
	}
	iterador->lista = lista;
	iterador->corriente = lista->nodo_inicio;
	return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
	return(iterador != NULL && iterador->corriente != NULL);
}

void* lista_iterador_siguiente(lista_iterador_t* iterador){
	if(iterador == NULL){
		return NULL;
	}
	if(iterador->corriente == NULL){
		return NULL;
	}
	void*elemento = iterador->corriente->elemento;
	iterador->corriente = iterador->corriente->siguiente;
	return elemento;
}

void lista_iterador_destruir(lista_iterador_t* iterador){
	free(iterador);
}

void lista_con_cada_elemento(lista_t* lista, void (*funcion)(void*)){
	if(lista_vacia(lista)){
		return;
	}
	int i = 0;
	nodo_t*aux = lista->nodo_inicio;
	while(i < lista->cantidad){
		funcion(aux->elemento);
		aux=aux->siguiente;
		i++;
	}
}
