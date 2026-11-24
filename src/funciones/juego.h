#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include "../constantes.h"
#include "interfaz.h"

void completarFila(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombres[2], int jugador, int fila);
void jugarComun(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombres[2], int jugador, int carta);
void jugarDiamante(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombres[2], int jugador, int carta);
void comodinRetirar(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, std::string nombres[2], int jugador);
#endif