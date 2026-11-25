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
    cantMazo = cantMazo - 1;            // la carta que ponemos a mano salio del mazo

    colocarCarta(tablero, 0, 0, 38);    // K T en fila 1, unica carta del tablero

    mostrarPantalla(tablero, nombres, puntaje, 0, cantMazo);
    jugarComodin(tablero, mazo, cantMazo, puntaje, nombres, 0);
    mostrarPantalla(tablero, nombres, puntaje, 0, cantMazo);
    return 0;
}