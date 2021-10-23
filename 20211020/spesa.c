/*
*   Es. 1
*/

#include <stdio.h>
#define MAX_PROD 50

int main (int argc, char * argv[]) {
    float prodotti[MAX_PROD], spesaMax, spesaTot;
    int nTot;
    int i, tmp, nProd;

    /* Acquisisce i prezzi dei prodotti */
    nProd = 0;
    scanf("%d", &tmp);
    while (tmp >= 0 && nProd < MAX_PROD) {
        prodotti[nProd] = tmp;
        nProd++;
        scanf("%d", &tmp);                
    }

    /* Ricava dall'ultimo elemento dell'array la spesa massima */
    spesaMax = prodotti[nProd - 1];
    nProd--;

    /* Per ogni prodotto verifica se può essere acquistato oppure no */
    nTot = 0;
    spesaTot = 0;
    for (i = 0; i < nProd /* && costoSpesa < maxSpesa */; i++) {
        if (spesaTot + prodotti[i] <= spesaMax) {
            nTot++;
            spesaTot += prodotti[i];
        }   
    }

    /* Stampa i risultati */
    printf("%d %f\n", nTot, spesaTot);

    return 0;    
}