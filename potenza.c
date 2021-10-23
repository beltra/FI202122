/*
*	Dati a e b strettamente postivi (se no li richiede), determini se b è 
*	potenza di a e in caso positivo determini l'esponente e tale che a^e = b
* 	e stampi l'esponente, altrimenti visualizzi -1
*/

#include <stdio.h>

int main(int argc, char * argv[]) {
	int a, b, e;
	int potenza;

	do {
		scanf("%d", &a);
	} while (a <= 0);

	do {
		scanf("%d", &b);
	} while (b <= 0);

	if (!(a == 1 && b != 1)) {
		potenza = 1;
		e = 0;
		while (potenza < b) {
			e++;
			potenza = potenza * a;
		}

		if (potenza == b) {
			printf("%d^%d = %d\n", a, e, b);
		}
		else {
			printf("-1\n");
		}
	} else {
		printf("-1\n");
	}

	return 0;
}