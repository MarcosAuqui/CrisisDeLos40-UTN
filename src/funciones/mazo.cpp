/*
funciones

crearMazo()

mezclar()

robarCarta()

devolverCarta()
*/

#include "mazo.h"
#include "../constantes.h"
#include <cstdlib>

// CREAR Y MEZCLAR
void crearMazo(int mazo[], int& cantMazo){
    for(int i = 0; i < TOTAL_CARTAS; i++){
        mazo[i] = i;
    }
    cantMazo = TOTAL_CARTAS;
}
/*crearMazo: llena el mazo con los ids 0 a 53 en orden y deja cantMazo en 54
la usa jugar al empezar la partida*/

void mezclar(int mazo[], int cantMazo){
    for(int i = cantMazo - 1 ; i > 0; i--){
        int j = rand() % (i + 1);
        int aux = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = aux;
    }

}
/*mezclar: desordena las cartas del mazo, de la ultima para atras cambia cada una con
una posicion al azar. solo toca las que estan en el mazo (0 a cantMazo-1)
necesita el srand del main. la usan jugar al empezar y jugarTurno al final de cada turno*/

// ROBAR Y DEVOLVER
int robarCarta(int mazo[], int& cantMazo){
    cantMazo--;
    return  mazo[cantMazo];
}
/*robarCarta: saca la carta de arriba del mazo, baja cantMazo en 1 y devuelve esa carta
la usa jugarTurno 2 veces por turno*/

void devolverCarta(int mazo[], int& cantMazo, int carta){
    mazo[cantMazo] = carta;
    cantMazo++;
}
/*devolverCarta: pone una carta en la primera posicion libre del mazo y sube cantMazo en 1
es lo contrario de robarCarta. la usan jugarTurno, devolverFila, jugarDiamante y comodinRetirar*/
