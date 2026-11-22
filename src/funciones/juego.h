#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include "../constantes.h"

void completarFila(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombre[2], int jugador, int fila);
void jugarComun(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombre[2], int jugador, int carta);

#endif