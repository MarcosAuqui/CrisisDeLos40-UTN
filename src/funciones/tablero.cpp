/*
funciones

inicializarTablero()

colocarCarta()

quitarCarta()

cartasEnFila()

sumarFila()

casilleroLibre()

primerCasilleroVacio()

tableroVacio()
*/

#include "tablero.h"
#include "cartas.h"
#include "../constantes.h"

// PREPARAR TABLERO
void inicializarTablero(int tablero[FILAS][COLUMNAS]) {
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            tablero[f][c] = VACIO;
        }
    }
}
/*inicializarTablero: deja los 15 casilleros en VACIO (-1) con 2 for, uno por fila y otro por columna
la usa jugar al empezar la partida*/

// PONER Y SACAR CARTAS
void colocarCarta(int tablero[FILAS][COLUMNAS], int fila, int columna, int carta){
    tablero[fila][columna] = carta;
}
/*colocarCarta: pone el id de una carta en el casillero (fila, columna) del tablero
la usan jugarComun, jugarDiamante y los comodines*/

int quitarCarta(int tablero[FILAS][COLUMNAS], int fila,  int columna){
    int carta = tablero[fila][columna];
    tablero[fila][columna] = VACIO;
    return carta;
}
/*quitarCarta: guarda la carta de un casillero, lo deja en VACIO y devuelve la carta
la usan devolverFila, jugarDiamante (reemplazar) y los comodines*/

// CONSULTAS DEL TABLERO
int cartasEnFila(int tablero[FILAS][COLUMNAS], int fila) {
    int cantidad = 0;
    for (int c = 0; c < COLUMNAS; c++) {
        if (tablero[fila][c] != VACIO) {
            cantidad = cantidad + 1;
        }
    }
    return cantidad;
}
/*cartasEnFila: cuenta cuantas cartas hay en una fila (0 a 5)
la usan las jugadas para saber si la fila se completo y la pantalla para mostrar Cartas: x/5*/

int sumarFila(int tablero[FILAS][COLUMNAS], int fila){
    int suma= 0;
    for(int c = 0; c < COLUMNAS; c++){
        if(tablero[fila][c] != VACIO){
            suma = suma + valorCarta(tablero[fila][c]);
        }
    }
    return suma;
}
/*sumarFila: suma los valores de las cartas de una fila, salteando los casilleros vacios
la usan completarFila y la pantalla*/

bool casilleroLibre(int tablero[FILAS][COLUMNAS], int fila, int columna){
    if(tablero[fila][columna] == VACIO){
        return true;
    }else{
        return false;
    }
}
/*casilleroLibre: devuelve true si el casillero esta vacio
la usan pedirCartaTablero y devolverFila*/

int primerCasilleroVacio(int tablero[FILAS][COLUMNAS], int fila){
    for(int c = 0; c < COLUMNAS; c++){
        if(tablero[fila][c] == VACIO){
            return c;
        }
    }
    return -1;
}
/*primerCasilleroVacio: devuelve la primera columna libre de la fila, buscando de izquierda a derecha
la usan jugarComun y comodinMover para saber donde cae la carta*/

bool tableroVacio(int tablero[FILAS][COLUMNAS]){
    for(int f = 0; f < FILAS; f++){
        if(cartasEnFila(tablero, f) != 0){
            return false;
        }
    }
    return true;
}
/*tableroVacio: devuelve true si no hay ninguna carta en el tablero, usa cartasEnFila
la usan jugarTurno (comodines con tablero vacio) y jugarDiamante*/
