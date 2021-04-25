#include "biblioteca_pruebas_lista.h"
#include <stdio.h>

int main() {
  int pruebas_totales = 39;
  int pruebas_pasadas = 0;
  pruebas_pasadas += DadaUnaListaNull_SeIntentaInsertar_DevuelveMenosUno();
  pruebas_pasadas += DadaUnaListaNull_SeIntentaInsertarEnUnaPosicion_DevuelveMenosUno();
  pruebas_pasadas += DadaUnaListaNull_SeIntentaBorrar_DevuelveMenosUno();
  pruebas_pasadas += DadaUnaListaNull_SeIntentaBorrarDeUnaPosicion_DevuelveMenosUno();
  pruebas_pasadas += DadaUnaListaNull_SepideElUltimoElemento_DevuelveNULL();
  pruebas_pasadas += DadaUnaListaNull_SePideElElementoEnUnaPosicion_DevuelveNULL();
  pruebas_pasadas += DadaUnaListaNull_SePreguntaSiEstaVacia_DevuelveTrue();
  pruebas_pasadas += DadaUnaListaNull_SePideLaCantidadDeElementosEnLaLista_DevuelveCero();
  pruebas_pasadas += DadaUnaListaNull_SeLaDestruye_NoCausaProblemas();
  pruebas_pasadas += DadaUnaListaVacia_SeInsertaUnElemento_LoInsertaCorrectamente();
  pruebas_pasadas += DadaUnaListaVacia_SePideInsertarUnElementoEnUnaPosicion_LoInsertaEnLaPosicionCero();
  pruebas_pasadas += DadaUnaListaVacia_SePideBorrarUnElemento_DevuelveMenosUno();
  pruebas_pasadas += DadaUnaListaVacia_SePideBorrarUnElementoDeUnaPosicion_DevuelveMenosUno();
  pruebas_pasadas += DadaUnaListaVacia_SePideElElementoEnUnaPosicion_DevuelveNULL();
  pruebas_pasadas += DadaUnaListaVacia_SePideElUltimoElemento_DevuelveNULL();
  pruebas_pasadas += DadaUnaListaVacia_InsertoUnElementoYPreguntoSiLaListaEstaVacia_DevuelveFalse();
  pruebas_pasadas += DadaUnaListaVacia_PidoLaCantidadDeElementos_DevuelveCero();
  pruebas_pasadas += DadaUnaListaVacia_InsertoElementosYpidoLaCantidadDeElementosEnLaLista_DevuelveLaCantidadDeElementosQueInserte();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SeInsertaUnElemento_LoInsertaAlFinal();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SeInsertaUnElementoEnUnaPosicionQueExiste_LoInsertaCorrectamente();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SePideInsertarUnElementoEnUnaPosicionQueNoExiste_LoInsertaAlFinal();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SePideBorrarUnElementoDeUnaPosicionQueNoExiste_BorraElDeLaUltimaPosicion();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SePideBorrarUnElementoDeUnaPosicionQueExiste_LoBorraCorrectamente();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SePideBorrarUnElemento_BorraElUltimo();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SePideElElementoEnUnaPosicionQueNoExiste_DevuelveNULL();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SePideElElementoEnUnaPosicionQueExiste_LoDevuelveCorrectamente();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SePideElElementoEnLaUltimaPosicion_LoDevuelveCorrectamente();
  pruebas_pasadas += DadaUnaListaConVariosElementos_LosBorroDeLaListaYPreguntoSiEstaVacia_DevuelveTrue();
  pruebas_pasadas += DadaUnaListaConVariosElementos_SeLaDestruye_NoCausaProblemas();
  pruebas_pasadas += DadoUnIteradorNULL_SePreguntaSiLaListaTieneSiguiente_DevelveFalse();
  pruebas_pasadas += DadoUnIteradorDeUnaListaVacia_SePreguntaSiTieneSiguiente_DevuelveFalse();
  pruebas_pasadas += DadoUnIteradorQueApuntaAlPrimerElementoDeUnaListaConVariosElementos_SePreguntaSiTieneSiguiente_Devuelvetrue();
  pruebas_pasadas += DadoUnIteradorQueApuntaAlUltimoElementoDeUnaListaConVariosElementos_SePreguntaSiTieneSiguiente_DevuelveFalse();
  pruebas_pasadas += DadoUnIteradorDeUnaListaVacia_SeAvanzaElIteradorAlProximoElementoDeLaLista_DevuelveNull();
  pruebas_pasadas += DadoUnIteradorNUll_SeAvanzaElIteradorAlProximoElementoDeLaLista_DevuelveNULL();
  pruebas_pasadas += DadoUnIteradorQueApuntaAlPrimerElementoDeUnaListaConVariosElementos_SeAvanzaElIteradorAlProximoElemento_DevuelveElElementoYAvanzaCorrectamente();
  pruebas_pasadas += DadoUnIteradorQueApuntaAlUltimoElementoDeUnaListaConVariosElementos_SeAvanzaElIteradorAlProximoElemento_DevuelveElElementoYElSiguienteElementoEsNUll();
  pruebas_pasadas += DadoUnIteradorInicializado_SeLoDestruye_NoCausaProblemas();
  pruebas_pasadas += DadaUnaListaNull_SeIntentaCrearUnIteradorParaLaLista_DevuelveNULL();
  printf("Cantidad de pruebas totales = %i\nCantidad de pruebas pasadas = %i\n",pruebas_totales,pruebas_pasadas);
  return 0;
}
