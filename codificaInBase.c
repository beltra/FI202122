/*
* 	Acquisito in ingresso un valore intero e strettamente positivo (e continua a richiederlo),
*	il programma visualizza la codifica in base due (allo specchio)
*/

#include <stdio.h>

#define BASE 2

int main(int argc, char * argv[]) {
	int num;
	int quoziente, resto;
	int pos;
	int codifica;

	do {
		scanf("%d", &num);
	} while (num <= 0);

	quoziente = num;
	pos = 1;
	codifica = 0;

	while (quoziente > 0) {
		resto = quoziente % BASE;
		codifica += resto * pos;
		pos *= 10;

		quoziente /= BASE;
	}

	printf("%d\n", codifica);

	return 0;
}