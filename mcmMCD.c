/*
* 	Acquisiti due numeri interi positivi a e b (finche non sono tali li richiedo), calcoli e visualizzi massimo comune divisore e minimo comune multiplo
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	int a, b;
	int mcm, mcd;
	int tmp;
	int min, divisore;

	do {
		scanf("%d", &a);
	} while (a < 0);

	do {
		scanf("%d", &b);
	} while (b < 0);


	/* Partendo da 1 */
 /*
	divisore = 1;

	if (a < b) {
		min = a;
	}
	else {
		min = b;
	}

	while (divisore <= min) {
		if ((a % divisore == 0) && (b % divisore == 0)) {
			mcd = divisore;
		}
		divisore++;
	} */

		
	/* Partendo dal valore minimo tra i due */

	if (a > b) {
		tmp = b;
	}
	else {
		tmp = a;
	}

	while(!(a % tmp == 0 && b % tmp == 0)) {
		tmp--;
	}

	mcd = tmp;

	mcm = (a*b) / mcd;

	printf("%d\t%d\n", mcd, mcm);

	return 0;
}