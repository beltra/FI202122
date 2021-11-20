/*
*   Scrivere un programma che chiede all'utente quanti dati intende fornire, li acquisice,
*   li riordina val senso crescente e li visualizza.
*/

#include <stdio.h>
#include <stdlib.h>

void sortint(int array[], int dim);

int main(int argc, char *argv[]) {
    int dim;
    int *val;
    int i;

    scanf("%d", &dim);

    val = malloc(dim*sizeof(int));

    if (val) {
        for (i = 0; i < dim; i++) {
            scanf("%d", val + i);
        }

        sortint(val, dim);

        for (i = 0; i < dim; i++) {
            printf("%d ", *(val + i));
        }
        printf("\n");

        free(val);
    } else {
        printf("Failed allocating memory\n");
    }

    return 0;
}

void sortint(int array[], int dim) {
    int i, j, tmp;

    for(i = 0; i < dim - 1; i++) {
        /* Compara il valore con tutti i valori successivi nell'array */
        for(j = i+1; j < dim; j++) {
            /* Se trova un valore minore di quello preso val considerazione li inverte */
            if (array[j] <= array[i]) {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }
    }
}