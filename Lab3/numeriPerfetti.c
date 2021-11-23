/*
*	Es. 4 - Numeri perfetti
*/

#include <stdio.h>
#define DIM 10

int tipoNum(int num);

int main(int argc, char *argv[]) {
	int num[DIM], type[DIM];
	int count1, count2, count3;
	int i;

	for (i = 0; i < DIM; i++) {
		scanf("%d", &num[i]);
	}

	count1 = 0;
	count2 = 0;
	count3 = 0;

	for (i = 0; i < DIM; i++) {
		type[i] = tipoNum(num[i]);

		if (type[i] == 1) {
			count1++;
		} else if (type[i] == 2) {
			count2++;
		} else if (type[i] == 3) {
			count3++;
		}
	}

	for (i = 0; i < DIM; i++) {
		printf("%d ", type[i]);
	}
	printf("\n");

	printf("%d %d %d\n", count1, count2, count3);

	return 0;
}

int tipoNum(int num) {
	int type;
	int i, sum;

	if (num <= 0) {
		type = 0;
	} else {
		sum = 0;
		for (i = 1; i < num; i++) {
			if (num % i == 0) {
				sum += i;
			}
		}
		if (num == sum) {
			type = 1;
		} else if (num < sum) {
			type = 2;
		} else if (num > sum) {
			type = 3;
		}
	} 

	return type;
}
