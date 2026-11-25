#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <string>
#include "../constantes.h"

// CONSOLA Y AUXILIARES
void configurarConsola();
void espacios(int n);

// DIBUJO DE CARTAS
void mostrarCarta(int id);
std::string simboloPalo(int palo);
void mostrarValorCentro(int valor);
void mostrarLineaCarta(int id, int linea);
void dibujarCarta(int id);

// MENU, REGLAS Y ESTADISTICAS
void mostrarMenu();
void mostrarReglas();
void mostrarEstadisticas(std::string mejorNombre, int mejorPuntaje);

// PANTALLA DEL TURNO
void mostrarFilaTablero(int tablero[FILAS][COLUMNAS], int f);
void mostrarPantalla(int tablero[FILAS][COLUMNAS], std::string nombre[2], int puntaje[2], int jugador, int cantMazo);

// INICIO DE PARTIDA
void pedirNombres(std::string nombres[2]);

// TURNO
void mostrarCartasRobadas(std::string nombre, int carta1, int carta2);
int pedirCartaJugar(int robadas[2], bool vacio);
void mostrarPierdeTurno(std::string nombre);

// ELEGIR LUGAR DEL TABLERO
int pedirFila();
int pedirColumna();
void pedirCartaTablero(int tablero[FILAS][COLUMNAS], int& fila, int& columna);
void pedirDosCartasTablero(int tablero[FILAS][COLUMNAS], int& fila1, int& columna1, int& fila2, int& columna2);
int pedirFilaDestino(int filaOrigen);

// CARTA COMUN Y FILA COMPLETA
void mostrarCartaColocada(std::string nombre, int carta, int fila);
void mostrarFilaCompleta(int tablero[FILAS][COLUMNAS], int fila, int suma);
void mostrarResultadoFila(std::string nombreJugador, std::string nombreRival, int suma);

// DIAMANTE
int pedirJugarDiamante();
void mostrarCartaReemplazada(std::string nombre, int cartaVieja, int cartaNueva, int fila);

// COMODIN
int pedirJugadaComodin(int cartasTablero);
void mostrarIntercambio(std::string nombre, int carta1, int fila1, int carta2, int fila2);
void mostrarMovimiento(std::string nombre, int carta, int filaOrigen, int filaDestino);
void mostrarCartaRetirada(std::string nombre, int carta, int fila);

// FIN DE PARTIDA
void mostrarGanador(std::string nombre, int puntos);

#endif
