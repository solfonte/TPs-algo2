#include"pila.h"
#include<stdio.h>
#define MAX_ELEMENTOS 10
#define ERROR -1
#define EXITO 0
int DadaUnaPilaNull_CuandoSePideApilar_DevuelveMenosUno(){
  printf("Prueba 1: se pide apilar en una pila NULL y devuelve -1\n");
  pila_t* pila = NULL;
  int elemento_1 = 4;
  int resultado_apilar = pila_apilar(pila,&elemento_1);
  if(resultado_apilar == ERROR){
    printf(" Paso la prueba\n");
    return 1;
  }else{
    printf(" Fallo la prueba\n");
    return 0;
  }
}
int DadaUnaPilaNull_CuandoSeLaDestruye_NoOcurreNingunError(){
  printf("Prueba 2: se intenta destruir una pila NULL\n Se espera que no ocurra ningun error\n");
  pila_t*pila = pila_crear();
  pila_destruir(pila);
  return 1;
}
int DadaUnaPilaVacia_CuandoSePideDesapilar_devuelveMenosUno(){
  printf("Prueba 3: se pide desapilar de una pila vacia y devuelve -1\n");
  pila_t*pila = pila_crear();
  if(pila == NULL){
    printf(" Ocurrio un error al crear la pila\n");
    return 0;
  }
  int resultado_desapilar = pila_desapilar(pila);
  pila_destruir(pila);
  if(resultado_desapilar == ERROR){
    printf(" Paso la prueba\n");
    return 1;
  }else{
    printf(" Fallo la prueba\n");
    return 0;
  }
}
int DadaUnaPilaVacia_CuandoSePideElElementoDelTope_DevuelveNull(){
  printf("Prueba 4: se pide el elemento del tope de una pila vacia y devuelve NULL\n");
  pila_t*pila = pila_crear();
  if(pila == NULL){
    printf(" Ocurrio un error al crear la pila\n");
    return 0;
  }
  void* elemento = pila_tope(pila);
  pila_destruir(pila);
  if(elemento == NULL){
    printf(" Paso la prueba\n");
    return 1;
  }else{
    printf(" Fallo la prueba\n");
    return 0;
  }
}
int DadaUnaPilaInicializadaConDiezElementos_CuandoSePidenLosUltimosTres_DevuelveLosTresElementos(){
  printf("Prueba 5: se piden los ultimos 3 elementos de una pila con 10 elementos apilados\n");
  pila_t* pila = pila_crear();
  if(pila == NULL){
    printf(" Ocurrio un error al crear la pila\n");
    return 0;
  }
  int elementos[MAX_ELEMENTOS] = {0,1,2,3,4,5,6,7,8,9};
  int*elemento_9 = NULL;
  int*elemento_8 = NULL;
  int*elemento_7 = NULL;
  for(int i = 0;i<10;i++){
    pila_apilar(pila,&elementos[i]);
  }
  elemento_9= (int*)pila_tope(pila);
  pila_desapilar(pila);
  elemento_8 = (int*)pila_tope(pila);
  pila_desapilar(pila);
  elemento_7 = (int*)pila_tope(pila);
  pila_destruir(pila);
  if(*elemento_9 == 9 && *elemento_8 == 8 && *elemento_7 == 7){
    printf(" Paso la prueba\n");
    return 1;
  }else{
    printf(" Fallo la prueba\n");
    return 0;
  }
}
int DadosMuchosElementos_CuandoSeApilanYDesapilan_SeVerificaQueElVectorDeElementosSeRedimensioneCorrectamente(){
  printf("Prueba 6: Se apilan y desapilan elementos de una pila. Se espera que el vector se redimensione cuando se apilan y desapilan los elementos\n");
  pila_t*pila = pila_crear();
  if(pila == NULL){
    printf(" Ocurrio un error al crear la pila\n");
    return 0;
  }
  int tamanio_inicial = pila->tamanio;
  char elemento_1 = 'A';
  char elemento_2 = 'L';
  char elemento_3 = 'G';
  char elemento_4 = 'O';
  char elemento_5 = '2';
  pila_apilar(pila, &elemento_1);
  pila_apilar(pila, &elemento_2);
  pila_apilar(pila, &elemento_3);
  pila_apilar(pila, &elemento_4);
  pila_apilar(pila, &elemento_5);
  int tamanio_despues_de_apilar = pila->tamanio;
  for(int i = 0;i<5 ;i++){
    pila_desapilar(pila);
  }
  int tamanio_despues_de_desapilar = pila->tamanio;
  pila_destruir(pila);
  if(tamanio_inicial < tamanio_despues_de_apilar && tamanio_despues_de_desapilar < tamanio_despues_de_apilar){
    printf(" Paso la prueba\n");
    return 1;
  }else{
    printf(" Fallo la prueba\n");
    return 0;
  }
}
int Dados10ElementosApilados_CuandoSePideLaCantidad_Devuelve10(){
  printf("Prueba 7: se carga una pila con 10 elementos y se espera que la cantidad de elementos en la pila sea 10\n");
  pila_t* pila = pila_crear();
  if(pila == NULL){
    printf(" Ocurrio un error al crear la pila\n");
    return 0;
  }
  int vector_elementos[] = {0,1,2,3,4,5,6,7,8,9};
  for(int i=0;i<10;i++){
    pila_apilar(pila,&vector_elementos[i]);
  }
  int cantidad_elementos = pila_cantidad(pila);
  pila_destruir(pila);
  if(cantidad_elementos == 10){
    printf(" Paso la prueba\n");
    return 1;
  }else{
    printf(" Fallo la prueba\n");
    return 0;
  }

}
int DadaUnaPilaCargada_CuandoSePreguntaSiEstaVacia_DevuelveFalse(){
  printf("Prueba 8:se carga una pila y se pregunta si esta vacia y devuelve que no lo esta\n");
  pila_t*pila = pila_crear();
  if(pila == NULL){
    printf("Ocurrio un error al crear la pila\n");
    return 0;
  }
  int elemento = 1;
  for(int i=0;i<MAX_ELEMENTOS;i++){
    pila_apilar(pila,&elemento);
  }
  bool pila_esta_vacia = pila_vacia(pila);
  pila_destruir(pila);
  if(!pila_esta_vacia){
    printf(" Paso la prueba\n");
    return 1;
  }else{
    printf(" Fallo la prueba\n");
    return 0;
  }

}
int DadaUnaPilaConUnElementoApilado_CuandoSeDesapila_LaCantidadDeElementosEsCero(){
  printf("Prueba 9:se apila un elemento en la pila y luego se desapila. Se espera que la cantidad de elementos en la pila despues de desapilar el elemento sea cero\n");
  pila_t*pila = pila_crear();
  int cantidad_inicial = -1;
  int cantidad_final = -1;
  if(pila == NULL){
    printf(" Ocurrio un error al crear la pila\n");
    return 0;
  }
  int elemento = 1;
  pila_apilar(pila,&elemento);
  cantidad_inicial = pila_cantidad(pila);
  pila_desapilar(pila);
  cantidad_final = pila_cantidad(pila);
  pila_destruir(pila);
  if(cantidad_inicial == 1 && cantidad_final == 0){
    printf(" Paso la prueba");
    return 1;
  }else{
    printf(" Fallo la prueba");
    return 0;
  }
}
int DadoUnElementoNull_CuandoSeLoApila_DevuelveCero(){
  printf("Prueba 10: se intenta apilar un elemento NULL y devuelve cero\n");
  pila_t*pila = pila_crear();
  void*elemento = NULL;
  int resultado = pila_apilar(pila,elemento);
  pila_destruir(pila);
  if(resultado == 0){
    printf(" Paso la prueba\n");
    return 1;
  }else{
    printf(" Fallo la prueba\n");
    return 0;
  }
}
int main(){
  int pruebas_pasadas = 0;
  int pruebas_totales = 10;
   pruebas_pasadas += DadaUnaPilaNull_CuandoSePideApilar_DevuelveMenosUno();
   pruebas_pasadas += DadaUnaPilaNull_CuandoSeLaDestruye_NoOcurreNingunError();
   pruebas_pasadas += DadaUnaPilaVacia_CuandoSePideDesapilar_devuelveMenosUno();
   pruebas_pasadas += DadaUnaPilaVacia_CuandoSePideElElementoDelTope_DevuelveNull();
   pruebas_pasadas += DadaUnaPilaInicializadaConDiezElementos_CuandoSePidenLosUltimosTres_DevuelveLosTresElementos();
   pruebas_pasadas += DadosMuchosElementos_CuandoSeApilanYDesapilan_SeVerificaQueElVectorDeElementosSeRedimensioneCorrectamente();
   pruebas_pasadas += Dados10ElementosApilados_CuandoSePideLaCantidad_Devuelve10();
   pruebas_pasadas += DadaUnaPilaCargada_CuandoSePreguntaSiEstaVacia_DevuelveFalse();
   pruebas_pasadas += DadaUnaPilaConUnElementoApilado_CuandoSeDesapila_LaCantidadDeElementosEsCero();
   pruebas_pasadas += DadoUnElementoNull_CuandoSeLoApila_DevuelveCero();
   printf("Cantidad de pruebas totales = %i\nCantidad de pruebas pasadas = %i\n",pruebas_totales,pruebas_pasadas);
  return 0;
}
