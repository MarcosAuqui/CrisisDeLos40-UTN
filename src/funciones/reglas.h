#ifndef REGLAS_H
#define REGLAS_H
#include "../constantes.h"

void puntuarFila(int puntaje[2], int jugador, int suma);
void devolverFila(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int fila);
int hayGanador(int puntaje[2]);

#endif