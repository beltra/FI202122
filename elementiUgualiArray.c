/*
*	Acquisiti in ingresso due array di 5 elementi di valori interi, salvi 
*	in un array risultato tutti e soli i valori che sono presenti in 
*	entrambi gli array di partenza
*/

#include <stdio.h>

#define NVAL 5

int main(int argc, char * argv[]) {
	int num1[NVAL], num2[NVAL], ris[NVAL];
	int i, j, nComuni;

	for(i = 0; i < NVAL; i++) {
		scanf("%d", &num1[i]);
	}
	for(i = 0; i < NVAL; i++) {
		scanf("%d", &num2[i]);
	}

	nComuni = 0;
	for(i = 0; i < NVAL; i++) {
		for (j = 0; j < NVAL; j++) {
			if (num1[i] == num2[j]) {
				ris[nComuni] = num1[i];
				nComuni++;
			}
		}
	}

	for(i = 0; i < nComuni; i++) {
		printf("%d ", ris[i]);
	}

	printf("\n");

	return 0;
}