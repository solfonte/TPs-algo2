#include <stdio.h>
#include <stdbool.h>
#include "cola.h"
#include "biblioteca_pruebas_cola.h"

int DadaUnaColaNull_SeIntentaDesencolar_DevuelveMenosUno(){
  printf("%s: ", __func__);
  cola_t*cola = NULL;
  if(cola_desencolar(cola) == -1){
    printf("La prueba paso con exito\n");
    return 1;
  }else{
    printf("Fallo la prueba\n");
    return 0;
  }
}

int DadaUnaColaNull_SeIntentaEncolar_DevuelveMenosUno(){
  printf("%s: ", __func__);
  cola_t*cola = NULL;
  int elemento = 1;
  if(cola_encolar(cola,&elemento) == -1){
    printf("La prueba paso con exito\n");
    return 1;
  }else{
    printf("Fallo la prueba\n");
    return 0;
  }
}

int DadaUnaColaNull_SePreguntaSiEstaVacia_DevuelveTrue(){
  printf("%s: ", __func__);
  cola_t*cola = NULL;
  if(cola_vacia(cola)){
    printf("La prueba paso con exito\n");
    return 1;
  }else{
    printf("Fallo la prueba\n");
    return 0;
  }
}

int DadaUnaColaNull_SeDestruye_NoOcurreNingunError(){
  printf("%s: ", __func__);
  cola_t*cola = NULL;
  cola_destruir(cola);
  printf("La prueba paso con exito\n");
  return 1;
}

int DadaUnaColaNull_SePideLaCantidadDeElementos_DevuelveCero(){
  printf("%s: ", __func__);
  cola_t*cola = NULL;
  if(cola_cantidad(cola) == 0){
    printf("La prueba paso con exito\n");
    return 1;
  }else{
    printf("Fallo la prueba\n");
    return 0;
  }
}

int DadaUnaColaVacia_SeIntentaDesencolar_DevuelveMenosUno(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  if(cola_desencolar(cola) == -1){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}

int DadaUnaColaVacia_SePreguntaSiEstaVacia_DevuelveTrue(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  if(cola_vacia(cola)){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}

int DadaUnaColaConUnElemento_SePreguntaSiEstaVacia_DevuelveFalse(){
  printf("%s: ", __func__);
  cola_t* cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  int elemento = 2;
  cola_encolar(cola,&elemento);
  if(!cola_vacia(cola)){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}

int DadaUnaColaConDiezElementos_SeDesencolanCincoElementos_LaCantidadDeElementosEnLaColaDevuelveCinco(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  int elementos[10] = {1,2,3,4,5,6,7,8,9,10};
  for(int i = 0; i<10; i++){
    cola_encolar(cola,&elementos[i]);
  }
  for(int j = 0;j<5; j++){
    cola_desencolar(cola);
  }
  if(cola_cantidad(cola) == 5){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}

int DadaUnaColaConDiezElementos_SeDesencolan_LosDevuelveEnOrdenDeFIFO(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  bool se_desencolan_correctamente = true;
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  int elementos[10] = {1,2,3,4,5,6,7,8,9,10};
  for(int i = 0; i<10; i++){
    cola_encolar(cola,&elementos[i]);
  }
  for(int j = 0;j<10; j++){
    if(elementos[j] != *(int*)cola_primero(cola)){
      se_desencolan_correctamente = false;
    }
    cola_desencolar(cola);
  }
  if(se_desencolan_correctamente){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}

int DadaUnaColaConUnElemento_SeDesencolaElElementoYSePreguntaSiEstaVacia_DevuelveTrue(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  char elemento = 'r';
  cola_encolar(cola,&elemento);
  cola_desencolar(cola);
  if(cola_vacia(cola)){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}

int DadaUnaColaInicializada_SeDestruye_NoOcurreNingunError(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  cola_destruir(cola);
  printf("La prueba paso con exito\n");
  return 1;
}

int DadaUnaColaIncializada_SeEncolaUnElementoNull_DevuelveCero(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  void*elemento = NULL;
  if(cola_encolar(cola,elemento) == 0){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}

int DadaUnaColaInicializada_SeEncolanDiezElementos_LaCantidadDevuelveDiez(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  int elementos[10] = {1,2,3,4,5,6,7,8,9,10};
  for(int i = 0; i<10; i++){
    cola_encolar(cola,&elementos[i]);
  }
  if(cola_cantidad(cola) == 10){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}

int DadaUnaColaConDiezElementos_SeVacia_LaCantidadDeElementosDevuelveCero(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  int elementos[10] = {1,2,3,4,5,6,7,8,9,10};
  for(int i = 0; i<10; i++){
    cola_encolar(cola,&elementos[i]);
  }
  while(!cola_vacia(cola)){
    cola_desencolar(cola);
  }
  if(cola_cantidad(cola) == 0){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}

int DadaUnaColaInicializada_SeEncolanTresElementosDeDistintosTiposDeDatos_LaCantidadDeElementosEsTres(){
  printf("%s: ", __func__);
  cola_t*cola = cola_crear();
  if(cola == NULL){
    printf("Error al crear la cola para la prueba\n");
    return 0;
  }
  int numero = 6;
  char letra = 'f';
  registro_t registro;
  registro.numero = 4;
  registro.string = 'h';
  cola_encolar(cola,&numero);
  cola_encolar(cola,&letra);
  cola_encolar(cola,&registro);
  if(cola_cantidad(cola) == 3){
    printf("La prueba paso con exito\n");
    cola_destruir(cola);
    return 1;
  }else{
    printf("Fallo la prueba\n");
    cola_destruir(cola);
    return 0;
  }
}
