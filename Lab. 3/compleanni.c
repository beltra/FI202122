/*
*	Es. 2 - Compleanni
*/

#include <stdio.h>
#define MAXPEOPLE 10

typedef struct date_s {
	int d, m, y;
} date_t;

void bornEqual(date_t date[], int num, date_t verifica, int *count1, int *count2);

int main (int argc, char *argv[]) {
	date_t nascite[MAXPEOPLE];
	date_t dataVerifica;
	int count1, count2;
	int i;

	/* Get all the birth dates */
	for (i = 0; i < MAXPEOPLE; i++) {
		do {		
			scanf("%d", &nascite[i].d);
			scanf("%d", &nascite[i].m);
			scanf("%d", &nascite[i].y);
		} while (nascite[i].d < 1 || nascite[i].d > 31 || nascite[i].m < 1 || nascite[i].m > 12 || nascite[i].y < 1);
	}

	/* Get the date to verify */
	do {		
		scanf("%d", &dataVerifica.d);
		scanf("%d", &dataVerifica.m);
		scanf("%d", &dataVerifica.y);
	} while (dataVerifica.d < 1 || dataVerifica.d > 31 || dataVerifica.m < 1 || dataVerifica.m > 12 || dataVerifica.y < 1);

	/* Call the subroutine */
	bornEqual(nascite, MAXPEOPLE, dataVerifica, &count1, &count2);

	/* Print the results */
	printf("%d %d\n", count1, count2);

	return 0;
}

void bornEqual(date_t date[], int num, date_t verifica, int *count1, int *count2) {
	int i, c1, c2;

	*count1 = 0;
	*count2 = 0;
 	
	for (i = 0; i < num; i++) {
		if (date[i].d == verifica.d && date[i].m == verifica.m && date[i].y == verifica.y) {
			*count1 += 1;
		}
		if (date[i].d == verifica.d && date[i].m == verifica.m) {
			*count2 += 1;
		}
	}
	/*
	*count1 = c1;
	*count2 = c2; */
}