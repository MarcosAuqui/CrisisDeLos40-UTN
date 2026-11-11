#include <iostream>
#include "funciones/tablero.h"
#include "constantes.h"

using namespace std;


int main()
{
    int tablero[FILAS][COLUMNAS];


    // Inicializar todo vacío
    inicializarTablero(tablero);


    // Simulamos cartas colocadas manualmente
    // Fila 1:
    tablero[0][0] = 7;   // carta cualquiera
    tablero[0][3] = 12;


    // Fila 2:
    tablero[1][1] = 25;
    tablero[1][2] = 40;
    tablero[1][4] = 5;


    // Fila 3:
    tablero[2][0] = 18;


    cout << "=== PRUEBA DE CASILLEROS LIBRES ===" << endl;


    int fila;

    cout << "Ingrese fila a consultar (1-3): ";
    cin >> fila;

    fila--; // pasamos a indice de matriz


    cout << endl;

    mostrarCasillerosLibres(tablero, fila);


    cout << endl;


    int columna;

    cout << "Ingrese columna a comprobar (1-5): ";
    cin >> columna;

    columna--;


    if(casilleroLibre(tablero, fila, columna))
    {
        cout << "El casillero esta libre." << endl;
    }
    else
    {
        cout << "El casillero esta ocupado." << endl;
    }


    return 0;
}