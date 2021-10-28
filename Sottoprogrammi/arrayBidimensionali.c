/* Passaggio di array bidimensionali a sottoprogrammi */

#include <stdio.h>
#define SIZE 5

/*  
*   Quando passo array di dimensioni superiori a 1, è necessario scrivere tra parentesi quadre il valore di tutte le
*   dimensioni ad eccezione della prima 
*/

int identita(int[][SIZE], int);
void riempiMatr(int[][SIZE], int);

int main (int argc, char *argv[]) {
    int matr[SIZE][SIZE];
    int i, j, ris;

    riempiMatr(matr, SIZE);
  
    /* Siccome è quadrata basta una dimensione */
    ris = identita(matr, SIZE);

    printf("%d\n", ris);
    return 0;
}

int identita(int mat[][SIZE], int dim) {
    int i, j;
    int ris;

    ris = 1; 
    for (i = 0; i < dim && ris; i++) {
        for (j = 0; j < dim && ris; j++) {
            if ((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0)) {
                ris = 0;
            }
        }
    }
    return ris;
}

void riempiMatr(int matr[][SIZE], int dim) {
    int i, j;

    /* NON utilizzare SIZE al posto di dim, SIZE è SOLO per il computer, non per il programmatore */
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            scanf("%d", &matr[i][j]);
        }
    }
}

/*
*   Definire le colonne dell'array nel sottoprogramma permette di risolvere il problema della linearizzazione della memoria
*   (uno stack ha una dimensione, anche se i dati sono pluridimensionali).
*   Si crea però il problema di dover utilizzare una define all'interno del sottoprogramma, rendendo il sottoprogramma non universale.
*   Una possibilità è passare al sottoprogramma un puntatore (all'inzio dell'array) e le dimensioni dell'array,
*   per poi elaborare matematicamente l'indirizzo dell'elemento necessario
*/
/*
int identita(int *dati, int nRow, int nCol, int nColTot) {
    // Per indicare dati[i][j], con dati sottomatrice di una matrice più grande con nColTot colonne

    *(dati + (i * nColTot) + j)
    
}
*/