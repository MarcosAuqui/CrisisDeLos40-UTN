#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <string>
#include "../constantes.h"

void configurarConsola();
void mostrarMenu();
void mostrarPantalla(std::string nombre1, std::string nombre2);   // MAQUETA por ahora
void mostrarReglas();
void mostrarCarta(int id);
void mostrarCasillerosLibres(int tablero[FILAS][COLUMNAS], int fila);

#endif
