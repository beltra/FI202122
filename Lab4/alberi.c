#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "alberi1.txt"
#define MAX_DIM 10
#define TREE 1
#define LIMIT_CHANGE 8

void printGame(char colors[][MAX_DIM], int trees[][MAX_DIM], int dim);
int checkGriglia(char[][MAX_DIM], int[][MAX_DIM], int);
int checkRiga(int[][MAX_DIM], int);
int checkColonna(int[][MAX_DIM], int);
int checkColore(char[][MAX_DIM], int[][MAX_DIM], int);
int listColors(char[][MAX_DIM], char[], int);
int checkDistanza(int[][MAX_DIM], int);

int main (int argc, char*argv[]) {
	FILE *fp;

	char colors[MAX_DIM][MAX_DIM];
	int trees[MAX_DIM][MAX_DIM];

	int dim;
	int i, j;
	int r, c;

	char tmp;

	fp = fopen(FILE_NAME, "r");

	if (fp) {

		fscanf(fp, "%d\n", &dim);

		for (i = 0; i < dim; i++) {
			for (j = 0; j < dim; j++) {
				fscanf(fp, "%c", &colors[i][j]);
			}
			fscanf(fp, "%c", &tmp);
		}

		for (i = 0; i < dim; i++) {
			for (j = 0; j < dim; j++) {
				trees[i][j] = 0;
			}
		}

		fscanf(fp, "%d", &r);
		while (!feof(fp)) {
			fscanf(fp, "%d", &c);
			trees[r][c] = 1;
			fscanf(fp, "%d ", &r);
		}

		printGame(colors, trees, dim);

		printf("%d\n", checkGriglia(colors, trees, dim));

	} else {
		printf("Error opening input file\n");
	}

	return 0;
}

void printGame(char colors[][MAX_DIM], int trees[][MAX_DIM], int dim) {
	int i, j;

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			printf("%c", colors[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			printf("%d", trees[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

int checkGriglia(char colors[][MAX_DIM], int trees[][MAX_DIM], int dim) {
	int check;
	int riga, colonna, colore, distanza;

	riga = checkRiga(trees, dim);
	colonna = checkColonna(trees, dim);
	colore = checkColore(colors, trees, dim);
	distanza = checkDistanza(trees, dim);

	printf("Riga: %d\nColonna: %d\nColore: %d\nDistanza: %d\n", riga, colonna, colore, distanza);

	if(riga == 1 && colonna == 1 && colore == 1 && distanza == 1)
		check = 1;
	else
		check = 0;

	return check;
}

int checkRiga(int matrice[][MAX_DIM], int dim) {
	int i, j, lim, trovato, check;
		
	if (dim <= LIMIT_CHANGE)
		lim = 1;
	else 
		lim = 2;

	check = 1;
	for (i = 0; i < dim && check == 1; i++) {
		trovato = lim;
		for (j = 0; j < dim && check == 1; j++){
			if (matrice[i][j] == TREE)
				trovato--;
		}
		if (trovato != 0)
			check = 0;
	}

	return check;
}

int checkColonna(int matrice[][MAX_DIM], int dim) {
	int i, j, lim, trovato, check;
		
	if (dim <= LIMIT_CHANGE)
		lim = 1;
	else 
		lim = 2;

	check = 1;
	for (j = 0; j < dim && check == 1; j++) {
		trovato = lim;
		for (i = 0; i < dim && check == 1; i++){
			if (matrice[i][j] == TREE)
				trovato --;
		}
		if (trovato != 0)
			check = 0;
	}

	return check;
}


int checkColore(char colors[][MAX_DIM], int trees[][MAX_DIM], int dim) {
	int isValid;
	int check;
	int i, j, k;
	char colorsList[MAX_DIM*MAX_DIM];
	int *count;
	int colorsNum;

	if (dim <= LIMIT_CHANGE) {
		check = 1;
	} else {
		check = 2;
	}

	colorsNum = listColors(colors, colorsList, dim);
	count = malloc(colorsNum*sizeof(int));
	
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
						if (colors[i][j] == colorsList[k]) 
							*(count + k) += 1;				
					}
				}
			}
		}

		for (i = 0; i < colorsNum && isValid; i++) {
			if (count[i] != check) {
				isValid = 0;
			}
		}

		free(count);
	} else {
		printf("checkColors: failed allocating memory\n");
	}

	return isValid;
}

int listColors(char colors[][MAX_DIM], char list[], int dim) {
	int num;
	int i, j, k;
	int found;

	num = 0;
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			found = 0;
			for (k = 0; k < num && !found; k++) {
				if (colors[i][j] == list[k]) {
					found = 1;
				}
			}
			if (!found) {
				*(list + num) = colors[i][j];
				num++;
			}
		}
	}
	return num;
}


int checkDistanza(int mat[][MAX_DIM],int dim){
	int i, j;
	int check;
	check = 1;

	for(i = 0; i < dim && check != 0; i++) {
		for(j = 0; j < dim && check != 0; j++) {
			if(mat[i][j] == 1){
				if(i != 0 && mat[i-1][j] == 1)
					check=0;
				if(j != 0 && mat[i][j-1] == 1)
					check=0;
				if(j != dim && mat[i][j+1] == 1)
					check=0;
				if(i != dim && mat[i+1][j]==1)
					check=0;
			}
		}
	}

	return check;
}

