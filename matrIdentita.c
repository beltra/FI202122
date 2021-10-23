/*
*	Chiede all'utente di inserire i dati di un array bidimensionale di dimensione 4x4 (di interi).
*	Visualizza 1 se è una matrice identità, altrimenti 0
*/

#include <stdio.h>

#define DIM 4

int main(int argc, char * argv[]) {
	int mat[DIM][DIM];
	int i, j, ident;

	/* Riempi la matrice con valor idati dall'utente */

	for(i = 0; i < DIM; i++) {
		for(j = 0; j < DIM; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	/* Verifica che la matrice sia I */
	ident = 1;

	for(i = 0; i < DIM && ident != 0; i++) {
		for (j = 0; j < DIM && ident != 0; j++) {
			if ((mat[i][j] != 0 && i != j) || (mat[i][j] != 1 && i == j)) {
				ident = 0;
			}
		}
	}

	/*  Visualizza la matrice */
	printf("%d\n", ident);

	return 0;
}