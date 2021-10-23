/*
*   Acquisito un input di una matrice 4x4, visualizza 1 se è triangolare superiore, altrimenti 0
*/

#include <stdio.h>

#define SIZE 4

int main(int argc, char * argv[]) {
	int mat[SIZE][SIZE];
	int trg;
    int i, j;

	/* Riempi la matrice con valori dati dall'utente */
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

    trg = 1;
    for (i = 1; i < SIZE && trg == 1; i++) {
        for (j = 0; j < i && trg == 1; j++) {
            if (mat[i][j] != 0) {
                trg = 0;
            }
        }
    }

    printf("%d\n", trg);

    return 0;
}