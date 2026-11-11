#ifndef TABLERO_H
#define TABLERO_H
#include "../constantes.h"

void inicializarTablero(int tablero[FILAS][COLUMNAS]);
void colocarCarta(int tablero[FILAS][COLUMNAS], int fila, int columna, int carta);
int quitarCarta(int tablero[FILAS][COLUMNAS], int fila,  int columna);
int cartasEnFila(int tablero[FILAS][COLUMNAS], int fila);
int sumarFila(int tablero[FILAS][COLUMNAS], int fila);
bool filaLlena(int tablero[FILAS][COLUMNAS], int fila);
bool casilleroLibre(int tablero[FILAS][COLUMNAS], int fila, int columna);
bool tableroVacio(int tablero[FILAS][COLUMNAS]);

#endif