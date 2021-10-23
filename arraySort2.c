/*
*	Si scriva un programma che acquisisca in ingresso due array di
*	5 numeri interi (assumendo che l'utente li inserisca in ordine 
*	crescente). A partire da questi due array si crei l'array risultato
*	che contiene tutti i numeri contenuti nei due array di partenza,
* 	anch'esso ordinato in ordine crescente. Ad esempio:
*
*	array1 = [1, 3, 4, 9, 10]
*	array2 = [2, 5, 6, 10, 11]
*	risultato = [1, 2, 3 ,4, 5, 6, 9, 10, 10, 11]
*/

#include <stdio.h>

/* Definisce il numero di valori all'interno dei due array di input */
#define NVAL 5

int main(int argc, char * argv[]) {
	int val1[NVAL], val2[NVAL];
	int tmp, ris[NVAL*2];
	int i, j, k;

	/* Acquisisce i due array di input */
	printf("Inserisci un array di %d valori ordinati: ", NVAL);
	for(i = 0; i < NVAL; i++) {
		scanf("%d", &val1[i]);
	}
	printf("Inserisci un altro array di %d valori ordinati: ", NVAL);
	for(i = 0; i < NVAL; i++) {
		scanf("%d", &val2[i]);
	}

	/* Inizializza tre indici */
	i = 0;
	j = 0;
	k = 0;

	/* Ordina i due array all'interno dell'array ristultato*/
	while (i < NVAL && j < NVAL) {
		if (val1[i] < val2[j]) {
			ris[k] = val1[i];
			i++;
		}
		else {
			ris[k] = val2[j];
			j++;
		}
		k++;
	}

	/* Completa l'array risultato con gli ultimi elementi di un array maggiori di tutti quelli dell'altro array */
	while (i < NVAL) {
		ris[k] = val1[i];
		
		k++;
		i++;
	}

	while (j < NVAL) {
		ris[k] = val2[j];
		
		k++;
		j++;
	}

	/* Stampa il risultato */
	for(i = 0; i < NVAL*2; i++) {
		printf("%d ", ris[i]);
	}
	printf("\n");
	
	return 0;
}