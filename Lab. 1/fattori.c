#include <stdio.h>

int main (int argc, char * argv[]) {
    int n1, n2;
    int ris;

    /* Acquisisci i due numeri */
    scanf("%d %d", &n1, &n2);

    /* Se uno dei due è 0, sicuramente non è divisore */
    if (n1 == 0 || n2 == 0) {
        ris = 0;
    }
    /* Controlla se è divisore */
    else if (n1 % n2 == 0 || n2 % n1 == 0) {
        ris = 1;
    }
    else {
        ris = 0;
    }

    /* Stampa il risultato */
    printf("%d\n", ris);

    return 0;
}