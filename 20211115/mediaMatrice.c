/*
*   Programma che chiede due nomi di file, contenenti ognuno una matrice 5*5 di numeri interi.
*   Legge i file e crea un nuovo file, di cui chiede il nome, contenente una matrice i cui elementi sono la media degli elementi delle due matrici
*/

#include <stdio.h>
#define DIM 5
#define LEN 60

void solve(int m1[][DIM], int m2[][DIM], float mout[][DIM], int h, int w);

int main (int argc, char *argv[]) {
    FILE *fin1, *fin2, *fout;

    int i,j;

    char fileNameIn1[LEN +1], fileNameIn2[LEN +1], fileNameOut[LEN +1];

    int matIn1[DIM][DIM], matIn2[DIM][DIM];
    float matOut[DIM][DIM];

    scanf("%s", fileNameIn1);
    scanf("%s", fileNameIn2);
    scanf("%s", fileNameOut);

    fin1 = fopen(fileNameIn1, "rb");
    fin2 = fopen(fileNameIn2, "rb");
    fout = fopen(fileNameOut, "wb");

    if (fin1) {
        if (fin2) {
            if (fout) {
                fread(matIn1, sizeof(int), DIM * DIM, fin1);
                fread(matIn2, sizeof(int), DIM * DIM, fin2);

                for (i = 0; i < DIM; i++) {
                    for (j = 0; j < DIM; j++) {
                        printf("%d ", matIn1[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");

                for (i = 0; i < DIM; i++) {
                    for (j = 0; j < DIM; j++) {
                        printf("%d ", matIn2[i][j]);
                    }
                    printf("\n");
                }
                printf("\n"); 

                solve(matIn1, matIn2, matOut, DIM, DIM);

                for (i = 0; i < DIM; i++) {
                    for (j = 0; j < DIM; j++) {
                        printf("%f ", matOut[i][j]);
                    }
                    printf("\n");
                }   

                fwrite(matOut, sizeof(float), DIM * DIM, fout);

                fclose(fout);
            } else {
                printf("Error opening output file");
            }
            fclose(fin2);
        } else {
            printf("Error opening second input file");
        }
        fclose(fin1);        
    } else {
        printf("Error opening first input file");
    }

    return 0;
}

void solve(int m1[][DIM], int m2[][DIM], float mout[][DIM], int h, int w) {
    int r, c;

    for (r = 0; r < h; r++) {
        for (c = 0; c < w; c++) {
            mout[r][c] = (m1[r][c] + m2[r][c]) / 2;
        }
    }
}

