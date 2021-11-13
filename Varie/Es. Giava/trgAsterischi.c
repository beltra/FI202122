/*
*   Ricevuto in input un numero, restituire un triangolo di n righe con un numeor crescente di caratteri
*/

#include <stdio.h>
#define BLOCK '*'

int main (int argc, char * argv[]) {
    int i, j, h;

    do {
        scanf("%d", &h);
    } while (h <= 0);

    for (i = 1; i <= h; i++) {
        for (j = 0; j < i; j++) {
            printf("%c", BLOCK);
        }
        printf("\n");
    }
    return 0;
}