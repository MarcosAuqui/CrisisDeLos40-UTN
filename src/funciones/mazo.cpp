/*
Funciones a desarrollar

crearMazo()

mezclar()

robarCarta()

devolverCarta()
*/

#include "mazo.h"
#include "../constantes.h" 

void crearMazo(int mazo[], int& cantMazo){
    for(int i = 0; i < TOTAL_CARTAS; i++){
        mazo[i] = i;
    }
    cantMazo = TOTAL_CARTAS;
}
