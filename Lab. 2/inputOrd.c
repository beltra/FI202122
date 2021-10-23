/*
*	Solo in ordine
*/

#include <stdio.h>
#define MAX_NUM 20

int main (int argc, char * argv[]) {
	int num, ord[MAX_NUM];
	int i, nOrd, tmp;

	/* Get the number of elements given */
	scanf("%d", &num);

	/* Get the first number of the sequence */
	scanf("%d", &ord[0]);
	nOrd = 1;

	/* For every number got append it to the results only if greater than the one before */
	for (i = 1; i < num; i++) {
		scanf("%d", &tmp);
		if (tmp > ord[nOrd - 1]) {
			ord[nOrd] = tmp;
			nOrd++;
		}
	}

	/* Print the results */
	printf("%d\n", nOrd);
	for (i = 0; i < nOrd; i++) {
		printf("%d ", ord[i]);
	}
	printf("\n");

	return 0;
}