#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include "../constantes.h"

// FILA COMPLETA
void completarFila(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombres[2], int jugador, int fila);

// CARTA COMUN Y DIAMANTE
void jugarComun(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombres[2], int jugador, int carta);
void jugarDiamante(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombres[2], int jugador, int carta);

// COMODIN
void comodinIntercambiar(int tablero[FILAS][COLUMNAS], std::string nombres[2], int jugador);
void comodinMover(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombres[2], int jugador);
void comodinRetirar(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, std::string nombres[2], int jugador);
void jugarComodin(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombres[2], int jugador);

// TURNO Y PARTIDA
void jugarTurno(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], std::string nombres[2], int jugador);
void jugar(std::string& mejorNombre, int& mejorPuntaje);

#endif
