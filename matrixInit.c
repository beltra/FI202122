/*
*	Dichiara un array di array e inizializza con valori dati dall'utente, poi chiede
*	una linea e una colonna e ne modifica i valori a 0. Infine visualizza la matrice
*/

#include <stdio.h>

#define DIM1 2
#define DIM2 3

int main(int argc, char * argv[]) {
	int mat[DIM1][DIM2];
	int i, j, k;

	/* Riempi la matrice con valor idati dall'utente */

	for(i = 0; i < DIM1; i++) {
		for(j = 0; j < DIM2; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	/* Azzera la k-esima colonna */
	do {
		scanf("%d", &k);
	} while (k < 0 || k >= DIM1);

	for(j = 0; j < DIM2; j++) {
		mat[k][j] = 0;
	}

	/* Azzera l'h-esima riga */
	do {
		scanf("%d", &h);
	} while (h < 0 || h >= DIM2);

	for(i = 0; i < DIM1; i++) {
		mat[i][h] = 0;
	}

	/*  Visualizza la matrice */
	for(i = 0; i < DIM1; i++) {
		for(j = 0; j < DIM2; j++) {
			printf("%2d ", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}