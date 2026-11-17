/* 
funciones a desarrollar

pedirOpcion()

esperarTecla()

limpiarPantalla()

intercambiar()

numeroAleatorio() quizas no sea necesria
*/

#include <iostream>
using namespace std;
#include "utilidades.h"



int pedirOpcion(int min, int max){
    int opcion;
    cin >> opcion;

    while(opcion < min || opcion > max){
        cout << "opcion invalida. Ingrese un numero entre " << min << "y "<< max << ": ";
        cin >> opcion;
    }
    return opcion;
}
/*pedirOpcion: lee el entero de opcion y repite hasta que este entre min y max
devuelve ese numero. La usaran menu principal, cartaAJugar, jugarDiamante,
jugarComodin, Fila, en todos estos casos pide una opcion en formato de entero. 
PROBLEMA: si se escribe una letra en vez de un numero, cin se traba
y queda un bucle infinito. */

#include "utilidades.h"
#include "../constantes.h" 