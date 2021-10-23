/*
*	Acquisito un numero intero strettamente positivo (se non tale lo richiede), 
*	restituisce la parte intera della sua radice quadrata
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	int val;
	int radq, quad;

	do {
		scanf("%d", &val);
	} while (val <= 0);

	radq = 0;

	do {
		radq++;
		quad = radq * radq;
	} while (quad <= val);

	radq--;

	printf("%d\n", radq);
}