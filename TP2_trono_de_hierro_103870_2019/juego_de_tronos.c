#include "biblioteca_juego.h"

int main() {
  printf("Bienvenido a la simulacion del juego de tronos\n");
  char comando = 'P';
  int estado = EXITO;
  juego_t* juego_de_tronos = juego_crear();
  if(juego_de_tronos == NULL){
    printf("ERROR: no se pudo realizar la simulacion\n");
    return 0;
  }
  pedir_comando(&comando);
  while(comando != COMANDO_FINALIZAR && estado == EXITO){
    estado = ejecutar_comando(comando,juego_de_tronos);
    if(estado == EXITO){
      pedir_comando(&comando);
    }
  }
  if(estado != EXITO){
    mostrar_falla_del_programa(estado);
  }
  juego_destruir(juego_de_tronos);
  return 0;
}
