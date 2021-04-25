#include <stdio.h>
#include "biblioteca_pruebas_abb.h"

int main(){
  int pruebas_pasadas = 0, pruebas_totales = 38;
  pruebas_pasadas += DadoUnArbolNull_SeIntentaInsertarEnDichoArbol_DevuelveERROR();
  pruebas_pasadas += DadoUnArbolNull_SeIntentaBorrarUnElementoDeDichoArbol_DevuelveERROR();
  pruebas_pasadas += DadoUnArbolNUll_SeIntentaBuscarUnElemento_DevuelveNull();
  pruebas_pasadas += DadoUnArbolNull_SePideLaRaiz_DevuelveNull();
  pruebas_pasadas += DadoUnArbolNull_SePreguntaSiEstaVacio_DevuelveTrue();
  pruebas_pasadas += DadoUnArbolNull_SeLoDestruyeNoCausaProblemas();
  pruebas_pasadas += DadoUnComparadorNull_SeIntentaCrearUnArbol_DevuelveNull();
  pruebas_pasadas += DadoUnArbolVacio_SeIntentaBorrarUnElemento_DevuelveERROR();
  pruebas_pasadas += DadoUnArbolVacio_SePideLaRaiz_DevuelveNull();
  pruebas_pasadas += DadoUnArbolVacio_SeInsertaUnElemento_DevuelveEXITO();
  pruebas_pasadas += DadoUnArbolConMuchosElementos_SeBuscaUnElementoQueNoEsta_DevuelveNull();
  pruebas_pasadas += DadoUnArbolConMuchosElementos_SeBuscaUnElementoQueEsta_DevuelveElElementoCorrectamente();
  pruebas_pasadas += DadoUnArbolConMuchosElementos_SeIntentaBorrarUnElementoQueEsta_LoBorraCorrectamente();
  pruebas_pasadas += DadoUnArbolConMuchosElementos_SeIntentaBorrarUnElementoQueNoEsta_DevuelveERROR();
  pruebas_pasadas += DadoUnArbolConMuchosElementos_SeIntentaBorrarUnElementoQueEsta_LoBorraCorrectamente();
  pruebas_pasadas += DadoUnArbolConMuchosElementos_SeInserta3VecesElMismoElemento_Esta3VecesEnElArbol();
  pruebas_pasadas += DadoUnArbolConMuchosElementos_SeBorraUnElementoQueEstaDosVeces_TodaviaQuedaUnaVezEseElementoEnElArbol();
  pruebas_pasadas += DadoUnArbolVacio_SeInserta3VecesElMismoElemento_SeInsertanSiempreDelLadoDerechoDelRepetido();
  pruebas_pasadas += DadoUnArbolConMuchosElementos_SeBorraUnElementoQueEsta_DevuelveEXITO();
  pruebas_pasadas += DadoUnArbolVacio_SeInsertaUnElemento_LoInsertaEnLaRaiz();
  pruebas_pasadas += DadoUnArbolConUnElemento_SeInsertaUnElementoMasChicoYUnoMasGrandeQueElQueYaEstaEnElArbol_ElMasChicoSeInsertaALaIzquierdaYElMasGrandeALaDerecha();
  pruebas_pasadas += DadoUnArbolVacio_InsertoUnElementoYPreguntoSiEstaVacio_DevuelveFalse();
  pruebas_pasadas += DadoUnArbolNull_SePideElRecorridoInorden_DevuelveCero();
  pruebas_pasadas += DadoUnArbolNull_SePideElRecorridoPostorden_DevuelveCero();
  pruebas_pasadas += DadoUnArbolNull_SePideElRecorridoPreorden_DevuelveCero();
  pruebas_pasadas += DadoUnArbolVacio_SePideElRecorridoInorden_DevuelveCero();
  pruebas_pasadas += DadoUnArbolVacio_SePideElRecorridoPostorden_DevuelveCero();
  pruebas_pasadas += DadoUnArbolVacio_SePideElRecorridoPreorden_DevuelveCero();
  pruebas_pasadas += DadoUnArrayNull_SePideElRecorridoInorden_DevuelveCero();
  pruebas_pasadas += DadoUnArrayNull_SePideElRecorridoPreorden_DevuelveCero();
  pruebas_pasadas += DadoUnArrayNull_SePideElRecorridoPostorden_DevuelveCero();
  pruebas_pasadas += DadoUnArrayDeTamanioCero_SePideElRecorridoInorden_DevuelveCero();
  pruebas_pasadas += DadoUnArrayDeTamanioCero_SePideElRecorridoPreorden_DevuelveCero();
  pruebas_pasadas += DadoUnArrayDeTamanioCero_SePideElRecorridoPostorden_DevuelveCero();
  pruebas_pasadas += DadoUnArbolCon10Elementos_SePideElRecorridoPreordenConUnArrayDeTamanio5_Devuelve5();
  pruebas_pasadas += DadoUnArbolCon10Elementos_SePideElRecorridoPostordenConUnArrayDeTamanio5_Devuelve5();
  pruebas_pasadas += DadoUnArbolCon10Elementos_SePideElRecorridoInordenConUnArrayDeTamanio5_Devuelve5();
  pruebas_pasadas += DadoUnArbolCuyaRaizTieneDosHijos_EliminoLaRaiz_LaNuevaRaizEsElMenorDeLosMayores();
  printf("Pruebas pasadas: %i\nPruebas totales: %i\n",pruebas_pasadas,pruebas_totales);
  return 0;
}
