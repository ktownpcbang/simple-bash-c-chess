#include "ajedrez.h"
char tablero[TAM][TAM];

void empezar_tablero() {
    int i, j;
    for(i = 0; i < TAM; i++) {
        if(i == 0) {
            tablero[i][0] = 'r';
            tablero[i][1] = 'n';
            tablero[i][2] = 'b';
            tablero[i][3] = 'q';
            tablero[i][4] = 'k';
            tablero[i][5] = 'b';
            tablero[i][6] = 'n';
            tablero[i][7] = 'r';
        } else if(i == 7) {
            tablero[i][0] = 'R';
            tablero[i][1] = 'N';
            tablero[i][2] = 'B';
            tablero[i][3] = 'Q';
            tablero[i][4] = 'K';
            tablero[i][5] = 'B';
            tablero[i][6] = 'N';
            tablero[i][7] = 'R';
        } else if(i == 2 || i == 3 || i == 4 || i == 5){
            for(j = 0; j < TAM; j++){
                tablero[i][j] = '.';
            }
        } else if(i == 1) {
            for(j = 0; j < TAM; j++){
                tablero[i][j] = 'p';
            }
        } else if(i == 6) {
            for(j = 0; j < TAM; j++){
                tablero[i][j] = 'P';
            }
        }
    }
}

void imprimir_tablero() {
    int filas[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int i, j;
    printf("   a b c d e f g h\n\n");
    for(i = 0; i < TAM; i++) {
        printf("%d  ", filas[i]);
        for(j = 0; j < TAM; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

int mover_ficha(int i1, char col1, int i2, char col2, int njugador) {
    int j1, j2;
    switch(col1) {  
    case 'a':
        j1 = 0;
        break;
    case 'b':  
        j1 = 1;
        break;
    case 'c':
        j1 = 2;
        break;
    case 'd':
        j1 = 3;
        break;
    case 'e':
        j1 = 4;
        break;
    case 'f':
        j1 = 5;
        break;
    case 'g':
        j1 = 6;
        break;
    case 'h':
        j1 = 7;
        break;
    default :
        printf("ERROR en la columna de la ficha que quiere mover\n");
        return 0;
    }
    switch(col2) {  
    case 'a':
        j2 = 0;
        break;
    case 'b':  
        j2 = 1;
        break;
    case 'c':
        j2 = 2;
        break;
    case 'd':
        j2 = 3;
        break;
    case 'e':
        j2 = 4;
        break;
    case 'f':
        j2 = 5;
        break;
    case 'g':
        j2 = 6;
        break;
    case 'h':
        j2 = 7;
        break;
    default :
        printf("ERROR en la columna de la posicion a la que quiere mover\n");
        return 0;
    }
    if (i1 < 0 || i1 > 7 || i2 < 0 || i2 > 7) {
        printf("ERROR en el numero de fila introducido\n");
        return 0;   /*movimiento no posible*/
    }
    if(njugador == 1) {     /*JUGADOR BLANCO*/
        if(tablero[i1][j1] == '.') {
            printf("ERROR en esa posicion no hay ninguna pieza para mover\n");
            return 0;
        }
        if(tablero[i1][j1] == 'p' || tablero[i1][j1] == 'r' || tablero[i1][j1] == 'n' || tablero[i1][j1] == 'b' || tablero[i1][j1] == 'q' || tablero[i1][j1] == 'k') {
                printf("ERROR ha intentado mover una pieza del otro jugador\n");
                return 0;
            }
        if(tablero[i1][j1] == 'P' || tablero[i1][j1] == 'R' || tablero[i1][j1] == 'N' || tablero[i1][j1] == 'B' || tablero[i1][j1] == 'Q' || tablero[i1][j1] == 'K') {
            if(tablero[i2][j2] == 'P' || tablero[i2][j2] == 'R' || tablero[i2][j2] == 'N' || tablero[i2][j2] == 'B' || tablero[i2][j2] == 'Q' || tablero[i2][j2] == 'K') {
                printf("ERROR ha intentado comer una pieza del propio jugador\n");
                return 0;       /*Ha intentado comerse a si mismo*/
            } else {
                tablero[i2][j2] = tablero[i1][j1];
                tablero[i1][j1]='.'; 
                return 1;
            }
        }
    } else if(njugador == 2) {     /*JUGADOR NEGRO*/
        if(tablero[i1][j1] == '.') {
            printf("ERROR en esa posicion no hay ninguna pieza\n");
            return 0;
        }
        if(tablero[i1][j1] == 'P' || tablero[i1][j1] == 'R' || tablero[i1][j1] == 'N' || tablero[i1][j1] == 'B' || tablero[i1][j1] == 'Q' || tablero[i1][j1] == 'K') {
                printf("ERROR ha intentado mover una pieza del otro jugador\n");
                return 0;
            }
        if(tablero[i1][j1] == 'p' || tablero[i1][j1] == 'r' || tablero[i1][j1] == 'n' || tablero[i1][j1] == 'b' || tablero[i1][j1] == 'q' || tablero[i1][j1] == 'k') {
            if(tablero[i2][j2] == 'p' || tablero[i2][j2] == 'r' || tablero[i2][j2] == 'n' || tablero[i2][j2] == 'b' || tablero[i2][j2] == 'q' || tablero[i2][j2] == 'k') {
                printf("ERROR ha intentado comer una pieza del propio jugador\n");
                return 0;       /*Ha intentado comerse a si mismo*/
            } else {
                tablero[i2][j2] = tablero[i1][j1];
                tablero[i1][j1]='.';   
                return 1;
            }
        }
    }
    return 1;
}

void guardar_secuencia(FILE * fichero, int cont, char j1, int i1, char j2, int i2, int njugador) {
    if(njugador == 1) {
        fprintf(fichero, "Movimiento numero %d del jugador BLANCO: [%c %d] a [%c %d]\n", cont, j1, (i1 + 1), j2, (i2 + 1));
    } else if(njugador == 2) {
        fprintf(fichero, "Movimiento numero %d del jugador NEGRO: [%c %d] a [%c %d]\n", cont, j1, (i1 + 1), j2, (i2 + 1));
    }
}

int comprobar_ganador() {
    int i, j;
    int N = 0, B = 0;
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            if(tablero[i][j] == 'k') {
                N = 1;
            } else if(tablero[i][j] == 'K') {
                B = 1;
            }
        }
    }
    if(N == 1 && B == 0) {
        printf("EL JUGADOR NEGRO HA GANADO LA PARTIDA\n");
        return 1;
    } else if(N == 0 && B == 1) {
        printf("EL JUGADOR BLANCO HA GANADO LA PARTIDA\n");
        return 1;
    } else {
        return 0;
    }
}