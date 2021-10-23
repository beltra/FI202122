/*
*	Si scriva un programma che acquisisca in ingresso due array di
*	5 numeri interi (assumendo che l'utente li inserisca in ordine 
*	crescente). A partire da questi due array si crei l'array risultato
*	che contiene tutti i numeri contenuti nei due array di partenza,
* 	anch'esso ordinato in ordine crescente
*	Es.
*	array1 = [1, 3, 4, 9, 10]
*	array2 = [2, 5, 6, 10, 11]
*	risultato = [1, 2, 3 ,4, 5, 6, 9, 10, 10, 11]
*/

#include <stdio.h>

#define NVAL 5

int main(int argc, char * argv[]) {
	int val1[NVAL], val2[NVAL];
	int tmp, ris[NVAL*2];
	int i, j, minIndex;

	/* Acquisisce i due array di input */
	for(i = 0; i < NVAL; i++) {
		scanf("%d", &val1[i]);
	}
	for(i = 0; i < NVAL; i++) {
		scanf("%d", &val2[i]);
	}

	/* Scrive in un unico array i due array di input in sequenza */
	for(i = 0; i < NVAL*2; i++) {
		if (i < NVAL) {
			ris[i] = val1[i];
		} else {
			ris[i] = val2[i-5];
		}
	}

	/* Partendo dal primo elemento dell'array unico, itera fino alla fine dell'array */
	for(i = 0; i < NVAL * 2 - 1; i++) {
		/* Compara il valore con tutti i valori successivi nell'array */
		for(j = i+1; j < NVAL*2; j++) {
			/* Se trova un valore minore di quello preso in considerazione li inverte */
			if (ris[j] <= ris[i]) {
				tmp = ris[j];
				ris[j] = ris[i];
				ris[i] = tmp;
			}
		}
	}

	/* Stampa il risultato */
	for(i = 0; i < NVAL*2; i++) {
		printf("%d ", ris[i]);
	}

	printf("\n");
}