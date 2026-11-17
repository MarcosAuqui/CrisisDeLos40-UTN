#include <iostream>
#include "funciones/utilidades.h"
using namespace std;

int main(){
    cout << "Esto se va a borrar" << endl;
    esperarTecla();
    limpiarPantalla();

    cout << "Pantalla limpia. Elegi entre 1 y 3: ";
    int a = pedirOpcion(1, 3);
    cout << "Elegiste " << a << endl;

    esperarTecla();
    return 0;
}