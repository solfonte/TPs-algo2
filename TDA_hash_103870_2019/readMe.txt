    El trabajo presentado en este archivo comprimido es un TDA hash, que es una estructura de datos que cuenta con las operaciones para crear un hash, destruirlo, agregar elementos y sacar elementos de el, consultar si dicho hash contiene una clave, obtener un elemento y consultar la cantidad de elementos.Tambien cuenta con un iterador externo que cuenta con las operaciones de crear iterador, destruirlo, avanzar al siguiente elemento y devolverlo, y consultar si hay siguiente.
    El criterio elegido para solucionar las colisiones debido a dos claves que devuelven una misma posicion para la tabla de hash, fue el de hash abierto con listas. Las listas se crean cuando se intenta insertar un elemento en una posicion y si no se pudo insertar, se borra la lista. Otros criterio elegidos fueron el de rehasheo, que se realiza cuando el factor de carga alcanzado es igual a dos, y el de la capacidad inicial del hash, que se inicializa con el proximo numero primo inmediato despues del  numero recibido por parametros como capacidad minima inicial.
    Ademas, cuenta con 25 pruebas automaticas tanto de caja negra como de caja blanca que testean el correcto funcionamiento del tda, que testean los casos borde que no fueron testeados en las mini pruebas.
    A continuacion se especifican las lineas a utilizar en la terminal para compilar y ejecutar el programa, y chequear posibles perdidas de memoria:

    Para compilar el programa: gcc *.c -std=c99 -Wall -Wconversion  -Wtype-limits -pedantic -Werror -O0 
    Para ejecutar el programa: ./a.out
    Para chequear posibles perdidas de memoria: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./a.out


