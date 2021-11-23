/*
*	Es. 3 - Cifra k
*/

#include <stdio.h>
#define BASE 10

int cifra(int num, int k);

int main (int argc, char *argv[]) {
	int num, k;

	scanf("%d %d", &num, &k);

	printf("%d\n", cifra(num, k));

	return 0;
}

int cifra(int num, int k) {
	int cifra, pos, tmp;
	int i;

	if (num >= 0) {
		num = num;
	} else {
		num = -num;
	}

	tmp = num;

	pos = 1;
	cifra = tmp % BASE;
	tmp /= BASE;

	for (i = 1; i < k; i++) {
		cifra = tmp % BASE;
		tmp /= BASE;
		pos *= BASE;
	}

	if (pos > num || k <= 0) {
		return -1;
	} else {
		return cifra;
	}
}