#include <iostream>
#include "constantes.h"
#include "funciones/cartas.h"

using namespace std;

int main() {
    // valorCarta: esperado 1, 1, 13
    cout << valorCarta(0) << endl;
    cout << valorCarta(13) << endl;
    cout << valorCarta(25) << endl;

    // paloCarta: esperado 0, 1, 3
    cout << paloCarta(0) << endl;
    cout << paloCarta(13) << endl;
    cout << paloCarta(45) << endl;

    // esComodin: esperado 0, 1
    cout << esComodin(51) << endl;
    cout << esComodin(52) << endl;

    // esDiamante: esperado 0, 1, 0
    cout << esDiamante(38) << endl;
    cout << esDiamante(39) << endl;
    cout << esDiamante(53) << endl;

    return 0;
}