#include <iostream>
#include "funciones/utilidades.h"
using namespace std;

int main(){
    cout << "Elegi entre 1 y 3: ";
    int a = pedirOpcion(1, 3);
    cout << "Elegiste " << a << endl;
    return 0;
}