/*
*   Scrivere un sottoprogramma che istanzia, riempie e ritorna al chiamante un array di numeri interi
*/

#include <stdio.h>
#include <stdlib.h>

int *fillArray(int *dim);

int main (int argc, char *argv[]) {
    int dim, i;
    int *num;

    num = fillArray(&dim);

    if (num) {
        for (i = 0; i < dim; i++) {
            printf("%d ", *(num + i));
        }
        printf("\n");
        free(num);
    }

    return 0;
}

int *fillArray (int *dim) {
    int size;
    int *num;
    int i;

    scanf("%d", &size);

    num = malloc(size * sizeof(int));

    if (num) {
        for (i = 0; i < size; i++) {
            scanf("%d", num + i);
        }
    } else {
        printf("Failed to allocate memory\n");
    }

    *dim = size;

    return num;
}