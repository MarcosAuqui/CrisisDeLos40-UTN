#include <iostream>
#include "constantes.h"
#include "funciones/mazo.h"
using namespace std;

int main() {
    int mazo[TOTAL_CARTAS];
    int cantMazo = 0;

    crearMazo(mazo, cantMazo);

    cout << cantMazo << endl;    
    cout << mazo[0] << endl;     
    cout << mazo[13] << endl;    
    cout << mazo[53] << endl;    

    for(int i = 0; i < cantMazo; i++){
        cout << mazo[i] << endl;
    }
    
    return 0;
}



//comandos para ejecutar
// g++ src/main.cpp src/funciones/*.cpp -o src/main.exe
// src\main.exe