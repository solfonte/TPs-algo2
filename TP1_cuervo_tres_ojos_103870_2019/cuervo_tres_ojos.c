#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "cuervo_tres_ojos.h"
#define VISION_PASADO 'P'
#define VISION_FUTURO 'F'
#define CANTIDAD_CUERVOS 1
#define CANTIDAD_APRENDICES 1
#define ERROR -1
#define EXITO 0

cuervo_tres_ojos_t* invocar_cuervo(char*nombre){
  cuervo_tres_ojos_t*cuervo_viejo;
  cuervo_viejo = (cuervo_tres_ojos_t*)calloc(CANTIDAD_CUERVOS,sizeof(cuervo_tres_ojos_t));
  if(cuervo_viejo == NULL){
    return NULL;
  }
  strcpy(cuervo_viejo->nombre,nombre);
  return cuervo_viejo;
}
cuervo_aprendiz_t* invocar_aprendiz(char*nombre){
  cuervo_aprendiz_t*cuervo_nuevo;
  cuervo_nuevo = (cuervo_aprendiz_t*)calloc(CANTIDAD_APRENDICES,sizeof(cuervo_aprendiz_t));
  if(cuervo_nuevo == NULL){
    return NULL;
  }
  strcpy(cuervo_nuevo->nombre,nombre);
  return cuervo_nuevo;
}
int agregar_vision(cuervo_tres_ojos_t* cuervo, vision_t vision){
  vision_t*vision_aux;
  if(vision.epoca == VISION_PASADO){
    vision_aux = (vision_t*)realloc(cuervo->visiones_del_pasado,sizeof(vision_t)*(long unsigned int)(cuervo->cantidad_visiones_pasado+1));
    if(vision_aux != NULL){
      cuervo->visiones_del_pasado = vision_aux;
      cuervo->visiones_del_pasado[cuervo->cantidad_visiones_pasado] = vision;
      cuervo->cantidad_visiones_pasado++;
      return EXITO;
    }
  }else if(vision.epoca == VISION_FUTURO){
    vision_aux = (vision_t*)realloc(cuervo->visiones_del_futuro,sizeof(vision_t)*(long unsigned int)(cuervo->cantidad_visiones_futuro+1));
    if(vision_aux != NULL){
      cuervo->visiones_del_futuro = vision_aux;
      cuervo->visiones_del_futuro[cuervo->cantidad_visiones_futuro] = vision;
      cuervo->cantidad_visiones_futuro++;
      return EXITO;
    }
  }
  return -1;
}
/*pre condiciones: la funcion recibe dos registros de visiones inicializados
post condiciones: la funcion devuelve true si los registros son iguales*/
bool visiones_son_iguales(vision_t vision,vision_t vision_aprendiz){
  if((strcmp(vision.protagonista,vision_aprendiz.protagonista) == 0) && (strcmp(vision.casa_protagonista,vision_aprendiz.casa_protagonista) == 0) && (strcmp(vision.descripcion,vision_aprendiz.descripcion) == 0) && (vision.epoca == vision_aprendiz.epoca)){
    return true;
  }else{
    return false;
  }
}
/*pre condiciones: funcion que recibe un registro de vision inicializadao y un puntero a un registro de aprendiz inicializado
post condiciones: la funcion devuelve true si la vision recibida por parametro esta en el vector de visiones del aprendiz*/
bool vision_fue_adquirida(vision_t vision,cuervo_aprendiz_t*aprendiz){
  bool encontre = false;
  int i = 0;
  while(i < aprendiz->cantidad_visiones && !encontre){
    if(visiones_son_iguales(vision,aprendiz->visiones_adquiridas[i])){
      encontre = true;
    }
    i++;
  }
  return encontre;
}
/*pre condiciones: funcion que recibe un registro de vision inicializado y un puntero a un registro de aprendiz inicializado
post condiciones: la funcion devuelve -1 si no la pudo transmitir */
int transmitir_vision(vision_t vision,cuervo_aprendiz_t*aprendiz){
  vision_t*vision_aux;
  if(!vision_fue_adquirida(vision,aprendiz)){
    vision_aux = (vision_t*)realloc(aprendiz->visiones_adquiridas,sizeof(vision_t)*(long unsigned int)(aprendiz->cantidad_visiones+1));
    if(vision_aux == NULL){
      return ERROR;
    }
    aprendiz->visiones_adquiridas = vision_aux;
    aprendiz->visiones_adquiridas[aprendiz->cantidad_visiones] = vision;
    aprendiz->cantidad_visiones++;
  }
  return EXITO;
}
int transmitir_visiones(cuervo_tres_ojos_t* cuervo, cuervo_aprendiz_t* aprendiz, bool (*es_transmisible)(vision_t)){
  int i = 0,j = 0;
  int resultado_operacion;
  while(i < cuervo->cantidad_visiones_pasado){
    if(es_transmisible(cuervo->visiones_del_pasado[i])){
      resultado_operacion = transmitir_vision(cuervo->visiones_del_pasado[i],aprendiz);
      if(resultado_operacion == ERROR){
        return ERROR;
      }
    }
    i++;
  }
  while(j < cuervo->cantidad_visiones_futuro){
    if(es_transmisible(cuervo->visiones_del_futuro[j])){
      resultado_operacion = transmitir_vision(cuervo->visiones_del_futuro[j],aprendiz);
      if(resultado_operacion == -1){
        return -1;
      }
    }
    j++;
  }
  return EXITO;
}
void listar_visiones_transmitidas(cuervo_aprendiz_t aprendiz, bool (*es_listable)(vision_t)){
  int i = 0;
  while(i < aprendiz.cantidad_visiones){
    if(es_listable(aprendiz.visiones_adquiridas[i])){
      printf("Vision sobre %s: %s\n", aprendiz.visiones_adquiridas[i].protagonista,aprendiz.visiones_adquiridas[i].descripcion);
    }
    i++;
  }
}
int destruir_cuervo(cuervo_tres_ojos_t* cuervo){
  if(cuervo == NULL){
    return ERROR;
  }else{
    if(cuervo->visiones_del_pasado != NULL){
      free(cuervo->visiones_del_pasado);
    }
    if(cuervo->visiones_del_futuro != NULL){
      free(cuervo->visiones_del_futuro);
    }
    free(cuervo);
    return EXITO;
  }
}
int destruir_aprendiz(cuervo_aprendiz_t* aprendiz){
  if(aprendiz == NULL){
    return ERROR;
  }else{
    if(aprendiz->visiones_adquiridas != NULL){
      free(aprendiz->visiones_adquiridas);
    }
    free(aprendiz);
    return EXITO;
  }
}
