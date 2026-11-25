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
/*puntuarFila: aplica a una fila completa. Con suma 30 exacto, el jugador que la
completo suma 30 y el rival resta 15 (sin bajar de 0). De 31 a 39, el jugador suma la suma.
Con 40 o mas (crisis de los 40) los puntos van al rival. Con menos de 30 nadie puntua.
No imprime ni vacia la fila: eso lo va a hacer interfaz. La usa jugar despues
de colocar una carta o de mover con comodin cuando la fila llega a 5 cartas.*/

void devolverFila(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int fila){
    for(int c = 0; c < COLUMNAS; c++){
        if(!casilleroLibre(tablero, fila, c)){
            int carta = quitarCarta(tablero, fila, c);
            devolverCarta(mazo, cantMazo, carta);
        }
    }
}
/*devolverFila: devuelve al mazo todas las cartas de una fila y la deja vacia (VACIO).
Recorre las 5 columnas y en cada casillero con una carta carta, quitarCarta la saca
del tablero y devolverCarta la pone arriba del mazo. Se la llama despues de puntuarFila, cuando la
fila ya se mostro y se repartieron los puntos.*/

// VICTORIA
int hayGanador(int puntaje[2]){
    if(puntaje[0] >= PUNTOS_VICTORIA){
        return 0;
    }else if(puntaje[1] >= PUNTOS_VICTORIA){
        return 1;
    }
    return -1;
}
/*hayGanador: revisa si algun jugador llego a PUNTOS_VICTORIA (50) o mas. Devuelve su indice en vector
(0 o 1) o -1 si todavia nadie gano. La usa jugar al final decada turno (paso 7): si devuelve 
distinto de -1, la partida debera termina en ese momento.*/