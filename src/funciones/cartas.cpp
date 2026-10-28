/*
funciones a desarrollar

valorCarta() da el valor de 1 al 13 (As=1 ... K=13)

paloCarta() da el palo 0 a 3

esDiamante() 

esComodin()

mostrarCarta()
*/

#include "cartas.h"
#include "../constantes.h" 

int valorCarta(int id) {
    return id % CARTAS_POR_PALO + 1;
}
/* valorCarta: recibe el id de una carta (0 a 51) y devuelve su valor (1 a 13).
Como cada palo tiene 13 cartas seguidas, el valor se repite cada 13 ids:
el resto de dividir por 13 da 0 a 12, y se le suma 1 (As=1 - K=13).
En el proyecto la usan sumaFila (para sumar las filas), puntuarFila
y mostrarCarta (para imprimir el valor de la carta). */

int paloCarta(int id) {
    return id / CARTAS_POR_PALO;
}
/*  paloCarta: recibe el id de una carta (0 a 51) y devuelve su palo (0 a 3).
Las cartas están ordenadas por palo, de a 13: la división entera por 13
da 0 (picas), 1 (corazones), 2 (tréboles) o 3 (diamantes).
En el proyecto la usan esDiamante (para saber si la carta tiene jugada
especial) y mostrarCarta (para imprimir la inicial del palo). */

bool esComodin(int id){
    if( id >= PRIMER_COMODIN){
        return true;
    }
    return false;
}
/* esComodin: devuelve verdadero si la carta es uno de los dos comodines.
Los comodines son los ids 52 y 53, o sea todos los mayores o iguales
a PRIMER_COMODIN. En el proyecto la usan jugar (para saber si la carta
robada es comodín y si el tablero permite usarla) y mostrarCarta
(para imprimir [COMODIN]). */

bool esDiamante(int id){
    if(paloCarta(id) == DIAMANTES){
        return true;
    }
    return false;
}
/* esDiamante: devuelve verdadero si la carta es de diamantes.
Usa paloCarta para obtener el palo y lo compara con DIAMANTES.
En el proyecto la usa jugar para ofrecer al jugador las dos jugadas
especiales del diamante (colocar o reemplazar una carta del tablero). */