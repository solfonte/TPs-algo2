    El trabajo presentado en este archivo comprimido es un TDA cola, que es una estructura de datos que cuenta con las operaciones para crear una cola, destruirla, encolar elementos en ella, desencolar dichos elementos, consultar la cantidad actual de elementos, consultar cual es el elemento que esta primero en la cola, y consultar si dicha cola esta vacia.
    Las pruebas creadas se crean a partir del punto de vista de caja blanca, probando los resultados de la combinacion de las distintas operaciones del TDA y se testean los casos borde. Para crear una prueba, se debe primero elegir un nombre descriptivo de la forma "DADO_CUANDO_ENTONCES();". Luego, dentro de cada prueba se crea una cola con los datos necesarios para llevar a cabo las pruebas y luego se destruye dicha cola. Para cada prueba se crea una cola distinta dado que en cada caso puede requerirse encolar y desencolar distintos elementos, ya sea distinta cantidad de elementos o elementos de distintos tipos de datos. Cada prueba debe contar con un tipo de retorno numerico, para asi llevar un contador de pruebas pasadas. Las pruebas son del tipo automaticas.
    A continuacion se especifican las lineas a utilizar en la terminal para compilar y ejecutar el programa, y chequear posibles perdidas de memoria:
    Para compilar el programa: gcc *.c -std=c99 -Wall -Wconversion  -Wtype-limits -pedantic -Werror -O0 
    Para ejecutar el programa: ./a.out
    Para chequear posibles perdidas de memoria: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./a.out


