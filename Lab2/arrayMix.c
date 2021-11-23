/*
*	Mix di due array ordinati
*/

#include <stdio.h>
#define LEN 20

int main (int argc, char * argv[]) {
	int in1[LEN], in2[LEN], out[LEN*2];
	int i, j, k, tmp;

	/* Get the two arrays of integers */
	for (i = 0; i < LEN; i++) {
		scanf("%d", &in1[i]);
	}
	for (i = 0; i < LEN; i++) {
		scanf("%d", &in2[i]);
	}

	/* Sort the two arrays */
	/* Compare each value with the ones following, if one is smaller, invert the two */
	for (i = 0; i < LEN - 1; i++) {
		for (j = i+1; j < LEN; j++) {
			if (in1[j] <= in1[i]) {
				tmp = in1[j];
				in1[j] = in1[i];
				in1[i] = tmp;
			}
		}
	}
	for (i = 0; i < LEN - 1; i++) {
		for (j = i+1; j < LEN; j++) {
			if (in2[j] <= in2[i]) {
				tmp = in2[j];
				in2[j] = in2[i];
				in2[i] = tmp;
			}
		}
	}

	/* Mix the two arrays, creating one in ascending order, with no duplicates */
	i = 0;
	j = 0;
	/* Put the first value equal to the lower between the first values of the ordered arrays */
	if (in1[0] < in2[0]) {
		out[0] = in1[0];
	} else {
		out[0] = in2[0];
	}
	k = 1;
	
	/* Loop in the two arrays choosing the lowest value between the two */
	while (i < LEN && j < LEN) {
		if (in1[i] <= in2[j]) {
			if (in1[i] != out[k-1]) {
				out[k] = in1[i];
				k++;
			}			
			i++;
		} else {
			if (in2[j] != out[k-1]) {
				out[k] = in2[j];
				k++;
			}		
			j++;			
		}					
	}

	/* Complete the out array with the values of the array which values are greater than the ones of the other array */
	for (; i < LEN; i++) {
		if (in1[i] != out[k-1]) {
			out[k] = in1[i];
			k++;
		}
	}
	for (; j < LEN; j++) {
		if (in2[j] != out[k-1]) {
			out[k] = in2[j];
			k++;
		}		
	}
	
	/* Print the results */
	for (i = 0; i < k; i++) {
		printf("%d ", out[i]);
	}
	printf("\n");

	return 0;
}
