#include <iostream>
#include "constantes.h"
#include "funciones/cartas.h"

using namespace std;

int main() {
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        mostrarCarta(i);  // muestra cada carta del mazo
        cout << " "; // da un espacio entre cada carta

        if ((i + 1) % CARTAS_POR_PALO == 0) {
            cout << endl;   // salta de linea cada 13
        }
    }

    cout << endl;
    mostrarCarta(VACIO) ; //muestra carta vacia
    return 0;
}