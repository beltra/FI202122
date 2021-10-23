/* 
* 	Dato in input un valore maggiore o uguale a 0 (se non è tale lo richiede), conta il numero di cifre e lo visualizza.
*/

#include <stdio.h>

#define BASE 10

int main(int argc, char * argv[]) {

	int num;
	int cifre, ordGrandezza;

	/*
	scanf("%d", &num);
	while (num < 0) {
		scanf("%d", &num);
	} */

	/* Ciclo a condizione finale - Il costrutto do while*/
	do {
		scanf("%d", &num);
	} while (num < 0);

	ordGrandezza = 1;
	cifre = 0;

 	while(ordGrandezza <= num) {
 		cifre++;
 		ordGrandezza *= BASE;
 	}

 	/* oppure 
 	cifre = 0;
 	do {
 		cifre++;
 		val = val/BASE;
 	} while (val > 0);
 	*/

 	printf("Il numero di cifre e' %d\n", cifre);

	return 0;
}
