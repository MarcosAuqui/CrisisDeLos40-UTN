/* 
funciones a desarrollar

inicializarTablero()

colocarCarta()

quitarCarta())

cartasEnFila()

sumaFila()

filaLlena()

primerVacioFila()

tableroVacio()
*/

#include "tablero.h"
#include "cartas.h"
#include "../constantes.h" 

void inicializarTablero(int tablero[FILAS][COLUMNAS]) {
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            tablero[f][c] = VACIO;
        }
    }
}
/*inicializarTablero: deja los 15 casilleros del tablero en VACIO(-1).
ysa dos for, el de afuera elige la fila y el de adentro recorre las colimnas de desa fila.
se usa al empezar cada partida para arrancar con el tablero limpio*/

void colocarCarta(int tablero[FILAS][COLUMNAS], int fila, int columna, int carta){
    tablero[fila][columna] = carta;
}
/*colocarCarta: se encarga de colocar el id de X carta seleccionada en un casillero
especifico de la matriz del tablero. fila va de 0 a 2(3) y columna de 0 a 4(5).
se usaria en jugarComun y jugar diamante para poder poner la carta elegida,
y en jugar comodin para ubicar la carta que se mueve*/

int quitarCarta(int tablero[FILAS][COLUMNAS], int fila,  int columna){
    int carta = tablero[fila][columna];
    tablero[fila][columna] = VACIO;
    return carta;
}
/*quitarcarta: esta funcion devuelve el id de una carta seleccionada.
busca en el tablero[][] y guarda el id de esa posicion en la var carta
luego deja esa posicion enn VACIO
La usan puntuarFila (para vaciar la fila)
jugarDiamante (para sacarla carta reemplazada) 
jugarComodin (para retirar o mover una carta)*/

int cartasEnFila(int tablero[FILAS][COLUMNAS], int fila) {
    int cantidad = 0;
    for (int c = 0; c < COLUMNAS; c++) {
        if (tablero[fila][c] != VACIO) {
            cantidad = cantidad + 1;
        }
    }
    return cantidad;
}

/*cartasEnFila: cuenta cuántas cartas hay en una fila del tablero.
Recorre las 5 columnas de esa fila con un for y suma 1 cada vez que
el casillero no está VACIO. Devuelve la cantidad (0 a 5).
No modifica el tablero.
La usan jugar y las jugadas con comodín para saber si una fila quedó
completa (cantidad == 5), y mostrarPantalla para mostrar "Cartas: 3/5". 
*/

int sumarFila(int tablero[FILAS][COLUMNAS], int fila){
    int suma= 0;
    for(int c = 0; c < COLUMNAS; c++){
        if(tablero[fila][c] != VACIO){
            suma = suma + valorCarta(tablero[fila][c]);
        }
    }
    return suma;
}
/*sumarFila: devuelve la suma de los valores
de las cartas de toda una fila del tablero.
recorre las  5 columnas y sui el casillero 
no esta VACIO, le suma el valor de la carta.
la usara puntuarFila()*/

bool filaLlena(int tablero[FILAS][COLUMNAS], int fila){
    if(cartasEnFila(tablero, fila) == COLUMNAS){
        return true;
    }else{
        return false;
    }    
}
/*filaLlena: esta funcion toma la matriz "tablero" y una fila de
esta. Compara con cartasEnFila*/

