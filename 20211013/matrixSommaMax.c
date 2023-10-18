/*
*   Data in input una matrice massimo 50x50, determinare l'indice della riga in cui la somma dei valori della riga è massima
*   L'utente sceglie la dimensione della matrice e il programma continua a chiederle finchè non sono valide
*/

#include <stdio.h>

#define MAX_DIM 50

int main(int argc, char * argv[]) {
	int mat[MAX_DIM][MAX_DIM];
	int rows, cols, sum, lastSum, index;
    int i, j;

	/* Riempi la matrice con valori dati dall'utente */
    do {
        scanf("%d", &rows);
    } while (rows < 1 || rows > 50);

    do {
        scanf("%d", &cols);
    } while (cols < 1 || cols > 50);

	for(i = 0; i < rows; i++) {
		for(j = 0; j < cols; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

    /* Analizza le righe per trovare quella con somma massima */
    for (i = 0; i < rows; i++) {
        sum = 0;
        for (j = 0; j < cols; j++) {
            sum += mat[i][j];
        }
        if (sum > lastSum) {
            index = i;
        }
        lastSum = sum;
    }

    printf("%d\n", index);
    return 0;
}