#ifndef __BIBLIOTECA_JUEGO_H__
#define __BIBLIOTECA_JUEGO_H__
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define COMANDO_LISTAR 'L'
#define COMANDO_FINALIZAR 'Q'
#define COMANDO_AGREGAR_CASA 'A'
#define COMANDO_INICIAR_SIMULACION 'S'
#define COMANDO_MOSTRAR_CASAS_EXTINTAS 'E'
#define MAX_NOMBRE 50
#define MAX_INTEGRANTES 30
#define ERROR -1
#define EXITO 0

typedef struct juego_de_tronos juego_t;

/*La funcion recibe parametros inicializados.
Ejecuta el comando recibido por parametros. Devuelve EXITO en caso de poder ejecutarlo o ERROR segun el comando que falle*/
int ejecutar_comando(char comando, juego_t*juego_de_tronos);

/*El procedimiento recibe un parametro inicializado.
Le pide un comando al usuario hasta que el ingresado sea valido*/
void pedir_comando(char*comando);

/*La funcion no recibe parametros.
Crea la estructura juego_t* reservando la memoria necesaria. Devuelve un puntero a la estructura o NULL en caso de fallar*/
juego_t*juego_crear();

/*El procedimento recibe un parametro inicializado.
Destruye la memoria reservada para la estructura juego_t */
void juego_destruir(juego_t*juego);

/* El procedimiento recibe un parametro inicializado.
Muestra por pantalla que comando fallo en caso de fallar el programa*/
void mostrar_falla_del_programa(int estado);

#endif /*__BIBLIOTECA_JUEGO_H__*/
