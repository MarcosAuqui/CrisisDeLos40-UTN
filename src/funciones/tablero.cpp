/* 
funciones a desarrollar

inicializarTablero()

colocarCarta()

quitarCarta())

cartasEnFila()

sumaFila()

filaLlena()

primerVacioFila()

tableroVacio()
*/

#include "tablero.h"
#include "../constantes.h" 

void inicializarTablero(int tablero[FILAS][COLUMNAS]) {
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            tablero[f][c] = VACIO;
        }
    }
}
/*inicializarTablero: deja los 15 casilleros del tablero en VACIO(-1).
ysa dos for, el de afuera elige la fila y el de adentro recorre las colimnas de desa fila.
se usa al empezar cada partida para arrancar con el tablero limpio*/

void colocarCarta(int tablero[FILAS][COLUMNAS], int fila, int columna, int carta){
    tablero[fila][columna] = carta;
}
/*colocarCarta: se encarga de colocar el id de X carta seleccionada en un casillero
especifico de la matriz del tablero. fila va de 0 a 2(3) y columna de 0 a 4(5).
se usaria en jugarComun y jugar diamante para poder poner la carta elegida,
 y en jugar comodin para ubicar la carta que se mueve*/
