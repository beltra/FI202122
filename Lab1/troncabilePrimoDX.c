#include <stdio.h>

int main (int argc, char * argv[]) {
    int val;
    int i, ris;

    /* Acquisisci il numero, controllando che sia valido */
    do {
        scanf("%d", &val);
    } while (val <= 0);
    
    ris = 1;
    while (val > 0 && ris != 0) {
        /* Se divisibile per due */
        if (val % 2 == 0) {
            ris = 0;
        }
        /* Controlla solo i numeri non multipli di due, fino a metà del valore finale */
        else {
            for(i = 3; i < val/2 && ris != 0; i += 2) {
                if (val % i == 0) {
                    ris = 0;
                    i = val;
                }
            }
        }
        val /= 10;
    }

    /* Stampa il risultato */
    printf("%d\n", ris);

    return 0;
}