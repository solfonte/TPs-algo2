    El trabajo presentado en este archivo comprimido es un TDA arbol binario de busqueda, que es una estructura de datos que cuenta con las operaciones para crear un arbol, destruirlo, agregar elementos y sacar elementos de el, consultar la raiz del arbol, buscar elementos en el, consultar si dicho arbol esta vacio, y con los recorridos preorden, inorden y postorden que llenan un array con los elementos del arbool en el orden de estos recorridos.
   Cuenta con un iterador interno  para poder recorrer los elementos del arbol con los recorridos preorden, postorden e inorden.El criterio elegido para la insercion de elementos repetidos en el arbol, fue el de insertarlos a la derecha del elemento que ya e encontraba en el arbol. Y el criterio elegido para el borrado de los nodos que tienen dos hijos fue el de reemplazar dicho nodo por el menor de los mayores.
    Ademas, cuenta con 38 pruebas automaticas tanto de caja negra como de caja blanca que testean el correcto funcionamiento del tda.
    A continuacion se especifican las lineas a utilizar en la terminal para compilar y ejecutar el programa, y chequear posibles perdidas de memoria:

    Para compilar el programa: gcc *.c -std=c99 -Wall -Wconversion  -Wtype-limits -pedantic -Werror -O0 
    Para ejecutar el programa: ./a.out
    Para chequear posibles perdidas de memoria: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./a.out


