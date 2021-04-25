 #include "biblioteca_juego.h"
#include "abb.h"
#include "cola.h"
#include "lista.h"
#include <string.h>
#define PRIMERO_ES_MAYOR 1
#define PRIMERO_ES_MENOR -1
#define SON_IGUALES 0
#define FORMATO_LECTURA_CARACTER "%c;"
#define FORMATO_LECTURA_CASAS "%[^;];%i;%i\n"
#define FORMATO_LECTURA_INTEGRANTES "%[^;];%i\n"
#define FORMATO_ARCHIVO ".txt"
#define CARACTER_CASA 'C'
#define CARACTER_INTEGRANTE 'I'
#define CANTIDAD_DE_CAMPOS_CASA 3
#define CANTIDAD_DE_CAMPOS_INTEGRANTE 2
#define EDAD_MUERTE 60
#define FORMATO_LECTURA_NOMBRES_NACIDOS "%[^\n]\n"
#define NOMBRE_ARCHIVO_NOMBRES_NACIDOS "nombres.txt"
#define ERROR_AGREGAR_CASAS -7
#define ERROR_DE_SIMULACION -8
#define ERROR_DE_LISTAR -9
#define ERROR_DE_MOSTRAR_CASAS_EXTINTAS -10

typedef struct integrante{
  char nombre[MAX_NOMBRE];
  int edad;
}integrante_t;

typedef struct casa{
  char nombre[MAX_NOMBRE];
  lista_t* integrantes;
  size_t cantidad_de_integrantes;
  int factor_de_envejecimiento;
  int factor_de_nacimiento;
}casa_t;

struct juego_de_tronos{
  abb_t* casas;
  size_t cantidad_de_casas;
  cola_t* casas_extintas;
};

/*La funcion recibe parametros inicializados
Compara las casas recibidos por parametros y devuelve PRIMERO_ES_MAYOR si la primera tiene mas integrantes, PRIMERO_ES_MENOR si la primera tiene menos o SON_IGUALES si tiene igual cantidad*/
int comparador_cant_integrantes_casas(void* casa1,void* casa2){
  if(lista_elementos(((casa_t*)casa1)->integrantes) > lista_elementos(((casa_t*)casa2)->integrantes)){
    return PRIMERO_ES_MAYOR;
  }else if(lista_elementos(((casa_t*)casa1)->integrantes) < lista_elementos(((casa_t*)casa2)->integrantes)){
    return PRIMERO_ES_MENOR;
  }else{
    return SON_IGUALES;
  }
}

/*El procedimiento recibe parametros inicializados.
Le pide al usuario la cantidad de anios que desea simular*/
void pedir_cantidad_de_anios(int* cantidad_de_anios){
  printf("Ingrese una cantidad de anios a simular\n");
  scanf("%i",cantidad_de_anios);
  while(*cantidad_de_anios < 0){
    printf("Reingrese un numero de anios mayor a cero\n");
    scanf("%i",cantidad_de_anios);
  }
}

/*La funcion recibe un parametro inicializado.
Devuelve true en caso de existir el archivo recibido por parametro o false en caso de no existir*/
bool archivo_existe(char nombre[]){
  FILE* archivo = fopen(nombre,"r");
  if(archivo == NULL){
    return false;
  }
  fclose(archivo);
  return true;
}

/*El procedimento recibe un parametro inicializado.
Le pide al usuario el nombre del archivo que contiene las casas que seran utilizadas para simular*/
void pedir_nombre_archivo(char nombre[]){
  printf("Ingrese el nombre del archivo de casas\n");
  scanf("%s",nombre);
  char respuesta;
  if(!archivo_existe(nombre)){
    printf("El archivo ingresado no existe. Si quiere reingresar el nombre del archivo ingrese S o cualquier otra letra para salir\n");
    scanf(" %c",&respuesta);
    if(respuesta == 'S'){
      pedir_nombre_archivo(nombre);
    }
  }
}

/*El procedimento recibe un parametros inicializado.
Destruye la memoria reservada para la lista de integrantes*/
void destruir_lista_integrantes(lista_t*integrantes){
  while(!lista_vacia(integrantes)){
    free(lista_ultimo(integrantes));
    lista_borrar(integrantes);
  }
  lista_destruir(integrantes);
}

/*La funcion recibe parametros inicializados.
Compara las casas recibidas por parametro*/
int comparador_de_nombre_casas(void* casa_1,void*casa_2){
  if(strcmp(((casa_t*)casa_1)->nombre,((casa_t*)casa_2)->nombre) > 0){
    return PRIMERO_ES_MAYOR;
  }else if(strcmp(((casa_t*)casa_1)->nombre,((casa_t*)casa_2)->nombre) < 0){
    return PRIMERO_ES_MENOR;
  }else{
    return SON_IGUALES;
  }
}

/*El procedimiento recibe parametros inicializados.
Destruye la memoria reservada para la cola de casas extintas*/
void destruir_cola_casas_extintas(cola_t* casas_extintas){
  if(casas_extintas == NULL){
    return;
  }
  while(!cola_vacia(casas_extintas)){
    free(cola_primero(casas_extintas));
    cola_desencolar(casas_extintas);
  }
  cola_destruir(casas_extintas);
}

/*El procedimiento recibe parametros inicializados.
Destruye la memoria reservada para las casas*/
void destructor_de_casas(void* casa){
  if(casa == NULL){
    return;
  }
  casa_t* casa_destruir = (casa_t*)casa;
  destruir_lista_integrantes(casa_destruir->integrantes);
  free(casa_destruir);
}

/*La funcion recibe parametros inicializados.
Lee del archivo recibido por parametros y devuelve la cantidad de campos que pudo llenar de la estructura de casa_t */
int leer_casas(FILE* archivo,casa_t* casa){
  return fscanf(archivo,FORMATO_LECTURA_CASAS,casa->nombre,&(casa->factor_de_envejecimiento),&(casa->factor_de_nacimiento));
}

/*La funcion recibe parametros inicializados.
Lee del archivo recibido por parametros y devuelve la cantidad de campos que pudo llenar de la estructura de integrante_t */
int leer_integrante(FILE*archivo,integrante_t*integrante){
  return fscanf(archivo,FORMATO_LECTURA_INTEGRANTES,integrante->nombre,&(integrante->edad));
}

/*La funcion recibe parametros inicializados.
Lee del archivo recibido por parametros y devuelve 1 en caso de haber leido un caracter del archivo o cero si no pudo leer*/
int leer_caracter(FILE* archivo,char*caracter){
  return fscanf(archivo,FORMATO_LECTURA_CARACTER,caracter);
}

/*La funcion no recibe parametros.
Crea a un integrante_t reservando la memoria necesaria para la estructura y devuelve un puntero al mismo.*/
integrante_t* crear_integrante(){
  integrante_t* integrante = (integrante_t*)calloc(1,sizeof(integrante_t));
  if(integrante == NULL){
    return NULL;
  }
  return integrante;
}

/*La funcion no recibe parametros.
Crea a una casa_t reservando la memoria necesaria para la estructura y devuelve un puntero al mismo o NULL en caso de fallar*/
casa_t* crear_casa(){
  casa_t* nueva_casa = (casa_t*)calloc(1,sizeof(casa_t));
  if(nueva_casa == NULL){
    return NULL;
  }
  nueva_casa->integrantes = lista_crear();
  if(nueva_casa->integrantes == NULL){
    free(nueva_casa);
    return NULL;
  }
  return nueva_casa;
}

/*La funcion recibe parametros inicializados.
Guarda una casa del archivo en el arbol de casas del juego y devuelve un puntero de la misma o NULL en caso de que ya exista la casa o de fallar*/
casa_t* guardar_casa(FILE* archivo,abb_t* casas,size_t* cantidad_de_casas){
  casa_t* casa_leida = crear_casa();
  if(casa_leida == NULL){
    return NULL;
  }
  int casas_leidas = leer_casas(archivo,casa_leida);
  if(casas_leidas < CANTIDAD_DE_CAMPOS_CASA){
    destructor_de_casas((void*)casa_leida);
    return  NULL;
  }
  casa_t* casa_actual = (casa_t*)arbol_buscar(casas,(void*)casa_leida);
  if(casa_actual == NULL){
    arbol_insertar(casas,(void*)casa_leida);
    (*cantidad_de_casas)++;
    return casa_leida;
  }else{
    destructor_de_casas((void*)casa_leida);
    return casa_actual;
  }
}

/*La funcion recibe parametros inicializados.
Guarda un integrante leido del archivo en la casa recibida por parametro. Devuelve EXITO si pudo agregarlo o ERROR si no pudo.*/
int guardar_integrante(FILE* archivo,casa_t* casa){
  integrante_t* integrante_leido = crear_integrante();
  if(integrante_leido == NULL){
    return ERROR;
  }
  int integrantes_leido = leer_integrante(archivo,integrante_leido);
  if(integrantes_leido < CANTIDAD_DE_CAMPOS_INTEGRANTE){
    free(integrante_leido);
    return ERROR;
  }
  int estado = lista_insertar(casa->integrantes,(void*)integrante_leido);
  if(estado == ERROR){
    free(integrante_leido);
  }
  return estado;
}

/*La funcion recibe parametros inicializados.
Agrega las casas a la estructura de juego_t. Devuelve ERROR_AGREGAR_CASAS en caso de fallar o EXITO si pudo agregar las casas (comando A)*/
int agregar_casas(juego_t* juego_de_tronos){
  char nombre_archivo[MAX_NOMBRE] = {0};
  pedir_nombre_archivo(nombre_archivo);
  FILE* archivo_casas = fopen(nombre_archivo,"r");
  if(archivo_casas == NULL){
    printf("Error al abrir el archivo\n");
    return ERROR-ERROR_AGREGAR_CASAS;
  }
  bool fallo = false;
  char caracter_leido = '0';
  casa_t* casa_leida = NULL;
  int caracteres_leidos = leer_caracter(archivo_casas,&caracter_leido);
  while(!fallo && caracteres_leidos > 0){
    if(caracter_leido == CARACTER_CASA){
      casa_leida = guardar_casa(archivo_casas,juego_de_tronos->casas,&(juego_de_tronos->cantidad_de_casas));
      fallo = (casa_leida == NULL?true:false);
      caracteres_leidos = leer_caracter(archivo_casas,&caracter_leido);
    }else if(caracter_leido == CARACTER_INTEGRANTE){
      fallo = (guardar_integrante(archivo_casas,casa_leida) == ERROR? true:false);
      caracteres_leidos = leer_caracter(archivo_casas,&caracter_leido);
    }else{
      fallo = true;
    }
  }
  fclose(archivo_casas);
  printf("Se agregaron las casas con exito.\n");
  return (fallo? ERROR_AGREGAR_CASAS:EXITO);
}

/*La funcion recibe parametros inicializados.
Asigna un nombre al recien nacido dentro de una casa. Devuelve ERROR en caso de fallar y sino EXITO*/
int nombrar_recien_nacido(FILE* archivo,char nombre[]){
  return fscanf(archivo,FORMATO_LECTURA_NOMBRES_NACIDOS,nombre);
}

/*La funcion recibe parametros inicializados.
verifica los nacimientos de los integrantes recibidos por parametros. Devuelve ERROR en caso de fallar y sino EXITO*/
int verificar_nacimientos(lista_t* integrantes,int factor_de_nacimiento){
  int cantidad_a_nacer = ((int)lista_elementos(integrantes)/factor_de_nacimiento);
  bool fallo = false;
  int contador_de_nacidos = 0;
  integrante_t* nuevo_integrante = NULL;
  FILE* archivo_nombres = fopen(NOMBRE_ARCHIVO_NOMBRES_NACIDOS,"r");
  if(archivo_nombres == NULL){
    return ERROR;
  }
  while(contador_de_nacidos < cantidad_a_nacer && !fallo){
    nuevo_integrante = crear_integrante();
    if(nuevo_integrante == NULL){
      fallo = true;
    }else{
      fallo = (nombrar_recien_nacido(archivo_nombres,nuevo_integrante->nombre) < 1? true:false);
      lista_insertar(integrantes,(void*)nuevo_integrante);
      if(feof(archivo_nombres)){
        fclose(archivo_nombres);
        archivo_nombres = fopen(NOMBRE_ARCHIVO_NOMBRES_NACIDOS,"r");
        fallo = (archivo_nombres == NULL? true:false);
      }
    }
    contador_de_nacidos++;
  }
  fclose(archivo_nombres);
  return (fallo? ERROR:EXITO);
}

/*La funcion recibe parametros inicializados.
Verifica las muertes de los integrantes recibidos por parametros. Devuelve ERROR en caso de fallar y sino EXITO*/
int verificar_muertes(lista_t* integrantes,int factor_de_envejecimiento){
  if(integrantes == NULL){
    return ERROR;
  }
  integrante_t* integrante_actual;
  size_t posicion_actual = 0;
  bool fallo = false;
  while(posicion_actual < lista_elementos(integrantes) && !fallo){
    integrante_actual = (integrante_t*)lista_elemento_en_posicion(integrantes,posicion_actual);
    if(integrante_actual == NULL){
      fallo =  true;
    }else{
      integrante_actual->edad += factor_de_envejecimiento;
    }
    if(integrante_actual->edad >= EDAD_MUERTE && !fallo){
      free(lista_elemento_en_posicion(integrantes,posicion_actual));
      fallo = (lista_borrar_de_posicion(integrantes,posicion_actual) == ERROR? true:false);
    }else{
      posicion_actual++;
    }
  }
  return (fallo? ERROR:EXITO);
}

/*La funcion recibe parametros inicializados.
Actualiza los integrantes de las casas recursivamente con el paso de los anios ingresados por el usuario para la simulacion. Devuelve ERROR en caso de fallar y sino EXITO*/
int actualizar_integrantes_rec(casa_t*casa,int anios_transcurridos,int anios_totales,bool fallo){
  if(anios_transcurridos == anios_totales || fallo){
    return (fallo? ERROR:EXITO);
  }
   fallo = (verificar_muertes(casa->integrantes,casa->factor_de_envejecimiento) == ERROR? true:false);
   if(!fallo){
     fallo = (verificar_nacimientos(casa->integrantes,casa->factor_de_nacimiento) == ERROR? true:false);
   }
  return actualizar_integrantes_rec(casa,anios_transcurridos+1,anios_totales,fallo);
}

/*La funcion recibe parametros inicializados.
Actualiza los integrantes de las casas con el paso de los anios ingresados por el usuario para la simulacion. Devuelve ERROR en caso de fallar y sino EXITO*/
int actualizar_integrantes(casa_t*casa,int cantidad_de_anios){
  return actualizar_integrantes_rec(casa,0,cantidad_de_anios,false);
}

/*La funcion recibe un parametro inicializado.
Devuelve true si la casa  recibida por parametros esta extinta o false en caso contrario*/
bool casa_esta_extinta(casa_t* casa){
  return lista_vacia(casa->integrantes);
}

/*La funcion recibe parametros inicializados.
Guarda la la casa recibida por parametros en la cola de casas extintas. Devuelve ERROR en caso de fallar y sino EXITO*/
int guardar_casa_extinta(cola_t* casas_extintas,casa_t* casa_extinta){
  char* nombre_casa_extinta = (char*)malloc(sizeof(char)*MAX_NOMBRE);
  if(nombre_casa_extinta == NULL){
    return ERROR;
  }
  strcpy(nombre_casa_extinta,casa_extinta->nombre);
  return cola_encolar(casas_extintas,(void*)nombre_casa_extinta);
}

/*La funcion recibe parametros inicializados.
Guarda las casas recibidas por parametros en un Array. Devuelve el puntero a dicho array o NULL en caso de fallar*/
void** guardar_casas_array(abb_t* casas,size_t cantidad_de_casas){
  void** array_de_casas = calloc(1,sizeof(void*)*cantidad_de_casas);
  if(array_de_casas == NULL){
    return NULL;
  }
  int estado = arbol_recorrido_inorden(casas,array_de_casas,(int)(cantidad_de_casas));
  if(estado == ERROR){
    return NULL;
  }
  return array_de_casas;
}

/*La funcion recibe parametros inicializados.
La funcion devuelve true si la casa actual tiene mas integrantes que la casa que se hallaba en el trono previamente*/
bool nueva_casa_con_mas_integrantes(casa_t* casa_en_el_trono,casa_t* casa_actual){
  return (lista_elementos(casa_en_el_trono->integrantes) < lista_elementos(casa_actual->integrantes));
}

/*El procedimiento recibe parametros inicializados.
Muestra la casa que se halla en el trono luego de la simulacion*/
void mostrar_casa_en_el_trono(casa_t* casa_en_el_trono,int cantidad_de_anios){
  if(casa_en_el_trono == NULL){
    printf("No hay casas en el trono luego de %i anios\n",cantidad_de_anios);
    return;
  }
  printf("Luego de %i anios, la casa en el trono es: %s\n",cantidad_de_anios,casa_en_el_trono->nombre);
}

/*La funcion recibe parametros inicializados.
Devuelve la casa en el trono luego del paso de los anios pedidos al usuario. Devuelve ERROR_DE_SIMULACION en caso de fallar y sino EXITO (comando S)*/
int iniciar_simulacion(juego_t* juego_de_tronos){
  if(juego_de_tronos == NULL){
    return ERROR_DE_SIMULACION;
  }
  if(arbol_vacio(juego_de_tronos->casas)){
    printf("Ejecute el comando 'A' para agregar casas.\n");
    return EXITO;
  }
  int cantidad_de_anios = 0,i = 0;
  casa_t* casa_en_el_trono = NULL;
  bool fallo = false;
  pedir_cantidad_de_anios(&cantidad_de_anios);
  void** array_de_casas = guardar_casas_array(juego_de_tronos->casas,juego_de_tronos->cantidad_de_casas);
  if(array_de_casas == NULL){
    return ERROR_DE_SIMULACION;
  }
  size_t cantidad_casas_extintas = 0;
  while(i < juego_de_tronos->cantidad_de_casas && !fallo){
    fallo = (actualizar_integrantes((casa_t*)array_de_casas[i],cantidad_de_anios) == ERROR? true:false);
    if(casa_esta_extinta(array_de_casas[i]) && !fallo){
      fallo = (guardar_casa_extinta(juego_de_tronos->casas_extintas,(casa_t*)array_de_casas[i]) == ERROR? true:false);
      if(!fallo){
        fallo = (arbol_borrar(juego_de_tronos->casas,array_de_casas[i]) == ERROR?true:false);
        cantidad_casas_extintas++;
      }
    }else if((casa_en_el_trono == NULL || nueva_casa_con_mas_integrantes(casa_en_el_trono,(casa_t*)array_de_casas[i])) && !fallo){
      casa_en_el_trono = (casa_t*)array_de_casas[i];
    }
    i++;
  }
  juego_de_tronos->cantidad_de_casas = juego_de_tronos->cantidad_de_casas - cantidad_casas_extintas;
  mostrar_casa_en_el_trono(casa_en_el_trono,cantidad_de_anios);
  free(array_de_casas);
  return (fallo? ERROR_DE_SIMULACION:EXITO);
}

/*El procedimiento recibe parametros inicializados.
Imprime el array recibido por parametros de manera recursiva*/
void imprimir_array_rec(void** array_de_casas,size_t cantidad_de_casas,size_t contador){
  if(contador == cantidad_de_casas){
    return;
  }
  printf("%s\n",((casa_t*)array_de_casas[contador])->nombre);
  imprimir_array_rec(array_de_casas,cantidad_de_casas,contador+1);
}

/*El procedimiento recibe parametros inicializados.
Imprime el array recibido por parametros*/
void imprimir_array(void** array_de_casas,size_t cantidad_de_casas){
  printf("Las casas en orden descendente segun la cantidad de integrantes es:\n");
  imprimir_array_rec(array_de_casas, cantidad_de_casas,0);
}

/*El procedimiento recibe parametros inicializados.
Ordena la porcion de array recibida por parametros*/
void merge(void** array_de_casas,int inicio1, int fin1, int fin2, int (*comparador_cant_integrantes_casas)(void*, void*)){
  int inicio2=fin1+1;
  while(inicio1<=fin1 && inicio2 <= fin2){
    if(comparador_cant_integrantes_casas(array_de_casas[inicio1], array_de_casas[inicio2]) == PRIMERO_ES_MAYOR){
      inicio1++;
    }else{
      void* aux = array_de_casas[inicio2];
      for(int i=inicio2;i > inicio1;i--)
	     array_de_casas[i] = array_de_casas[i-1];
       array_de_casas[inicio1] = aux;
       inicio1++;
       inicio2++;
       fin1++;
    }
  }
}

/*El procedimiento recibe parametros inicializados
Ordena el array recibido por parametros recursivamente mediante el algoritmo de mergesort*/
void merge_sort_rec(void** array_de_casas,int inicio, int fin, int (*comparador_cant_integrantes_casas)(void*, void*)){
  if(inicio==fin)
    return;
  int medio = (fin+inicio)/2;
  merge_sort_rec(array_de_casas, inicio, medio, comparador_cant_integrantes_casas);
  merge_sort_rec(array_de_casas, medio+1, fin, comparador_cant_integrantes_casas);
  merge(array_de_casas, inicio, medio, fin, comparador_cant_integrantes_casas);
}

/*El procedimiento recibe parametros inicializados
Ordena el array recibido por parametros mediante el algoritmo de mergesort*/
void merge_sort(void** array_de_casas,int cantidad_de_casas, int (*comparador_cant_integrantes_casas)(void*, void*)){
  merge_sort_rec(array_de_casas, 0, cantidad_de_casas-1, comparador_cant_integrantes_casas);
}

/*La funcion recibe parametros inicializados.
Ordena ordena el array recibido por parametros segun cantidad de integrantes en orden descendente. Devuelve ERROR en caso de fallar y sino EXITO*/
int ordenar_segun_integrantes_descendentemente(void** array_de_casas,int cantidad_de_casas){
  if(array_de_casas == NULL){
    return ERROR;
  }
  merge_sort(array_de_casas, cantidad_de_casas,comparador_cant_integrantes_casas);
  return EXITO;
}

/*La funcion recibe parametros inicializados.
mustra las casas por pantalla en orden segun cantidad de integrantes. Devuelve ERROR_DE_LISTAR en caso de fallar y sino EXITO (comando L)*/
int listar_casas(abb_t* casas,size_t cantidad_de_casas){
  if(casas == NULL){
    return ERROR_DE_LISTAR;
  }
  bool fallo = false;
  void**array_de_casas = guardar_casas_array(casas,cantidad_de_casas);
  if(array_de_casas == NULL){
    return ERROR_DE_LISTAR;
  }
  fallo = (ordenar_segun_integrantes_descendentemente(array_de_casas,(int)cantidad_de_casas) == ERROR? true:false);
  imprimir_array(array_de_casas,cantidad_de_casas);
  free(array_de_casas);
  return (fallo? ERROR_DE_LISTAR:EXITO);
}

/*La funcion recibe parametros inicializados.
Muestra las casas extintas en orden en que fueron desaparenciendo. Devuelve ERROR_DE_MOSTRAR_CASAS_EXTINTAS en caso de fallar y sino EXITO (comando E)*/
int mostrar_casas_extintas(cola_t* casas_extintas,int cantidad_de_casas_extintas){
  if(casas_extintas == NULL){
    return ERROR_DE_MOSTRAR_CASAS_EXTINTAS;
  }
  if(cola_vacia(casas_extintas)){
    printf("No hay casas extintas\n");
    return EXITO;
  }
  while(!cola_vacia(casas_extintas)){
    printf("%s\n",(char*)cola_primero(casas_extintas));
    free(cola_primero(casas_extintas));
    cola_desencolar(casas_extintas);
  }
  return EXITO;
}

/*El procedimiento no recibe parametros.
Muestra por pantalla la informacion acerca de los comandos ejecutables dentro del programa*/
void imprimir_informacion(){
  printf("Para iniciar la simulacion ingrese: S\n");
  printf("Para agregar una casa la simulacion igrese: A\n");
  printf("Para listar las casas por cantidad de integrantes en orden descendente ingrese: L\n");
  printf("Para mostrar las casas extintas en el orden en el que fueron desapareciendo ingrese: E\n");
  printf("Para finalizar la ejecucion del programa ingrese: Q\n");
}

/*La funcion recibe un parametro inicializado.
La funcion devuelve true si el comando ingresado es valido o false si no lo es*/
bool comando_es_valido(char comando){
  return (comando == COMANDO_AGREGAR_CASA || comando == COMANDO_INICIAR_SIMULACION || comando == COMANDO_LISTAR || comando == COMANDO_MOSTRAR_CASAS_EXTINTAS || comando == COMANDO_FINALIZAR);
}

int ejecutar_comando(char comando,juego_t*juego_de_tronos){
  int estado = 0;
  switch(comando){
    case COMANDO_LISTAR:
    estado = listar_casas(juego_de_tronos->casas,juego_de_tronos->cantidad_de_casas);
    break;
    case COMANDO_AGREGAR_CASA:
    estado = agregar_casas(juego_de_tronos);
    break;
    case COMANDO_INICIAR_SIMULACION:
    estado = iniciar_simulacion(juego_de_tronos);
    break;
    case COMANDO_MOSTRAR_CASAS_EXTINTAS:
    estado = mostrar_casas_extintas(juego_de_tronos->casas_extintas,cola_cantidad(juego_de_tronos->casas_extintas));
  }
  return estado;
}

void pedir_comando(char*comando){
  do{
    imprimir_informacion();
    scanf(" %c",comando);
  }while(!comando_es_valido(*comando));
}

juego_t*juego_crear(){
  juego_t* juego = (juego_t*)calloc(1,sizeof(juego_t));
  if(juego == NULL){
    return NULL;
  }
  juego->casas = arbol_crear(comparador_de_nombre_casas,destructor_de_casas);
  if(juego->casas == NULL){
    free(juego);
    return NULL;
  }
  juego->casas_extintas = cola_crear();
  if(juego->casas_extintas == NULL){
    arbol_destruir(juego->casas);
    free(juego);
    return NULL;
  }
  return juego;
}

void juego_destruir(juego_t*juego){
  if(juego == NULL){
    return;
  }
  arbol_destruir(juego->casas);
  destruir_cola_casas_extintas(juego->casas_extintas);
  free(juego);
}

void mostrar_falla_del_programa(int estado){
  switch(estado){
    case ERROR_DE_LISTAR:
      printf("Fallo el comando listar\n");
      break;
    case ERROR_DE_SIMULACION:
      printf("Fallo la simulacion\n");
      break;
    case ERROR_DE_MOSTRAR_CASAS_EXTINTAS:
      printf("Fallo el comando que muestra las casas extintas\n");
      break;
    case ERROR_AGREGAR_CASAS:
      printf("Fallo el comando que agrega las casas\n");
      break;
  }
}
