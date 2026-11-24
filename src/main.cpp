#include <iostream>
#include "constantes.h"
#include "funciones/interfaz.h"
using namespace std;

int main(){
    configurarConsola();

    // J de picas y 2 de diamantes
    mostrarCartasRobadas("Marcos", 10, 40);

    // comodin y 10 de corazones
    mostrarCartasRobadas("Santiago", 52, 22);
    
    return 0;
}