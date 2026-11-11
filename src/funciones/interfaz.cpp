/* 
funciones a desarrollar

configurarConsola() - -

mostrarMenu() - - 

mostrarPantalla() - -

mostrarReglas() - - 

mostrarTurno()

mostrarMensajes() 

mostrarCarta()

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "interfaz.h"
#include "cartas.h"
#include "tablero.h"
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

void mostrarCasillerosLibres(int tablero[FILAS][COLUMNAS], int fila){
    for(int c = 0; c < COLUMNAS; c++){
        if(casilleroLibre(tablero, fila, c)){
            cout << c + 1 << " ";
        }
    }
    cout << endl;
}
/*mostrarCasillerosLibres: imprime los numeros (1 a 5) de los casilleros libres de la fila
la usara pedirCasillero cuando el jugador tenga que elegir un casillero libre*/