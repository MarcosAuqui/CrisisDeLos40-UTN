/*
funciones

puntuarFila()

devolverFila()

hayGanador()
*/
#include "reglas.h"
#include "tablero.h"
#include "mazo.h"
#include "../constantes.h"

// FILA COMPLETA
void puntuarFila(int puntaje[2], int jugador, int suma){
    int rival = 1 - jugador; // declara el rival del jugador

    if(suma == PUNTOS_EXACTOS){
        puntaje[jugador] += PUNTOS_EXACTOS;
        puntaje[rival] -= PENALIDAD_EXACTO;
        if(puntaje[rival] < 0){
            puntaje[rival] = 0;
        }
    }else if(suma > PUNTOS_EXACTOS && suma < LIMITE_CRISIS){
        puntaje[jugador] += suma;
    }else if(suma >= LIMITE_CRISIS){
        puntaje[rival] += suma;
    }
}
/*puntuarFila: reparte los puntos de una fila completa segun la suma
30 exacto: el jugador suma 30 y el rival resta 15 (sin bajar de 0). de 31 a 39 el jugador suma la suma
40 o mas (crisis de los 40) los puntos van al rival. menos de 30 nadie suma. la usa completarFila*/

void devolverFila(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int fila){
    for(int c = 0; c < COLUMNAS; c++){
        if(!casilleroLibre(tablero, fila, c)){
            int carta = quitarCarta(tablero, fila, c);
            devolverCarta(mazo, cantMazo, carta);
        }
    }
}
/*devolverFila: devuelve al mazo las cartas de una fila y la deja vacia
usa quitarCarta y devolverCarta en cada casillero con carta. la usa completarFila despues de puntuar*/

// VICTORIA
int hayGanador(int puntaje[2]){
    if(puntaje[0] >= PUNTOS_VICTORIA){
        return 0;
    }else if(puntaje[1] >= PUNTOS_VICTORIA){
        return 1;
    }
    return -1;
}
/*hayGanador: devuelve 0 o 1 si ese jugador llego a 50 puntos, o -1 si todavia nadie gano
la usa jugar para saber cuando termina la partida*/