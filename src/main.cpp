#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "constantes.h"
#include "funciones/tablero.h"
#include "funciones/interfaz.h"
using namespace std;

int main(){
    srand(time(NULL));
    configurarConsola();

    int tablero[FILAS][COLUMNAS];
    inicializarTablero(tablero);
    string nombres[2];
    int puntaje[2] = {0, 0};

    pedirNombres(nombres);

    int jugador = rand() % 2;
    cout << "Sorteo: empieza " << nombres[jugador] << "." << endl;

    mostrarPantalla(tablero, nombres, puntaje, jugador, 54);
    mostrarCartasRobadas(nombres[jugador], 10, 40);

    int elegida = pedirCartaJugar();
    cout << "Elegiste el indice " << elegida << endl;
    
    return 0;
}