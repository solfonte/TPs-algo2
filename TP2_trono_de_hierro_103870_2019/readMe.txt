    El tp 2 juego de tronos tiene como objetivo principal la simulacion de una cierta cantidad de años (introducidos por el usuario), devolviendo la casa en el trono luego del paso de dichos anios. Las casas utilizadas para la simulacion son leidas de un archivo de texto introducido por el usuario, y a partir de la cantidad final de integrantes luego del paso de dichos años se determina que casa es la que tiene el trono, y esta casa es la que posea mayor cantidad de integrantes.
    El formato del archivo a utilizar para la simulacion tiene el siguiente formato:
C;nombre_casa_1;FEnvej;FNac
I;nombre_intregrante_1;edad
I;nombre_integrante_2;edad;
.
.
.
.
I:nombre_integrante_n;edad
C;nombre_casa_2;Fenvej;Fnac
I;nombre_integrante_1;edad
.
.
.
donde los caracteres C e I indican si la linea brinda informacion acerca de la casa o de un integrante, Fenevj es el factor de envejecimiento de los integrantes de la casa y FNac el de nacimiento de dicha casa. Los integrantes mueren cuando llegan a o superan los 60 años (en caso de que un integrante dentro del archivo tenga mas de dicha edad,se lo considera como un ser con una extraña mutacion genetica y muere al primer año de simulacion introducida por el usuario), calculandose su edad cada año como:
edad_integrante = edad_integrante + FEnvej
y los nacimientos se calculan como:
cantidad_a_nacer = cantidad_integrantes_de_la_casa / FNac
    Los comandos ejecutables dentro del programa son los siguientes:
A: para ingresar las casas al programa. Se le pide al usuario el nombre del archivo que contiene la informacion sobre ellas.
S: inicia la simulacion. Se le pide al usuario una cierta cantidad de años a simular y devuelve la casa en el trono luego del paso de los años ingresados
L: lista las casas en orden descendente segun la cantidad de integrantes.
E: muestra las casas en el orden en que estas se fueron extinguendo.
Q: finaliza la ejecucion del programa


