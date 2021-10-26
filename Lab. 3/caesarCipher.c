/*
*	Es. 5 - Lettere a scorrere
*/

#include <stdio.h>

#define LEN 50
#define FIRSTLOWER 'a'
#define FIRSTUPPER 'A'
#define LETTERS 26

void encrypt(char str[], int key);

int main (int argc, char *argv[]) {
	char str[LEN +1];
	int key;

	gets(str);

	scanf("%d", &key);

	encrypt(str, key);

	printf("%s\n", str);

	return 0;
}

void encrypt(char str[], int key) {
	int i, lowercase;

	/* If lowercase */
	/*if (str[0] >= FIRSTLOWER && str[0] <= FIRSTLOWER + LETTERS) {
		lowercase = 1;
	} else {
		lowercase = 0;
	}*/

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= FIRSTLOWER && str[i] <= FIRSTLOWER + LETTERS) {
			str[i] = FIRSTLOWER + ((str[i] - FIRSTLOWER) + key) % LETTERS;
		} else {
			str[i] = FIRSTUPPER + ((str[i] - FIRSTUPPER) + key) % LETTERS;
		}
	}
}
