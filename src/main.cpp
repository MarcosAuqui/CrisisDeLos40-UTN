#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"
#include "funciones/interfaz.h"
using namespace std;

int main(){
    int t[FILAS][COLUMNAS];

    inicializarTablero(t);

    colocarCarta(t, 1, 0, 38);  // K de treboles
    colocarCarta(t, 1, 1, 43);  // 5 de diamantes
    colocarCarta(t, 1, 2, 7);   // 8 de picas
    colocarCarta(t, 1, 3, 14); // 2 de corazones
    colocarCarta(t, 1, 4, 40);  // 2 de diamantes

    mostrarFilaCompleta(t, 1, 30);

    mostrarResultadoFila("ANGEL", "ABEL", 30);
    mostrarResultadoFila("ANGEL", "ABEL", 35);
    mostrarResultadoFila("ANGEL", "ABEL", 41);
    mostrarResultadoFila("ANGEL", "ABEL", 25);

    return 0;
}