#include "biblioteca_pruebas_cola.h"
#include <stdio.h>
int main(){
  int pruebas_totales = 16,pruebas_pasadas = 0;
  pruebas_pasadas += DadaUnaColaNull_SeIntentaDesencolar_DevuelveMenosUno();
  pruebas_pasadas += DadaUnaColaNull_SeIntentaEncolar_DevuelveMenosUno();
  pruebas_pasadas += DadaUnaColaNull_SePreguntaSiEstaVacia_DevuelveTrue();
  pruebas_pasadas += DadaUnaColaNull_SeDestruye_NoOcurreNingunError();
  pruebas_pasadas += DadaUnaColaNull_SePideLaCantidadDeElementos_DevuelveCero();
  pruebas_pasadas += DadaUnaColaVacia_SeIntentaDesencolar_DevuelveMenosUno();
  pruebas_pasadas += DadaUnaColaVacia_SePreguntaSiEstaVacia_DevuelveTrue();
  pruebas_pasadas += DadaUnaColaConUnElemento_SePreguntaSiEstaVacia_DevuelveFalse();
  pruebas_pasadas += DadaUnaColaConDiezElementos_SeDesencolanCincoElementos_LaCantidadDeElementosEnLaColaDevuelveCinco();
  pruebas_pasadas += DadaUnaColaConDiezElementos_SeDesencolan_LosDevuelveEnOrdenDeFIFO();//preguntar este nombre
  pruebas_pasadas += DadaUnaColaConUnElemento_SeDesencolaElElementoYSePreguntaSiEstaVacia_DevuelveTrue();
  pruebas_pasadas += DadaUnaColaInicializada_SeDestruye_NoOcurreNingunError();
  pruebas_pasadas += DadaUnaColaIncializada_SeEncolaUnElementoNull_DevuelveCero();
  pruebas_pasadas += DadaUnaColaInicializada_SeEncolanDiezElementos_LaCantidadDevuelveDiez();
  pruebas_pasadas += DadaUnaColaConDiezElementos_SeVacia_LaCantidadDeElementosDevuelveCero();
  pruebas_pasadas += DadaUnaColaInicializada_SeEncolanTresElementosDeDistintosTiposDeDatos_LaCantidadDeElementosEsTres();
  printf("Cantidad de pruebas totales = %i\nCantidad de pruebas pasadas = %i\n",pruebas_totales,pruebas_pasadas);
  return 0;
}
