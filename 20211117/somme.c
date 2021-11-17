/*
*   Scrivere un programma che acquisiti 10 numeri interi ed un ulteriore numero, determini il numero dei
*   modi in cui è possibile sommare i 10 numeri per otternere l'ultimo numero inserito, ignorando l'ordine degli elementi
*   1 2 3 4 5 6 7 8 9 10
*   7
*   5
*/

#include <stdio.h>

#define DIM 10

int countComb(int num[], int dim, int obj);

int main (int argc, char *argv[]) {
    int sumObj;
    int num[DIM];

    int i;
    int count;

    for (i = 0; i < DIM; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &sumObj);

    count = countComb(num, DIM, sumObj);

    printf("%d\n", count);

    return 0;
}

int countComb(int num[], int dim, int obj) {
    int i, j;
    int count;

    count = 0;

    return count;
}