#include "biblioteca_pruebas_lista.h"
#include "lista.h"
#include <stdio.h>

/*La funcion recibe una variable bool inicializada.
Devuelve 1 si la prueba paso, y cero si no paso*/
int verificar_resultado_prueba(bool resultado){
  if(resultado){
    printf("PASO\n");
    return 1;
  }else{
    printf("FALLO\n");
    return 0;
  }
}

int DadaUnaListaNull_SeIntentaInsertar_DevuelveMenosUno(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  int elemento = 6;
  bool resultado = (lista_insertar(lista,&elemento) == -1? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaNull_SeIntentaInsertarEnUnaPosicion_DevuelveMenosUno(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  int elemento = 6;
  size_t posicion = 1;
  bool resultado = (lista_insertar_en_posicion(lista,&elemento,posicion) == -1? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaNull_SeIntentaBorrar_DevuelveMenosUno(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  bool resultado = (lista_borrar(lista) == -1? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaNull_SeIntentaBorrarDeUnaPosicion_DevuelveMenosUno(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  size_t posicion = 1;
  bool resultado = (lista_borrar_de_posicion(lista,posicion) == -1? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaNull_SepideElUltimoElemento_DevuelveNULL(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  bool resultado = (lista_ultimo(lista) == NULL? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaNull_SePideElElementoEnUnaPosicion_DevuelveNULL(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  size_t posicion = 1;
  bool resultado = (lista_elemento_en_posicion(lista,posicion) == NULL? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaNull_SePreguntaSiEstaVacia_DevuelveTrue(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  bool resultado = (lista_vacia(lista)? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaNull_SePideLaCantidadDeElementosEnLaLista_DevuelveCero(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  bool resultado = (lista_elementos(lista) == 0? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaNull_SeLaDestruye_NoCausaProblemas(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  lista_destruir(lista);
  printf("%s : PASO\n",__func__);
  return 1;
}

int DadaUnaListaVacia_SeInsertaUnElemento_LoInsertaCorrectamente(){
  printf("%s: ",__func__);
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento = 8;
  bool resultado = (lista_insertar(lista,&elemento) == 0? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaVacia_SePideInsertarUnElementoEnUnaPosicion_LoInsertaEnLaPosicionCero(){
  printf("%s: ",__func__);
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento = 7;
  size_t posicion = 8;
  bool resultado = (lista_insertar_en_posicion(lista,&elemento,posicion) == 0? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaVacia_SePideBorrarUnElemento_DevuelveMenosUno(){
  printf("%s: ",__func__);
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  bool resultado = (lista_borrar(lista) == -1? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaVacia_SePideBorrarUnElementoDeUnaPosicion_DevuelveMenosUno(){
  printf("%s: ",__func__);
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  size_t posicion = 3;
  bool resultado = (lista_borrar_de_posicion(lista,posicion) == -1? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaVacia_SePideElElementoEnUnaPosicion_DevuelveNULL(){
  printf("%s: ",__func__);
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  size_t posicion = 0;
  bool resultado = (lista_elemento_en_posicion(lista,posicion) == NULL? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaVacia_SePideElUltimoElemento_DevuelveNULL(){
  printf("%s: ",__func__);
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  bool resultado = (lista_borrar(lista) == -1? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);

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
  printf("%s: ",__func__);
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  int elemento = 9;
  lista_insertar(lista,&elemento);
  bool resultado = (!lista_vacia(lista));
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaVacia_PidoLaCantidadDeElementos_DevuelveCero(){
  printf("%s: ",__func__);
  lista_t*lista = lista_crear();
  if(lista == NULL){
    printf("Fallo la creacion de la lista para la prueba. Prueba no pasada\n");
    return 0;
  }
  bool resultado = (lista_elementos(lista) == 0? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaVacia_InsertoElementosYpidoLaCantidadDeElementosEnLaLista_DevuelveLaCantidadDeElementosQueInserte(){
  printf("%s: ",__func__);
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
  bool resultado = (lista_elementos(lista) == 3? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SeInsertaUnElemento_LoInsertaAlFinal(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)(lista_ultimo(lista)) == elemento_3? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SeInsertaUnElementoEnUnaPosicionQueExiste_LoInsertaCorrectamente(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)lista_elemento_en_posicion(lista,posicion) == elemento_4? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SePideInsertarUnElementoEnUnaPosicionQueNoExiste_LoInsertaAlFinal(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)lista_ultimo(lista) == elemento_4? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SePideBorrarUnElementoDeUnaPosicionQueNoExiste_BorraElDeLaUltimaPosicion(){
  printf("%s: ",__func__);
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
  bool resultado = (lista_borrar_de_posicion(lista,posicion) == 0 && *(int*)lista_ultimo(lista) == elemento_2? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SePideBorrarUnElementoDeUnaPosicionQueExiste_LoBorraCorrectamente(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)lista_elemento_en_posicion(lista,posicion) == elemento_4? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SePideBorrarUnElemento_BorraElUltimo(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)lista_ultimo(lista) == elemento_3? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SePideElElementoEnUnaPosicionQueNoExiste_DevuelveNULL(){
  printf("%s: ",__func__);
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
  bool resultado = (lista_elemento_en_posicion(lista,posicion) == NULL? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SePideElElementoEnUnaPosicionQueExiste_LoDevuelveCorrectamente(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)lista_elemento_en_posicion(lista,posicion) == elemento_2? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SePideElElementoEnLaUltimaPosicion_LoDevuelveCorrectamente(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)lista_ultimo(lista) == elemento_4? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_LosBorroDeLaListaYPreguntoSiEstaVacia_DevuelveTrue(){
  printf("%s: ",__func__);
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
  bool resultado = lista_vacia(lista);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadaUnaListaConVariosElementos_SeLaDestruye_NoCausaProblemas(){
  printf("%s: ",__func__);
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
  printf("PASO\n");
  return 1;
}

int DadaUnaListaNull_SeIntentaCrearUnIteradorParaLaLista_DevuelveNULL(){
  printf("%s: ",__func__);
  lista_t*lista = NULL;
  lista_iterador_t* iterador = lista_iterador_crear(lista);
  bool resultado = (iterador == NULL? true:false);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorNULL_SePreguntaSiLaListaTieneSiguiente_DevelveFalse(){
  printf("%s: ",__func__);
  lista_iterador_t*iterador = NULL;
  bool resultado = (lista_iterador_tiene_siguiente(iterador) == false? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorDeUnaListaVacia_SePreguntaSiTieneSiguiente_DevuelveFalse(){
  printf("%s: ",__func__);
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
  bool resultado = (lista_iterador_tiene_siguiente(iterador) == false? true:false);
  lista_destruir(lista);
  lista_iterador_destruir(iterador);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorQueApuntaAlPrimerElementoDeUnaListaConVariosElementos_SePreguntaSiTieneSiguiente_Devuelvetrue(){
  printf("%s: ",__func__);
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
  bool resultado = (lista_iterador_tiene_siguiente(iterador) == true? true:false);
  lista_destruir(lista);
  lista_iterador_destruir(iterador);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorQueApuntaAlUltimoElementoDeUnaListaConVariosElementos_SePreguntaSiTieneSiguiente_DevuelveFalse(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)lista_iterador_siguiente(iterador) == elemento_4 && lista_iterador_tiene_siguiente(iterador) == false);
  lista_destruir(lista);
  lista_iterador_destruir(iterador);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorDeUnaListaVacia_SeAvanzaElIteradorAlProximoElementoDeLaLista_DevuelveNull(){
  printf("%s: ",__func__);
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
  bool resultado = (lista_iterador_siguiente(iterador) == NULL? true:false);
  lista_destruir(lista);
  lista_iterador_destruir(iterador);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorNUll_SeAvanzaElIteradorAlProximoElementoDeLaLista_DevuelveNULL(){
  printf("%s: ",__func__);
  lista_iterador_t*iterador = NULL;
  bool resultado = (lista_iterador_siguiente(iterador) == NULL? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorQueApuntaAlPrimerElementoDeUnaListaConVariosElementos_SeAvanzaElIteradorAlProximoElemento_DevuelveElElementoYAvanzaCorrectamente(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)lista_iterador_siguiente(iterador) == elemento_1 && *(int*)lista_iterador_siguiente(iterador) == elemento_2? true:false);
  lista_iterador_destruir(iterador);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorQueApuntaAlUltimoElementoDeUnaListaConVariosElementos_SeAvanzaElIteradorAlProximoElemento_DevuelveElElementoYElSiguienteElementoEsNUll(){
  printf("%s: ",__func__);
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
  bool resultado = (*(int*)lista_iterador_siguiente(iterador) == elemento_4 && lista_iterador_siguiente(iterador) == NULL? true:false);
  lista_iterador_destruir(iterador);
  lista_destruir(lista);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorInicializado_SeLoDestruye_NoCausaProblemas(){
  printf("%s: ",__func__);
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
