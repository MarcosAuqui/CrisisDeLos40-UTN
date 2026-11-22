/* 
funciones a desarrollar

pedirOpcion()

esperarTecla()

limpiarPantalla()

intercambiar()
*/

#include <iostream>
#include <cstdlib>
#include "utilidades.h"
using namespace std;



int pedirOpcion(int min, int max){
    int opcion;
    cin >> opcion;

    while(opcion < min || opcion > max){
        cout << "Opcion invalida. Ingrese un numero entre " << min << " y " << max << ": ";
        cin >> opcion;
    }
    return opcion;
}
/*pedirOpcion: lee el entero de opcion y repite hasta que este entre min y max
devuelve ese numero. La usaran menu principal, cartaAJugar, jugarDiamante,
jugarComodin, Fila, en todos estos casos pide una opcion en formato de entero. 
PROBLEMA: si se escribe una letra en vez de un numero, cin se traba
y queda un bucle infinito. */

void limpiarPantalla(){
    system("cls");
}
/*limpiarPantalla: borra la consola con el comando "cls" de Windows.
La usan mostrarPantalla y el menu antes de redibujar asi no se acumule texto viejo.*/

void esperarTecla(){
    system("pause");
}
/*esperarTecla: pausa hasta que el jugador apriete una tecla.
"pause" de windows ya imprime "presione una tecla . . ."
la usan todas las jugadas, las pantallas de reglas y estadisticas*/
