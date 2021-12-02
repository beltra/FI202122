#include <stdio.h>
#include <stdlib.h>
#include "liste_int.h"

listi_t *fattori(int n);

int main (int argc, char *argv[]) {
    listi_t *h;
    int n;

    scanf("%d", &n);

    h = fattori(n);

    view(h);

    return 0;
}

listi_t *fattori(int n) {
    listi_t *h = NULL;
    int f;

    for (f = 2; f <= n; f++) {
        while (n % f == 0) {
            h = append(h, f);
            n = n / f;
        }
    }
    
    return h;
}