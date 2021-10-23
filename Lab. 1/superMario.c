#include <stdio.h>

#define SPAZI 2
#define MAXALT 16
#define BLOCK '#'

int main (int argc, char * argv[]) {
    int alt;
    int i, j;

    /* Acquisisci il numero di righe */
    do {
        scanf("%d", &alt);
    } while (alt <= 0 || alt > MAXALT);

    /* Per ogni riga */
    for (i = 1; i <= alt; i++) {
        /* Stampa una sequenza di spazi e blocchi */
        /*for (j = 0; j < alt - i; j++) {
            printf(" ");
        }
        for (j = alt - i; j < alt; j++) {
            printf("%c", BLOCK);
        }
        for (j = alt; j < alt + SPAZI; j++) {
            printf(" ");
        }
        for (j = alt + SPAZI; j < alt + SPAZI + i; j++) {
            printf("%c", BLOCK);
        }*/

        for (j = 0; j < (alt + SPAZI + i); j++) {
            if ((j >= (alt - i) && j < alt) || j >= alt + SPAZI) {
                printf("%c", BLOCK);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
