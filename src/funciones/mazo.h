#ifndef MAZO_H
#define MAZO_H

// CREAR Y MEZCLAR
void crearMazo(int mazo[], int& cantMazo);
void mezclar(int mazo[], int cantMazo);

// ROBAR Y DEVOLVER
int robarCarta(int mazo[], int& cantMazo);
void devolverCarta(int mazo[], int& cantMazo, int carta);

#endif
