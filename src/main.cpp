#include <iostream>
#include <string>
#include "constantes.h"
#include "funciones/tablero.h"
#include "funciones/interfaz.h"
using namespace std;

int main(){
    configurarConsola();

    int tablero[FILAS][COLUMNAS];
    inicializarTablero(tablero);

    // fila 1: K T, 2 C, 8 P
    colocarCarta(tablero, 0, 0, 38);
    colocarCarta(tablero, 0, 1, 14);
    colocarCarta(tablero, 0, 2, 7);

    // fila 2: 10 C, 5 D, A P, K D
    colocarCarta(tablero, 1, 0, 22);
    colocarCarta(tablero, 1, 1, 43);
    colocarCarta(tablero, 1, 2, 0);
    colocarCarta(tablero, 1, 3, 51);

    string nombre[2] = {"ANGEL", "ABEL"};
    int puntaje[2] = {18, 23};

    mostrarPantalla(tablero, nombre, puntaje, 0, 46);   // le toca a ANGEL
    mostrarPantalla(tablero, nombre, puntaje, 1, 46);   // le toca a ABEL
    return 0;
}