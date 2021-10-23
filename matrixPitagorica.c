#include <stdio.h>
#define RIGHE 10
#define COLONNE 10

int main (int argc, char * argv[]) {
	int mat[RIGHE][COLONNE];
	int i, j;

	for(i = 1; i <= RIGHE; i++) {
		for(j = 1; j <= COLONNE; j++) {
			mat[i-1][j-1] = i * j;
		}
	}

    for (i = 0; i < RIGHE; i++) {
        for (j = 0; j < COLONNE; j++) {
			printf("%3d ", mat[i][j]);
		}   
		printf("\n");     
    }
    

    return 0;
}