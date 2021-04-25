#include "biblioteca_pruebas_hash.h"
#include <stdio.h>

int main(){
  int pruebas_totales = 26, pruebas_pasadas = 0;
  pruebas_pasadas += DadaUnaCapacidadMinimaCero_SeIntentaCrearUnHash_DevuelveNULL();
  pruebas_pasadas += DadoUnHashNULL_SeIntentaInsertarUnElemento_DevuelveERROR();
  pruebas_pasadas += DadoUnHashNULL_SeIntentaQuitarUnElemento_DevuelveERROR();
  pruebas_pasadas += DadoUnHashNULL_SeQuiereObtenerUnElemento_DevuelveNULL();
  pruebas_pasadas += DadoUnHashNULL_SePreguntaSiContieneUnElemento_DevuelveFalse();
  pruebas_pasadas += DadoUnHashNULL_SePreguntaLaCantidadDeElementos_DevuelveCero();
  pruebas_pasadas += DadoUnHashVacio_SeQuiereQuitarUnElemento_DevuelveERROR();
  pruebas_pasadas += DadoUnHashVacio_SeQuiereObtenerUnElemento_DevuelveNULL();
  pruebas_pasadas += DadoUnHashVacio_SePreguntaSiContieneUnElemento_DevuelveFalse();
  pruebas_pasadas += DadoUnHashVacio_SePreguntaLaCantidadDeElementos_DevuelveCero();
  pruebas_pasadas += DadoUnHashVacio_SeIntentaInsertarUnElementoConUnaClaveNULL_DevuelveERROR();
  pruebas_pasadas += DadoUnHashConMuchosElementos_SeIntentaQuitarUnElementoConClaveNULL_DevuelveERROR();
  pruebas_pasadas += DadoUnHashConMuchosElementos_SeIntentaObtenerUnElementoConClaveNULL_DevuelveNULL();
  pruebas_pasadas += DadoUnHashConMuchosElementos_SePreguntaSiContieneUnElementoConClaveNULL_DevuelveFalse();
  pruebas_pasadas += DadoUnHashConMuchosElementos_SeIntentaQuitarUnElementoConUnaClaveQueNoEsta_DevuelveERROR();
  pruebas_pasadas += DadoUnHashConMuchosElementos_SeIntentaObtenerUnElementoConUnaCLaveQueNoEsta_DevuelveNULL();
  pruebas_pasadas += DadoUnHashConMuchosElementos_SePreguntaSiContieneUnElementoConUnaClaveQueNoEsta_DevuelveFalse();
  pruebas_pasadas += DadoUnHashVacio_SeInsertanDiezElementosYPreguntoLaCantidadDeElementosEnElHash_DevuelveDiez();
  pruebas_pasadas += DadoUnHashConDiezElementos_SeQuitanLosDiezElementosYSePreguntaLaCantidad_DevuelveCero();
  pruebas_pasadas += DadoUnHashNULL_SeLoDestruyeNoCausaProblemas();
  pruebas_pasadas += DadoUnHashNull_SeIntentaCrearUnIteradorParaDichoHash_DevuelveNULL();
  pruebas_pasadas += DadoUnHashVacio_SeIntentaCrearUnIteradorParaDichoHash_DevuelveNULL();
  pruebas_pasadas += DadoUnIteradorNULL_SePreguntaSiTieneSiguiente_Devuelvefalse();
  pruebas_pasadas += DadoUnIteradorNULL_SeIntentaAvanzarAlSiguienteElemento_DevuelveNULL();
  pruebas_pasadas += DadoUnIteradorNULL_SeLoDestruye_NoCausaProblemas();
  pruebas_pasadas += DadoUnHashConCapacidadMinimaDos_SeInsertanDiezElementos_LaTablaDeHashSeRedimensionaCorrectamente();


printf("Pruebas Totales: %i\nPruebas Pasadas: %i\n",pruebas_totales,pruebas_pasadas);

}
