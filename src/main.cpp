#include <iostream>
#include "constantes.h"
#include "funciones/tablero.h"
#include "funciones/mazo.h"
#include "funciones/reglas.h"
using namespace std;

int main(){
    //puntuarFila 
    cout << "== puntuarFila ==" << endl;
    int p[2] = {10, 10};
    puntuarFila(p, 0, 30);
    cout << p[0] << " " << p[1] << endl;  // 40 0

    int q[2] = {10, 10};
    puntuarFila(q, 1, 35);
    cout << q[0] << " " << q[1] << endl;  // 10 45

    int r[2] = {10, 10};
    puntuarFila(r, 0, 40);
    cout << r[0] << " " << r[1] << endl;  // 10 50

    int s[2] = {10, 10};
    puntuarFila(s, 0, 25);
    cout << s[0] << " " << s[1] << endl;  // 10 10

    //devolverFila
    cout << "== devolverFila ==" << endl;
    int mazo[TOTAL_CARTAS];
    int cantMazo;
    int tablero[FILAS][COLUMNAS];
    crearMazo(mazo, cantMazo);
    inicializarTablero(tablero);

    for(int c = 0; c < COLUMNAS; c++){
        colocarCarta(tablero, 1, c, robarCarta(mazo, cantMazo));
    }
    colocarCarta(tablero, 0, 0, robarCarta(mazo, cantMazo));

    cout << "Mazo antes: " << cantMazo << " | cartas en fila 2: " << cartasEnFila(tablero, 1) << endl;

    devolverFila(tablero, mazo, cantMazo, 1);
    
    cout << "Mazo despues: " << cantMazo << " | fila 2: " << cartasEnFila(tablero, 1) << " | fila 1: " << cartasEnFila(tablero, 0) << endl;

    //hayGanador
    cout << "== hayGanador ==" << endl;
    int a[2] = {49, 10};  cout << hayGanador(a) << endl; // -1
    int b[2] = {50, 10};  cout << hayGanador(b) << endl; // 0
    int c[2] = {10, 63};  cout << hayGanador(c) << endl; // 1
    int d[2] = {0, 0};    cout << hayGanador(d) << endl; // -1

    return 0;
}