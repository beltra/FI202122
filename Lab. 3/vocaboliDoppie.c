/*
*	Es. 1 - Vocaboli con doppie
*/

#include <stdio.h>
#include <string.h>

#define LEN 50

int conta(char str[]);

int main(int argc, char *argv[]) {
	char str[LEN+1];
	int num;

	gets(str);

	num = conta(str);

	printf("%d\n", num);

	return 0;
}

int conta(char str[]) {
	int count;
	int i, tmp;

	count = 0;
	tmp = 0;

	for (i = 1; str[i] != '\0'; i++) {
		/* If it finds a repeated letter */
		if (str[i] == str[i-1]) {
			tmp++;
		}
		/* When the word finishes */
		else if (str[i] == ' ' && tmp != 0) {
			count++;
			tmp = 0;
		}
	}

	return count;
}