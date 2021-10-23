/*
*	Acquisito un valore intero che denota la fine della sequenza, seguito da una sequenza di numeri arbitraria, terminata dal numero iniziale.
* 	Il programma calcola e visualizza valore massimo, valore minimo e media dei valori acquisiti. Il valore fine non fa parte della sequenza. 
*/

#include <stdio.h>

int main(int argc, char * argv[]) {
	int fineSequenza, val;
	int numValori, tot, max, min;
	float media;

	scanf("%d", &fineSequenza);

	/* Deve esserci un primo valore diverso da fine sequenza */
	scanf("%d", &val);

	max = val;
	min = val;
	numValori = 1;
	tot = val;

	scanf("%d", &val);

	/* Per ogni valore successivo diverso dalla fine */
	while (val != fineSequenza) {
		if (val > max) {
			max = val;
		}
		else if (val < min) {
			min = val;
		}
		numValori++;
		tot += val;

		scanf("%d", &val);
	}

	media = (float)tot / numValori;

	printf("Il massimo e' %d\n", max);
	printf("Il minimo e' %d\n", min);
	printf("La media e' %.2f\n", media);    
	return 0;
}
