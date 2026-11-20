#include <iostream>
#include <string>
#include "constantes.h"
#include "funciones/tablero.h"
#include "funciones/mazo.h"
#include "funciones/juego.h"
using namespace std;

int main(){

    int mazo[TOTAL_CARTAS];
    int cantMazo;
    int tablero[FILAS][COLUMNAS];
    int puntaje[2] = {10, 20};
    string nombre[2] = {"ANGEL", "ABEL"};

    crearMazo(mazo, cantMazo);
    inicializarTablero(tablero);

    // fila 2: K T, 5 D, 8 P, 2 C, 2 D (suma 30)
    colocarCarta(tablero, 1, 0, 38);
    colocarCarta(tablero, 1, 1, 43);
    colocarCarta(tablero, 1, 2, 7);
    colocarCarta(tablero, 1, 3, 14);
    colocarCarta(tablero, 1, 4, 40);
    
    cantMazo = cantMazo - 5;   // simulamos que esas 5 cartas salieron del mazo

    cout << "Antes: puntajes " << puntaje[0] << " " << puntaje[1] << " | mazo " << cantMazo << " | cartas en fila 2: " << cartasEnFila(tablero, 1) << endl;
    completarFila(tablero, mazo, cantMazo, puntaje, nombre, 0, 1);
    cout << "Despues: puntajes " << puntaje[0] << " " << puntaje[1] << " | mazo " << cantMazo << " | cartas en fila 2: " << cartasEnFila(tablero, 1) << endl;
  
    return 0;
}
