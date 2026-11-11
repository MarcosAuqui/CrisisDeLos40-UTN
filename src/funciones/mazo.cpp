/*
Funciones a desarrollar

crearMazo()

mezclar()

robarCarta()

devolverCarta()
*/

#include "mazo.h"
#include "../constantes.h"
#include <cstdlib>

void crearMazo(int mazo[], int& cantMazo){
    for(int i = 0; i < TOTAL_CARTAS; i++){
        mazo[i] = i;
    }
    cantMazo = TOTAL_CARTAS;
}
/* crearMazo: llena el vector con los id 0 a 53 en orden (la carta i queda
en la posición i) y deja cantMazo en 54, o sea el mazo completo.
En el proyecto la usa jugar al empezar cada partida, para tener un mazo
nuevo con todas las cartas antes de repartir */

int robarCarta(int mazo[], int& cantMazo){
    cantMazo--;
    return  mazo[cantMazo];
}
/* robarCarta: saca la carta de arriba del mazo y devuelve su id.
Primero baja cantMazo en 1 (la última carta deja de ser parte del
mazo) y después devuelve esa carta. El vector no se borra: lo que queda
fuera de cantMazo simplemente no cuenta.
En el proyecto la usa jugar al principio de cada turno, dos veces, para
darle al jugador activo sus dos cartas. */

void devolverCarta(int mazo[], int& cantMazo, int carta){
    mazo[cantMazo] = carta;
    cantMazo++;
}
/* devolverCarta: pone una carta de vuelta en el mazo.
La escribe en la primera posición libre (mazo[cantMazo]) y después sube
cantMazo en 1, así esa posición pasa a ser parte del mazo. Hace lo
inverso de robarCarta. La usa jugar al final de cada turno para devolver la carta
que no se jugó y el comodín usado. También la usan puntuarFila y las jugadas de diamante 
y comodín cuando una carta sale del tablero. El mazo siempre se mezcla al terminar 
el turno, así que no importa en qué posición quede cada carta */

void mezclar(int mazo[], int cantMazo){
    for(int i = cantMazo - 1 ; i > 0; i--){
        int j = rand() % (i + 1);
        int aux = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = aux;
    }

}
/*mezclar: desordena al azar las cartas que están en el mazo. Desde la última 
posición hacia la segunda: en cada paso elige una posición al azar entre 0 e i 
e intercambia esas dos cartas. Solo toca las posiciones 0 a cantMazo - 1, o sea 
las cartas que realmente están en el mazo. Necesita que main llame
a srand(time(NULL)) una sola vez al inicio del código.
Se usa al crear el mazo y al final de cada turno (paso 6)*/
