#include <iostream>
#include "constantes.h"
#include "funciones/mazo.h"
using namespace std;

int main() {
    int mazo[TOTAL_CARTAS];
    int cantMazo = 0;

    crearMazo(mazo, cantMazo);

    int carta1 = robarCarta(mazo, cantMazo);
    int carta2 = robarCarta(mazo, cantMazo);

    cout << carta1 << endl;      // esperado: 53
    cout << carta2 << endl;      // esperado: 52
    cout << cantMazo << endl;    // esperado: 52

    return 0;
}