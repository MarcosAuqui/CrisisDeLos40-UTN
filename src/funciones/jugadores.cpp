/*
funciones a desarrollar

actualizarMejorJugador()
*/

#include <string>
#include "jugadores.h"
#include "../constantes.h"
using namespace std;

void actualizarMejorJugador(string nombres[2], int puntaje[2], string& mejorNombre, int& mejorPuntaje){
    for(int i = 0; i < 2; i++){
        if(puntaje[i] > mejorPuntaje){
            mejorPuntaje = puntaje[i];
            mejorNombre = nombres[i];
        }
    }
}
/*actualizarMejorJugador: compara el puntaje final de los 2 jugadores con el mejor puntaje guardado
(mejorPuntaje). Si alguno lo supera, guarda su puntaje y su nombre.
La llama jugar al terminar cada partida, y mostrarEstadisticas (interfaz) muestra el resultado.*/