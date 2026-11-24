#include <iostream>
#include <string>
#include "constantes.h"
#include "funciones/mazo.h"
#include "funciones/tablero.h"
#include "funciones/interfaz.h"
#include "funciones/juego.h"
using namespace std;

int main(){
    configurarConsola();

    int mazo[TOTAL_CARTAS];
    int cantMazo;
    int tablero[FILAS][COLUMNAS];
    int puntaje[2] = {0, 0};
    string nombres[2] = {"ANGEL", "ABEL"};

    crearMazo(mazo, cantMazo);
    inicializarTablero(tablero);
    cantMazo = cantMazo - 3;            // las 3 cartas que ponemos a mano salieron del mazo

    colocarCarta(tablero, 0, 0, 38);    // K T en fila 1
    colocarCarta(tablero, 0, 1, 14);    // 2 C en fila 1
    colocarCarta(tablero, 1, 0, 22);    // 10 C en fila 2

    cout << "-- Mensaje de reemplazo (A de treboles por K de diamantes)" << endl;
    mostrarCartaReemplazada("ANGEL", 26, 51, 0);

    cout << endl << "-- Comodin: retirar" << endl;
    mostrarPantalla(tablero, nombres, puntaje, 0, cantMazo);
    comodinRetirar(tablero, mazo, cantMazo, nombres, 0);
    mostrarPantalla(tablero, nombres, puntaje, 0, cantMazo);
    return 0;
}