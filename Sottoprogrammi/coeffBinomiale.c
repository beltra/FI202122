/*
*   Acquisiti due valori interi strettamente positivi n e k, con k strettamente minore di n,
*   controllo che tutte e tre le condizioni siano verificate.
*   calcolo e restituisco il coefficiente binomiale (n k)
*/

#include <stdio.h>

int main (int argc, char *argv[]) {
    int n, k;
    int i, fn, fk, fnk, ris;

    do {
        scanf("%d", &n);
        scanf("%d", &k)
    } while (k >= n || n <= 0 || k <= 0);

    fn = 1;
    for (i = 2; i <= n; i++) {
        fn *= i;
    }

    fk = 1;
    for (i = 2; i <= k; i++) {
        fk *= i;
    }

    fnk = 1;
    for (i = 2; i <= (n-k); i++) {
        fnk *= i;
    }

    ris = fn/(fk*fnk);

    printf("%d\n", ris);

    return 0;
}