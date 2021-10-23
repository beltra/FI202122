/*
*	Mix di due array ordinati - v2 (singolo array di lunghezza doppia)
*/

#include <stdio.h>
#define LEN 20

int main (int argc, char * argv[]) {
	int in1[LEN], in2[LEN], out[LEN*2];
	int i, j, outLen, tmp;

	/* Get the two arrays of integers */
	for (i = 0; i < LEN; i++) {
		scanf("%d", &in1[i]);
	}
	for (i = 0; i < LEN; i++) {
		scanf("%d", &in2[i]);
	}

	/* Put the two arrays in one with double the width */
	for (i = 0; i < LEN*2; i++) {
		if (i < LEN) {
			out[i] = in1[i];
		} else {
			out[i] = in2[i - LEN];
		}
	}

	/* Sort the array */
	for (i = 0; i < LEN*2 - 1; i++) {
		for (j = i+1; j < LEN*2; j++) {
			if (out[j] <= out[i]) {
				tmp = out[j];
				out[j] = out[i];
				out[i] = tmp;
			}
		}
	}

	/* Remove duplicates */
	outLen = 1;
	for (i = 1; i < LEN*2; i++) {
		if (out[i] != out[outLen - 1]) {
			out[outLen] = out[i];
			outLen++;
		}
	}
	
	/* Print the result */
	for (i = 0; i < outLen; i++) {
		printf("%d ", out[i]);
	}
	printf("\n");

	return 0;
}
