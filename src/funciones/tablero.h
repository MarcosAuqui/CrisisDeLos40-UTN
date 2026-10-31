#ifndef CARTAS_H
#define CARTAS_H
#include "../constantes.h"

void inicializarTablero(int tablero[FILAS][COLUMNAS]);
void colocarCarta(int tablero[FILAS][COLUMNAS], int fila, int columna, int carta);

#endif