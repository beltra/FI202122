/*
*	Scrivere un programma che acquisisce in input un 
*   valore tra 0 e 1023 inclusi (se non tale lo 
*   richiede). Il programma restituisce la conversione in
*	base 2
*/

#include <stdio.h>
#define BASE 2
#define NBIT 10

int main(int argc, char * argv[]) {
	int codifica[NBIT];
	int val, bit, quoziente, i;

	do {
		scanf("%d", &val);
	} while (val < 0 || val > 1023);

	quoziente = val;

	for(i = NBIT - 1; i >= 0; i--) {
		bit = quoziente % BASE;
		codifica[i] = bit;
		quoziente /= BASE;
	}

	for(i = 0; i < NBIT; i++) {
		printf("%d", codifica[i]);
	}

	printf("\n");
	return 0;
}
