#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "constantes.h"
#include "funciones/cartas.h"
#include "funciones/mazo.h"
#include "funciones/tablero.h"
#include "funciones/interfaz.h"
#include "funciones/reglas.h"
#include "funciones/juego.h"
using namespace std;

int main(){

    srand(time(NULL));

    int mazo[TOTAL_CARTAS];
    int cantMazo;
    int tablero[FILAS][COLUMNAS];
    int puntaje[2] = {0, 0};
    string nombre[2] = {"ANGEL", "ABEL"};
    int jugador = 0;
    int turno = 1;
    int carta;

    crearMazo(mazo, cantMazo); //inicia matriz
    mezclar(mazo, cantMazo);
    inicializarTablero(tablero);//inicializa toda la matriz en -1

    while(hayGanador(puntaje) == -1 && turno <= 30){
        cout << endl << "===== Turno " << turno << " | juega " << nombre[jugador] << " =====" << endl;
        cout << nombre[0] << ": " << puntaje[0] << " puntos | " << nombre[1] << ": " << puntaje[1] << " puntos | mazo: " << cantMazo << endl;

        for(int f = 0; f < FILAS; f++){
            cout << "Fila " << f + 1 << ": ";
            for(int c = 0; c < COLUMNAS; c++){
                mostrarCarta(tablero[f][c]);
                cout << " ";
            }
            cout << " Cartas: " << cartasEnFila(tablero, f) << "/5  Suma: " << sumarFila(tablero, f) << endl;
        }

        // roba una carta; si sale comodin la devuelve y vuelve a robar (jugarComun no los maneja)
        do{
            carta = robarCarta(mazo, cantMazo);
            if(esComodin(carta)){
                devolverCarta(mazo, cantMazo, carta);
                mezclar(mazo, cantMazo);
            }
        }while(esComodin(carta));

        cout << endl << nombre[jugador] << " robo: ";
        mostrarCarta(carta);
        cout << endl;

        jugarComun(tablero, mazo, cantMazo, puntaje, nombre, jugador, carta);

        mezclar(mazo, cantMazo);
        jugador = 1 - jugador;
        turno++;
    }

    cout << endl << "===== FIN TEST =====" << endl;
    cout << nombre[0] << ": " << puntaje[0] << " | " << nombre[1] << ": " << puntaje[1] << endl;
    if(hayGanador(puntaje) != -1){
        cout << "Gano " << nombre[hayGanador(puntaje)] << endl;
    }else{
        cout << "Nadie llego a 50 en 30 turnos" << endl;
    }
    return 0;
}