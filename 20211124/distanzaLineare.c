/*
*   Es. 4
*/

#include <stdio.h>
#include <stdlib.h>

float *distanzalineare(float start, float stop, int numero, int escludistop);

int main(int argc, char *argv[]) {
    float start, stop;
    int numero, escludistop;
    int i;
    float *ris;

    scanf("%f %f %d %d", &start, &stop, &numero, &escludistop);

    ris = distanzalineare(start, stop, numero, escludistop);

    if (ris) {
        for (i = 0; i < numero; i++) {
            printf("%.2f ", *(ris + i));
        }
        printf("\n");
        free(ris);
    }

    return 0;
}

float *distanzalineare(float start, float stop, int numero, int escludistop) {
    float *ris;
    int i;
    float distance;

    ris = malloc(numero * sizeof(float));

    if (ris) {
        distance = (stop - start) / (numero - 1 + escludistop);

        for (i = 0; i < numero; i++) {
            *(ris + i) = start + distance*i;
        }

    } else {
        printf("Failed allocating memory\n");
    }

    return ris;
}