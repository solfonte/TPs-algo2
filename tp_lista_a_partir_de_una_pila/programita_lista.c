#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#define CANTIDAD_PARES 5
#define CANTIDAD_IMPARES 5
#define CANTIDAD_DE_NUMEROS 10

/*El procedimiento recibe una lista inicializada que contiene numeros.
Imprime la suma de los numeros en ella*/
void sumar_numeros(lista_t* lista){
  lista_iterador_t* iterador = lista_iterador_crear(lista);
  if(iterador == NULL){
    printf("Fallo la creacion del iterador\n");
    return;
  }
  int suma = 0;
  while(lista_iterador_tiene_siguiente(iterador)){
    suma += *(int*)lista_iterador_siguiente(iterador);
  }
  lista_iterador_destruir(iterador);
  printf("La suma de los numeros es: %i\n",suma);
}

/*El procedimiento recibe un puntero a void de un numero.
Muestra el numero por pantalla*/
void imprimir_numeros_lista(void*numero){
  printf("%i ",*(int*)numero);
}

/*El procedimiento recibe una lista inicializada que contiene numeros.
Ordena la lista de numeros, ubicando los impares en las posiciones impares y a los pares en las posiciones pares*/
void ordenar_lista(lista_t* lista){
  printf("Ordeno la lista con los numeros pares en las posiciones pares y los impares en las posiciones impares\n");
  void* numero;
  size_t posicion_inicial = 1;
  for(size_t i = CANTIDAD_IMPARES; i < CANTIDAD_DE_NUMEROS; i++){
    numero = lista_elemento_en_posicion(lista,i);
    lista_borrar_de_posicion(lista,i);
    lista_insertar_en_posicion(lista,numero,posicion_inicial);
    posicion_inicial += 2;
  }
  lista_con_cada_elemento(lista,&imprimir_numeros_lista);
  printf("\n");
}

/*El procedimiento recibe una lista inicializada, y dos vectores con uno de numeros pares y el otro con numeros impares.
Aniade los numeros pares y luego los impares a la lista*/
void aniadir_numeros_a_la_lista(lista_t*lista,int numeros_pares[],int numeros_impares[]){
  for(int i = 0; i < CANTIDAD_DE_NUMEROS/2; i++){
    numeros_pares[i] = (rand()%CANTIDAD_DE_NUMEROS)*2;
    numeros_impares[i] = (rand()%CANTIDAD_DE_NUMEROS)*2 + 1;
  }
  printf("Inserto los siguientes %i numeros en una lista (%i pares, %i impares) en el siguiente orden\n",CANTIDAD_DE_NUMEROS,CANTIDAD_PARES,CANTIDAD_IMPARES);
  for(int j = 0; j < CANTIDAD_PARES;j++){
    printf("%i ",numeros_pares[j]);
    lista_insertar(lista,&numeros_pares[j]);
  }
  for(int k = 0; k < CANTIDAD_IMPARES;k++){
    printf("%i ",numeros_impares[k]);
    lista_insertar(lista,&numeros_impares[k]);
  }
  printf("\n");
}

int main(){
  srand((unsigned int)time(NULL));
  int numeros_pares[CANTIDAD_PARES] = {0};
  int numeros_impares[CANTIDAD_IMPARES] = {0};
  lista_t* lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para el programa\n");
    return 0;
  }
  aniadir_numeros_a_la_lista(lista,numeros_pares,numeros_impares);
  printf("ordenando los numeros de la lista insertando, borrando, y pidiendo elementos de posiciones\n");
  ordenar_lista(lista);
  printf("Suma usando el iterador externo\n");
  sumar_numeros(lista);
  lista_destruir(lista);
  return 0;
}
