#include "biblioteca_pruebas_abb.h"
#include "abb.h"
#include <stdio.h>

/*pre condiciones: la funcion recibe dos punteros void inicilizados
post condiciones: la funcion devuelve 1 si el primer elemento es mayor al segundo, -1 si el primero es menor y cero si son iguales*/
int comparador_de_numeros(void*elemento_1,void*elemento_2){
  if(*(int*)elemento_1 > *(int*)elemento_2){
    return 1;
  }else if(*(int*)elemento_1 < *(int*)elemento_2){
    return -1;
  }else{
    return 0;
  }
}

/*pre condiciones: la funcion recibe una variable bool inicializada
post condiciones: la funcion devuelve 1 si la prueba paso, y cero si no paso*/
int verificar_resultado_prueba(bool resultado){
  if(resultado){
    printf("PASO\n");
    return 1;
  }else{
    printf("FALLO\n");
    return 0;
  }
}

int DadoUnArbolNull_SeIntentaInsertarEnDichoArbol_DevuelveERROR(){
  printf("%s: ",__func__);
  abb_t* arbol = NULL;
  int elemento = 7;
  bool resultado = (arbol_insertar(arbol,&elemento) == ERROR? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolNull_SeIntentaBorrarUnElementoDeDichoArbol_DevuelveERROR(){
  printf("%s: ",__func__);
  abb_t* arbol = NULL;
  int elemento = 7;
  bool resultado = (arbol_borrar(arbol,&elemento) == ERROR? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolNUll_SeIntentaBuscarUnElemento_DevuelveNull(){
  printf("%s: ",__func__);
  abb_t* arbol = NULL;
  int elemento = 7;
  bool resultado = (arbol_buscar(arbol,&elemento) == NULL? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolNull_SePideLaRaiz_DevuelveNull(){
  printf("%s: ",__func__);
  abb_t* arbol = NULL;
  bool resultado = (arbol_raiz(arbol) == NULL? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolNull_SePreguntaSiEstaVacio_DevuelveTrue(){
  printf("%s: ",__func__);
  abb_t* arbol = NULL;
  bool resultado = arbol_vacio(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolNull_SeLoDestruyeNoCausaProblemas(){
  printf("%s: ",__func__);
  abb_t* arbol = NULL;
  arbol_destruir(arbol);
  printf("PASO\n");
  return 1;
}

int DadoUnComparadorNull_SeIntentaCrearUnArbol_DevuelveNull(){
  printf("%s: ",__func__);
  bool resultado = (arbol_crear(NULL,NULL) == NULL? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolVacio_SeIntentaBorrarUnElemento_DevuelveERROR(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elemento = 3;
  bool resultado = (arbol_borrar(arbol,&elemento) == ERROR? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolVacio_SePideLaRaiz_DevuelveNull(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  bool resultado = (arbol_raiz(arbol) == NULL? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolVacio_SeInsertaUnElemento_DevuelveEXITO(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elemento = 9;
  bool resultado = (arbol_insertar(arbol,&elemento) == EXITO? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolConMuchosElementos_SeBorraUnElementoQueEsta_DevuelveEXITO(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {70,45,7,5,21,67,4,9,90,54};
  int elemento_a_borrar = 21;
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  bool resultado = (arbol_borrar(arbol,&elemento_a_borrar) == EXITO? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolConMuchosElementos_SeBuscaUnElementoQueNoEsta_DevuelveNull(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {5,1,3,2,6,7,12,8,9,56};
  int elemento_buscado = 0;
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  bool resultado = (arbol_buscar(arbol,&elemento_buscado) == NULL? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolConMuchosElementos_SeBuscaUnElementoQueEsta_DevuelveElElementoCorrectamente(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {5,1,3,2,6,7,12,8,9,56};
  int elemento_buscado = 1;
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  bool resultado = (*(int*)arbol_buscar(arbol,&elemento_buscado) == elemento_buscado? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolConMuchosElementos_SeIntentaBorrarUnElementoQueNoEsta_DevuelveERROR(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {70,45,7,5,21,67,4,9,90,54};
  int elemento_a_borrar = 1;
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  bool resultado = (arbol_borrar(arbol,&elemento_a_borrar) == ERROR? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolConMuchosElementos_SeIntentaBorrarUnElementoQueEsta_LoBorraCorrectamente(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {70,45,7,5,21,67,4,9,90,54};
  int elemento_a_borrar = 1;
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  arbol_borrar(arbol,&elemento_a_borrar);
  bool resultado = (arbol_buscar(arbol,&elemento_a_borrar) == NULL? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolConMuchosElementos_SeInserta3VecesElMismoElemento_Esta3VecesEnElArbol(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {1,2,4,0,5,5,5,7,8,43};
  int elemento_repetido = 5;
  int cantidad_de_veces_en_el_arbol = 0;
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  while(arbol_buscar(arbol,&elemento_repetido) != NULL){
    cantidad_de_veces_en_el_arbol ++;
    arbol_borrar(arbol,&elemento_repetido);
  }
  bool resultado = (cantidad_de_veces_en_el_arbol == 3? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolConMuchosElementos_SeBorraUnElementoQueEstaDosVeces_TodaviaQuedaUnaVezEseElementoEnElArbol(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {1,2,4,0,3,5,5,7,8,43};
  int elemento_repetido = 5;
  int cantidad_de_veces_en_el_arbol = 0;
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  arbol_borrar(arbol,&elemento_repetido);
  while(arbol_buscar(arbol,&elemento_repetido) != NULL){
    cantidad_de_veces_en_el_arbol ++;
    arbol_borrar(arbol,&elemento_repetido);
  }
  bool resultado = (cantidad_de_veces_en_el_arbol == 1? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolVacio_SeInserta3VecesElMismoElemento_SeInsertanSiempreDelLadoDerechoDelRepetido(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elemento_repetido = 5;
  for(int i = 0;i < 3; i++){
    arbol_insertar(arbol,&elemento_repetido);
  }
  bool resultado = (*(int*)(arbol->nodo_raiz->elemento) == elemento_repetido && *(int*)(arbol->nodo_raiz->derecha->elemento) == elemento_repetido && *(int*)(arbol->nodo_raiz->derecha->derecha->elemento) == elemento_repetido? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolVacio_SeInsertaUnElemento_LoInsertaEnLaRaiz(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elemento = 1;
  arbol_insertar(arbol,&elemento);
  bool resultado = (arbol_raiz(arbol) == &elemento? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolConUnElemento_SeInsertaUnElementoMasChicoYUnoMasGrandeQueElQueYaEstaEnElArbol_ElMasChicoSeInsertaALaIzquierdaYElMasGrandeALaDerecha(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elemento = 2;
  int elemento_menor = 1;
  int elemento_mayor = 3;
  arbol_insertar(arbol,&elemento);
  arbol_insertar(arbol,&elemento_menor);
  arbol_insertar(arbol,&elemento_mayor);
  bool resultado = (arbol->nodo_raiz->derecha->elemento == &elemento_mayor && arbol->nodo_raiz->izquierda->elemento == &elemento_menor? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolVacio_InsertoUnElementoYPreguntoSiEstaVacio_DevuelveFalse(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elemento = 2;
  arbol_insertar(arbol,&elemento);
  bool resultado = (arbol_vacio(arbol) == false? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolNull_SePideElRecorridoInorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = NULL;
  int*array[5] = {0,0,0,0,0};
  bool resultado = (arbol_recorrido_inorden(arbol,(void**)array,5) == 0? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolNull_SePideElRecorridoPostorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = NULL;
  int*array[5] = {0,0,0,0,0};
  bool resultado = (arbol_recorrido_postorden(arbol,(void**)array,5) == 0? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolNull_SePideElRecorridoPreorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = NULL;
  int*array[5] = {0,0,0,0,0};
  bool resultado = (arbol_recorrido_preorden(arbol,(void**)array,5) == 0? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolVacio_SePideElRecorridoInorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int*array[5] = {0,0,0,0,0};
  bool resultado = (arbol_recorrido_inorden(arbol,(void**)array,5) == 0? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolVacio_SePideElRecorridoPostorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int*array[5] = {0,0,0,0,0};
  bool resultado = (arbol_recorrido_postorden(arbol,(void**)array,5) == 0? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolVacio_SePideElRecorridoPreorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int*array[5] = {0,0,0,0,0};
  bool resultado = (arbol_recorrido_preorden(arbol,(void**)array,5) == 0? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArrayNull_SePideElRecorridoInorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  bool resultado = (arbol_recorrido_inorden(arbol,NULL,5) == 0? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArrayNull_SePideElRecorridoPreorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  bool resultado = (arbol_recorrido_preorden(arbol,NULL,5) == 0? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArrayNull_SePideElRecorridoPostorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  bool resultado = (arbol_recorrido_postorden(arbol,NULL,5) == 0? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArrayDeTamanioCero_SePideElRecorridoInorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int*array[10]={0,0,0,0,0,0,0,0,0,0};
  bool resultado = (arbol_recorrido_inorden(arbol,(void**)array,0) == 0? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArrayDeTamanioCero_SePideElRecorridoPreorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int*array[10]={0,0,0,0,0,0,0,0,0,0};
  bool resultado = (arbol_recorrido_preorden(arbol,(void**)array,0) == 0? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArrayDeTamanioCero_SePideElRecorridoPostorden_DevuelveCero(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int*array[10]={0,0,0,0,0,0,0,0,0,0};
  bool resultado = (arbol_recorrido_postorden(arbol,(void**)array,0) == 0? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);

}

int DadoUnArbolCon10Elementos_SePideElRecorridoPreordenConUnArrayDeTamanio5_Devuelve5(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {70,45,7,5,21,67,4,9,90,54};
  int*array[5] = {0,0,0,0,0};
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  bool resultado = (arbol_recorrido_preorden(arbol,(void**)array,5) == 5? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolCon10Elementos_SePideElRecorridoPostordenConUnArrayDeTamanio5_Devuelve5(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {70,45,7,5,21,67,4,9,90,54};
  int*array[5] = {0,0,0,0,0};
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  bool resultado = (arbol_recorrido_postorden(arbol,(void**)array,5) == 5? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolCon10Elementos_SePideElRecorridoInordenConUnArrayDeTamanio5_Devuelve5(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {70,45,7,5,21,67,4,9,90,54};
  int*array[5] = {0,0,0,0,0};
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  bool resultado = (arbol_recorrido_inorden(arbol,(void**)array,5) == 5? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}

int DadoUnArbolCuyaRaizTieneDosHijos_EliminoLaRaiz_LaNuevaRaizEsElMenorDeLosMayores(){
  printf("%s: ",__func__);
  abb_t*arbol = arbol_crear(comparador_de_numeros,NULL);
  if(arbol == NULL){
    printf("Fallo la creacion del arbol para la prueba, prueba no pasada\n");
    return 0;
  }
  int elementos[10] = {1,0,5,15,16,4,2,10,9,89};
  int*menor_de_los_mayores = &elementos[6];
  for(int i = 0;i < 10; i++){
    arbol_insertar(arbol,&elementos[i]);
  }
  arbol_borrar(arbol,arbol->nodo_raiz->elemento);
  bool resultado = (arbol->nodo_raiz->elemento == menor_de_los_mayores? true:false);
  arbol_destruir(arbol);
  return verificar_resultado_prueba(resultado);
}
