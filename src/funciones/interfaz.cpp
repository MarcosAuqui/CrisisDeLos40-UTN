/* 
funciones a desarrollar

configurarConsola() - -

mostrarMenu() - - 

mostrarReglas() - - 

mostrarCarta() - -

lineaJugador() quiza vuele

mostrarTurno()

mostrarPantalla() - - se modifica todo, debe recibir tablero, nombres, puntajes,. jugador activo y cantMazo

pedirFila() --

pedirColumna() -- 

pedirCartaTablero()

pedirNombre()

mostrarEstadisticas()

mostrarFilaCompleta() se completo La fila

mostrarTotalFila() cout de 30 exacto o crisis de los 40 o suma normal

mostrarGanador()

mostrarMensajes() 
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "interfaz.h"
#include "cartas.h"
#include "tablero.h"
#include "utilidades.h"
#include "../constantes.h"
 
using namespace std;

void configurarConsola(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    system("color 2F");
}
/*congigurarConsola: deja la consola en UTF-8 (para simbolos de cartas)
y con fondo verde, letras blancas
se lo llama una vez desde el main*/
 
void mostrarMenu()
{
    cout << ". ------------------------------------------------------------------------------------------------------------------ ." << endl;
    cout << "|♥                                                                                                                  ♠|" << endl;
 
    for (int i = 0; i < 19; i++)
    {
        if (i == 2)
        {
            cout << "|                                               crisis de los cuarenta                                               |" << endl;
        }
        else if (i == 9)
        {
            cout << "|                                                     1 -Jugar-                                                      |" << endl;
            cout << "|                                                                                                                    |" << endl;
            cout << "|                                                     2 -Estadísticas-                                               |" << endl;
            cout << "|                                                                                                                    |" << endl;
            cout << "|                                                     3 -Reglas-                                                     |" << endl;
            cout << "|                                                                                                                    |" << endl;
            cout << "|                                                     0 -Salir-                                                      |" << endl;
        }
        else
        {
            cout << "|                                                                                                                    |" << endl;
        }
    }
 
    cout << "|♣                              (seleccione una opcion apretando el numero que marca)                               ♦|" << endl;
    cout << ". ------------------------------------------------------------------------------------------------------------------ ." << endl;
}
/*mostrarMenu: dibuja el menu principal. NO lee la opcion,eso lo hara main
con pedirOpcion(). 
Opciones segun enunciado: 1, 2, 3 y 0.*/

void lineaJugador(string nombre)
{
    int largo = nombre.length();
 
    cout << "| " << nombre << ":";
    for (int k = 0; k < 114 - largo; k++){
        cout << " ";
    }
    cout << "|" << endl;
}
/*lineaJugador: dibuja la fila "| NOMBRE:      |" rellenando con espacios hasta el borde.
nombre.length() es la cantidad de letras del nombre; asi el borde derecho no se corre*/
 
void mostrarPantalla(string nombre1, string nombre2)
{
    cout << ". ------------------------------------------------------------------------------------------------------------------ ." << endl;
    cout << "|♥                                                 crisis de los 40                                                 ♠|" << endl;
    cout << "| Puntuacion                                                                                                         |" << endl;
    lineaJugador(nombre1);
    lineaJugador(nombre2);
    cout << "|                                                                                                                    |" << endl;
 
    // 3 filas de 5 cartas (maqueta: siempre las mismas)
    for (int f = 0; f < 3; f++)
    {
        cout << "|                                         +---+  +---+  +---+  +---+  +---+                                          |" << endl;
        cout << "|                                         |♥  |  |♣  |  |♦  |  |♠  |  |j  |                                          |" << endl;
        cout << "|                                         | 1 |  | 2 |  | 3 |  | 4 |  | ! |                                          |" << endl;
        cout << "|                                         |  ♥|  |  ♣|  |  ♦|  |  ♠|  |  j|                                          |" << endl;
        cout << "|                                         +---+  +---+  +---+  +---+  +---+                                          |" << endl;
    }
 
    // relleno hasta la linea de abajo
    for (int i = 0; i < 6; i++)
    {
        cout << "|                                                                                                                    |" << endl;
    }
 
    cout << "|♣                             (apriete cualquier tecla para volver al menú principal)                              ♦|" << endl;
    cout << ". ------------------------------------------------------------------------------------------------------------------ ." << endl;
}
/*mostrarPantalla: MAQUETA de la pantalla del tablero (diseño de Santiago).
Todavia dibuja 15 cartas FIJAS y no muestra puntajes. Cuando definamos como
pintar las cartas reales la parte de las cartas se reemplaza por un bucle sobre
la matriz del tablero y esta funcion pasa a recibir tablero, puntajes, etc. */
 
void mostrarReglas()
{
    cout << ". ------------------------------------------------------------------------------------------------------------------ ." << endl;
    cout << "|♥                                                                                                                  ♠|" << endl;
 
    for (int i = 0; i < 19; i++)
    {
        if (i == 2)
        {
            cout << "|                                               crisis de los cuarenta                                               |" << endl;
        }
        else if (i == 9)
        {
            cout << "|                                                                                                                    |" << endl;
            cout << "|      Crisis de los 40 es un juego de cartas para 2 jugadores que se juega con un mazo de póker. Los jugadores      |" << endl;
            cout << "|      colocan cartas por turnos en un tablero de 3 filas y suman puntos al completarlas. Quien coloca la quinta     |" << endl;
            cout << "|      carta de una fila se lleva su puntaje, siempre que la suma no llegue a 40: si llega a 40 o más, los puntos    |" << endl;
            cout << "|                                                  son para el rival.                                                |" << endl;
        }
        else
        {
            cout << "|                                                                                                                    |" << endl;
        }
    }
 
    cout << "|♣                             (apriete cualquier tecla para volver al menú principal)                              ♦|" << endl;
    cout << ". ------------------------------------------------------------------------------------------------------------------ ." << endl;
}

/*mostrarReglas: texto del reglamento dentro del marco verde.
Se llama desde la opcion 3 del menu. Solo dibuja: la espera de la tecla la hace quien la llama. */

void mostrarCarta(int id){
    if(id == VACIO){
        cout << "[    ]";
    }else if(esComodin(id)){
        cout << "[COMODIN]";
    }else{
        int valor = valorCarta(id);
        int palo = paloCarta(id);

        cout << "[";

        switch (valor) {
            case 1: 
             cout << " A";
             break;
            case 11:
             cout << " J";
             break;
            case 12:
             cout << " Q";
             break;
            case 13:
             cout << " K";
             break;
            default:
             if(valor < 10){
                 cout << " " << valor;
             }else{
                 cout << valor;
             }
             break;
        }

        cout << " ";

        switch (palo) {
            case PICAS:
             cout << "P";
             break;
            case CORAZONES:
             cout << "C";
             break;
            case TREBOLES:
             cout << "T";
             break;
            default:
             cout << "D";
             break;
        }

        cout << "]";
    }
}
/*mostrarCarta: se encarga de imprimir las cartas
formato [valor palo], asi sera cada carta impresa en consola
si el id es VACIO imprime un casillero vacio [    ]
si es comodin imprime [COMODIN]
la usaran mostrar pantalla y jugar seguramente*/

int pedirFila(){
    cout << "Seleccione una Fila (1-3): ";
    int fila = pedirOpcion(1, 3);
    return fila - 1;
}
/*pedirFila: pide la fila al jugador (1 a 3) y la devuelve como indice (0 a 2).
La usan jugarComun, jugarDiamante y jugarComodin cada vez que hay que elegir una fila del tablero.*/

int pedirColumna(){
    cout << "Seleccione un casilero (1 -5): ";
    int columna = pedirOpcion(1, 5);
    return columna - 1;
}
/*pedirColumna: pide el casillero al jugador (1 a 5) y lo devuelve como indice (0 a 4).
Solo se usa para elegir una carta que ya esta puesta (reemplazar, intercambiar, retirar
y el origen de mover), porque las cartas nuevas van al primer casillero vacio.*/

void pedirCartaTablero(int tablero[FILAS][COLUMNAS], int& fila, int& columna){
    bool vacio;
    
    do{
        fila = pedirFila();
        columna = pedirColumna();

        vacio = casilleroLibre(tablero, fila, columna);

        if(vacio){
            cout << "Ese casillero esta vacio." << endl << "Elija una carta del tablero";
        }
    }while(vacio);

}
/*pedirCartaTablero: pide fila y casillero y repite hasta que el casillero 
tenga una carta. Devuelve fila y columna como indices desde 0, por referencia.
La usan jugarDiamante para reemplazar y jugarComodin para intercambiar, mover o retirar.
IMPORTANTE: al ser llamada se debe comprobar antes que el tablero no este vacio (tableroVacio).*/

void mostrarFilaCompleta(int tablero[FILAS][COLUMNAS], int fila, int suma){
    cout << "se completo la fila " << fila+1 << ": ";

    for(int c = 0; c < COLUMNAS; c++){
        mostrarCarta(tablero[fila][c]);
        cout << " ";
    }
    cout << endl;
    cout << "suma de la fila: " << suma << endl;

}
/*mostrarFilaCompleta: imprime las 5 cartas de la fila que se acaba de completar y su suma.
Usa mostrarCarta para cada casillero. fila viene como indice(0 a 2) y se muestra 
como 1 a 3. La usara completarFila antes de puntuar y vaciar la fila.*/

void mostrarResultadoFila(string nombrejugador, string nombreRival, int suma){
    if(suma == PUNTOS_EXACTOS){
        cout << "30 exacto! " <<nombrejugador << "suma " << PUNTOS_EXACTOS << "puntos y " << nombreRival << "resta " << PENALIDAD_EXACTO << endl;
    }else if(suma >  PUNTOS_EXACTOS && suma < LIMITE_CRISIS){
        cout << nombrejugador << " suma " << suma << " puntos." << endl;
    }else if(suma >= LIMITE_CRISIS){
        cout << "CRISIS DE LOS 40! Los " << suma << "puntos son para " << nombreRival << endl;
    }else{
        cout << "la fila no llega a " << PUNTOS_EXACTOS << ": nadie suma puntos " << endl;
    }
}
/*mostrarResultadoFila: imprime que paso con los puntos segun la suma (30 exacto, 31 a 39,
crisis de los 40 o menos de 30). Solo imprime, los puntajes los cambia puntuarFila.
La llama completarFila  despues de puntuar.*/