/*
funciones

completarFila()

jugarComun()

jugarDiamante()

comodinIntercambiar()

comodinMover()

comodinRetirar()

jugarComodin()

jugarTurno()

jugar()
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "juego.h"
#include "cartas.h"
#include "utilidades.h"
#include "jugadores.h"
#include "tablero.h"
#include "mazo.h"
#include "interfaz.h"
#include "reglas.h"
#include "../constantes.h"

// FILA COMPLETA
void completarFila(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], string nombre[2], int jugador, int fila){
    
    int rival = 1 - jugador;
    int suma = sumarFila(tablero, fila);

    mostrarFilaCompleta(tablero, fila, suma);
    puntuarFila(puntaje, jugador, suma);
    mostrarResultadoFila(nombre[jugador], nombre[rival], suma);
    devolverFila(tablero, mazo, cantMazo, fila);
}
/*completarFila: cuando una fila llega a 5 la muestra, reparte los puntos con puntuarFila,
muestra el resultado y devuelve las 5 cartas al mazo
la usan jugarComun y comodinMover*/

// CARTA COMUN Y DIAMANTE
void jugarComun(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], string nombre[2], int jugador, int carta){
    int fila = pedirFila();
    int columna = primerCasilleroVacio(tablero, fila);

    colocarCarta(tablero, fila, columna, carta);
    mostrarCartaColocada(nombre[jugador], carta, fila);

    if(cartasEnFila(tablero, fila) == COLUMNAS){
        completarFila(tablero, mazo, cantMazo, puntaje, nombre, jugador, fila);
    }
}
/*jugarComun: juega una carta comun, el jugador elige la fila y cae en el primer vacio
si la fila llega a 5 llama a completarFila. tambien la usa jugarDiamante para colocar*/

void jugarDiamante(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], string nombres[2], int jugador, int carta){
    if(tableroVacio(tablero)){
        jugarComun(tablero, mazo, cantMazo, puntaje, nombres, jugador, carta);
        return;
    }

    int jugada = pedirJugarDiamante();

    if(jugada == 1){
        jugarComun(tablero, mazo, cantMazo, puntaje, nombres, jugador, carta);
    }else{
        int fila, columna;
        pedirCartaTablero(tablero, fila, columna);

        int cartaVieja = quitarCarta(tablero, fila, columna);
        colocarCarta(tablero, fila, columna, carta);
        devolverCarta(mazo, cantMazo, cartaVieja);

        mostrarCartaReemplazada(nombres[jugador], cartaVieja, carta, fila);
    }
}
/*jugarDiamante: juega una carta de diamantes, si el tableor esta vacio solo se puede
colocar y no se pregunta sino el jugador elige entre colocar o reemplazar una del tablero.
cartaVieja vuelve al mazo y el diamante ocupoa su lugar
reemplazar nunca completa una fila asi que no se llama a completarFila*/

// COMODIN
void comodinIntercambiar(int tablero[FILAS][COLUMNAS], string nombres[2], int jugador){
    int fila1, columna1, fila2, columna2;
    pedirDosCartasTablero(tablero, fila1, columna1, fila2, columna2);

    int carta1 = quitarCarta(tablero, fila1, columna1);
    int carta2 = quitarCarta(tablero, fila2, columna2);

    colocarCarta(tablero, fila1, columna1, carta2);
    colocarCarta(tablero, fila2, columna2, carta1);

    mostrarIntercambio(nombres[jugador], carta1, fila1, carta2, fila2);
}
/*comidinIntercambiar: jugada dle comodin que cambia de lugar 2 cartas seleccionadas en tablero
saca las 2 y pone una en casillero de la otra*/

void comodinMover(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], string nombres[2], int jugador){
    int filaOrigen, columnaOrigen;
    pedirCartaTablero(tablero, filaOrigen, columnaOrigen);

    int filaDestino = pedirFilaDestino(filaOrigen);

    int carta = quitarCarta(tablero, filaOrigen, columnaOrigen);
    int columnaDestino = primerCasilleroVacio(tablero, filaDestino);
    colocarCarta(tablero, filaDestino, columnaDestino, carta);

    mostrarMovimiento(nombres[jugador], carta, filaOrigen, filaDestino);

    if(cartasEnFila(tablero, filaDestino) == COLUMNAS){
        completarFila(tablero, mazo, cantMazo, puntaje, nombres, jugador, filaDestino);
    }
}
/*comodinMover: mueve una carta del tablero al primer vacio de otra fila
si la fila destino llega a 5 se completa y puntua el que jugo el comodin
la usa jugarComodin*/

void comodinRetirar(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, string nombres[2], int jugador){
    int fila, columna;
    pedirCartaTablero(tablero, fila, columna);

    int carta = quitarCarta(tablero, fila, columna);
    devolverCarta(mazo, cantMazo, carta);

    mostrarCartaRetirada(nombres[jugador], carta, fila);
}

/*comidinRetirar: jugada del comodin que saca una carta del tablero y devuelve
al mazo, la va a llamar jugarComodin*/

void jugarComodin(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], string nombres[2], int jugador){
    int total = 0;

    for(int f = 0; f < FILAS; f++){
        total += cartasEnFila(tablero, f);
    }

    int jugada = pedirJugadaComodin(total);

    if(jugada == 1){
        comodinIntercambiar(tablero, nombres, jugador);
    }else if(jugada == 2){
        comodinMover(tablero, mazo, cantMazo, puntaje, nombres, jugador);
    }else{
        comodinRetirar(tablero, mazo, cantMazo, nombres, jugador);
    }
}
/*jugarComodin: cuenta las cartas del tablero, pregunta la jugada del comodin y
llama a comodinINtercambiar, comodinMover o comodinRetirar. el tablero no puede estar vacio.*/

// TURNO Y PARTIDA
void jugarTurno(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], string nombres[2], int jugador){
    int robadas[2];
    robadas[0] = robarCarta(mazo, cantMazo);
    robadas[1] = robarCarta(mazo, cantMazo);

    limpiarPantalla();
    mostrarPantalla(tablero, nombres, puntaje, jugador, cantMazo);
    mostrarCartasRobadas(nombres[jugador], robadas[0], robadas[1]);

    bool vacio = tableroVacio(tablero);

    if(esComodin(robadas[0]) && esComodin(robadas[1]) && vacio){
        mostrarPierdeTurno(nombres[jugador]);
        devolverCarta(mazo, cantMazo, robadas[0]);
        devolverCarta(mazo, cantMazo, robadas[1]);
    }else{
        int elegida = pedirCartaJugar(robadas, vacio);
        int carta = robadas[elegida];
        int noJugada = robadas[1 - elegida];

        if(esComodin(carta)){
            jugarComodin(tablero, mazo, cantMazo, puntaje, nombres, jugador);
            devolverCarta(mazo, cantMazo, carta);
        }else if(esDiamante(carta)){
            jugarDiamante(tablero, mazo, cantMazo, puntaje, nombres, jugador, carta);
        }else{
            jugarComun(tablero, mazo, cantMazo, puntaje, nombres, jugador, carta);
        }

        devolverCarta(mazo, cantMazo, noJugada);
    }

    mezclar(mazo, cantMazo);
    esperarTecla();
}
/*jugarTurno: un turno entero. roba 2 cartas, muestra pantalla y cartas
si son los 2 comodines con el tablero vacio pierde el turno
si no elige carta y la juega segun sea comun, diamante o comodin
despues vuelven al mazo la que no se jugo y el comodin, se mezcla y espera tecla. la usa jugar*/

void jugar(string& mejorNombre, int& mejorPuntaje){
    int mazo[TOTAL_CARTAS];
    int cantMazo;
    int tablero[FILAS][COLUMNAS];
    int puntaje[2] = {0, 0};
    string nombres[2];

    crearMazo(mazo, cantMazo);
    mezclar(mazo, cantMazo);
    inicializarTablero(tablero);

    limpiarPantalla();
    pedirNombres(nombres);

    int jugador = rand() % 2;
    cout << "Sorteo: empieza " << nombres[jugador] << "." << endl;   //unica excepcion: imprime fuera de interfaz
    esperarTecla();

    while(hayGanador(puntaje) == -1){
        jugarTurno(tablero, mazo, cantMazo, puntaje, nombres, jugador);
        jugador = 1 - jugador;
    }

    int ganador = hayGanador(puntaje);
    limpiarPantalla();
    mostrarPantalla(tablero, nombres, puntaje, ganador, cantMazo);
    mostrarGanador(nombres[ganador], puntaje[ganador]);
    actualizarMejorJugador(nombres, puntaje, mejorNombre, mejorPuntaje);
    esperarTecla();
}
/*jugar: la partida entera. arma mazo y tablero, pide nombres y sortea quien empieza
repite jugarTurno hasta que alguien llega a 50, muestra el ganador y actualiza el mejor jugador
la usa main en la opcion 1*/
