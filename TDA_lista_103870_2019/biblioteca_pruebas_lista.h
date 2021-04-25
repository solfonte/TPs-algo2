#ifndef __BIBLIOTECA_PRUEBAS_LISTA_H__
#define __BIBLIOTECA_PRUEBAS_LISTA_H__
int DadaUnaListaNull_SeIntentaInsertar_DevuelveMenosUno();
int DadaUnaListaNull_SeIntentaInsertarEnUnaPosicion_DevuelveMenosUno();
int DadaUnaListaNull_SeIntentaBorrar_DevuelveMenosUno();
int DadaUnaListaNull_SeIntentaBorrarDeUnaPosicion_DevuelveMenosUno();
int DadaUnaListaNull_SepideElUltimoElemento_DevuelveNULL();
int DadaUnaListaNull_SePideElElementoEnUnaPosicion_DevuelveNULL();
int DadaUnaListaNull_SePreguntaSiEstaVacia_DevuelveTrue();
int DadaUnaListaNull_SePideLaCantidadDeElementosEnLaLista_DevuelveCero();
int DadaUnaListaNull_SeLaDestruye_NoCausaProblemas();
int DadaUnaListaVacia_SeInsertaUnElemento_LoInsertaCorrectamente();
int DadaUnaListaVacia_SePideInsertarUnElementoEnUnaPosicion_LoInsertaEnLaPosicionCero();
int DadaUnaListaVacia_SePideBorrarUnElemento_DevuelveMenosUno();
int DadaUnaListaVacia_SePideBorrarUnElementoDeUnaPosicion_DevuelveMenosUno();
int DadaUnaListaVacia_SePideElElementoEnUnaPosicion_DevuelveNULL();
int DadaUnaListaVacia_SePideElUltimoElemento_DevuelveNULL();
int DadaUnaListaVacia_InsertoUnElementoYPreguntoSiLaListaEstaVacia_DevuelveFalse();
int DadaUnaListaVacia_PidoLaCantidadDeElementos_DevuelveCero();
int DadaUnaListaVacia_InsertoElementosYpidoLaCantidadDeElementosEnLaLista_DevuelveLaCantidadDeElementosQueInserte();
int DadaUnaListaConVariosElementos_SeInsertaUnElemento_LoInsertaAlFinal();
int DadaUnaListaConVariosElementos_SeInsertaUnElementoEnUnaPosicionQueExiste_LoInsertaCorrectamente();
int DadaUnaListaConVariosElementos_SePideInsertarUnElementoEnUnaPosicionQueNoExiste_LoInsertaAlFinal();
int DadaUnaListaConVariosElementos_SePideBorrarUnElementoDeUnaPosicionQueNoExiste_DevuelveMenosUno();
int DadaUnaListaConVariosElementos_SePideBorrarUnElementoDeUnaPosicionQueExiste_LoBorraCorrectamente();
int DadaUnaListaConVariosElementos_SePideBorrarUnElemento_BorraElUltimo();
int DadaUnaListaConVariosElementos_SePideElElementoEnUnaPosicionQueNoExiste_DevuelveNULL();
int DadaUnaListaConVariosElementos_SePideElElementoEnUnaPosicionQueExiste_LoDevuelveCorrectamente();
int DadaUnaListaConVariosElementos_SePideElElementoEnLaUltimaPosicion_LoDevuelveCorrectamente();
int DadaUnaListaConVariosElementos_LosBorroDeLaListaYPreguntoSiEstaVacia_DevuelveTrue();
int DadaUnaListaConVariosElementos_SeLaDestruye_NoCausaProblemas();
int DadaUnaListaConVariosElementos_SeIteraSobreSusElementosUtilizandoUnPunteroAUnaFuncion_SeObtieneElResultadoEesperado();
int DadoUnIteradorNULL_SePreguntaSiLaListaTieneSiguiente_DevelveFalse();
int DadoUnIteradorDeUnaListaVacia_SePreguntaSiTieneSiguiente_DevuelveFalse();
int DadoUnIteradorQueApuntaAlPrimerElementoDeUnaListaConVariosElementos_SePreguntaSiTieneSiguiente_Devuelvetrue();
int DadoUnIteradorQueApuntaAlUltimoElementoDeUnaListaConVariosElementos_SePreguntaSiTieneSiguiente_DevuelveFalse();
int DadoUnIteradorDeUnaListaVacia_SeAvanzaElIteradorAlProximoElementoDeLaLista_DevuelveNull();
int DadoUnIteradorNUll_SeAvanzaElIteradorAlProximoElementoDeLaLista_DevuelveNULL();
int DadoUnIteradorQueApuntaAlPrimerElementoDeUnaListaConVariosElementos_SeAvanzaElIteradorAlProximoElemento_DevuelveElElementoYAvanzaCorrectamente();
int DadoUnIteradorQueApuntaAlUltimoElementoDeUnaListaConVariosElementos_SeAvanzaElIteradorAlProximoElemento_DevuelveElElementoYElSiguienteElementoEsNUll();
int DadoUnIteradorInicializado_SeLoDestruye_NoCausaProblemas();
int DadaUnaListaNull_SeIntentaCrearUnIteradorParaLaLista_DevuelveNULL();
#endif /*__BIBLIOTECA_PRUEBAS_LISTA_H__*/
