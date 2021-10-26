/*
*   Acquisiti due valori interi strettamente positivi n e k, con k strettamente minore di n,
*   controllo che tutte e tre le condizioni siano verificate.
*   calcolo e restituisco il coefficiente binomiale (n k).
*	Utilizza un sottoprogramma che restituisce il fattoriale.
*/

#include <stdio.h>

int fact(int);

int main (int argc, char *argv[]) {
    int n, k;
    int i, fn, fk, fnk, ris;

    do {
        scanf("%d", &n);
        scanf("%d", &k);
    } while (!(n > k && n > 0 && k > 0));

    fn = fact(n);
    fk = fact(k);
    fnk = fact(n-k);

    ris = fn/(fk*fnk);

    printf("%d\n", ris);

    return 0;
}

int fact(int num) {
	int i, ris;

	ris = 1;
	for (i = 2; i <= num; i++) {
        ris *= i;
    }

    return ris;
}

/* Passaggio parametri per copia-valore */
/* I valori passati al sottoprogramma vengono copiati in una parte di memoria ad esso dedicata,
   ogni modifica rimane nel sottoprogramma */

/* Usando una sola variabile in più */
/*
int fact(int num) {
	int f;
	f = 1;
	for (num >= 2; num--) {
		f *= num;
	}

	return f;
}
*/

