#include "biblioteca_pruebas_lista.h"
#include "lista.h"
#include <stdio.h>

int DadaUnaListaNull_SeIntentaInsertar_DevuelveMenosUno(){
  lista_t*lista = NULL;
  int elemento = 6;
  if(lista_insertar(lista,&elemento) == -1){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadaUnaListaNull_SeIntentaInsertarEnUnaPosicion_DevuelveMenosUno(){
  lista_t*lista = NULL;
  int elemento = 6;
  size_t posicion = 1;
  if(lista_insertar_en_posicion(lista,&elemento,posicion) == -1){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadaUnaListaNull_SeIntentaBorrar_DevuelveMenosUno(){
  lista_t*lista = NULL;
  if(lista_borrar(lista) == -1){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadaUnaListaNull_SeIntentaBorrarDeUnaPosicion_DevuelveMenosUno(){
  lista_t*lista = NULL;
  size_t posicion = 1;
  if(lista_borrar_de_posicion(lista,posicion) == -1){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadaUnaListaNull_SepideElUltimoElemento_DevuelveNULL(){
  lista_t*lista = NULL;
  if(lista_ultimo(lista) == NULL){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadaUnaListaNull_SePideElElementoEnUnaPosicion_DevuelveNULL(){
  lista_t*lista = NULL;
  size_t posicion = 1;
  if(lista_elemento_en_posicion(lista,posicion) == NULL){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadaUnaListaNull_SePreguntaSiEstaVacia_DevuelveTrue(){
  lista_t*lista = NULL;
  if(lista_vacia(lista)){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadaUnaListaNull_SePideLaCantidadDeElementosEnLaLista_DevuelveCero(){
  lista_t*lista = NULL;
  if(lista_elementos(lista) == 0){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadaUnaListaNull_SeLaDestruye_NoCausaProblemas(){
  lista_t*lista = NULL;
  lista_destruir(lista);
  printf("%s : PASO\n",__func__);
  return 1;
}

int DadaUnaListaVacia_SeInsertaUnElemento_LoInsertaCorrectamente(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento = 8;
  if(lista_insertar(lista,&elemento) == 0){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaVacia_SePideInsertarUnElementoEnUnaPosicion_LoInsertaEnLaPosicionCero(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento = 7;
  size_t posicion = 8;
  if(lista_insertar_en_posicion(lista,&elemento,posicion) == 0){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaVacia_SePideBorrarUnElemento_DevuelveMenosUno(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  if(lista_borrar(lista) == -1){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaVacia_SePideBorrarUnElementoDeUnaPosicion_DevuelveMenosUno(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  size_t posicion = 3;
  if(lista_borrar_de_posicion(lista,posicion) == -1){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaVacia_SePideElElementoEnUnaPosicion_DevuelveNULL(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  size_t posicion = 0;
  if(lista_elemento_en_posicion(lista,posicion) == NULL){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaVacia_SePideElUltimoElemento_DevuelveNULL(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  if(lista_ultimo(lista) == NULL){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaVacia_InsertoUnElementoYPreguntoSiLaListaEstaVacia_DevuelveFalse(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento = 9;
  lista_insertar(lista,&elemento);
  if(!lista_vacia(lista)){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaVacia_PidoLaCantidadDeElementos_DevuelveCero(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  if(lista_elementos(lista) == 0){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaVacia_InsertoElementosYpidoLaCantidadDeElementosEnLaLista_DevuelveLaCantidadDeElementosQueInserte(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 9;
  int elemento_2 = 6;
  int elemento_3 = 8;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  if(lista_elementos(lista) == 3){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_SeInsertaUnElemento_LoInsertaAlFinal(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 7;
  int elemento_3 = 9;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  if(*(int*)(lista_ultimo(lista)) == elemento_3){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_SeInsertaUnElementoEnUnaPosicionQueExiste_LoInsertaCorrectamente(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  size_t posicion = 2;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar_en_posicion(lista,&elemento_4,posicion);
  if(*(int*)lista_elemento_en_posicion(lista,posicion) == elemento_4){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_SePideInsertarUnElementoEnUnaPosicionQueNoExiste_LoInsertaAlFinal(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  size_t posicion = 6;
  lista_insertar_en_posicion(lista,&elemento_4,posicion);
  if(*(int*)lista_ultimo(lista) == elemento_4){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_SePideBorrarUnElementoDeUnaPosicionQueNoExiste_DevuelveMenosUno(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  size_t posicion = 6;

  if(lista_borrar_de_posicion(lista,posicion) == -1){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_SePideBorrarUnElementoDeUnaPosicionQueExiste_LoBorraCorrectamente(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  size_t posicion = 2;
  lista_borrar_de_posicion(lista,posicion);
  if(*(int*)lista_elemento_en_posicion(lista,posicion) == elemento_4){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_SePideBorrarUnElemento_BorraElUltimo(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  lista_borrar(lista);
  if(*(int*)lista_ultimo(lista) == elemento_3){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_SePideElElementoEnUnaPosicionQueNoExiste_DevuelveNULL(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  size_t posicion = 6;
  if(lista_elemento_en_posicion(lista,posicion) == NULL){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_SePideElElementoEnUnaPosicionQueExiste_LoDevuelveCorrectamente(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  size_t posicion = 1;
  if(*(int*)lista_elemento_en_posicion(lista,posicion) == elemento_2){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_SePideElElementoEnLaUltimaPosicion_LoDevuelveCorrectamente(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  if(*(int*)lista_ultimo(lista) == elemento_4){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadaUnaListaConVariosElementos_LosBorroDeLaListaYPreguntoSiEstaVacia_DevuelveTrue(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  lista_borrar(lista);
  lista_borrar(lista);
  lista_borrar(lista);
  lista_borrar(lista);
  if(lista_vacia(lista)){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }

}

int DadaUnaListaConVariosElementos_SeLaDestruye_NoCausaProblemas(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  lista_destruir(lista);
  printf("%s : PASO\n",__func__);
  return 1;
}

int DadaUnaListaNull_SeIntentaCrearUnIteradorParaLaLista_DevuelveNULL(){
  lista_t*lista = NULL;
  lista_iterador_t* iterador = lista_iterador_crear(lista);
  if(iterador == NULL){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    return 0;
  }
}

int DadoUnIteradorNULL_SePreguntaSiLaListaTieneSiguiente_DevelveFalse(){
  lista_iterador_t*iterador = NULL;
  if(lista_iterador_tiene_siguiente(iterador) == false){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadoUnIteradorDeUnaListaVacia_SePreguntaSiTieneSiguiente_DevuelveFalse(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion del lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  lista_iterador_t*iterador = lista_iterador_crear(lista);
  if(iterador == NULL){
    lista_destruir(lista);
    printf("Fallo la creacion del iterador para la prueba. Prueba no pasada\n");
    return 0;
  }
  if(lista_iterador_tiene_siguiente(iterador) == false){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 0;
  }
}

int DadoUnIteradorQueApuntaAlPrimerElementoDeUnaListaConVariosElementos_SePreguntaSiTieneSiguiente_Devuelvetrue(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion del lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  lista_iterador_t*iterador = lista_iterador_crear(lista);
  if(iterador == NULL){
    lista_destruir(lista);
    printf("Fallo la creacion del iterador para la prueba. Prueba no pasada\n");
    return 0;
  }
  if(lista_iterador_tiene_siguiente(iterador) == true){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 0;
  }
}

int DadoUnIteradorQueApuntaAlUltimoElementoDeUnaListaConVariosElementos_SePreguntaSiTieneSiguiente_DevuelveFalse(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion del lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  lista_iterador_t*iterador = lista_iterador_crear(lista);
  if(iterador == NULL){
    lista_destruir(lista);
    printf("Fallo la creacion del iterador para la prueba. Prueba no pasada\n");
    return 0;
  }
  for(int i = 0;i < 3;i++){
    lista_iterador_siguiente(iterador);
  }
  if(*(int*)lista_iterador_siguiente(iterador) == elemento_4 && lista_iterador_tiene_siguiente(iterador) == false){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 0;
  }
}

int DadoUnIteradorDeUnaListaVacia_SeAvanzaElIteradorAlProximoElementoDeLaLista_DevuelveNull(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion del lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  lista_iterador_t*iterador = lista_iterador_crear(lista);
  if(iterador == NULL){
    lista_destruir(lista);
    printf("Fallo la creacion del iterador para la prueba. Prueba no pasada\n");
    return 0;
  }
  if(lista_iterador_siguiente(iterador) == NULL){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 0;
  }
}

int DadoUnIteradorNUll_SeAvanzaElIteradorAlProximoElementoDeLaLista_DevuelveNULL(){
  lista_iterador_t*iterador = NULL;
  if(lista_iterador_siguiente(iterador) == NULL){
    printf("%s : PASO\n",__func__);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    return 0;
  }
}

int DadoUnIteradorQueApuntaAlPrimerElementoDeUnaListaConVariosElementos_SeAvanzaElIteradorAlProximoElemento_DevuelveElElementoYAvanzaCorrectamente(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion del lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  lista_iterador_t*iterador = lista_iterador_crear(lista);
  if(iterador == NULL){
    lista_destruir(lista);
    printf("Fallo la creacion del iterador para la prueba. Prueba no pasada\n");
    return 0;
  }
  if(*(int*)lista_iterador_siguiente(iterador) == elemento_1 && *(int*)lista_iterador_siguiente(iterador) == elemento_2){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 0;
  }
}

int DadoUnIteradorQueApuntaAlUltimoElementoDeUnaListaConVariosElementos_SeAvanzaElIteradorAlProximoElemento_DevuelveElElementoYElSiguienteElementoEsNUll(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion del lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento_1 = 8;
  int elemento_2 = 9;
  int elemento_3 = 7;
  int elemento_4 = 0;
  lista_insertar(lista,&elemento_1);
  lista_insertar(lista,&elemento_2);
  lista_insertar(lista,&elemento_3);
  lista_insertar(lista,&elemento_4);
  lista_iterador_t*iterador = lista_iterador_crear(lista);
  if(iterador == NULL){
    lista_destruir(lista);
    printf("Fallo la creacion del iterador para la prueba. Prueba no pasada\n");
    return 0;
  }
  for(int i = 0;i < 3;i++){
    lista_iterador_siguiente(iterador);
  }
  if(*(int*)lista_iterador_siguiente(iterador) == elemento_4 && lista_iterador_siguiente(iterador) == NULL){
    printf("%s : PASO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 1;
  }else{
    printf("%s : FALLO\n",__func__);
    lista_destruir(lista);
    lista_iterador_destruir(iterador);
    return 0;
  }
}

int DadoUnIteradorInicializado_SeLoDestruye_NoCausaProblemas(){
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion del lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  lista_iterador_t*iterador = lista_iterador_crear(lista);
  if(iterador == NULL){
    lista_destruir(lista);
    printf("Fallo la creacion del iterador para la prueba. Prueba no pasada\n");
    return 0;
  }
  lista_iterador_destruir(iterador);
  lista_destruir(lista);
  printf("%s : PASO\n",__func__);
  return 1;

}
