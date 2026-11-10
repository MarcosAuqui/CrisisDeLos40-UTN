/* main.cpp TEMPORAL: sirve para probar las pantallas (menu, maqueta del tablero y reglas).
No escribas letras en el menu hasta que tengamos pedirOpcion, una letra 
deja el programa en bucle.*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "funciones/interfaz.h"

using namespace std;

int main()
{
    configurarConsola();

    int opcion;

    do
    {
        system("cls");
        mostrarMenu();
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                // las llaves del case hacen falta porque se declaran variables adentro
                string nombre1, nombre2;

                system("cls");
                cout << "Nombre del primer jugador: ";
                cin >> nombre1;
                cout << "Nombre del segundo jugador: ";
                cin >> nombre2;

                system("cls");
                mostrarPantalla(nombre1, nombre2);
                system("pause > nul");
                break;
            }

            case 2:
                cout << "Estadísticas: todavía no está hecho." << endl;
                system("pause");
                break;

            case 3:
                system("cls");
                mostrarReglas();
                system("pause > nul");
                break;

            case 0:
                break;

            default:
                cout << "Opción inválida." << endl;
                system("pause");
                break;
        }

    } while (opcion != 0);

    return 0;
}