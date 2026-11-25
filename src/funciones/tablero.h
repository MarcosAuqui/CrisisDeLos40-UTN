#ifndef TABLERO_H
#define TABLERO_H
#include "../constantes.h"

// PREPARAR TABLERO
void inicializarTablero(int tablero[FILAS][COLUMNAS]);

// PONER Y SACAR CARTAS
void colocarCarta(int tablero[FILAS][COLUMNAS], int fila, int columna, int carta);
int quitarCarta(int tablero[FILAS][COLUMNAS], int fila,  int columna);

// CONSULTAS DEL TABLERO
int cartasEnFila(int tablero[FILAS][COLUMNAS], int fila);
int sumarFila(int tablero[FILAS][COLUMNAS], int fila);
bool casilleroLibre(int tablero[FILAS][COLUMNAS], int fila, int columna);
int primerCasilleroVacio(int tablero[FILAS][COLUMNAS], int fila);
bool tableroVacio(int tablero[FILAS][COLUMNAS]);

#endif