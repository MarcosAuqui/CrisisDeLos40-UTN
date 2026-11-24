#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <string>
#include "../constantes.h"

void configurarConsola(); //
void mostrarMenu();//
void mostrarPantalla(int tablero[FILAS][COLUMNAS], std::string nombre[2], int puntaje[2], int jugador, int cantMazo);   // MAQUETA por ahora
void mostrarReglas();//
int pedirFila();
int pedirColumna();
void pedirCartaTablero(int tablero[FILAS][COLUMNAS], int& fila, int& columna);
void mostrarCarta(int id);//
void mostrarFilaCompleta(int tablero[FILAS][COLUMNAS], int fila, int suma);
void mostrarResultadoFila(std::string nombreJugador, std::string nombreRival, int suma);
void mostrarCartaColocada(std::string nombre, int carta, int fila);
std::string simboloPalo(int palo);
void mostrarValorCentro(int valor);
void mostrarLineaCarta(int id, int linea);
void espacios(int n);
void mostrarFilaTablero(int tablero[FILAS][COLUMNAS], int f);
void mostrarCartasRobadas(std::string nombre, int carta1, int carta2);
void pedirNombres(std::string nombres[2]);
int pedirCartaJugar();
int pedirJugarDiamante();
void mostrarCartaReemplazada(std::string nombre, int cartaVieja, int cartaNueva, int fila);
void dibujarCarta(int id);
void mostrarCartaRetirada(std::string nombnre, int carta, int fila);

#endif
