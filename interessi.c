/*
*	Tre input: numero pos di partenza (saldo conto), num pos (tasso di interesse, 0.01 = 1%), saldo desiderato
*	Restituisce dopo quanti anni viene raggiunto (o superato) il saldo desiderato e il saldo raggiunto
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	float saldoIniziale, interesse, saldoDesiderato;
	float saldoFinale;
	int anni;

	/* Acquisizione dati */
	do {

		scanf("%f", &saldoIniziale);
	} while (saldoIniziale <= 0);

	do {
		scanf("%f", &interesse);
	} while (interesse <= 0);

	do {
		scanf("%f", &saldoDesiderato);
	} while (saldoDesiderato <= 0);


	/* Calcolo anni impiegati */
	anni = 0;
	saldoFinale = saldoIniziale;

	while (saldoFinale < saldoDesiderato) {
		anni++;
		saldoFinale += interesse * saldoFinale;
	}

	/* Restituzione valori */
	printf("Saldo finale: %.2f, raggiunto in %d anni\n", saldoFinale, anni);

	return 0;
}