#include "ajedrez.h"

int main() {
    int cont1 = 1, cont2 = 1;
    int njugador = 1;
    int i1, i2;
    char j1, j2;
    FILE* fichero;
    fichero = fopen("secuencia_movimientos.txt", "w");
    printf("JUEGO DE AJEDREZ\n");
    printf("Para mover las piezas introduzca la columna en letra y la fila en numero en ese orden separados por un espacio (ejemplo: e 5)\n\n");
    empezar_tablero();
    imprimir_tablero();
    while(comprobar_ganador() == 0) {
        if(njugador == 1) {
            printf("TURNO DEL JUGADOR BLANCO (MAYUSCULAS)\n");
            printf("Introduzca pieza a mover: ");
            scanf("\n%c %d", &j1, &i1);
            fflush( stdin );
            printf("Introduzca a que posicion quiere mover: ");
            scanf ("\n%c %d", &j2, &i2);
            fflush( stdin );
            i1--;
            i2--;
            while(mover_ficha(i1, j1, i2, j2, njugador) == 0) {
                printf("Primero columna en letra y despues fila en numero separados por un espacio\n");
                printf("Introduzca de nuevo pieza a mover: ");
                scanf("\n%c %d", &j1, &i1);
                fflush( stdin );
                printf("Introduzca a que posicion quiere mover: ");
                scanf ("\n%c %d", &j2, &i2);
                fflush( stdin );
                i1--;
                i2--;
            }
            guardar_secuencia(fichero, cont1, j1, i1, j2, i2, njugador);
            printf("Movimiento numero %d del jugador BLANCO: [%c %d] a [%c %d]\n\n", cont1, j1, (i1 + 1), j2, (i2 + 1));
            imprimir_tablero();
            printf("\n");
            cont1++;
            njugador = 2;
            if(comprobar_ganador() != 0)
                return 0;
        } else if(njugador == 2) {
            printf("TURNO DEL JUGADOR NEGRO (minusculas)\n");
            printf("Introduzca pieza a mover: ");
            scanf("\n%c %d", &j1, &i1);
            fflush( stdin );
            printf("Introduzca a que posicion quiere mover: ");
            scanf ("\n%c %d", &j2, &i2);
            fflush( stdin );
            i1--;
            i2--;
            while(mover_ficha(i1, j1, i2, j2, njugador) == 0) {
                printf("Primero columna en letra y despues fila en numero separados por un espacio\n");
                printf("Introduzca de nuevo pieza a mover: ");
                scanf("\n%c %d", &j1, &i1);
                fflush( stdin );
                printf("Introduzca a que posicion quiere mover: ");
                scanf ("\n%c %d", &j2, &i2);
                fflush( stdin );
                i1--;
                i2--;
            }
            guardar_secuencia(fichero, cont2, j1, i1, j2, i2, njugador);
            printf("Movimiento numero %d del jugador NEGRO: [%c %d] a [%c %d]\n\n", cont2, j1, (i1 + 1), j2, (i2 + 1));
            imprimir_tablero();
            printf("\n");
            cont2++;
            njugador = 1;
        }
    }
    fclose(fichero);
    return 0;
}