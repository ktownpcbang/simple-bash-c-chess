#include <stdio.h>
#define TAM 8
char matriz[TAM][TAM];


void start_board (){
   
    int i, j;  
    for (i=1, j=0; j<TAM; j++){
        matriz[i][j]='P';
    }
    for (i=6, j=0; j<TAM; j++){
        matriz[i][j]='p';
    }
    for (i=2; i<6; i++)
        for (j=0; j<TAM; j++)
            matriz[i][j]='.';
    matriz[0][0]='T';
    matriz[0][1]='H';
    matriz[0][2]='B';
    matriz[0][3]='K';
    matriz[0][4]='Q';
    matriz[0][5]='B';
    matriz[0][6]='H';
    matriz[0][7]='T';
    matriz[7][0]='t';
    matriz[7][1]='h';
    matriz[7][2]='b';
    matriz[7][3]='k';
    matriz[7][4]='q';
    matriz[7][5]='b';
    matriz[7][6]='h';
    matriz[7][7]='t'; 
}

void print_board(){
    int i, j;
    printf ("  01234567\n");
    printf ("0 ");
    for (j=0; j<TAM; j++)
        printf ("%c", matriz[0][j]);
    printf ("\n1 ");
    for (j=0; j<TAM; j++)
        printf ("%c", matriz[1][j]);
    printf ("\n2 ");
    for (j=0; j<TAM; j++)
        printf ("%c", matriz[2][j]);
    printf ("\n3 ");
    for (j=0; j<TAM; j++)
        printf ("%c", matriz[3][j]);
    printf ("\n4 ");
    for (j=0; j<TAM; j++)
        printf ("%c", matriz[4][j]);
    printf ("\n5 ");
    for (j=0; j<TAM; j++)
        printf ("%c", matriz[5][j]);
    printf ("\n6 ");
    for (j=0; j<TAM; j++)
        printf ("%c", matriz[6][j]);
    printf ("\n7 ");
    for (j=0; j<TAM; j++)
        printf ("%c", matriz[7][j]);
}

void mover_pieza(int i, int j, int k, int l){   
    matriz[k][l]=matriz[i][j];
    matriz[i][j]='.';    
}

int finished_game(){
    int i, j, a=0, b=0;
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            if(matriz[i][j]=='K'){
                a+=1;
            }
            if(matriz[i][j]=='k'){
                b+=1;
            }
        }
    }
    if (a==1 && b==0){
        printf ("BLACK PLAYER WINS\n");//black player: capital letters
        return 0;
    }
    else if (a==0 && b==1){
        printf ("WHITE PLAYER WINS\n");//white player: regular letters
        return 0;
    }
    else if (a==1 && b==1)
        return 1;
   
}



int main (){
    int a, b, c, d;
    int i, final, j;
    start_board();
    
    
   
    for (j=1; j;){
        if ((finished_game())){
    print_board();
    printf ("\n\tBLACK PLAYER MAKE YOUR MOVE: ");
    printf ("\nChoose the piece you want to move, first the row and then the column (separated by a space): ");
    scanf ("%d %d", &a, &b);
    printf ("Choose where you want to move the piece, first the row and then the column(separated by a space): ");
    scanf ("%d %d", &c, &d);
    while (c>7 || c<0 || d>7 || d<0){//with this while we check that the place we want to move is inside the chess
        printf ("This destination is not valid, try again: \n");
        printf ("Choose where you want to move the piece, first the row and then the column(separated by a space): ");
        scanf ("%d %d", &c, &d);
    }
    while (matriz[c][d]>='A' && matriz[c][d]<='Z'){//with this while we check that there is not a piece of our own team in the spot we want to ocuppy
        printf ("This move cannot be done, try again: \n");
        printf ("Choose where you want to move the piece, first the row and then the column(separated by a space): ");
        scanf ("%d %d", &c, &d);
        while (c>7 || c<0 || d>7 || d<0){
        printf ("This move cannot be done, try again: \n");
        printf ("Choose where you want to move the piece, first the row and then the column(separated by a space): ");
        scanf ("%d %d", &c, &d);}
    }
    mover_pieza(a, b, c, d);
    if (!(finished_game())){
        break;
    }
    if (finished_game()){
        print_board();
    printf ("\n\tWHITE PLAYER MAKE YOUR MOVE: ");
    printf ("\nChoose the piece you want to move, first the row and then the column (separated by a space): ");
    scanf ("%d %d", &a, &b);
    printf ("Choose where you want to move the piece, first the row and then the column(separated by a space): ");
    scanf ("%d %d", &c, &d);
    while (c>7 || c<0 || d>7 || d<0){
        printf ("This destination is not valid, try again: \n");
        printf ("Choose where you want to move the piece, first the row and then the column(separated by a space): ");
        scanf ("%d %d", &c, &d);
    }
    while (matriz[c][d]>='a' && matriz[c][d]<='z'){
        printf ("This move cannot be done, try again: \n");
        printf ("Choose where you want to move the piece, first the row and then the column(separated by a space): ");
        scanf ("%d %d", &c, &d);
        while (c>7 || c<0 || d>7 || d<0){
        printf ("This move cannot be done, try again: \n");
        printf ("Choose where you want to move the piece, first the row and then the column(separated by a space): ");
        scanf ("%d %d", &c, &d);}
    }
    mover_pieza(a, b, c, d);
    if (!(finished_game())){
        break;
    }
    }
    }
    }
    return 0;
}
  

