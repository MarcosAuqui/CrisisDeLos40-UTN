/* 
funciones a desarrolla

completarFila()

jugarComun()

jugarDiamante()

jugarComodin()

jugarTurno()

jugar()
*/

#include <string>
using namespace std;
#include "juego.h"
#include "tablero.h"
#include "mazo.h"
#include "interfaz.h"
#include "reglas.h"
#include "../constantes.h"

void completarFila(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], string nombre[2], int jugador, int fila){
    
    int rival = 1 - jugador;
    int suma = sumarFila(tablero, fila);

    mostrarFilaCompleta(tablero, fila, suma);
    puntuarFila(puntaje, jugador, suma);
    mostrarResultadoFila(nombre[jugador], nombre[rival], suma);
    devolverFila(tablero, mazo, cantMazo, fila);
}
/*completarFila: resuelve una fila que acaba de llegar a 5 cartas. Primero la muestra con su 
suma, despues reparte los puntos con puntuarFila, muestra que paso con ellos y por ultimo 
devuelve las 5 cartas al mazo. La usaran jugarComun, jugarDiamante (al colocar)
y jugarComodin (al mover), siempre con el jugador del turno, que es quien completo la fila.*/

void jugarComun(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, int puntaje[2], string nombre[2], int jugador, int carta){
    int fila = pedirFila();
    int columna = primerCasilleroVacio(tablero, fila);

    colocarCarta(tablero, fila, columna, carta);
    mostrarCartaColocada(nombre[jugador], carta, fila);

    if(cartasEnFila(tablero, fila) == COLUMNAS){
        completarFila(tablero, mazo, cantMazo, puntaje, nombre, jugador, fila);
    }
}
/*jugarComun: juega una carta comun (pica, corazon o trebol). El jugador elige la fila y la carta
cae en el primer casillero vacio. Si con esa carta la fila llega a 5, aplica completarFila.
No devuelve la carta no jugada ni mezcla, eso lo hace jugarTurno. La reutiliza jugarDiamante
cuando el diamante se coloca en un casillero vacio.*/

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

void comodinRetirar(int tablero[FILAS][COLUMNAS], int mazo[], int& cantMazo, string nombres[2], int jugador){
    int fila, columna;
    pedirCartaTablero(tablero, fila, columna);

    int carta = quitarCarta(tablero, fila, columna);
    devolverCarta(mazo, cantMazo, carta);

    mostrarCartaRetirada(nombres[jugador], carta, fila);
}

/*comidinRetirar: jugada del comodin que saca una carta del tablero y devuelve
al mazo, la va a llamar jugarComodin*/