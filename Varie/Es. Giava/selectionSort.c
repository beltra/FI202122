#include <stdio.h>

#define NVAL 30

int main(int argc, char * argv[]) {
	int val[NVAL];
	int tmp, n;
	int i, j;

	scanf("%d", &n);

	/* Acquisisce l'array di input */
	for(i = 0; i < n; i++) {
		scanf("%d", &val[i]);
	}

	/* Partendo dal primo elemento dell'array, itera fino alla fine dell'array */
	for(i = 0; i < n - 1; i++) {
		/* Compara il valore con tutti i valori successivi nell'array */
		for(j = i+1; j < n; j++) {
			/* Se trova un valore minore di quello preso in considerazione li inverte */
			if (val[j] <= val[i]) {
				tmp = val[j];
				val[j] = val[i];
				val[i] = tmp;
			}
		}
	}

	/* Stampa il risultato */
	for(i = 0; i < n; i++) {
		printf("%d ", val[i]);
	}

	printf("\n");
}