/*
*   Es. 2
*/

#include <stdio.h>
#define DIM 4

int main (int argc, char * argv[]) {
    int matr[DIM][DIM];
    int i, j, tmp;

    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            scanf("%d", &matr[i][j]);
        }
    }

    for (i = 1; i < DIM; i++) {
        for (j = 0; j < i; j++) {
            tmp = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = tmp;
        }
    }
    
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            printf("%2d ", matr[i][j]);
        }
        printf("\n");
    }

    return 0;
}