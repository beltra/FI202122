/*
*   Scrivere un sottoprogramma che, ricevuta in ingresso una matrice di interi e le coordinate del punto iniziale
*   ritorni il numero di celle connesse al punto iniziale
*/

#include <stdio.h>

#define MAXDIM 10
#define LEN 60

int celleConnesse(int mat[][MAXDIM], int w, int h, int r, int c);
void stampaMatrice(int mat[][MAXDIM], int w, int h);

int main(int argc, char *argv[]) {
    int w, h;
    int mat[MAXDIM][MAXDIM];
    int r, c;
    int i, j;

    /*
    scanf("%d %d", &h, &w);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    scanf("%d %d", &r, &c);
    */

    FILE *fin;
    char fileName[LEN+1];

    scanf("%s", fileName);

    if (fin = fopen(fileName, "r")) {
        fscanf(fin, "%d%d", &h, &w);

        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                fscanf(fin, "%d", &mat[i][j]);
            }
        }

        fscanf(fin, "%d%d", &r, &c);
        fclose(fin);

        printf("%d\n", celleConnesse(mat, w, h, r, c));        
    } else {
        printf("Error opening file ./%s\n", fileName);
    }
    
    return 0;
}

int celleConnesse(int mat[][MAXDIM], int w, int h, int r, int c) {
    int value, count;

    count = 1;
    value = mat[r][c];

    mat[r][c] = value + 3;

    stampaMatrice(mat, w, h);

    if (r - 1 >= 0 && mat[r-1][c] == value) {
        count += celleConnesse(mat, w, h, r-1, c);
    } 
    if (r + 1 < w && mat[r+1][c] == value) {
        count += celleConnesse(mat, w, h, r+1, c);
    }     
    if (c - 1 >= 0 && mat[r][c-1] == value) {
        count += celleConnesse(mat, w, h, r, c-1);
    }    
    if (c + 1 < h && mat[r][c+1] == value) {
        count += celleConnesse(mat, w, h, r, c+1);
    }

    return count;
    
}

void stampaMatrice(int mat[][MAXDIM], int w, int h) {
    int i, j;
    
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("========\n");
}