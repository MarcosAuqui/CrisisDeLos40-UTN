#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"

using namespace std;

int main() {
    int tablero[FILAS][COLUMNAS];

    inicializarTablero(tablero);
    cout << filaLlena(tablero, 0) << endl;     // 0 (vacía)

    colocarCarta(tablero, 0, 0, 0);            // As de picas referencia
    colocarCarta(tablero, 0, 1, 10);
    colocarCarta(tablero, 0, 3, 25);
    colocarCarta(tablero, 0, 4, 12);
    cout << filaLlena(tablero, 0) << endl;     // 0 (debe haber 4 cartas)

    colocarCarta(tablero, 0, 2, 11);
    cout << filaLlena(tablero, 0) << endl;     // 1 (5 cartas)

    cout << filaLlena(tablero, 1) << endl;     // 0 (otra fila, vacía)

    quitarCarta(tablero, 0, 2);
    cout << filaLlena(tablero, 0) << endl;     // 0 (volvió a 4)

    return 0;
}