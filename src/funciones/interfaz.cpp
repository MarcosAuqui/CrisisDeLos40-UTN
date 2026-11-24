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
/*lineaJugador: dibuja una linea del marco con "> NOMBRE: 18 puntos". El ">" marca al jugador que
juega este turno. Calcula cuantos digitos tiene el puntaje para rellenar con espacios y que el
borde derecho no se corra (el interior del marco mide 116 caracteres).
La usa mostrarPantalla, una vez por cada jugador.*/
 
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
/*mostrarPantalla: dibuja la pantalla del turno: objetivo y cartas del mazo, puntaje de cada jugador
(con ">" en el que juega) y el tablero con cantidad de cartas y suma de cada fila.
Las 2 cartas robadas y las preguntas del turno se muestran debajo del marco, no aca.
La usa jugarTurno al principio de cada turno.*/
 
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
            cout << "Ese casillero esta vacio. Elegi una carta del tablero." << endl;
        }
    }while(vacio);

}
/*pedirCartaTablero: pide fila y casillero y repite hasta que el casillero 
tenga una carta. Devuelve fila y columna como indices desde 0, por referencia.
La usan jugarDiamante para reemplazar y jugarComodin para intercambiar, mover o retirar.
IMPORTANTE: al ser llamada se debe comprobar antes que el tablero no este vacio (tableroVacio).*/

void mostrarFilaCompleta(int tablero[FILAS][COLUMNAS], int fila, int suma){
    cout << "Se completo la fila " << fila+1 << ": ";

    for(int c = 0; c < COLUMNAS; c++){
        mostrarCarta(tablero[fila][c]);
        cout << " ";
    }
    cout << endl;
    cout << "Suma de la fila: " << suma << endl;

}
/*mostrarFilaCompleta: imprime las 5 cartas de la fila que se acaba de completar y su suma.
Usa mostrarCarta para cada casillero. fila viene como indice(0 a 2) y se muestra 
como 1 a 3. La usara completarFila antes de puntuar y vaciar la fila.*/

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
/*mostrarResultadoFila: imprime que paso con los puntos segun la suma (30 exacto, 31 a 39,
crisis de los 40 o menos de 30). Solo imprime, los puntajes los cambia puntuarFila.
La llama completarFila  despues de puntuar.*/

void mostrarCartaColocada(string nombre, int carta, int fila){
    cout << nombre << " coloca "; 
    mostrarCarta(carta);
    cout << " en la fila " << fila+1 << "." << endl;
}
/*mostrarCartaColocada: imprime "ANGEL coloca [ 2 D] en la fila 2." con el formato del enunciado.
fila viene como indice (0 a 2) y se muestra de 1 a 3. La llama jugarComun despues de colocar la carta.*/

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
/*mostrarLineaCarta: dibuja UNA sola linea (0 a 4) de la cajita de una carta. Como la consola
imprime renglon por renglon, mostrarFilaTablero la va a llamar para cada carta de la fila
una linea a la vez. Maneja carta comun, casillero vacio (VACIO) y comodin.*/

void espacios(int n){
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}
/*espacios: imprime n espacios seguidos.
La usa mostrarFilaTablero para rellenar el marco sin que se corra el borde derecho.*/

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

int pedirCartaJugar(){
    cout << "Carta a jugar (1 o 2): ";
    int carta = pedirOpcion(1, 2);
    return carta-1;
}
/*pedirCartaJugar: pregunta cual de las 2 cartas robadas se usara en el turno
y devuelve su indice, con este indice jugarTurno() va a elegir que carta usar
*/

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

void dibujarCarta(int id){
    for(int linea = 0; linea < 5; linea++){
        mostrarLineaCarta(id, linea);
        cout << endl;
    }
}
/*dibujarCarta: dibuja una carta sola completa en cajita, sus 5 renglones uno debajo del otro.
Para cartas que van una al lado de la otra se usa mostrarLineaCarta renglon por renglon
(como en mostrarFilaTablero), porque la consola no puede volver para arriba.
La usan los mensajes de reemplazar, retirar, mover e intercambiar.*/

void mostrarCartaRetirada(string nombre, int carta, int fila){
    cout << nombre << " usa el comodin y retira una carta de la fila " << fila+1 << " (vuelve al mazo): " << endl;
    dibujarCarta(carta);
}
/*mostrarCartaRetirada: muestra la carta que se saco del tablero con el comodin
fila viene como indice(0  a 2). La llama comodinRetirar*/

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
/*pedirDosCartasTablero: pide dos cartas del tablero y repite la segunda si es la misma que la primera.
Devuelve las dos posiciones (indices desde 0) por referencia. La usa comodinIntercambiar.*/

void mostrarIntercambio(string nombre, int carta1, int fila1, int carta2, int fila2){
    cout << nombre << " usa comodin e intercambia la carta de la fila " << fila1+1 << ":" << endl;
    dibujarCarta(carta1);
    cout << "con la carta de la fila " << fila2+1 << ":" << endl;
    dibujarCarta(carta2);
}
/*mostrarIntercambio: muestra las 2 cartas que se intercambiaron de lugar con el comodin,
una debajo de la otra. La usa comodinIntercambiar*/