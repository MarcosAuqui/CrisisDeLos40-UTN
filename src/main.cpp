#include <iostream>
#include <string>
#include <cstdlib>              // rand y srand
#include <ctime>                // time, para la semilla del azar
#include "constantes.h"
#include "funciones/cartas.h"       // esComodin, esDiamante
#include "funciones/mazo.h"         // crearMazo, mezclar, robarCarta, devolverCarta
#include "funciones/tablero.h"      // inicializarTablero
#include "funciones/utilidades.h"   // limpiarPantalla, esperarTecla
#include "funciones/interfaz.h"     // pantalla, cartas robadas, pedidos al jugador
#include "funciones/reglas.h"       // hayGanador
#include "funciones/juego.h"        // jugarComun, jugarDiamante
using namespace std;

int main(){
    srand(time(NULL));          // inicia el azar una sola vez, para que cada partida sea distinta
    configurarConsola();        // consola en UTF-8 (simbolos de palos) y colores verdes

    int mazo[TOTAL_CARTAS];         // las 54 cartas del mazo (ids 0 a 53)
    int cantMazo;                   // cuantas cartas hay en el mazo ahora
    int tablero[FILAS][COLUMNAS];   // matriz 3x5, VACIO = -1 en los casilleros libres
    int puntaje[2] = {0, 0};        // puntaje de cada jugador, arrancan en 0
    string nombres[2];              // nombre de cada jugador
    int robadas[2];                 // las 2 cartas que roba el jugador en su turno

    crearMazo(mazo, cantMazo);      // llena el mazo con los ids 0 a 53 y deja cantMazo en 54
    mezclar(mazo, cantMazo);        // desordena el mazo
    inicializarTablero(tablero);    // deja los 15 casilleros en VACIO

    pedirNombres(nombres);          // pide los 2 nombres (maximo 15 letras)
    int jugador = rand() % 2;       // sorteo: 0 o 1 al azar, como tirar una moneda
    cout << "Sorteo: empieza " << nombres[jugador] << "." << endl;
    esperarTecla();                 // pausa para leer el sorteo

    while(hayGanador(puntaje) == -1){   // se juega mientras nadie llegue a 50 (-1 = sin ganador)

        // robar 2 cartas, si sale comodin se devuelve y se roba otra (todavia no esta hhecha jugarComodin)
        for(int i = 0; i < 2; i++){                     // una vuelta por cada carta robada
            do{
                robadas[i] = robarCarta(mazo, cantMazo);    // saca la carta de arriba del mazo
                if(esComodin(robadas[i])){                  // si es comodin...
                    devolverCarta(mazo, cantMazo, robadas[i]);  // ...vuelve al mazo
                    mezclar(mazo, cantMazo);                    // y se mezcla para no robarlo de nuevo
                }
            }while(esComodin(robadas[i]));              // repite hasta que no sea comodin
        }

        limpiarPantalla();                                                  // borra la consola
        mostrarPantalla(tablero, nombres, puntaje, jugador, cantMazo);      // marco con puntajes y tablero
        mostrarCartasRobadas(nombres[jugador], robadas[0], robadas[1]);     // las 2 cartas en cajita

        int elegida = pedirCartaJugar();        // indice de la carta elegida: 0 o 1
        int carta = robadas[elegida];           // la carta que se juega
        int noJugada = robadas[1 - elegida];    // la otra (si elegida es 0, es la 1, y al reves)

        if(esDiamante(carta)){                  // diamante: colocar o reemplazar
            jugarDiamante(tablero, mazo, cantMazo, puntaje, nombres, jugador, carta);
        }else{                                  // carta comun: se coloca en el primer hueco de la fila
            jugarComun(tablero, mazo, cantMazo, puntaje, nombres, jugador, carta);
        }

        devolverCarta(mazo, cantMazo, noJugada);    // la carta que no se jugo vuelve al mazo
        mezclar(mazo, cantMazo);                    // se mezcla al final del turno (paso 6 del turno)

        esperarTecla();                 // pausa para leer los mensajes antes de borrar la pantalla
        jugador = 1 - jugador;          // pasa el turno al otro (0 pasa a 1, 1 pasa a 0)
    }

    int ganador = hayGanador(puntaje);      // indice del que llego a 50 o mas
    limpiarPantalla();
    mostrarPantalla(tablero, nombres, puntaje, ganador, cantMazo);   // pantalla final con el ">" en el ganador
    cout << "*** " << nombres[ganador] << " GANA LA PARTIDA CON " << puntaje[ganador] << " PUNTOS ***" << endl;
    
    return 0;
}