#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"

using namespace std;

int main() {
    int tablero[FILAS][COLUMNAS];

    inicializarTablero(tablero);
    cout << cartasEnFila(tablero, 0) << endl;    // esperado: 0

    colocarCarta(tablero, 0, 0, 0);              // As de picas
    colocarCarta(tablero, 0, 3, 25);
    cout << cartasEnFila(tablero, 0) << endl;    // esperado: 2
    cout << cartasEnFila(tablero, 1) << endl;    // esperado: 0

    colocarCarta(tablero, 0, 1, 10);
    colocarCarta(tablero, 0, 2, 11);
    colocarCarta(tablero, 0, 4, 12);
    cout << cartasEnFila(tablero, 0) << endl;    // esperado: 5
    
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            cout << tablero[f][c] << " ";
        }
        cout << endl;
    }

    return 0;
}