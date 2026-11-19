#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <string>
#include "../constantes.h"

void configurarConsola(); //
void mostrarMenu();//
void mostrarPantalla(std::string nombre1, std::string nombre2);   // MAQUETA por ahora
void mostrarReglas();//
int pedirFila();
int pedirColumna();
void pedirCartaTablero(int tablero[FILAS][COLUMNAS], int& fila, int& columna);
void mostrarCarta(int id);//


#endif
