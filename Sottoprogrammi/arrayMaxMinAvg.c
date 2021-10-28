/*
*	Scrivere un sottoprogramma che trasmette l'indice del numero minimo e l'indice del numero massimo e
*	la media dei valori di un array
*/

/* Gli ultimi tre parametri sono indirizzi della memoria, in cui il sottoprogramma salverà i risultati */
/* int *risMax indica il tipo di dato e il suo indirizzo */

/*
int main (char *argv[], int argc) {}

char *argv[] 	significa che passo l'indirizzo dell'array argv
int argc 		è la dimensione dell'array
*/

#include <stdio.h>
#define MAXVAL 100

void statsint(int[], int, int*, int*, float*);

int main (int argc, char *argv[]) {
	int val[MAXVAL];
	int nVal, i;
	int risMax, risMin, risAvg;

	do {
		scanf("%d", &nVal);
	} while (nVal <= 0 || nVal > MAXVAL);

	for (i = 0; i < nVal; i++) {
		scanf("%d", &val[i]);
	}

	statstint(val, nVal, &risMax, &risMin, &risAvg);

	printf("%d %d %f", val[risMax], val[risMin], risAvg);

	

	return 0;
}

void statsint(int v[], int dim, int *risMax, int *risMin, float *risAvg) {
	int i, iMax, iMin, tot;
	float avg;

	iMax = 0;
	iMin = 0;
	tot = v[0];

	for (i = 1; i < dim; i++) {
		if (v[i] > v[iMax]) {
			iMax = i;
		} else if (v[i] < v[iMin]) {
			iMin = i;
		}
		tot += v[i];
	}

	/* risMin = iMin; 	NO, sostituisce all'indirizzo il valore di iMin */

	*risMax = iMax;		/* risMax è un indirizzo, *risMax è un int */
	*risMin = iMin;
	*risAvg = avg;

	avg = (float) tot/dim;
}