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

int quitarCarta(int tablero[FILAS][COLUMNAS], int fila,  int columna){
    int carta = tablero[fila][columna];
    tablero[fila][columna] = VACIO;
    return carta;
}
/*quitarcarta: esta funcion devuelve el id de una carta seleccionada.
busca en el tablero[][] y guarda el id de esa posicion en la var carta
luego deja esa posicion enn VACIO*/

int cartasEnFila(int tablero[FILAS][COLUMNAS], int fila) {
    int cantidad = 0;
    for (int c = 0; c < COLUMNAS; c++) {
        if (tablero[fila][c] != VACIO) {
            cantidad = cantidad + 1;
        }
    }
    return cantidad;
}
/*cartasEnFila: saca la carta de un casillero del tablero, lo deja en VACIO
Y devuelve el ID de la carta de esa posicion
guarda la carta en una variable y después vacía el casillero
no toca el mazo, si vuelve al mazo o no lo decide otra funcion
la usaran puntuarFila, para vaciar una fila
jugarDiamante para sacar la carta reemplazada
jugar comodin para retirar o mover una carta*/