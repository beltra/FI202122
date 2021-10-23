#include <stdio.h>

#define BASE 10

int main (int argc, char * argv[]) {
    int num, k;
    int cifre, i;
    
    /* Acquisisci due numeri */
    do {
        scanf("%d", &num);
    } while (num <= 0);

    do {
        scanf("%d", &k);
    } while (k <= 0);

    /* Calcola il numero di cifre del numero*/
    cifre = 0;
    i = 1;
    while (i < num) {
        cifre++;
        i *= BASE;
    }
    
    /* Per ogni cifra in più richiesta stampa 0, infine stampa il numero */
    for (i = k; i > cifre; i--) {
        printf("0");
    }
    printf("%d\n", num);

    return 0;
}