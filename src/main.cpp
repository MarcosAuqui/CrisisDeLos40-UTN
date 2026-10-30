#include <iostream>
#include <cstdlib>
#include <ctime>
#include "constantes.h"
#include "funciones/mazo.h"

using namespace std;

int main() {
    srand(time(NULL));    // una sola vez, al principio del programa

    int mazo[TOTAL_CARTAS];
    int cantMazo = 0;

    crearMazo(mazo, cantMazo);
    cout << "mazo sin mezclar: " << endl;
    
    for(int h = 0; h < cantMazo; h++){
        cout << mazo[h] << endl;
    }
    mezclar(mazo, cantMazo);

    

    // Mostrar el mazo mezclado
    cout << "mazo mezclado: " << endl;
    for (int i = 0; i < cantMazo; i++) {
        cout << mazo[i] << endl;
    }

    //Controlar que no se perdió ninguna carta
    int suma = 0;
    for (int i = 0; i < cantMazo; i++) {
        suma = suma + mazo[i];
    }
    cout << "Cantidad: " << cantMazo << endl;   // esperado: 54
    cout << "Suma: " << suma << endl;           // esperado: 1431

    return 0;
}