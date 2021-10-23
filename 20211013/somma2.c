/*
*   Acquisiti in ingresso 10 valori interi, e un ulteriore numero intero, obiettivo da raggiungere
*   Determina il numero di coppie distinte di valori che sommati tra loro diano come riultato il numero
*   inserito. Non compaiono valori ripetuti, visualizzare il numero di coppie trovate
*/

#include <stdio.h>

#define DIM 10

int main (int argc, char * argv[]) {
    int num[DIM];
    int obj;
    int i, j, coppie;

    for (i = 0; i < DIM; i++) {
        scanf("%d", &num[i]);
    }

    scanf("%d", &obj);

    coppie = 0;
    for (i = 0; i < DIM - 1; i++) {
        for (j = i + 1; j < DIM; j++) {
            if (num[i] + num[j] == obj) {
                coppie++;
                /* Se dovessi considerare tutte le coppie, anche quelle invertite */
                /* coppie += 2 */
            }
        }
    }

    printf("%d\n", coppie);
    return 0;
}