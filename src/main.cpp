#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"

using namespace std;

int main() {
    int tablero[FILAS][COLUMNAS];

    inicializarTablero(tablero);

    colocarCarta(tablero, 0, 0, 0);     // As de picas arriba a la izquierda
    colocarCarta(tablero, 1, 3, 25);    // K de corazones en fila 1, columna 3
    colocarCarta(tablero, 2, 4, 51);    // K de diamantes abajo a la derecha

    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            cout << tablero[f][c] << " ";
        }
        cout << endl;
    }

    return 0;
}