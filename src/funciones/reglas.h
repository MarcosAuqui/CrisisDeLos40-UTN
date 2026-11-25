#ifndef REGLAS_H
#define REGLAS_H
#include "../constantes.h"

// FILA COMPLETA
void puntuarFila(int puntaje[2], int jugador, int suma);
void devolverFila(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int fila);

// VICTORIA
int hayGanador(int puntaje[2]);

#endif