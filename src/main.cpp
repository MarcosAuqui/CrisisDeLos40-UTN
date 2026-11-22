#include <iostream>
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

    // fila 3: vacia
    for(int f = 0; f < FILAS; f++){
        mostrarFilaTablero(tablero, f);
    }
    return 0;
}