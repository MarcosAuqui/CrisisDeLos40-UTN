/*
funciones

pedirOpcion()

limpiarPantalla()

esperarTecla()
*/

#include <iostream>
#include <cstdlib>
#include "utilidades.h"
using namespace std;

// ENTRADA
int pedirOpcion(int min, int max){
    int opcion;
    cin >> opcion;

    while(opcion < min || opcion > max){
        cout << "Opcion invalida. Ingrese un numero entre " << min << " y " << max << ": ";
        cin >> opcion;
    }
    return opcion;
}
/*pedirOpcion: lee un numero y lo vuelve a pedir hasta que este entre min y max
lo usan el menu y todas las preguntas del juego
ojo: si se escribe una letra cin se traba y queda un bucle infinito*/

// PANTALLA
void limpiarPantalla(){
    system("cls");
}
/*limpiarPantalla: borra la consola con system("cls") de windows
la usan main y jugarTurno antes de dibujar*/

void esperarTecla(){
    system("pause");
}
/*esperarTecla: pausa hasta que se apriete una tecla con system("pause"), que ya imprime el mensaje
la usan main, jugar y jugarTurno*/
