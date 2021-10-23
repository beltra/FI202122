/*
*	Data in input una sequenza di 50 valori interi e un intero soglia,
*	il programma visualizza i valori strettamente superiori alla soglia, indicandone anche la quantità
*/

#include <stdio.h>
#define NEL 5

int main(int argc, char * argv[]) {
	int numeri[NEL];
	int i, soglia, counter;

	i = 0;
	while(i < NEL) {
		scanf("%d", &numeri[i]);
		i++;
	}

	scanf("%d", &soglia);

	i = 0;
	counter = 0;
	while(i < NEL) {
		if(numeri[i] > soglia) {
			printf("%d\n", numeri[i]);
			counter++;
		}
		i++;
	}
	printf("%d\n", counter);
	return 0;
}