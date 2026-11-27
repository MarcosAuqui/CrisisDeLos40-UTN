/*
funciones

valorCarta()

paloCarta()

esComodin()

esDiamante()
*/

#include "cartas.h"
#include "../constantes.h"

// VALOR Y PALO
int valorCarta(int id) {
    return id % CARTAS_POR_PALO + 1;
}
/*valorCarta: recibe el id (0 a 51) y devuelve el valor de 1 a 13 (As=1 ... K=13)
como cada palo tiene 13 cartas, el resto de dividir por 13 da 0 a 12 y se le suma 1
la usan sumarFila y las funciones que dibujan la carta*/

int paloCarta(int id) {
    return id / CARTAS_POR_PALO;
}
/*paloCarta: recibe el id y devuelve el palo de 0 a 3
las cartas van de a 13 por palo, asi que la division por 13 da 0 picas, 1 corazones, 2 treboles o 3 diamantes
la usan esDiamante y las funciones que dibujan la carta*/

// TIPO DE CARTA
bool esComodin(int id){
    if( id >= PRIMER_COMODIN){
        return true;
    }
    return false;
}
/*esComodin: devuelve true si la carta es uno de los 2 comodines (ids 52 y 53)
la usan jugarTurno y las funciones que dibujan la carta*/

bool esDiamante(int id){
    if(paloCarta(id) == DIAMANTES){
        return true;
    }
    return false;
}
/*esDiamante: devuelve true si la carta es de diamantes, usa paloCarta
la usa jugarTurno para saber si la carta tiene la jugada especial*/
