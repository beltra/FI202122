/* Quesito 2 */

#include <stdlib.h>
#include <stdio.h>

void stats(int val[], int dim, int *q1, int *q2, int *q3);
void riordina(int val[], int dim);

int main(int argc, char *argv[]) {
    int i;
    int dim;
    int *val;
    int q1, q2, q3;

    scanf("%d", &dim);

    val = malloc(dim*sizeof(int));

    if (val) {
        for (i = 0; i < dim; i++) {
            scanf("%d", val + i);
        }

        stats(val, dim, &q1, &q2, &q3);
        
        for (i = 0; i < dim; i++) {
            printf("%d ", *(val + i));
        }
        printf("\n");
        printf("Q1 = %d, Q2 = %d; Q3 = %d\n", q1, q2, q3);

        free(val);
    } else {
        printf("Failed allocating memory\n");
    }


    return 0;
}

void stats(int val[], int dim, int *q1, int *q2, int *q3) {
    int i;
    int cnt;

    riordina(val, dim);


    *q1 = val[dim/4];
    *q2 = val[dim/2];
    *q3 = val[dim*3/4];

}

void riordina(int val[], int dim) {
    int i, j;
    int tmp;

    for (i = 0; i < dim - 1; i++) {
        for (j = i; j < dim; j++) {
            if (val[j] < val[i]) {
                tmp = val[i];
                val[i] = val[j];
                val[j] = tmp;
            }
        }
    }
}