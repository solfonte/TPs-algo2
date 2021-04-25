    El trabajo presentado en este archivo comprimido es un TDA lista, que es una estructura de datos que cuenta con las operaciones para crear una lista, destruirla, agregar elementos y sacar elementos de ella, consultar la cantidad actual de elementos, consultar cual es el elemento que esta al final de la, y consultar si dicha lista esta vacia.
   Ademas, cuenta con un iterador interno y uno externo, para poder recorrer los datos de la lista.El struct de la lista fue implementado como lista de nodos simplemente enlazados y con una referencia al nodo inicio y uno al nodo fin. De esta manera, con la referencia al nodo inicio y al nodo fin, la complejidad computacional de las funciones lista_insertar() y lista_borrar() se vueven O(1) dado que estas funciones necesitan una referencia al ultimo nodo en la lista y asi no hace falta recorrer toda la lista para insertar y borrar elementos que del final
    El iterador externo cuenta con operaciones para crear el iterador, consultar si hay un elemento siguiente, avanzar el iterador al siguiente elemento en caso de haberlo, y destruir. El iterador externo creado solo es valido mientras la lista no sea modificada.
    A continuacion se especifican las lineas a utilizar en la terminal para compilar y ejecutar el programa, y chequear posibles perdidas de memoria:

    Para compilar el programa: gcc *.c -std=c99 -Wall -Wconversion  -Wtype-limits -pedantic -Werror -O0 
    Para ejecutar el programa: ./a.out
    Para chequear posibles perdidas de memoria: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./a.out


