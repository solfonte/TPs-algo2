#ifndef __BIBLIOTECA_PRUEBAS_H__
#define __BIBLIOTECA_PRUEBAS_H__
#define ERROR -1
#define EXITO 0

int DadoUnArbolNull_SeIntentaInsertarEnDichoArbol_DevuelveERROR();
int DadoUnArbolNull_SeIntentaBorrarUnElementoDeDichoArbol_DevuelveERROR();
int DadoUnArbolNUll_SeIntentaBuscarUnElemento_DevuelveNull();
int DadoUnArbolNull_SePideLaRaiz_DevuelveNull();
int DadoUnArbolNull_SePreguntaSiEstaVacio_DevuelveTrue();
int DadoUnArbolNull_SeLoDestruyeNoCausaProblemas();
int DadoUnComparadorNull_SeIntentaCrearUnArbol_DevuelveNull();
int DadoUnArbolVacio_SeIntentaBorrarUnElemento_DevuelveERROR();
int DadoUnArbolVacio_SePideLaRaiz_DevuelveNull();
int DadoUnArbolConMuchosElementos_SeBuscaUnElementoQueNoEsta_DevuelveNull();
int DadoUnArbolConMuchosElementos_SeBuscaUnElementoQueEsta_DevuelveElElementoCorrectamente();
int DadoUnArbolConMuchosElementos_SeIntentaBorrarUnElementoQueNoEsta_DevuelveERROR();
int DadoUnArbolConMuchosElementos_SeIntentaBorrarUnElementoQueEsta_LoBorraCorrectamente();
int DadoUnArbolConMuchosElementos_SeInserta3VecesElMismoElemento_Esta3VecesEnElArbol();
int DadoUnArbolConMuchosElementos_SeBorraUnElementoQueEstaDosVeces_TodaviaQuedaUnaVezEseElementoEnElArbol();
int DadoUnArbolVacio_SeInserta3VecesElMismoElemento_SeInsertanSiempreDelLadoDerechoDelRepetido();
int DadoUnArbolVacio_SeInsertaUnElemento_DevuelveEXITO();
int DadoUnArbolConMuchosElementos_SeBorraUnElementoQueEsta_DevuelveEXITO();
int DadoUnArbolVacio_SeInsertaUnElemento_LoInsertaEnLaRaiz();
int DadoUnArbolConUnElemento_SeInsertaUnElementoMasChicoYUnoMasGrandeQueElQueYaEstaEnElArbol_ElMasChicoSeInsertaALaIzquierdaYElMasGrandeALaDerecha();
int DadoUnArbolVacio_InsertoUnElementoYPreguntoSiEstaVacio_DevuelveFalse();
int DadoUnArbolNull_SePideElRecorridoInorden_DevuelveCero();
int DadoUnArbolNull_SePideElRecorridoPostorden_DevuelveCero();
int DadoUnArbolNull_SePideElRecorridoPreorden_DevuelveCero();
int DadoUnArbolVacio_SePideElRecorridoInorden_DevuelveCero();
int DadoUnArbolVacio_SePideElRecorridoPostorden_DevuelveCero();
int DadoUnArbolVacio_SePideElRecorridoPreorden_DevuelveCero();
int DadoUnArrayNull_SePideElRecorridoInorden_DevuelveCero();
int DadoUnArrayNull_SePideElRecorridoPreorden_DevuelveCero();
int DadoUnArrayNull_SePideElRecorridoPostorden_DevuelveCero();
int DadoUnArrayDeTamanioCero_SePideElRecorridoInorden_DevuelveCero();
int DadoUnArrayDeTamanioCero_SePideElRecorridoPreorden_DevuelveCero();
int DadoUnArrayDeTamanioCero_SePideElRecorridoPostorden_DevuelveCero();
int DadoUnArbolCon10Elementos_SePideElRecorridoPreordenConUnArrayDeTamanio5_Devuelve5();
int DadoUnArbolCon10Elementos_SePideElRecorridoPostordenConUnArrayDeTamanio5_Devuelve5();
int DadoUnArbolCon10Elementos_SePideElRecorridoInordenConUnArrayDeTamanio5_Devuelve5();
int DadoUnArbolCuyaRaizTieneDosHijos_EliminoLaRaiz_LaNuevaRaizEsElMenorDeLosMayores();

#endif /*__BIBLIOTECA_PRUEBAS_H__*/