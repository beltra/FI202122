/*
*	Solo in ordine - v2 (Con array di supporto)
*/

#include <stdio.h>
#define MAX_NUM 20

int main (int argc, char * argv[]) {
	int num, in[MAX_NUM], ord[MAX_NUM];
	int i, nOrd, tmp;

	/* Get the number of elements given */
	scanf("%d", &num);

	/* Get the sequence of numbers and put it in an array */
	for (i = 0; i < num; i++) {
		scanf("%d", &in[i]);
	}
	
	/* Put in an array only the values in ascending order */
	ord[0] = in[0];
	nOrd = 1;
	for (i = 0; i < num; i++) {
		tmp = in[i];
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