#include <stdio.h>
#define TAM 8

void empezar_tablero();
void imprimir_tablero();
int mover_ficha(int i1, char col1, int i2, char col2, int njugador);
void guardar_secuencia(FILE * fichero, int cont, char j1, int i1, char j2, int i2, int njugador);
int comprobar_ganador();
