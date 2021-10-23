/*
*	Inizializzata una matrice quadrata 5x5, il porgramma calcola la matrice ruotata di
* 	90 gradi in senso antiorario, la salva in un'altra variabile e poi la stampa	
*/

#include <stdio.h>

#define DIM 3

int main(int argc, char * argv[]) {
	int mat[DIM][DIM], matRot[DIM][DIM];
	int i, j;

	/* Riempi la matrice con valor idati dall'utente */
	for(i = 0; i < DIM; i++) {
		for(j = 0; j < DIM; j++) {
			scanf("%d", &matRot[DIM - 1 - j][i]);
		}
	}

	/* Ruota la matrice */
	for(i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			/*matRot[i][j] = mat[j][DIM - 1 - i];*/
			matRot[DIM - 1 - j][i] = mat[i][j];
		}
	}

	/*  Visualizza la matrice */
	for(i = 0; i < DIM; i++) {
		for(j = 0; j < DIM; j++) {
			printf("%2d ", matRot[i][j]);
		}
		printf("\n");
	}

	return 0;
}