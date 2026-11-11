#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"

using namespace std;

int main() {
    int tablero[FILAS][COLUMNAS];

    inicializarTablero(tablero);
    cout << tableroVacio(tablero) << endl;     // esperado: 1 (recién inicializado)

    colocarCarta(tablero, 2, 4, 0);            // As de picas, id 0, en la última fila
    cout << tableroVacio(tablero) << endl;     // esperado: 0 (hay una carta)

    quitarCarta(tablero, 2, 4);
    cout << tableroVacio(tablero) << endl;     // esperado: 1 (volvió a quedar vacío)

    colocarCarta(tablero, 0, 0, 25);
    cout << tableroVacio(tablero) << endl;     // esperado: 0 (carta en la primera fila)

    return 0;
}