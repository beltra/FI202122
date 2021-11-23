/*
*	Alberi
*/

#define MAX_DIM 10
#define LIMIT_CHANGE 8
#include <stdio.h>
#include <stdlib.h>

int checkColore(char colors[][MAX_DIM], int trees[][MAX_DIM], int dim);
int listColors(char colors[][MAX_DIM], char list[]);

int main (int argc, char *argv[]) {
	FILE *fp;

	char colors[][MAX_DIM];
	int trees[][MAX_DIM];

	int dim;
	int i, j;
	int r, c;

	fp = fopen(PATH, "r");

	if (fp) {
		fscanf(fp, "%d", &dim);
		for (i = 0; i < dim; i++) {
			for (j = 0; j < dim; j++) {
				fscanf(fp, "%c", &colors[i][j]);
			}
		}

		for (i = 0; i < dim; i++) {
			for (j = 0; j < dim; j++) {
				colors[i][j] = 1;
			}
		}

		while (!feof(fp)) {
			fscanf(fp, "%d %d", &r, &c);
			colors[r][c] = 1;
		}

		printf("%d\n", checkGriglia(colors, trees, dim));

	} else {
		printf("Error opening input file\n");
	}

	return 0;
}

int checkColore(char colors[][MAX_DIM], int trees[][MAX_DIM], int dim) {
	int isValid;
	int check;
	int i, j, k;
	char *colorsList;
	int *count;
	int colorsNum;

	if (dim <= LIMIT_CHANGE) {
		check = 1;
	} else {
		check = 2;
	}

	colorsNum = listColors(colors, colorsList);
	count = malloc(colorsNum);
	
	if (count) {
		/* Inizializza i contatori */
		for (i = 0; i < colorsNum; i++) {
			*(count + i) = 0;
		}

		isValid = 1;

		/* Per ogni casella */
		for (i = 0; i < dim; i++) {
			for (j = 0; j < dim; j++) {
				/* Se c'è un albero */
				if (trees[i][j] == 1) {
					/* Aumenta il contatore del colore corrispondente */
					for (k = 0; k < colorsNum; k++) {
						if (colors[i][j] == k) {
							*(count + k) += 1;
						}
					}
				}
			}
		}

		for (i = 0; i < colorsNum && isValid; i++) {
			if (count[i] > check) {
				isValid = 0;
			}
		}

		free(count);
	} else {
		printf("checkColors: failed allocating memory\n");
	}

	return isValid;
}

int listColors(char colors[][MAX_DIM], char list[]) {
	int dim;
	int i, j, k;
	int found;

	dim = 0;
	list[0] = colors[0][0];
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			found = 0;
			for (k = 0; k < dim && !found; k++) {
				if (colors[i][j] == list[k]) {
					found = 1;
				}
			}
			if (!found) {
				list[dim] = colors[i][j];
				dim++;
			}
		}
	}
}