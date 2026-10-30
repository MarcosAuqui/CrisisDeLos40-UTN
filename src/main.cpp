#include <iostream>
#include "constantes.h"
#include "funciones/mazo.h"

using namespace std;

int main() {
    int mazo[TOTAL_CARTAS];
    int cantMazo = 0;

    crearMazo(mazo, cantMazo);

    int carta1 = robarCarta(mazo, cantMazo);   // 53
    int carta2 = robarCarta(mazo, cantMazo);  // 52
    cout << "se robaron 2 cartas, cantidad de cartas en mazo: " << endl;   
    cout << cantMazo << endl;                  // esperado: 52
    
    devolverCarta(mazo, cantMazo, carta1);
    cout << "se devolvio una carta al mazo, cantidad de cartas en mazo: " << endl;
    cout << cantMazo << endl;                  // esperado: 53

    int otraCarta = robarCarta(mazo, cantMazo);
    cout << "se robaron 1 cartas, cantidad de cartas en mazo: " << endl;  
    cout << otraCarta << endl;                  // esperado: 53
    cout << cantMazo << endl;                  // esperado: 52

    return 0;
}