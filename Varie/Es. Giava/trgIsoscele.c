#include <stdio.h>

#define BLOCK '*'

int main (int argc, char * argv[]) {
    int alt;
    int i, j;

    /* Acquisisci il numero di righe */
    do {
        scanf("%d", &alt);
    } while (alt <= 0);

    /* Per ogni riga */
    for (i = 1; i <= alt; i++) { 
        for (j = 0; j < (alt - i); j++) {
            printf(" ");
        }
        for (j = alt - i; j < alt - 1 + i; j++) {
            printf("%c", BLOCK);
        }
        printf("\n");
    }
    return 0;
}