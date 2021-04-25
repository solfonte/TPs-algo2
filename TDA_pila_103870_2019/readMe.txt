    El trabajo presentado en este archivo comprimido es un TDA pila, que es una estructura de datos que cuenta con las operaciones para crear una pila, destruirla, apilar y desapilar elementos, y consultar la cantidad actual de elementos, consultar cual es el elemento tope, y consultar si dicha pila esta vacia.
    Las pruebas se crean a partir del punto de vista de caja blanca.Para este TDA creefunciones que prueban los resultados de la combinacion de las distintas operaciones del TDA y testeo los casos borde, ademas testear casos particulares sobre la implementacion. Para crear una prueba, se debe primero elegir un nombre descriptivo de la forma "DADO_CUANDO_ENTONCES();". Luego, dentro de cada prueba se crea una pila con los datos necesarios para llevar a cabo las pruebas y luego se destruye dicha pila. Para cada prueba se crea una pila distinta dado que en cada caso puede requerirse apilar y desapilar distintos elementos, ya sea distinta cantidad de elementos o elementos de distintos tipos de datos. Cada prueba debe contar con un tipo de retorno numerico, para asi llevar un contador de pruebas pasadas. Las pruebas son del tipo automaticas.
    El criterio de redimension del vector dinamico es aumentar al doble el vector cuando necesito seguir cargandolo con elementos y disminuir a la mitad el vector cuando este esta cargado solo un  veinticinco por ciento.
    A continuacion se especifican las lineas a utilizar en la terminal para compilar y ejecutar el programa, y chequear posibles perdidas de memoria:
    Para compilar el programa: gcc *.c -std=c99 -Wall -Wconversion  -Wtype-limits -pedantic -Werror -O0 
    Para ejecutar el programa: ./a.out
    Para chequear posibles perdidas de memoria: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./a.out
		
	


