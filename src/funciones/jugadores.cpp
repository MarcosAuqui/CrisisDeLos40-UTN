/*
funciones

actualizarMejorJugador()
*/

#include <string>
#include "jugadores.h"
#include "../constantes.h"
using namespace std;

// ESTADISTICAS
void actualizarMejorJugador(string nombres[2], int puntaje[2], string& mejorNombre, int& mejorPuntaje){
    for(int i = 0; i < 2; i++){
        if(puntaje[i] > mejorPuntaje){
            mejorPuntaje = puntaje[i];
            mejorNombre = nombres[i];
        }
    }
}
/*actualizarMejorJugador: compara el puntaje final de los 2 con el mejor guardado
si alguno lo supera guarda su nombre y puntaje. la usa jugar al terminar la partida*/