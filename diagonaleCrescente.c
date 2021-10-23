/*
*   Data una matrice quadrata 4x4 in input, restituire 1 se gli elementi della diagonale
*   sono in ordine crescente, altrimenti 0
*/

#include <stdio.h>

#define DIM 4

int main(int argc, char * argv[]) {
	int mat[DIM][DIM];
	int i, j, cresc;

	for(i = 0; i < DIM; i++) {
		for(j = 0; j < DIM; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

    cresc = 1;
    for(i = 1; i < DIM && cresc == 1; i++) {
        if (mat[i-1][i-1] >= mat[i][i]) {
            cresc = 0;
        }
    }

    printf("%d\n", cresc);
    return 0;
}