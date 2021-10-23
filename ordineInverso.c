/*
*	Dati 5 numeri in ingresso, visualizzarli in ordine inverso
*/

#include <stdio.h>
#define NEL 5

int main(int argc, char * argv[]) {
	/*
	int n1, n2, n3, n4, n5;

	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	printf("%d %d %d %d %d", n5, n4, n3, n2, n1);
	*/

	int numeri[NEL];
	int i;

	i = 0;
	while(i < NEL) {
		scanf("%d", &numeri[i]);
		i++;
	}

	i = NEL - 1;
	while (i >= 0) {
		printf("%d\n", numeri[i]);
		i--;
	}

	return 0;
}