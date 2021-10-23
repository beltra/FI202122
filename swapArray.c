/*
*   Acquisiti al massimo 50 numeri interi strettamente positivi (terminare l'inserimento
*   al primo valore non valido). Scambi tra loro i numeri a due a due presenti nell'array.
*   Alla fine visualizzi l'array ottenuto.
*/

#include <stdio.h>

#define DIM 50

int main(int argc, char * argv[]) {
    int valori[DIM];
    int i, max, tmp;

    /* Get all the input numbers and put them in an array (stop when not > 0)*/
    max = 0;
    scanf("%d", &tmp);
    while (tmp > 0 && max < DIM) {
        valori[max] = tmp;

        scanf("%d", &tmp);
        max++;        
    }

    /*
    scanf("%d", &tmp);
    for(max = 0; tmp > 0 && max < DIM; max++) {
        input[max] = tmp;
        scanf("%d", &tmp);
    } */

    /* Swap values two by two */
    for (i = 0; i < max - 1; i+=2) {
        tmp = valori[i];
        valori[i] = valori[i+1];
        valori[i+1] = tmp;
    }

    /* Print the swapped array */
    for (i = 0; i < max; i++) {
        printf("%d ", valori[i]);
    }
    printf("\n");

    return 0;
}