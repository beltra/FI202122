/*
*	Sottostringa più lunga senza ripetizioni
*/

#include <stdio.h>
#define LEN 30

int main (int argc, char * argv[]) {
	char input[LEN+1];
	int i, j, k, tmpLen, len, maxLen, hasRepeats;

	/* Get the input string */
	scanf("%s", input);

	/* Compute the string's length */
	for (len = 0; input[len] != '\0'; len++);

	maxLen = 1;
	hasRepeats = 0;
	/* For each character */
	for (i = 0; i < len; i++) {
		hasRepeats = 0;
		/* Consider every next character */
		for (j = i + 1; j < len && hasRepeats == 0; j++) {
			/* Compare it with the rest of the substring between the i-th and j-th characters */
			tmpLen = j - i + 1;
			for (k = i; k < j && hasRepeats == 0; k++) {
				/* If it is equal to another character, then the substrings has repetition */
				if (input[j] == input[k]) {
					hasRepeats = 1;
					tmpLen = 1;
				}
			}
			/* If there are no repetitions, save only the max length of the substrings */
			if (hasRepeats == 0 && tmpLen > maxLen) {
				maxLen = tmpLen;
			}
		}
	}

	/* Print the length */
	printf("%d\n", maxLen); 

	return 0;
}
 