#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"
using namespace std;

int main(){
    int t[FILAS][COLUMNAS];
    inicializarTablero(t);
    cout << primerCasilleroVacio(t, 0) << " ";   // 0
    colocarCarta(t, 0, 0, 10);
    colocarCarta(t, 0, 1, 11);
    cout << primerCasilleroVacio(t, 0) << " ";   // 2
    quitarCarta(t, 0, 0);
    cout << primerCasilleroVacio(t, 0) << endl;  // 0 (hueco al principio)
    return 0;
}