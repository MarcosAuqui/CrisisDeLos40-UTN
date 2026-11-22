#include <iostream>
#include "constantes.h"
#include "funciones/interfaz.h"
using namespace std;

int main(){
    configurarConsola();

    // As de picas, 10 de corazones, K de treboles, comodin y casillero vacio
    int ids[5] = {0, 22, 38, 52, VACIO};

    for(int linea = 0; linea < 5; linea++){
        for(int i = 0; i < 5; i++){
            mostrarLineaCarta(ids[i], linea);
            cout << "  ";
        }
        cout << endl;
    }
    return 0;
}