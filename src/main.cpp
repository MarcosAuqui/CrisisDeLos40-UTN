#include <iostream>
#include <cstdlib>
#include <ctime>
#include "constantes.h"
#include "funciones/mazo.h"
#include "funciones/tablero.h"

using namespace std;

int main() {
    srand(time(NULL));    // una sola vez, al principio del programa

    int mazo[TOTAL_CARTAS]; //mazo
    int cantMazo = 0;

    int tablero[FILAS][COLUMNAS]; //Tablero matriz

    crearMazo(mazo, cantMazo);
    mezclar(mazo, cantMazo);
    cout << "mazo creado y mezclado" << endl;

    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            tablero[f][c] = 3;
        }
    }
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            cout << tablero[f][c] << " ";
        }
        cout << endl;
    }

    cout << "matriz crada con 7 en todo" << endl;

    inicializarTablero(tablero);

    cout << "matriz inicializada" << endl;

    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            cout << tablero[f][c] << " ";
        }
        cout << endl;
    }

    return 0;
}