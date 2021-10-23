/*
*	Ricevuto in ingresso un intero positivo o nullo (se non è così lo richiede), calcoli e visualizzi il suo fattoriale
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	int val;
	int fact, i;

	do {
		scanf("%d", &val);
	} while (val < 0);

	fact = 1;

	/*
	i = 2;

	while(i <= val) {
		fact *= i;
		i++;
	} */

	for (i = 2; i <= val; i++) {
		fact *= i;
	}

	printf("%d! = %d\n", val, fact);
	return 0;
}