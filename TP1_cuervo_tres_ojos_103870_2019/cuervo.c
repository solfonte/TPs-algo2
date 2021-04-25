#include "cuervo_tres_ojos.h"
#include <stdio.h>
#include <string.h>
#define EXITO 0
#define FORMATO_LECTURA "%[^;];%[^;];%[^;];%c\n"
#define NOMBRE_ARCHIVO_VISIONES "visiones.txt"
#define NOMBRE_CUERVO_VIEJO "Cuervo Misterioso"
#define NOMBRE_CUERVO_APRENDIZ "Bran Stark"
#define VISION_PASADO 'P'
#define VISION_FUTURO 'F'
#define ERROR -1
/*pre condiciones: la funcion recibe un puntero a un archvivo abierto y un puntero a un struct de visiones sin inicializar
post condiciones: la funcion devuelve la cantidad de visiones leidas del archivo e inicializa el struct de visiones*/
int leer_vision(FILE*archivo_visiones,vision_t*vision){
  return fscanf(archivo_visiones,FORMATO_LECTURA,vision->protagonista,vision->casa_protagonista,vision->descripcion,&vision->epoca);
}
/*pre condiciones: la funcion recibe un puntero a un archivo abierto y puntero a un struct de cuervo de tres ojos inicializado
post condiciones: la funcion devuelve 0 si pudo agregar todas las visiones del archivo y -1 si ocurrio un error de memoria*/
int agregar_visiones(FILE*archivo,cuervo_tres_ojos_t* cuervo){
  vision_t vision;
  int visiones_leidas = leer_vision(archivo,&vision);
  int resultado_vision;
  while(visiones_leidas > 0){
    resultado_vision = agregar_vision(cuervo,vision);
    if(resultado_vision == ERROR){
      return ERROR;
    }
    visiones_leidas = leer_vision(archivo,&vision);
  }
  return EXITO;
}
/*pre condiciones: la funcion recibe un struct de vision inicializado
post condiciones: la funcion devuelve true si la descripcion tiene mas de 20 caracteres*/
bool vision_tiene_mas_de_20_caracteres(vision_t vision){
  if(strlen(vision.descripcion) > 20){
    return true;
  }else{
    return false;
  }
}
/*pre condiciones: la funcion recibe un struct de vision inicializado
post condiciones: la funcion devuelve true si el protagonista de la vision es Jon Snow*/
bool es_vision_de_jon(vision_t vision){
  if(strcmp(vision.protagonista,"Jon Snow") == 0){
    return true;
  }else{
    return false;
  }
}
/*precondiciones: la funcion recibe un struct de vision inicializado
postcondiciones: la funcion devuelve true si la vision es del pasado*/
bool es_vision_pasada(vision_t vision){
  if(vision.epoca == VISION_PASADO){
    return true;
  }else{
    return false;
  }
}
/*precondiciones: la funcion recibe un struct de vision inicializado
postcondiciones: la funcion devuelve true si la vision es del futuro*/
bool es_vision_futura(vision_t vision){
  if(vision.epoca == VISION_FUTURO){
    return true;
  }else{
    return false;
  }
}

int main(){
  FILE*archivo_visiones = fopen(NOMBRE_ARCHIVO_VISIONES,"r");
  if(archivo_visiones == NULL){
    printf("No se pudo abrir el archivo de visiones\n");
    return ERROR;
  }
  cuervo_tres_ojos_t* cuervo_viejo;
  cuervo_aprendiz_t* cuervo_aprendiz;
  int resultado = ERROR;
  cuervo_viejo = invocar_cuervo(NOMBRE_CUERVO_VIEJO);
  cuervo_aprendiz = invocar_aprendiz(NOMBRE_CUERVO_APRENDIZ);
  if(cuervo_viejo != NULL && cuervo_aprendiz != NULL){
    resultado = agregar_visiones(archivo_visiones,cuervo_viejo);
  }
  fclose(archivo_visiones);
  if(resultado != ERROR){
    resultado = transmitir_visiones(cuervo_viejo,cuervo_aprendiz,es_vision_pasada);
  }
  if(resultado != ERROR){
    resultado = transmitir_visiones(cuervo_viejo,cuervo_aprendiz,vision_tiene_mas_de_20_caracteres);
  }
  if(resultado != ERROR){
    resultado = transmitir_visiones(cuervo_viejo,cuervo_aprendiz,es_vision_de_jon);
  }
  if(resultado != ERROR){
    listar_visiones_transmitidas(*cuervo_aprendiz,es_vision_futura);
  }
  resultado = destruir_cuervo(cuervo_viejo);
  if(resultado == ERROR){
    printf("ocurrio un error al liberar el cuervo de tres ojos\n");
  }
  resultado = destruir_aprendiz(cuervo_aprendiz);
  if(resultado == ERROR){
    printf("ocurrio un error al liberar el cuervo aprendiz\n");
  }
  return 0;
}
