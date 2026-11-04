#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"

using namespace std;

int main() {
    int tablero[FILAS][COLUMNAS];

    inicializarTablero(tablero);

    colocarCarta(tablero, 1, 3, 25);              // K de corazones
    cout << tablero[1][3] << endl;                // esperado: 25

    int sacada = quitarCarta(tablero, 1, 3);
    cout << sacada << endl;                       // esperado: 25
    cout << tablero[1][3] << endl;                // esperado: -1

    // Prueba con el id 0 (As de picas)
    colocarCarta(tablero, 0, 0, 0);
    int otra = quitarCarta(tablero, 0, 0);
    cout << otra << endl;                         // esperado: 0
    cout << tablero[0][0] << endl;                // esperado: -1
    
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            cout << tablero[f][c] << " ";
        }
        cout << endl;
    }

    return 0;
}