#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"
#include "funciones/interfaz.h"
using namespace std;

int main(){
    int t[FILAS][COLUMNAS];
    int f, c;

    inicializarTablero(t);
    colocarCarta(t, 1, 2, 25);  // una carta en fila 2, casillero 3
    pedirCartaTablero(t, f, c);
    
    cout << "Eligio fila " << f << " columna " << c << " carta " << t[f][c] << endl;
    return 0;
}