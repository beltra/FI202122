/*
* 	Programma che visualizza la tabella pitagorica su una dimensione di 10 righe per 10 colonne
*/

#include <stdio.h>
#define RIGHE 10
#define COLONNE 10

int main (int argc, char * argv[]) {
	int riga, colonna;
	int val;

	/*
	riga = 1;
	colonna = 1;

	while (riga <= RIGHE) {
		while (colonna <= COLONNE) {
			val = colonna * riga;
			printf("%d\t", val);

			colonna++;
		}
		printf("\n");

		colonna = 1;
		riga++;
	} */

	for(riga = 1; riga <= RIGHE; riga++) {
		for(colonna = 1; colonna <= COLONNE; colonna++) {
			val = colonna * riga;
			printf(" %3d", val);
		}
		printf("\n");
	}

	return 0;
}


