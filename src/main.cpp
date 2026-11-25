#include <string>
#include <cstdlib>
#include <ctime>
#include "constantes.h"
#include "funciones/utilidades.h"
#include "funciones/interfaz.h"
#include "funciones/juego.h"
using namespace std;

int main(){
    srand(time(NULL));
    configurarConsola();

    string mejorNombre = "";
    int mejorPuntaje = 0; //si es 0 todavia no se jugo ninguna partida
    int opcion = -1;

    while(opcion != 0){
        limpiarPantalla();
        mostrarMenu();
        opcion = pedirOpcion(0, 3);

        if(opcion == 1){
            jugar(mejorNombre, mejorPuntaje);
        }else if(opcion == 2){
            limpiarPantalla();
            mostrarEstadisticas(mejorNombre, mejorPuntaje);
            esperarTecla();
        }else if(opcion == 3){
            limpiarPantalla();
            mostrarReglas();
            esperarTecla();
        }
    }
    return 0;
}
/*main: inicia el rand y la consola, guarda el mejor jugador (sin globales)
y muestra el menu hasta que se elige 0. 1 juega, 2 estadisticas, 3 reglas*/
