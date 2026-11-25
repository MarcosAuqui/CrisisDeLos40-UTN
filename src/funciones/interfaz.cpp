/*
funciones

configurarConsola()

espacios()

mostrarCarta()

simboloPalo()

mostrarValorCentro()

mostrarLineaCarta()

dibujarCarta()

mostrarMenu()

mostrarReglas()

mostrarEstadisticas()

lineaJugador()

mostrarFilaTablero()

mostrarPantalla()

pedirNombres()

mostrarCartasRobadas()

pedirCartaJugar()

mostrarPierdeTurno()

pedirFila()

pedirColumna()

pedirCartaTablero()

pedirDosCartasTablero()

pedirFilaDestino()

mostrarCartaColocada()

mostrarFilaCompleta()

mostrarResultadoFila()

pedirJugarDiamante()

mostrarCartaReemplazada()

pedirJugadaComodin()

mostrarIntercambio()

mostrarMovimiento()

mostrarCartaRetirada()

mostrarGanador()
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

// CONSOLA Y AUXILIARES
void configurarConsola(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    system("color 2F");
}
/*congigurarConsola: deja la consola en UTF-8 (para simbolos de cartas)
y con fondo verde, letras blancas
se lo llama una vez desde el main*/

void espacios(int n){
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}
/*espacios: imprime n espacios seguidos, sirve para rellenar el marco
asi no se corre el borde derecho*/

// DIBUJO DE CARTAS
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

string simboloPalo(int palo){
    switch (palo) {
        case PICAS:
            return "♠";
        case CORAZONES:
            return "♥";
        case TREBOLES:
            return "♣";
        default:
            return "♦";
    }
}
/*simboloPalo: traduce el numero de palo(0-3) al simbolo UTF-8 que se dibuja en la carta.
la usara mostrarLineaCarta para dibujar las esquinas de la carta*/

void mostrarValorCentro(int valor){
    switch (valor) {
        case 1:
            cout << " A ";
            break;
        case 11:
            cout << " J ";
            break;
        case 12:
            cout << " Q ";
            break;
        case 13:
            cout << " K ";
            break;
        default:
            if (valor == 10) {
                cout << "10 ";
            } else {
                cout << " " << valor << " ";
            }
            break;
    }
}
/*mostrarValorCentro: imprime el valor de la carta en casos de A, J , Q, K
La usara mostrarLineaCarta en la linea del medio de la carta*/

void mostrarLineaCarta(int id, int linea){
    if (linea == 0 || linea == 4) {
        cout << "+---+";
        return;
    }

    if (id == VACIO) {
        cout << "|   |";
        return;
    }

    if (esComodin(id)) {
        if (linea == 1) {
            cout << "|*  |";
        } else if (linea == 2) {
            cout << "|JOK|";
        } else {
            cout << "|  *|";
        }
        return;
    }

    string s = simboloPalo(paloCarta(id));

    if (linea == 1) {
        cout << "|" << s << "  |";
    } else if (linea == 2) {
        cout << "|";
        mostrarValorCentro(valorCarta(id));
        cout << "|";
    } else {
        cout << "|  " << s << "|";
    }
}
/*mostrarLineaCarta: dibuja una sola linea (0 a 4) de la cajita de la carta
como la consola imprime de arriba para abajo se llama linea por linea
sirve para carta normal, casillero vacio y comodin*/

void dibujarCarta(int id){
    for(int linea = 0; linea < 5; linea++){
        mostrarLineaCarta(id, linea);
        cout << endl;
    }
}
/*dibujarCarta: dibuja una carta entera en cajita, las 5 lineas una abajo de la otra
la usan los mensajes de reemplazar, retirar, mover e intercambiar*/

// MENU, REGLAS Y ESTADISTICAS
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
    cout << "Opcion: ";
}
/*mostrarMenu: dibuja el menu principal. NO lee la opcion,eso lo hara main
con pedirOpcion(). 
Opciones segun enunciado: 1, 2, 3 y 0.*/

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

void mostrarEstadisticas(string mejorNombre, int mejorPuntaje){
    cout << "ESTADISTICAS" << endl;
    if(mejorPuntaje == 0){
        cout << "Todavia no se jugo ninguna partida." << endl;
    }else{
        cout << "Mejor jugador: " << mejorNombre << " con " << mejorPuntaje << " puntos." << endl;
    }
}
/*mostrarEstadisticas: muestra el mejor jugador y su puntaje, si es 0 todavia no se jugo
(provisoria hasta que santi pase la suya con el marco). la usa main en la opcion 2*/

// PANTALLA DEL TURNO
void lineaJugador(string nombre, int puntos, bool activo)
{
    int largo = nombre.length();
    int cifras = 1;

    if (puntos >= 10) {
        cifras = 2;
    }
    if (puntos >= 100) {
        cifras = 3;
    }

    cout << "| ";
    if (activo) {
        cout << "> ";
    } else {
        cout << "  ";
    }
    cout << nombre << ": " << puntos << " puntos";

    espacios(104 - largo - cifras);
    cout << "|" << endl;
}
/*lineaJugador: dibuja la linea del marco con el nombre y los puntos del jugador
el > marca al que juega. cuenta los digitos del puntaje para rellenar bien con espacios
la usa mostrarPantalla*/

void mostrarFilaTablero(int tablero[FILAS][COLUMNAS], int f){
    for (int linea = 0; linea < 5; linea++) {
        cout << "|";

        if (linea == 2) {
            espacios(33);
            cout << "Fila " << f + 1 << "  ";
        } else {
            espacios(41);
        }

        for (int c = 0; c < COLUMNAS; c++) {
            mostrarLineaCarta(tablero[f][c], linea);
            if (c < COLUMNAS - 1) {
                cout << "  ";
            }
        }

        if (linea == 2) {
            int suma = sumarFila(tablero, f);
            cout << "  Cartas: " << cartasEnFila(tablero, f) << "/5  Suma: ";
            if (suma < 10) {
                cout << " ";
            }
            cout << suma;
            espacios(19);
        } else {
            espacios(42);
        }

        cout << "|" << endl;
    }
}
/*mostrarLineaCarta: dibuja las 5 cartas reales de la fila f, lionea por linea
respeta el ancho del marco(41 espacios izquierda y 42 derecha). en linea del medio
escribe el numero de fila, a la izq la cant de cartas y la suma a la derecha
la llamara mostrarPantalla una vez por cada fila del trablero.*/

void mostrarPantalla(int tablero[FILAS][COLUMNAS], string nombre[2], int puntaje[2], int jugador, int cantMazo)
{
    cout << ". ------------------------------------------------------------------------------------------------------------------ ." << endl;
    cout << "|♥                                                 crisis de los 40                                                 ♠|" << endl;

    cout << "| Objetivo: " << PUNTOS_VICTORIA << " puntos";
    espacios(74);
    cout << "Cartas en el mazo: " << cantMazo << " |" << endl;

    cout << "|";
    espacios(116);
    cout << "|" << endl;

    for (int j = 0; j < 2; j++)
    {
        bool activo = false;
        if (j == jugador) {
            activo = true;
        }
        lineaJugador(nombre[j], puntaje[j], activo);
    }

    cout << "|";
    espacios(116);
    cout << "|" << endl;

    for (int f = 0; f < FILAS; f++)
    {
        mostrarFilaTablero(tablero, f);
    }

    cout << "|";
    espacios(116);
    cout << "|" << endl;

    cout << "|♣";
    espacios(114);
    cout << "♦|" << endl;
    cout << ". ------------------------------------------------------------------------------------------------------------------ ." << endl;
}
/*mostrarPantalla: dibuja la pantalla del turno, objetivo, cartas del mazo, puntos de cada uno
con > en el que juega y las 3 filas del tablero. la usa jugarTurno*/

// INICIO DE PARTIDA
void pedirNombres(string nombres[2]){
    for(int i = 0; i < 2; i++){
        cout << "Ingrese nombre del jugador " << i+1 << " (maximo " << LARGO_MAX_NOMBRE << " letras) : ";
        cin >> nombres[i];
    
        while(nombres[i].length() > LARGO_MAX_NOMBRE){
            cout << "Nombre demasiado largo. Ingrese uno de hasta " << LARGO_MAX_NOMBRE << " letras: ";
            cin >> nombres[i];
        }
    }

}
/*pedirNombres: pide el nombre de los 2 jugadores y los guarda en  nombnres[]
se repite si el nombre pasa del largo maximo de nombres, que es 15, para no romper
el formato del tablero.
La Llamara jugar() al empezar partida*/

// TURNO
void mostrarCartasRobadas(string nombre, int carta1, int carta2){
    cout << "Turno de " << nombre << ". Cartas robadas del mazo: "<< endl;

    espacios(4);
    cout << "1";
    espacios(7);
    cout << "2" << endl;

    for(int linea = 0; linea < 5; linea++){
        espacios(2);
        mostrarLineaCarta(carta1, linea);
        espacios(3);
        mostrarLineaCarta(carta2, linea);
        cout << endl;
    }
}
/*mostrarCartasRobadas: muestra en consola las 2 cartas que el jugador activo
tomo del mazo, una al lado de la otra. Las imprime linea por linea con
mostrarLineaCarta()*/

int pedirCartaJugar(int robadas[2], bool vacio){
    cout << "Carta a jugar (1 o 2): ";
    int carta = pedirOpcion(1, 2) - 1;

    while(vacio && esComodin(robadas[carta])){
        cout << "El comodin no se puede jugar con el tablero vacio. Elegi la otra carta: ";
        carta = pedirOpcion(1, 2) - 1;
    }
    return carta;
}
/*pedirCartaJugar: pregunta que carta de las 2 robadas se juega y devuelve el indice (0 o 1)
si el tablero esta vacio no deja elegir el comodin. la usa jugarTurno*/

void mostrarPierdeTurno(string nombre){
    cout << nombre << " robo los dos comodines con el tablero vacio: pierde el turno." << endl;
}
/*mostrarPierdeTurno: avisa que pierde el turno por robar los 2 comodines
con el tablero vacio. la usa jugarTurno*/

// ELEGIR LUGAR DEL TABLERO
int pedirFila(){
    cout << "Seleccione una Fila (1-3): ";
    int fila = pedirOpcion(1, 3);
    return fila - 1;
}
/*pedirFila: pide la fila (1 a 3) y la devuelve como indice (0 a 2)
la usan las jugadas cada vez que hay que elegir fila*/

int pedirColumna(){
    cout << "Seleccione un casilero (1 -5): ";
    int columna = pedirOpcion(1, 5);
    return columna - 1;
}
/*pedirColumna: pide el casillero (1 a 5) y lo devuelve como indice (0 a 4)
solo para elegir una carta que ya esta puesta, las nuevas van al primer vacio*/

void pedirCartaTablero(int tablero[FILAS][COLUMNAS], int& fila, int& columna){
    bool vacio;
    
    do{
        fila = pedirFila();
        columna = pedirColumna();

        vacio = casilleroLibre(tablero, fila, columna);

        if(vacio){
            cout << "Ese casillero esta vacio. Elegi una carta del tablero." << endl;
        }
    }while(vacio);

}
/*pedirCartaTablero: pide fila y casillero hasta que elija uno con carta
devuelve fila y columna por referencia. antes hay que fijarse que el tablero no este vacio
la usan el diamante (reemplazar) y el comodin*/

void pedirDosCartasTablero(int tablero[FILAS][COLUMNAS], int& fila1, int& columna1, int& fila2, int& columna2){
    cout << "Primera carta:" << endl;
    pedirCartaTablero(tablero, fila1, columna1);

    cout << "Segunda carta:" << endl;
    pedirCartaTablero(tablero, fila2, columna2);

    while(fila2 == fila1 && columna2 == columna1){
        cout << "es la misma carta. Elegi otra." << endl;
        pedirCartaTablero(tablero, fila2, columna2);
    }
}
/*pedirDosCartasTablero: pide 2 cartas del tablero, si la segunda es la misma la vuelve a pedir
devuelve las posiciones por referencia. tiene que haber 2 cartas minimo
la usa comodinIntercambiar*/

int pedirFilaDestino(int filaOrigen){
    cout << "Fila destino:" << endl;
    int fila = pedirFila();

    while(fila == filaOrigen){
        cout << "La carta ya esta en esa fila. Elegi otra fila." << endl;
        fila = pedirFila();
    }
    return fila;
}
/*pedirFilaDestino: pide la fila a donde se mueve la carta con el comodin
y la repite si es la misma fila donde ya esta. devuelve el indice (0 a 2). La usa comodinMover*/

// CARTA COMUN Y FILA COMPLETA
void mostrarCartaColocada(string nombre, int carta, int fila){
    cout << nombre << " coloca "; 
    mostrarCarta(carta);
    cout << " en la fila " << fila+1 << "." << endl;
}
/*mostrarCartaColocada: muestra "ANGEL coloca [ 2 D] en la fila 2."
la usa jugarComun*/

void mostrarFilaCompleta(int tablero[FILAS][COLUMNAS], int fila, int suma){
    cout << "Se completo la fila " << fila+1 << ": ";

    for(int c = 0; c < COLUMNAS; c++){
        mostrarCarta(tablero[fila][c]);
        cout << " ";
    }
    cout << endl;
    cout << "Suma de la fila: " << suma << endl;

}
/*mostrarFilaCompleta: muestra las 5 cartas de la fila que se completo y la suma
la usa completarFila antes de puntuar*/

void mostrarResultadoFila(string nombreJugador, string nombreRival, int suma){
    if(suma == PUNTOS_EXACTOS){
        cout << "30 EXACTO! " << nombreJugador << " suma " << PUNTOS_EXACTOS << " puntos y " << nombreRival << " resta " << PENALIDAD_EXACTO << "." << endl;
    }else if(suma >  PUNTOS_EXACTOS && suma < LIMITE_CRISIS){
        cout << nombreJugador << " suma " << suma << " puntos." << endl;
    }else if(suma >= LIMITE_CRISIS){
        cout << "CRISIS DE LOS 40! Los " << suma << " puntos son para " << nombreRival << "." << endl;
    }else{
        cout << "La fila no llega a " << PUNTOS_EXACTOS << ": nadie suma puntos." << endl;
    }
}
/*mostrarResultadoFila: muestra que paso con los puntos segun la suma
(30 exacto, 31 a 39, crisis de los 40 o menos de 30). la usa completarFila*/

// DIAMANTE
int pedirJugarDiamante(){
    cout << "1 - Colocar en un casillero vacio" << endl;  
    cout << "2 - Reemplazar una carta del tablero" << endl; 
    cout << "Jugada del diamante: ";
    return pedirOpcion(1,2);
}
/*pedirJugarDiamante: muestra las 2 jugadas posibles del diamante
y devuelve la elegida, la usa JugarDiamante*/

void mostrarCartaReemplazada(string nombre, int cartaVieja, int cartaNueva, int fila){
    cout << nombre << " reemplaza una carta de la fila " << fila+1 << ":" << endl;
    dibujarCarta(cartaVieja);
    cout << "por:" << endl;
    dibujarCarta(cartaNueva);
}
/*mostrarCartaReemplazada: muestra la carta que sale del tablero y debajo el diamante que entra.
las dos dibujadas con dibujarCarta. fila viene como indice (0 a 2). La llama jugarDiamante.*/

// COMODIN
int pedirJugadaComodin(int cartasTablero){
    cout << "1 - Intercambiar dos cartas" << endl;
    cout << "2 - Mover una carta a otra fila" << endl;
    cout << "3 - Retirar una carta (vuelve al mazo)" << endl;
    cout << "Jugada del comodin: ";
    int jugada = pedirOpcion(1,3);

    while(jugada == 1 && cartasTablero < 2){
        cout << "Para intercambiar hacen falta 2 cartas en el tablero. Elegi otra jugada: " << endl;
        jugada = pedirOpcion(1, 3);
    }
    return jugada;
}
/*pedirJugadaComodin: muestra las 3 jugadas del comodin y devuelve la elegida
si hay menos de 2 cartas no deja intercambiar. la usa jugarComodin*/

void mostrarIntercambio(string nombre, int carta1, int fila1, int carta2, int fila2){
    cout << nombre << " usa comodin e intercambia la carta de la fila " << fila1+1 << ":" << endl;
    dibujarCarta(carta1);
    cout << "con la carta de la fila " << fila2+1 << ":" << endl;
    dibujarCarta(carta2);
}
/*mostrarIntercambio: muestra las 2 cartas que se intercambiaron de lugar con el comodin,
una debajo de la otra. La usa comodinIntercambiar*/

void mostrarMovimiento(string nombre, int carta, int filaOrigen, int filaDestino){
    cout << nombre << " usa el comodin para mover de la fila " << filaOrigen+1 << " a la fila " << filaDestino+1 << ":" << endl;
    dibujarCarta(carta);
}
/*mostrarMovimiento: muestra la carta que se movio con el comodin y de que fila a que fila fue,
las filas vienen como indice (0 a 2). La usa comodinMover*/

void mostrarCartaRetirada(string nombre, int carta, int fila){
    cout << nombre << " usa el comodin y retira una carta de la fila " << fila+1 << " (vuelve al mazo): " << endl;
    dibujarCarta(carta);
}
/*mostrarCartaRetirada: muestra la carta que se saco del tablero con el comodin
fila viene como indice(0  a 2). La llama comodinRetirar*/

// FIN DE PARTIDA
void mostrarGanador(string nombre, int puntos){
    cout << "*** " << nombre << " GANA LA PARTIDA CON " << puntos << " PUNTOS ***" << endl;
}
/*mostrarGanador: muestra el mensaje del ganador al final de la partida. la usa jugar*/
