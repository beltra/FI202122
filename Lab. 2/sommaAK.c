/*
*	Somma a k
*/

#include <stdio.h>
#define NUM 100

int main (int argc, char * argv[]) {
	int input[NUM], k;
	int i, j, ris, tmp, num;

	/* Get every positive value and put it in an array, stop if negative or 0 */
	scanf("%d", &tmp);
	num = 0;
	while (tmp > 0 && num <= NUM) {
		input[num] = tmp;
		scanf("%d", &tmp);
		num++;
	}

	/* Get the desired sum */
	do {
		scanf("%d", &k);
	} while (k <= 0);

	/* Sum every pair of numbers and check if it's equal to k */
	ris = 0;
	for (i = 0; i < num && ris == 0; i++) {
		for (j = i; j < num && ris == 0; j++) {
			if (input[i] + input[j] == k) {
				ris = 1;
			}
		}
	}
	 
	/* Print the result */
	printf("%d\n", ris);
}