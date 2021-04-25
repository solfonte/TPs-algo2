    El trabajo presentado en este archivo comprimido es un TDA lista, que es una estructura de datos que cuenta con las siguientes operaciones:
 lista_crear();
lista_insertar();
lista_insertar_en_posicion();
lista_borrar();
lista_borrar_de_posicion();
lista_elemento_en_posicion();
lista_ultimo();
lista_vacia();
lista_elementos();
lista_destruir();
   El struct de la lista fue implementado unicamente con un puntero a una pila. Dado que la lista fue implementada unicamente usando una pila, como decia el enunciado, no se necesito guardar referencias como cuantos elementos hay en la lista ya que se puede consultar usando la primitiva de la pila, pila_cantidad(). Como fue implementado con una pila, se usaron unicamente las primitivas del TDA pila para implementar las funciones de la lista. 
   Las primitivas de la pila utilizadas en la implementacion de la lista son las siguientes: 
pila_crear();
pila_apilar();
pila_desapilar();
pila_vacia();
pila_cantidad();
pila_tope();
pila_destruir();
    Tambien cuenta con un iterador externo, el cual cuenta con las siguientes operaciones:
lista_iterador_crear();
lista_iterador_tiene_siguiente();
lista_iterador_siguiente();
lista_iterador_destruir();
lista_con_cada_elemento();
    El struct del iterador fue implementado con un puntero a la lista, y el corriente es una pila, que contiene a los elementos de la lista en sentido inverso a los elementos en la pila de la lista. Asi, cuando se avanza el iterador, simplemente se desapila el elemento del tope y se itera sobre los elementos en el orden de las posiciones en el cual se insertaron los elementos.
Algunas convenciones tomadas fueron por ejemplo, la eleccion de la primera y la ultima posicion de la lista. La ultima posicion de la lista es la posicion tope de la pila. Ademas, en las operaciones de lista_insertar_en_posicion,lista_borrar_de_posicion y lista_elemento_en_posicion, las cuales fueron implementadas recursivamente (dado que habia que desapilar elementos de la pila y luego reapilarlos y de esta manera se facilitaba la operacion), en caso de fallar antes de insertar/ borrar/ devolver el elemento se devuelve error y se corta la ejecucion de la funcion recursiva, y se devuelve la lista en las condiciones antes de realizar la operacion. Si falla la operacion de apilar(cuando se vuelven a apilar los elementos en la pila), ese elemento que no se volvio a apilar se pierde, y volviendo en las llamadas recursivas se intenta seguir apilando los demas.
    En el programa implementado usando algunas de las funciones del TDA se testean casos simples, y en las minipruebas se testean casos borde.
    Como solo se implemento la lista usando las primitivas de la pila, no considero que haga falta aclarar convenciones o implementaciones de la pila ya que estas podrian cambiar, pero el funcionamiento de cada operacion permanece igual("un que, mil comos").
    A continuacion se especifican las lineas a utilizar en la terminal para compilar y ejecutar el programa, y chequear posibles perdidas de memoria:
    Para los tests y el programa:
    Para compilar gcc *.c -std=c99 -Wall -Wconversion  -Wtype-limits -pedantic -Werror -O0 
    Para ejecutar el programa: ./a.out
    Para chequear posibles perdidas de memoria: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./a.out
