#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"

using namespace std;

int main() {
    
    int tablero[FILAS][COLUMNAS];
    inicializarTablero(tablero);

    cout << sumarFila(tablero, 0) << endl;   // esperado: 0 (fila vacía)

    colocarCarta(tablero, 0, 0, 0);         // As de picas = 1
    colocarCarta(tablero, 0, 1, 6);         // 7 de picas = 7
    colocarCarta(tablero, 0, 2, 25);        // K de corazones = 13
    cout << sumarFila(tablero, 0) << endl;   // 21

    cout << sumarFila(tablero, 1) << endl;   // 0 (otra fila, vacía)
    return 0;
}
