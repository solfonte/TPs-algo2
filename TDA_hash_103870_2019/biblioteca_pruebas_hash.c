#include "biblioteca_pruebas_hash.h"
#include "hash.h"
#include "hash_iterador.h"
#include <stdio.h>

extern char* strdup(const char*);


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

int DadaUnaCapacidadMinimaCero_SeIntentaCrearUnHash_DevuelveNULL(){
  bool estado = (hash_crear(NULL,0) == NULL? true:false);
  return verificar_resultado_prueba(estado);
}

int DadoUnHashNULL_SeIntentaInsertarUnElemento_DevuelveERROR(){
  printf("%s: ",__func__);
  hash_t*hash = NULL;
  int elemento = 6;
  const char* clave = "A";
  bool resultado = (hash_insertar(hash,clave,&elemento) == ERROR?true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashNULL_SeIntentaQuitarUnElemento_DevuelveERROR(){
  printf("%s: ",__func__);
  hash_t*hash = NULL;
  const char* clave = "B";
  bool resultado = (hash_quitar(hash,clave) == ERROR?true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashNULL_SeQuiereObtenerUnElemento_DevuelveNULL(){
  printf("%s: ",__func__);
  hash_t*hash = NULL;
  const char* clave = "C";
  bool resultado = (hash_obtener(hash,clave) == NULL?true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashNULL_SePreguntaSiContieneUnElemento_DevuelveFalse(){
  printf("%s: ",__func__);
  hash_t*hash = NULL;
  const char* clave = "A";
  bool resultado = (hash_contiene(hash,clave)?false:true);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashNULL_SePreguntaLaCantidadDeElementos_DevuelveCero(){
  printf("%s: ",__func__);
  hash_t*hash = NULL;
  bool resultado = (hash_cantidad(hash) == 0?true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashVacio_SeQuiereQuitarUnElemento_DevuelveERROR(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  const char* clave = "A";
  bool resultado = (hash_quitar(hash,clave) == ERROR?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashVacio_SeQuiereObtenerUnElemento_DevuelveNULL(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  const char* clave = "G";
  bool resultado = (hash_obtener(hash,clave) == NULL?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashVacio_SePreguntaSiContieneUnElemento_DevuelveFalse(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  const char* clave = "a";
  bool resultado = (hash_contiene(hash,clave)?false:true);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashVacio_SePreguntaLaCantidadDeElementos_DevuelveCero(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  bool resultado = (hash_cantidad(hash) == 0?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);

}

int DadoUnHashVacio_SeIntentaInsertarUnElementoConUnaClaveNULL_DevuelveERROR(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  const char* clave = NULL;
  int elemento = 7;
  bool resultado = (hash_insertar(hash,clave,&elemento) == ERROR?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashConMuchosElementos_SeIntentaQuitarUnElementoConClaveNULL_DevuelveERROR(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  int elementos[10] = {1,2,3,5,6,7,9,34,54,32};
  const char* claves[10] = {"A","B","C","D","E","F","G","H","i","J"};
  const char* clave_no_valida = NULL;
  for(int i = 0; i < 10; i++){
    hash_insertar(hash,claves[i],&elementos[i]);
  }
  bool resultado = (hash_quitar(hash,clave_no_valida) == ERROR?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashConMuchosElementos_SeIntentaObtenerUnElementoConClaveNULL_DevuelveNULL(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  int elementos[10] = {1,2,3,5,6,7,9,34,54,32};
  const char* claves[10] = {"A","B","C","D","E","F","G","H","i","J"};
  const char* clave_no_valida = NULL;
  for(int i = 0; i < 10; i++){
    hash_insertar(hash,claves[i],&elementos[i]);
  }
  bool resultado = (hash_obtener(hash,clave_no_valida) == NULL?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashConMuchosElementos_SePreguntaSiContieneUnElementoConClaveNULL_DevuelveFalse(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  int elementos[10] = {1,2,3,5,6,7,9,34,54,32};
  const char* claves[10] = {"A","B","C","D","E","F","G","H","i","J"};
  const char* clave_no_valida = NULL;
  for(int i = 0; i < 10; i++){
    hash_insertar(hash,claves[i],&elementos[i]);
  }
  bool resultado = (hash_contiene(hash,clave_no_valida)?false:true);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);

}

int DadoUnHashConMuchosElementos_SeIntentaQuitarUnElementoConUnaClaveQueNoEsta_DevuelveERROR(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  int elementos[10] = {1,2,3,5,6,7,9,34,54,32};
  const char* claves[10] = {"A","B","C","D","E","F","G","H","i","J"};
  const char* clave_que_no_esta = "K";
  for(int i = 0; i < 10; i++){
    hash_insertar(hash,claves[i],&elementos[i]);
  }
  bool resultado = (hash_quitar(hash,clave_que_no_esta) == ERROR?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashConMuchosElementos_SeIntentaObtenerUnElementoConUnaCLaveQueNoEsta_DevuelveNULL(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  int elementos[10] = {1,2,3,5,6,7,9,34,54,32};
  const char* claves[10] = {"A","B","C","D","E","F","G","H","i","J"};
  const char* clave_que_no_esta = "K";
  for(int i = 0; i < 10; i++){
    hash_insertar(hash,claves[i],&elementos[i]);
  }
  bool resultado = (hash_obtener(hash,clave_que_no_esta) == NULL?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashConMuchosElementos_SePreguntaSiContieneUnElementoConUnaClaveQueNoEsta_DevuelveFalse(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  int elementos[10] = {1,2,3,5,6,7,9,34,54,32};
  const char* claves[10] = {"A","B","C","D","E","F","G","H","i","J"};
  const char* clave_que_no_esta = "L";
  for(int i = 0; i < 10; i++){
    hash_insertar(hash,claves[i],&elementos[i]);
  }
  bool resultado = (hash_contiene(hash,clave_que_no_esta)?false:true);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);

}

int DadoUnHashVacio_SeInsertanDiezElementosYPreguntoLaCantidadDeElementosEnElHash_DevuelveDiez(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  int elementos[10] = {1,2,3,5,6,7,9,34,54,32};
  const char* claves[10] = {"A","B","C","D","E","F","G","H","i","J"};
  for(int i = 0; i < 10; i++){
    hash_insertar(hash,claves[i],&elementos[i]);
  }
  bool resultado = (hash_cantidad(hash) == 10?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashConDiezElementos_SeQuitanLosDiezElementosYSePreguntaLaCantidad_DevuelveCero(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,5);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  int elementos[10] = {1,2,3,5,6,7,9,34,54,32};
  const char* claves[10] = {"A","B","C","D","E","F","G","H","i","J"};
  for(int i = 0; i < 10; i++){
    hash_insertar(hash,claves[i],&elementos[i]);
  }
  for(int i = 0; i < 10; i++){
    hash_quitar(hash,claves[i]);
  }
  bool resultado = (hash_cantidad(hash) == 0?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashNULL_SeLoDestruyeNoCausaProblemas(){
  printf("%s: ",__func__);
  hash_t* hash = NULL;
  hash_destruir(hash);
  printf("PASO\n");
  return 1;
}

int DadoUnHashNull_SeIntentaCrearUnIteradorParaDichoHash_DevuelveNULL(){
  printf("%s: ",__func__);
  hash_t* hash = NULL;
  bool resultado = (hash_iterador_crear(hash) == NULL? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnHashVacio_SeIntentaCrearUnIteradorParaDichoHash_DevuelveNULL(){
  printf("%s: ",__func__);
  hash_t* hash = hash_crear(NULL,7);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  bool resultado = (hash_iterador_crear(hash) == NULL? true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorNULL_SePreguntaSiTieneSiguiente_Devuelvefalse(){
  printf("%s: ",__func__);
  hash_iterador_t* iterador = NULL;
  bool resultado = (hash_iterador_tiene_siguiente(iterador)? false:true);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorNULL_SeIntentaAvanzarAlSiguienteElemento_DevuelveNULL(){
  printf("%s: ",__func__);
  hash_iterador_t* iterador = NULL;
  bool resultado = (hash_iterador_siguiente(iterador) == NULL? true:false);
  return verificar_resultado_prueba(resultado);
}

int DadoUnIteradorNULL_SeLoDestruye_NoCausaProblemas(){
  printf("%s: ",__func__);
  hash_iterador_t* iterador = NULL;
  hash_iterador_destruir(iterador);
  printf("PASO\n");
  return 1;
}

int DadoUnHashConCapacidadMinimaDos_SeInsertanDiezElementos_LaTablaDeHashSeRedimensionaCorrectamente(){
  printf("%s: ",__func__);
  hash_t*hash = hash_crear(NULL,2);
  if(hash == NULL){
    printf("Fallo la creacion del hash para la prueba. Prueba no pasada.\n");
    return 0;
  }
  int elementos[10] = {1,2,3,5,6,7,9,34,54,32};
  const char* claves[10] = {"A","B","C","D","E","F","G","H","i","J"};
  for(int i = 0; i < 10; i++){
    hash_insertar(hash,claves[i],&elementos[i]);
  }
  bool resultado = (hash_cantidad(hash) == 10 ?true:false);
  hash_destruir(hash);
  return verificar_resultado_prueba(resultado);
}
